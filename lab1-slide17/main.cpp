#include <iostream>
#include <vector>
using namespace std;


class Shape {
public:
    virtual void display() const = 0;
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    void display() const override {
        cout << "Shape: circle" << endl;
        cout << "Radius: " << radius << endl;
    }

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    void display() const override {
        cout << "Shape: rectangle" << endl;
        cout << "Length: " << length << ", width: " << width << endl;
    }

    double area() const override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}

    void display() const override {
        cout << "Shape: triangle" << endl;
        cout << "Base: " << base << ", Height: " << height << endl;
    }

    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(8.0, 6.0));
    shapes.push_back(new Triangle(3.0, 7.0));

    for (size_t i = 0; i < shapes.size(); i++) {
        shapes[i]->display();
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "-----------------------------" << endl;
    }

    for (size_t i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();

    return 0;
}
