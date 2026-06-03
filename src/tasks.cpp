// Copyright 2022 UNN-CS
#include "tasks.h"
<<<<<<< HEAD

#include "circle.h"

namespace {

constexpr double kEarthRadiusKm = 6378.1;
constexpr double kMetersPerKm = 1000.0;
constexpr double kRopeExtensionM = 1.0;

}  // namespace

double earthRopeGap() {
    const double earthRadiusM = kEarthRadiusKm * kMetersPerKm;

    Circle globe(earthRadiusM);
    globe.setFerence(globe.getFerence() + kRopeExtensionM);

    return globe.getRadius() - earthRadiusM;
}

double poolMaterialsCost(double poolRadius, double pathWidth,
                         double concretePricePerSqM,
                         double fencePricePerMeter) {
    Circle pool(poolRadius);
    Circle ring(poolRadius + pathWidth);

    const double pathArea = ring.getArea() - pool.getArea();
    const double concreteCost = pathArea * concretePricePerSqM;
    const double fenceCost = ring.getFerence() * fencePricePerMeter;

    return concreteCost + fenceCost;
=======
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
>>>>>>> b6db93efe28c710d4340d209f52c57582f464387
}
