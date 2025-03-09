#include <iostream>
using namespace std;
void displaymenu(){
    cout<<"Simplecalc"<<endl;
    cout<<"1 Adsition(+)"<<endl;
    cout<<"3.Multiplication"<<endl;
    cout<<"4.Division"<<endl;
    cout<<"5.Exit"<<endl;
    cout<< "enter your choice:";
}

int main(){
    int choice;
    double num1, num2 ,result;

    do{
        displaymenu();
        cin>>choice;
        if(choice >= 1 && choice<=4)
        {
            cout<<"enter first number";
            cin>> num1;
            cout<< "enter second number";
            cin>> num2;

        }
        switch(choice)
        {
            case 1:
            result =num1+num2;
            cout<< "Result:"<< num1<<"+"<<num2<<"="<< result<<endl;
            break;

            case 2:
            result = num1*num2;
            cout<<"Result:"<<num1<<"/"<<num2<<"="<<result<<endl;
            case 3:
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
            case 4:
            if(num2!=0)
            {
            result = num1 / num2;
            cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            
            }
            else;
            {
                cout<<"Error ! Division by zero is not allowed"<<endl;
            }
            break;
            case 5:
            cout<< "existing the calculator thankyou"<<endl;
            break;
            default:
            cout<<"invalid choice !please enter valid operation";
        }
        }
        while (choice !=5);

    }


