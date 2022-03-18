#include <iostream>
#include <fstream>
#include <string>
#include "pretty-printing.h"

int main() {

    std::string line;
    std::ifstream fin("bad-code.cpp");

    //----------------------------------------------------------------//
                                // First Task //
                        // Task A: Removing indentation //
    //----------------------------------------------------------------//
    
    std::cout << "Task A\n";
    while(getline(fin,line)) {
        std::string unindented = removeLeadingSpaces(line);
        std::cout << unindented << std::endl;
    }
    fin.close();
    std::cout << "\n------------------------------------------------\n"; 

    //----------------------------------------------------------------//
                                // Second Task //
                // Task B: Counting blocks opened and closed by //
                    // { and }, and adding real indentation //
    //----------------------------------------------------------------//
    
    fin.open("bad-code.cpp");
    std::cout << "Task B\n";

    int outerBraces = 0;
    int innerBraces = 0;
    while(getline(fin,line)) {

        innerBraces = countChar(line, '}') + innerBraces;
        std::string unindented = removeLeadingSpaces(line);
        std::cout << indent(unindented, outerBraces, innerBraces) << std::endl;
        outerBraces = countChar(line, '{') + outerBraces;
    }
    fin.close();
    //----------------------------------------------------------------//
                                  // Done //
    //----------------------------------------------------------------//
    std::cout << "\n------------------------------------------------\n";
    std::cout << "Thank you for using the Automatic Style Program" << std::endl; 

    return 0;
}