// C++ implementation to find the
// Nth occurrence of a character

#include <iostream>
using namespace std;

// Function to find the
// Nth occurrence of a character
int findNthOccur(string str,
				char ch, int N)
{
	int occur = 0;

	// Loop to find the Nth
	// occurrence of the character
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ch) {
			occur += 1;
		}
		if (occur == N)
			return i;
	}
	return -1;
}

// Driver Code
int main()
{
	string str = "geeks";
	char ch = 'e';
	int N = 2;
	cout << findNthOccur(str, ch, N);
}
