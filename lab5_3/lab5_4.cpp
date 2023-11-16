#include <iostream>
#include <cmath>

using namespace std;

class Form {
private:
    string color;

protected:
    string name;

    void setColor(string color) {
        this->color = color;
    }

public:
    Form(string name) : name(name) {}

    virtual ~Form() {}

    string getName() {
        return this->name;
    }

    void setName(string name) {
        this->name = name;
    }

    void showMessage() {
        cout << "Message from Form" << endl;
    }

    virtual double computeArea() const = 0; 
};

class Rectangle : public Form {
protected:
    int width;
    int height;

public:
    Rectangle(string name, int width, int height) : Form(name), width(width), height(height) {}

    void setWidth(int width) {
        this->width = width;
    }

    int getWidth() {
        return this->width;
    }

    void showMessage() {
        Form::showMessage();
        cout << "Message from Rectangle" << endl;
    }

    double computeArea() const override {
        return width * height;
    }
};

class Square : public Form {
protected:
    int side;

public:
    Square(string name, int side) : Form(name), side(side) {}

    void setSide(int side) {
        this->side = side;
    }

    int getSide() {
        return this->side;
    }

    void showMessage() {
        cout << "Message from Square" << endl;
    }

    double computeArea() const override {
        return side * side;
    }
};

int main() {
    Form* r = new Rectangle("rectangle 1", 1, 2);
    Form* s = new Square("square 1", 20);

    cout << "Rectangle name: " << r->getName() << " Width: " << static_cast<Rectangle*>(r)->getWidth() << " Area: " << r->computeArea() << endl;
    r->showMessage();

    cout << "Square name: " << s->getName() << " Side: " << static_cast<Square*>(s)->getSide() << " Area: " << s->computeArea() << endl;
    s->showMessage();

    delete r;
    delete s;

    return 0;
}