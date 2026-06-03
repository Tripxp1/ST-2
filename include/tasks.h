// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double CalculateEarthGap();

double CalculatePoolCost(double poolRadius, double pathWidth, 
                         double concretePricePerSquareMeter, 
                         double fencePricePerMeter);

#endif  // INCLUDE_TASKS_H_
