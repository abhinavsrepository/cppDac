#include <iostream>
using namespace std;

int main() {
    string str, reversedStr;
    
    // Input string
    cout << "Enter a string: ";
    getline(cin, str);

    // Reverse manually
    for (int i = str.length() - 1; i >= 0; i--) {
        reversedStr += str[i];
    }

    // Display the reversed string
    cout << "Reversed string: " << reversedStr << endl;

    return 0;
}
