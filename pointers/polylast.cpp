#include <iostream>
#include<cmath>

using namespace std;

class shape{
    protected: 
    string color;
    bool filled;

    public :
    shape(string color , bool filled):color(color),filled(filled){}

    virtual void draw(){
        cout<< "Drawing a generic shape"<<endl;    
    }
    virtual double getPerimeter(){
        return 0.0;
    }
    virtual ~shape(){}

};
//Derived class circle

class Circle:public shape{
    private :
    double radius ;
    public : 
    Circle(string color, bool filled, double radius) : shape(color, filled), radius(radius) {}

    void draw()override
{
   cout<< "Draing a color "<<color << 
}}