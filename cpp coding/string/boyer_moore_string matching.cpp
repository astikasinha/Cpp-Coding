#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to build the bad match table
unordered_map<char, int> buildBadMatchTable(string& pattern) {
    unordered_map<char, int> badMatchTable;
    int m = pattern.size();
    for (int i = 0; i < m; ++i) {
        // Maximum shift is pattern length minus index minus one
        int shift = max(1, m - i - 1);
        badMatchTable[pattern[i]] = shift;
    }
    return badMatchTable;
}

// Boyer-Moore string search function
void boyerMooreSearch(string& text,string& pattern) {
    unordered_map<char, int> badMatchTable = buildBadMatchTable(pattern);
    int n = text.length();
    int m = pattern.length();
    int i = 0;

    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[i + j]) {
            j--;
        }
        if (j < 0) {
            cout << "Pattern found at index " << i << std::endl;
            if(i+m<n){
                i=i+badMatchTable[text[i+m]];
            }
            else{
                i=i+1;
            }
        } else {
            i += max(1, badMatchTable.find(text[i + j]) != badMatchTable.end() ? badMatchTable[text[i + j]] : m);
        }
    }
}

int main() {
    string text = "HERE IS A SIMPLE EXAMPLE";
    string pattern = "EXAMPLE";
    boyerMooreSearch(text, pattern);
    return 0;
}
