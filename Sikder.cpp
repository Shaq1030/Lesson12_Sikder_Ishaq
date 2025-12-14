#include <iostream>

class Shape {
protected:
    int numSides;
public:
    Shape() : numSides(1) {}
    Shape(int n) : numSides(n) {}
    virtual float area() const = 0;
    virtual void print() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    int length, width;
public:
    Rectangle() : Shape(4), length(1), width(2) {}
    float area() const override { return static_cast<float>(length * width); }
    void print() const override { std::cout << numSides << " " << length << " " << width << "\n"; }
};

class Triangle : public Shape {
private:
    int base, height;
public:
    Triangle() : Shape(3), base(2), height(1) {}
    float area() const override { return 0.5f * static_cast<float>(base * height); }
    void print() const override { std::cout << numSides << " " << base << " " << height << "\n"; }
};

int main() {
    std::cout << std::endl;

    // Q1: Why is the line "Shape s;" commented out?
    // Answer: Shape has "pure virtual" functions, so it's abstract.
    // Shape s;

    // Q2: What type of array is "shapes"?
    // Answer: It's an array of base-class pointers: Shape*.
    // Each slot can point to any specific shape (Triangle, Rectangle, etc.).
    Shape **shapes = new Shape*[2];

    // Q3: Does down casting or upcasting occur in this program?
    // Answer: Upcasting. We create Triangle/Rectangle objects and store their addresses in Shape* variables.
    shapes[0] = new Triangle;
    shapes[1] = new Rectangle;

    // Q4: What is the point of the "->" operator?
    // Answer: It's how you access members through a pointer.
    // Because print/area are virtual, this triggers polymorphism and calls the right override.
    shapes[0]->print();
    shapes[1]->print();

    std::cout << shapes[0]->area() << "\n";
    std::cout << shapes[1]->area() << "\n";

    // Clean up
    delete shapes[0];
    delete shapes[1];
    delete[] shapes;

    // Q5: Why is Shape an abstract class?
    // Answer: Shape declares pure virtual functions (print and area).
    // That means it only defines the common interface and leaves the actual work to the derived shapes.

    std::cout << std::endl;
    return 0;
}
