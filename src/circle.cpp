// Copyright 2022 UNN-CS
#include "circle.h"

const double PI = 3.14159265358979323846;

Circle::Circle(double r) {
    radius_ = 0.0;
    circumference_ = 0.0;
    area_ = 0.0;
    setRadius(r);
}

void Circle::updateFromRadius() {
    circumference_ = 2.0 * PI * radius_;
    area_ = PI * radius_ * radius_;
}

void Circle::updateFromCircumference(double circ) {
    if (circ < 0.0) {
        circumference_ = 0.0;
        radius_ = 0.0;
        area_ = 0.0;
    } else {
        circumference_ = circ;
        radius_ = circ / (2.0 * PI);
        area_ = PI * radius_ * radius_;
    }
}

void Circle::updateFromArea(double a) {
    if (a < 0.0) {
        area_ = 0.0;
        radius_ = 0.0;
        circumference_ = 0.0;
    } else {
        area_ = a;
        radius_ = std::sqrt(a / PI);
        circumference_ = 2.0 * PI * radius_;
    }
}

void Circle::setRadius(double r) {
    radius_ = r;
    updateFromRadius();
}

void Circle::setCircumference(double c) {
    updateFromCircumference(c);
}

void Circle::setArea(double a) {
    updateFromArea(a);
}

double Circle::getRadius() const {
    return radius_;
}

double Circle::getCircumference() const {
    return circumference_;
}

double Circle::getArea() const {
    return area_;
}

bool Circle::isValid() const {
    return (radius_ >= 0.0 && circumference_ >= 0.0 && area_ >= 0.0);
}
