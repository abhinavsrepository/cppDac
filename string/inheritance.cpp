#include<iostream>
#include<string>
using namespace std;


class vehicle {

    protected:
    string vehichleNo;
    string ownername;
    public :
    void accept(){
        cout<< "eneter vehicle number";
        cin>>vehichleNo;
        cout << "owner";
        cin>>ownername;


    
    }
    void display(){
        cout<< "vehicle number"<<vehichleNo;
        cout<< "onner"<<ownername;
    }
};
    //inheriting from base class

    class twowheeler :public vehicle{
        private:
        string vehtype;

        public : 
        virtual void accept(){
            vehicle :: accept();
            cout<< "enter vehicle type (motorcycle/scooter/etc);";
            cin>>vehtype;

        }
        void display(){
            vehicle::display();
            cout<< "vehivle type"<<vehtype<<endl;
        }

    };

        int main (){
            vehicle vh;
            twowheeler tw;

            tw.accept();
            tw.display();

            
            
            return 0;
        }

