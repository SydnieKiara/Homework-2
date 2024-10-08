// Programming_Lan_HW2.cpp
#include <iostream>
#include <unordered_map>
#include <string>

// Function: findMostFrequentChar
// ------------------------------
// This function takes a string as input and returns the character
// that appears most frequently in the string. In case of a tie,
//It returns the first character that reaches the highest frequency.
//
// Parameters:
//    input - a reference to the input string to analyze
//
// Returns:
//    The most frequently occurring character in the input string.
//
char findMostFrequentChar(const std::string& input) {
    std::unordered_map<char, int> frequency;
    
    // Build a frequency map for each character in the string
    for (char ch : input) {
        frequency[ch]++;
    }

    char maxChar = input[0];  // Initialize with the first character of the input
    int maxCount = 0;         // Initialize the maximum count to zero
    
    // Iterate over the frequency map to find the character with the highest count
    for (const auto& pair : frequency) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxChar = pair.first;
        }
    }
    return maxChar;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Check for empty string input
    if (input.empty()) {
        std::cout << "The string is empty." << std::endl;
        return 1;
    }

    // Find and print the most frequent character
    char mostFrequentChar = findMostFrequentChar(input);
    std::cout << "Most frequent character: " << mostFrequentChar << std::endl;

    // Test cases
    std::string test1 = "hello world";
    std::string test2 = "aabbcc";
    
    std::cout << "Test Case 1: Input = \"hello world\"\n";
    std::cout << "Expected Output: l\n";
    std::cout << "Actual Output: " << findMostFrequentChar(test1) << std::endl;

    std::cout << "Test Case 2: Input = \"aabbcc\"\n";
    std::cout << "Expected Output: a (or b or c due to tie)\n";
    std::cout << "Actual Output: " << findMostFrequentChar(test2) << std::endl;

    return 0;
}
