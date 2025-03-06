// #pointers
// 1) data variable
// 2) Adress variable

// #intro x=10;
// int *p  address takes 2 bytes of memory

#include <iostream>
using namespace std;

int main(){
    int x= 10;
    int *p;
    p=&x;
    cout<< x;
    cout<< &x;
    cout<< p;
    cout <<&p;
    cout<< *p;
}