#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

int main() {
    const int width = 80;
    const int height = 40;
    const double theta_spacing = 0.07;
    const double phi_spacing = 0.02;
    
    const double R1 = 1.0;
    const double R2 = 2.0;
    const double K2 = 5.0;
    const double K1 = width * K2 * 3 / (8 * (R1 + R2));
    
    double A = 0, B = 0;
    
    while (true) {
        std::vector<std::vector<double>> z_buffer(height, std::vector<double>(width, 0.0));
        std::vector<std::vector<char>> output(height, std::vector<char>(width, ' '));
        
        A += 0.07;
        B += 0.03;
        
        double cosA = cos(A), sinA = sin(A);
        double cosB = cos(B), sinB = sin(B);
        
        for (double theta = 0; theta < 2 * M_PI; theta += theta_spacing) {
            double costheta = cos(theta), sintheta = sin(theta);
            
            for (double phi = 0; phi < 2 * M_PI; phi += phi_spacing) {
                double cosphi = cos(phi), sinphi = sin(phi);
                
                double circlex = R2 + R1 * costheta;
                double circley = R1 * sintheta;
                
                double x = circlex * (cosB * cosphi + sinA * sinB * sinphi) - circley * cosA * sinB;
                double y = circlex * (sinB * cosphi - sinA * cosB * sinphi) + circley * cosA * cosB;
                double z = K2 + cosA * circlex * sinphi + circley * sinA;
                double ooz = 1 / z;
                
                int xp = (int)(width / 2 + K1 * ooz * x);
                int yp = (int)(height / 2 - K1 * ooz * y);
                
                double L = cosphi * costheta * sinB - cosA * costheta * sinphi - 
                          sinA * sintheta + cosB * (cosA * sintheta - costheta * sinA * sinphi);
                
                if (L > 0) {
                    if (xp >= 0 && xp < width && yp >= 0 && yp < height) {
                        if (ooz > z_buffer[yp][xp]) {
                            z_buffer[yp][xp] = ooz;
                            int luminance_index = (int)(L * 8);
                            const std::string luminance_chars = ".,-~:;=!*#$@";
                            output[yp][xp] = luminance_chars[std::min(luminance_index, (int)luminance_chars.length() - 1)];
                        }
                    }
                }
            }
        }
        
        std::cout << "\x1b[2J\x1b[H";
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                std::cout << output[i][j];
            }
            std::cout << '\n';
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    
    return 0;
}