/*--------------------------------------------------------
Program Name: User Input Program
Author: Zoheb Khan
Date: 09/18/24
----------------------------------------------------------
Pseudocode:
//For input/output operations (std::cin, std::cout, std::cerr)
//For file handling (std::ifstream, std::ofstream)
//For using the std::string class
//For std::reverse function used to reverse strings
//Function to append user input to the provided file
//Open file in append mode using std::ios::app
//Take user input, including spaces
//Append the input to the file
//Function to reverse the content of the original file and store it in a new file
//Open the input file for reading
//Read the entire file content into a string
//Reverse the content
//Write the reversed content to the output file
//Write the reversed content
//Use relative paths based on the assumption that the program is run from the "CSC475_CTA5" directory
//The input file provided
//The output file for reversed content
//Step 1: Append user input to the original file
//Step 2: Reverse the content of the file and write it to a new file
//Exit the program
----------------------------------------------------------
Program Inputs: Three user input integer values
Program Outputs: The values of the pointers
--------------------------------------------------------*/
#include <iostream>     //For input/output operations (std::cin, std::cout, std::cerr)
#include <fstream>      //For file handling (std::ifstream, std::ofstream)
#include <string>       //For using the std::string class
#include <algorithm>    //For std::reverse function used to reverse strings

//Function to append user input to the provided file
void appendToFile(const std::string& filename) {
    std::ofstream outFile;
    //Open file in append mode using std::ios::app
    outFile.open(filename, std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string userInput;
    std::cout << "Enter text to append to the file: ";
    std::getline(std::cin, userInput);  //Take user input, including spaces

    outFile << userInput << std::endl;  //Append the input to the file
    outFile.close();
    std::cout << "Data successfully appended to the file." << std::endl;
}

//Function to reverse the content of the original file and store it in a new file
void reverseFileContent(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inFile(inputFilename);  //Open the input file for reading

    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << inputFilename << std::endl;
        return;
    }

    //Read the entire file content into a string
    std::string fileContent((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();

    //Reverse the content
    std::reverse(fileContent.begin(), fileContent.end());

    //Write the reversed content to the output file
    std::ofstream outFile(outputFilename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << outputFilename << std::endl;
        return;
    }

    outFile << fileContent;  //Write the reversed content
    outFile.close();
    std::cout << "Reversed content written to " << outputFilename << std::endl;
}

int main() {
    //Use relative paths based on the assumption that the program is run from the "CSC475_CTA5" directory
    const std::string inputFilename = "CSC450_CT5_mod5.txt";  //The input file provided
    const std::string outputFilename = "CSC450_CT5_mod5-reverse.txt";  //The output file for reversed content

    //Step 1: Append user input to the original file
    appendToFile(inputFilename);

    //Step 2: Reverse the content of the file and write it to a new file
    reverseFileContent(inputFilename, outputFilename);

    return 0;  //Exit the program
}
