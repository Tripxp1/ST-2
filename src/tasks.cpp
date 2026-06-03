// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

const double EARTH_RADIUS_METERS = 6378100.0;
const double EXTRA_ROPE_METERS = 1.0;

double CalculateEarthGap() {
    Circle earthSphere(EARTH_RADIUS_METERS);
    
    double originalCircumference = earthSphere.getCircumference();
    double newCircumference = originalCircumference + EXTRA_ROPE_METERS;
    
    earthSphere.setCircumference(newCircumference);
    
    double newRadius = earthSphere.getRadius();
    double gapSize = newRadius - EARTH_RADIUS_METERS;
    
    return gapSize;
}

double CalculatePoolCost(double poolRadius, double pathWidth,
                         double concretePricePerSquareMeter,
                         double fencePricePerMeter) {
    Circle innerPool(poolRadius);
    Circle outerBoundary(poolRadius + pathWidth);
    
    double poolArea = innerPool.getArea();
    double totalArea = outerBoundary.getArea();
    double pathArea = totalArea - poolArea;
    
    double concreteCost = pathArea * concretePricePerSquareMeter;
    double fenceLength = outerBoundary.getCircumference();
    double fenceCost = fenceLength * fencePricePerMeter;
    
    double totalCost = concreteCost + fenceCost;
    
    return totalCost;
}
