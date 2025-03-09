#include <iostream>
using namespace std;
class shape{
    public:
    virtual int getArea ()=0;

    void setWidth(int w){
        int width =w;

    }
    void setHeight(int h){
        int height =h;
    }
    protected :
    int width;
    int height;

};
class Rectangle :public Shape{
    public :
    int getArea()
    {
        return (width *height)
    }
}