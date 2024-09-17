// Programming_Lan_HW2.cpp
#include <iostream>
#include <unordered_map>
#include <string>

char findMostFrequentChar(const std::string& input) {
    std::unordered_map<char, int> frequency;
    for (char ch : input) {
        frequency[ch]++;
    }

    char maxChar = input[0];
    int maxCount = 0;
    
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

    if (input.empty()) {
        std::cout << "The string is empty." << std::endl;
        return 1;
    }

    char mostFrequentChar = findMostFrequentChar(input);
    std::cout << mostFrequentChar << " " << findMostFrequentChar(input) << std::endl;

    return 0;
}
