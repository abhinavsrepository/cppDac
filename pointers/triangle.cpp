#include <iostream>
#include <cmath>  // For M_PI and sqrt()
using namespace std;

// Base class Shape
class Shape {
public:
    double area, perimeter;

    // Function to display area and perimeter
    void display() {
        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter << endl;
    }
};

// Derived class for Circle
class Circle : public Shape {
public:
    double radius;

    // Constructor to accept radius and calculate properties
    Circle(double r) {
        radius = r;
        area = M_PI * radius * radius;
        perimeter = 2 * M_PI * radius;
    }
};

// Derived class for Rectangle
class Rectangle : public Shape {
public:
    double length, width;

    // Constructor to accept length and width and calculate properties
    Rectangle(double l, double w) {
        length = l;
        width = w;
        area = length * width;
        perimeter = 2 * (length + width);
    }
};

// Derived class for Triangle
class Triangle : public Shape {
public:
    double a, b, c;

    // Constructor to accept three sides and calculate properties
    Triangle(double side1, double side2, double side3) {
        a = side1;
        b = side2;
        c = side3;
        double s = (a + b + c) / 2;  // Semi-perimeter
        area = sqrt(s * (s - a) * (s - b) * (s - c));  // Heron's formula
        perimeter = a + b + c;
    }
};

// Main function
int main() {
    double r, l, w, a, b, c;

    // Accept details for Circle
    cout << "Enter radius of Circle: ";
    cin >> r;
    Circle circle(r);
    cout << "Circle:\n";
    circle.display();

    // Accept details for Rectangle
    cout << "\nEnter length and width of Rectangle: ";
    cin >> l >> w;
    Rectangle rectangle(l, w);
    cout << "Rectangle:\n";
    rectangle.display();

    // Accept details for Triangle
    cout << "\nEnter three sides of Triangle: ";
    cin >> a >> b >> c;
    Triangle triangle(a, b, c);
    cout << "Triangle:\n";
    triangle.display();

    return 0;
}
