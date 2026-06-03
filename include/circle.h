// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <cmath>
#include <stdexcept>

class Circle {
 private:
    double radius_;
    double circumference_;
    double area_;

    void updateFromRadius();
    void updateFromCircumference(double circ);
    void updateFromArea(double a);

 public:
    explicit Circle(double r);
    
    void setRadius(double r);
    void setCircumference(double c);
    void setArea(double a);
    
    double getRadius() const;
    double getCircumference() const;
    double getArea() const;
    
    bool isValid() const;
};

#endif  // INCLUDE_CIRCLE_H_
