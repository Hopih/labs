#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <vector>
#include <random>

// Константы
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;
const float G = 6.67430e-11f; // Гравитационная постоянная
const float C = 299792458.0f; // Скорость света

// Структура для частицы
struct Particle {
    float x, y, z;
    float vx, vy, vz;
    float mass;
    bool captured;
    float life;
};

// Класс черной дыры
class BlackHole {
public:
    float x, y, z;
    float mass;
    float schwarzschild_radius;
    
    BlackHole(float x, float y, float z, float mass) 
        : x(x), y(y), z(z), mass(mass) {
        schwarzschild_radius = 2.0f * G * mass / (C * C);
    }
    
    // Расчет гравитационного ускорения
    void calculateAcceleration(float px, float py, float pz, 
                              float& ax, float& ay, float& az) {
        float dx = px - x;
        float dy = py - y;
        float dz = pz - z;
        
        float r = sqrt(dx*dx + dy*dy + dz*dz);
        
        if (r < schwarzschild_radius * 1.1f) {
            ax = ay = az = 0;
            return;
        }
        
        float r3 = r * r * r;
        float force = G * mass / r3;
        
        ax = -force * dx;
        ay = -force * dy;
        az = -force * dz;
    }
    
    // Проверка попадания в горизонт событий
    bool isInsideEventHorizon(float px, float py, float pz) {
        float dx = px - x;
        float dy = py - y;
        float dz = pz - z;
        float distance = sqrt(dx*dx + dy*dy + dz*dz);
        return distance <= schwarzschild_radius;
    }
};

// Глобальные переменные
BlackHole blackHole(0.0f, 0.0f, 0.0f, 1.0e15f);
std::vector<Particle> particles;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(-1.0, 1.0);

// Инициализация частиц
void initParticles(int count) {
    particles.clear();
    for (int i = 0; i < count; ++i) {
        Particle p;
        
        // Случайная позиция в сфере вокруг черной дыры
        float theta = dis(gen) * M_PI;
        float phi = dis(gen) * 2 * M_PI;
        float radius = 50.0f + dis(gen) * 100.0f;
        
        p.x = radius * sin(theta) * cos(phi);
        p.y = radius * sin(theta) * sin(phi);
        p.z = radius * cos(theta);
        
        // Начальная скорость (орбитальная)
        float orbital_speed = sqrt(G * blackHole.mass / radius) * 0.7f;
        p.vx = -orbital_speed * sin(phi);
        p.vy = orbital_speed * cos(phi);
        p.vz = dis(gen) * 0.1f;
        
        p.mass = 1.0f;
        p.captured = false;
        p.life = 1.0f;
        
        particles.push_back(p);
    }
}

// Обновление физики
void updatePhysics(float deltaTime) {
    for (auto& p : particles) {
        if (p.captured) continue;
        
        // Расчет ускорения от черной дыры
        float ax, ay, az;
        blackHole.calculateAcceleration(p.x, p.y, p.z, ax, ay, az);
        
        // Обновление скорости и позиции
        p.vx += ax * deltaTime;
        p.vy += ay * deltaTime;
        p.vz += az * deltaTime;
        
        p.x += p.vx * deltaTime;
        p.y += p.vy * deltaTime;
        p.z += p.vz * deltaTime;
        
        // Проверка на захват черной дырой
        if (blackHole.isInsideEventHorizon(p.x, p.y, p.z)) {
            p.captured = true;
            p.life = 0.0f;
        }
        
        // Уменьшение времени жизни
        p.life -= deltaTime * 0.1f;
    }
    
    // Удаление старых частиц
    particles.erase(
        std::remove_if(particles.begin(), particles.end(),
            [](const Particle& p) { return p.life <= 0.0f; }),
        particles.end());
    
    // Добавление новых частиц
    if (particles.size() < 500) {
        initParticles(50);
    }
}

// Рендеринг
void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Установка камеры
    gluLookAt(0.0, 0.0, 200.0,  // позиция камеры
              0.0, 0.0, 0.0,    // точка наблюдения
              0.0, 1.0, 0.0);   // вектор вверх
    
    // Рендеринг черной дыры
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    glutSolidSphere(blackHole.schwarzschild_radius * 10, 50, 50);
    
    // Аккреционный диск
    glColor3f(0.8f, 0.4f, 0.1f);
    glutSolidTorus(blackHole.schwarzschild_radius * 3, 
                   blackHole.schwarzschild_radius * 20, 30, 50);
    glPopMatrix();
    
    // Рендеринг частиц
    glBegin(GL_POINTS);
    for (const auto& p : particles) {
        if (!p.captured) {
            // Цвет в зависимости от скорости
            float speed = sqrt(p.vx*p.vx + p.vy*p.vy + p.vz*p.vz);
            float r = std::min(1.0f, speed / 100.0f);
            float g = std::min(1.0f, p.life);
            float b = std::min(1.0f, (100.0f - speed) / 100.0f);
            
            glColor3f(r, g, b);
            glVertex3f(p.x, p.y, p.z);
        }
    }
    glEnd();
    
    glutSwapBuffers();
}

// Обработка изменения размера окна
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}

// Таймер для анимации
void timer(int value) {
    updatePhysics(0.016f); // ~60 FPS
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

// Обработка клавиш
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'r':
        case 'R':
            initParticles(500);
            break;
        case 27: // ESC
            exit(0);
            break;
    }
}

// Инициализация OpenGL
void initGL() {
    glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(3.0f);
    
    // Включение blending для эффектов
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Black Hole Simulation");
    
    initGL();
    initParticles(500);
    
    glutDisplayFunc(render);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);
    
    std::cout << "Black Hole Simulation Controls:\n";
    std::cout << "R - Reset simulation\n";
    std::cout << "ESC - Exit\n";
    
    glutMainLoop();
    
    return 0;
}