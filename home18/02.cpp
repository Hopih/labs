#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdio>

int main() {
    std::string input;
    
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    
    std::cout << "\nOriginal string = \"" << input << "\"" << std::endl;
    
    int countS = 0, counts = 0;
    for (char c : input) {
        if (c == 'S') countS++;
        else if (c == 's') counts++;
    }
    int totalS = countS + counts;
    
    std::cout << "Count of S = " << countS << std::endl;
    std::cout << "Count of s = " << counts << std::endl;
    std::cout << "Count of s and S = " << totalS << std::endl;
    
    int digitCount = 0;
    for (char c : input) {
        if (std::isdigit(c)) digitCount++;
    }
    std::cout << "Count of digits = " << digitCount << std::endl;
    

    int upperCount = 0;
    for (char c : input) {
        if (std::isupper(c)) upperCount++;
    }
    std::cout << "Count of uppercase letters = " << upperCount << std::endl;
    
   
    std::string newString = input;
    
    
    for (char &c : newString) {
        if (c == '1') {
            c = '5';
        } else if (std::islower(c)) {
            c = std::toupper(c);
        }
    }
    
    std::cout << "New string = \"" << newString << "\"" << std::endl;
    
    
    std::cout << "\nAll results in one printf() call:" << std::endl;
    printf("Original string = \"%s\",\ncount of S = %d,\ncount of s = %d,\ncount of s and S = %d,\ncount of digits = %d,\ncount of uppercase letters = %d,\nnew string = \"%s\"\n", 
           input.c_str(), countS, counts, totalS, digitCount, upperCount, newString.c_str());
    
    return 0;
}