#include <iostream>
#include <string>

using namespace std;

string decompressString(const string& compressed) {
    string result;
    int n = compressed.length();
    
    for (int i = 0; i < n; i++) {
        if (isalpha(compressed[i])) {  // If it's a letter, store it
            result += compressed[i];
        } 
        else if (isdigit(compressed[i])) {  // If it's a number, repeat the last letter
            int count = compressed[i] - '0';  // Convert char to int
            
            if (!result.empty()) {  
                result.append(count - 1, result.back());  // Append (count-1) times the last character
            }
        }
    }
    
    return result;
}

int main() {
    string compressed;
    cout << "Enter compressed string: ";
    cin >> compressed;

    string decompressed = decompressString(compressed);
    cout << "Decompressed string: " << decompressed << endl;

    return 0;
}
