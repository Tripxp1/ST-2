// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

<<<<<<< HEAD
class Circle {
 private:
    double radius;
    double ference;
    double area;

    static const double kPi;

    void syncFromRadius();
    void syncFromFerence();
    void syncFromArea();

 public:
    explicit Circle(double r);

    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;
=======
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
>>>>>>> b6db93efe28c710d4340d209f52c57582f464387
};

#endif  // INCLUDE_CIRCLE_H_
