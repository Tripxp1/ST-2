// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

<<<<<<< HEAD
/** Зазор между поверхностью Земли и верёвкой после удлинения на 1 м. */
double earthRopeGap();

/**
 * Стоимость бетонной дорожки и ограды вокруг круглого бассейна.
 * poolRadius — радиус бассейна (м), pathWidth — ширина дорожки (м).
 */
double poolMaterialsCost(double poolRadius, double pathWidth,
                         double concretePricePerSqM,
=======
double CalculateEarthGap();

double CalculatePoolCost(double poolRadius, double pathWidth, 
                         double concretePricePerSquareMeter, 
>>>>>>> b6db93efe28c710d4340d209f52c57582f464387
                         double fencePricePerMeter);

#endif  // INCLUDE_TASKS_H_
