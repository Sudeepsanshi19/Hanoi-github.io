#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> computePrefixTable(const string &pattern) {
    int m = pattern.length();
    vector<int> prefixTable(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++) {
        if (pattern[i] == pattern[j]) {
            j++;
            prefixTable[i] = j;
        } else {
            if (j != 0) {
                j = prefixTable[j - 1];
                i--; // Check the current character again
            } else {
                prefixTable[i] = 0;
            }
        }
    }
    return prefixTable;
}


void KMPSearch(const string &text, const string &pattern) {
    vector<int> prefixTable = computePrefixTable(pattern);
    int n = text.length();
    int m = pattern.length();
    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = prefixTable[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = prefixTable[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "bacbababacaab";
    string pattern = "ababaca";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    KMPSearch(text, pattern);

    return 0;
}
