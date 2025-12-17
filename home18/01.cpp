#include <iostream>
#include <string>
#include <cctype> 


int main() {
    std::string firstName, middleName, lastName;
    
    
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    
    std::cout << "Enter middle name: ";
    std::cin >> middleName;
    
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    
    
    std::string fullName = lastName + " " + firstName + " " + middleName;
    
    
    std::string initials = std::string(1, firstName[0]) + "." + 
                          std::string(1, middleName[0]) + ".";
    
   
    std::string lastNameWithInitials = lastName + " " + 
                                      std::string(1, firstName[0]) + "." + 
                                      std::string(1, middleName[0]) + ".";
    
    
    std::string upperCaseName = "";
    for (char c : lastNameWithInitials) {
        upperCaseName += std::toupper(c);
    }
    
    
    std::cout << "\nResults:" << std::endl;
    std::cout << "1. Full name: " << fullName << std::endl;
    std::cout << "2. Initials: " << initials << std::endl;
    std::cout << "3. Last name with initials (uppercase): " << upperCaseName << std::endl;
    
    return 0;
}











