#include <iostream>
using namespace std;

bool isPalindrome(int num){
    int originalnum = num;
    int reversenum;

    while (num>0){
        int digit = num %10;
        reversenum = reversenum *10 +digit;
        num = num/10;



        
    }
    return originalnum == reversenum;


}
int main(){
    int number ;
    cout << "Enter a number: ";
    cin >> number;

    if (isPalindrome(number)) {
        cout << number << " is a Palindrome number.\n";
    } else {
        cout << number<< " is NOT a Palindrome number.\n";
    }

    return 0;
}
