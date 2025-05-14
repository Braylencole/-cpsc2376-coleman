#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>

constexpr double PI = 3.141592653589793;

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return PI * radius * radius;
    }
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << std::fixed << std::setprecision(4) << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << "Failed to open shapes.txt\n";
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "rectangle") {
            double width, height;
            if (iss >> width >> height) {
                shapes.push_back(std::make_unique<Rectangle>(width, height));
            }
        }
        else if (type == "circle") {
            double radius;
            if (iss >> radius) {
                shapes.push_back(std::make_unique<Circle>(radius));
            }
        }
    }

    printAllAreas(shapes);
    return 0;
}
