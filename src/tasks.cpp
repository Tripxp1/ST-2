// Copyright 2022 UNN-CS
#include "circle.h"
#include "tasks.h"

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
}
