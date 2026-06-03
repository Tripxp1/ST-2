// Copyright 2022 UNN-CS
#include "circle.h"

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
