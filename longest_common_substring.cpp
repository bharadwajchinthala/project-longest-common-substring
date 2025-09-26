#include <iostream>
#include <string>
using namespace std;

// Function to find the longest common substring using dynamic programming
int computeLongestCommonSubstring(const string& strA, const string& strB) {
    int lengthA = strA.length();  // Length of first string
    int lengthB = strB.length();  // Length of second string

    // Create a 2D DP table to store lengths of common substrings
    int dpGrid[lengthA + 1][lengthB + 1];

    int maxSubLen = 0;      // Maximum length of common substring found so far
    int lastCharIndex = 0;  // Ending index of the substring in strA

    // Build the DP table row by row
    for (int row = 0; row <= lengthA; row++) {
        for (int col = 0; col <= lengthB; col++) {
            if (row == 0 || col == 0) {
                // First row and first column represent empty strings
                dpGrid[row][col] = 0;
            } 
            else if (strA[row - 1] == strB[col - 1]) {
                // Characters match, so extend the previous substring
                dpGrid[row][col] = dpGrid[row - 1][col - 1] + 1;

                // Update max length and ending index if current substring is longer
                if (dpGrid[row][col] > maxSubLen) {
                    maxSubLen = dpGrid[row][col];
                    lastCharIndex = row - 1;
                }
            } 
            else {
                // Characters do not match, reset the substring length
                dpGrid[row][col] = 0;
            }
        }
    }

    // Display the DP table for visualization
    cout << "\nDynamic Programming Grid:" << endl;
    cout << "    ";
    for (int col = 0; col < lengthB; col++) cout << strB[col] << " ";
    cout << endl;

    for (int row = 0; row <= lengthA; row++) {
        if (row == 0) cout << "  ";        // Top left corner empty
        else cout << strA[row - 1] << " "; // Print character of strA for row
        for (int col = 0; col <= lengthB; col++) {
            cout << dpGrid[row][col] << " "; // Print the DP value
        }
        cout << endl;
    }

    // Extract and print the longest common substring
    cout << "\nLongest Common Substring: ";
    for (int idx = lastCharIndex - maxSubLen + 1; idx <= lastCharIndex; idx++) {
        cout << strA[idx];
    }
    cout << endl;

    // Return the length of the longest common substring
    return maxSubLen;
}

// Main function
int main() {
    string inputOne;  // First string input by user
    string inputTwo;  // Second string input by user

    // Prompt the user to enter the first string
    cout << "Enter first string: ";
    getline(cin, inputOne);

    // Prompt the user to enter the second string
    cout << "Enter second string: ";
    getline(cin, inputTwo);

    // Call the function to compute the longest common substring
    int lcsLength = computeLongestCommonSubstring(inputOne, inputTwo);

    // Display the length of the longest common substring
    cout << "Length of Longest Common Substring: " << lcsLength << endl;

    return 0;
}
