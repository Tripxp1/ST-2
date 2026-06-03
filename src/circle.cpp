// Copyright 2022 UNN-CS
#include "circle.h"

<<<<<<< HEAD
#include <cmath>

const double Circle::kPi = 3.14159265358979323846;

Circle::Circle(double r) : radius(0.0), ference(0.0), area(0.0) {
    setRadius(r);
}

void Circle::syncFromRadius() {
    ference = 2.0 * kPi * radius;
    area = kPi * radius * radius;
}

void Circle::syncFromFerence() {
    if (ference < 0.0) {
        radius = 0.0;
        ference = 0.0;
        area = 0.0;
        return;
    }
    radius = ference / (2.0 * kPi);
    area = kPi * radius * radius;
}

void Circle::syncFromArea() {
    if (area < 0.0) {
        radius = 0.0;
        ference = 0.0;
        area = 0.0;
        return;
    }
    radius = std::sqrt(area / kPi);
    ference = 2.0 * kPi * radius;
}

void Circle::setRadius(double r) {
    radius = r;
    syncFromRadius();
}

void Circle::setFerence(double f) {
    ference = f;
    syncFromFerence();
}

void Circle::setArea(double a) {
    area = a;
    syncFromArea();
}

double Circle::getRadius() const { return radius; }

double Circle::getFerence() const { return ference; }

double Circle::getArea() const { return area; }
=======
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
>>>>>>> b6db93efe28c710d4340d209f52c57582f464387
