// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
<<<<<<< HEAD

#include "circle.h"
#include "tasks.h"

namespace {

const double kEps = 1e-6;

}  // namespace

// --- Circle: конструктор и setRadius ---

TEST(CircleTest, ConstructorStoresRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, kEps);
}

TEST(CircleTest, ZeroRadiusGivesZeroFerenceAndArea) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, NegativeRadiusKeepsSign) {
    Circle c(-3.0);
    EXPECT_NEAR(c.getRadius(), -3.0, kEps);
    EXPECT_NEAR(c.getFerence(), -18.8495559215, kEps);
    EXPECT_NEAR(c.getArea(), 28.2743338823, kEps);
}

TEST(CircleTest, SetRadiusUpdatesFerence) {
    Circle c(1.0);
    c.setRadius(4.0);
    EXPECT_NEAR(c.getFerence(), 25.1327412287, kEps);
}

TEST(CircleTest, SetRadiusUpdatesArea) {
    Circle c(1.0);
    c.setRadius(4.0);
    EXPECT_NEAR(c.getArea(), 50.2654824574, kEps);
}

TEST(CircleTest, RepeatedSetRadius) {
=======
#include "circle.h"
#include "tasks.h"

const double EPSILON = 1e-6;

// ============== Конструктор ==============
TEST(CircleConstructor, WithPositiveRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPSILON);
}

TEST(CircleConstructor, WithZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleConstructor, WithNegativeRadius) {
    Circle c(-3.0);
    EXPECT_NEAR(c.getRadius(), -3.0, EPSILON);
    EXPECT_NEAR(c.getCircumference(), -18.8495559215, EPSILON);
    EXPECT_NEAR(c.getArea(), 28.2743338823, EPSILON);
}

// ============== setRadius ==============
TEST(CircleSetRadius, UpdatesRadiusOnly) {
    Circle c(2.0);
    c.setRadius(7.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7.0);
}

TEST(CircleSetRadius, RecalculatesCircumference) {
    Circle c(1.0);
    c.setRadius(4.0);
    EXPECT_NEAR(c.getCircumference(), 25.1327412287, EPSILON);
}

TEST(CircleSetRadius, RecalculatesArea) {
    Circle c(1.0);
    c.setRadius(4.0);
    EXPECT_NEAR(c.getArea(), 50.2654824574, EPSILON);
}

TEST(CircleSetRadius, AfterMultipleChanges) {
>>>>>>> b6db93efe28c710d4340d209f52c57582f464387
    Circle c(10.0);
    c.setRadius(5.0);
    c.setRadius(2.5);
    c.setRadius(7.5);
<<<<<<< HEAD
    EXPECT_NEAR(c.getArea(), 176.714586764, kEps);
}

// --- Circle: setFerence ---

TEST(CircleTest, SetFerenceRecalculatesRadius) {
    Circle c(1.0);
    c.setFerence(31.4159265359);
    EXPECT_NEAR(c.getRadius(), 5.0, kEps);
}

TEST(CircleTest, SetFerenceRecalculatesArea) {
    Circle c(1.0);
    c.setFerence(43.9822971503);
    EXPECT_NEAR(c.getArea(), 153.938040026, kEps);
}

TEST(CircleTest, SetFerenceToZeroClearsCircle) {
    Circle c(8.0);
    c.setFerence(0.0);
=======
    EXPECT_NEAR(c.getArea(), 176.714586764, EPSILON);
}

// ============== setCircumference ==============
TEST(CircleSetCircumference, UpdatesCircumference) {
    Circle c(1.0);
    c.setCircumference(30.0);
    EXPECT_DOUBLE_EQ(c.getCircumference(), 30.0);
}

TEST(CircleSetCircumference, RecalculatesRadius) {
    Circle c(1.0);
    c.setCircumference(31.4159265359);
    EXPECT_NEAR(c.getRadius(), 5.0, EPSILON);
}

TEST(CircleSetCircumference, RecalculatesArea) {
    Circle c(1.0);
    c.setCircumference(43.9822971503);
    EXPECT_NEAR(c.getArea(), 153.938040026, EPSILON);
}

TEST(CircleSetCircumference, WithZeroValue) {
    Circle c(8.0);
    c.setCircumference(0.0);
>>>>>>> b6db93efe28c710d4340d209f52c57582f464387
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

<<<<<<< HEAD
// --- Circle: setArea ---

TEST(CircleTest, SetAreaRecalculatesRadius) {
    Circle c(1.0);
    c.setArea(78.5398163397);
    EXPECT_NEAR(c.getRadius(), 5.0, kEps);
}

TEST(CircleTest, SetAreaRecalculatesFerence) {
    Circle c(1.0);
    c.setArea(254.469004941);
    EXPECT_NEAR(c.getFerence(), 56.5486677646, kEps);
}

TEST(CircleTest, SetAreaSmallValue) {
    Circle c(100.0);
    c.setArea(0.001);
    EXPECT_NEAR(c.getRadius(), 0.017841241, kEps);
    EXPECT_NEAR(c.getFerence(), 0.112099, kEps);
}

// --- Circle: геттеры и согласованность ---

TEST(CircleTest, GettersMatchInitialRadius) {
    Circle c(12.5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 12.5);
    EXPECT_NEAR(c.getFerence(), 78.5398163397, kEps);
    EXPECT_NEAR(c.getArea(), 490.873852209, kEps);
}

TEST(CircleTest, RoundTripViaFerence) {
    Circle c(2.0);
    const double savedArea = c.getArea();
    c.setFerence(c.getFerence());
    EXPECT_NEAR(c.getArea(), savedArea, kEps);
}

TEST(CircleTest, RoundTripViaArea) {
    Circle c(3.0);
    const double savedFerence = c.getFerence();
    c.setArea(c.getArea());
    EXPECT_NEAR(c.getFerence(), savedFerence, kEps);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e10);
    EXPECT_GT(c.getArea(), 0.0);
}

TEST(CircleTest, TinyRadius) {
    Circle c(1e-10);
    EXPECT_NEAR(c.getFerence(), 6.283185307e-10, 1e-20);
}

// --- Земля и верёвка ---

TEST(EarthRopeTest, GapIsPositive) {
    EXPECT_GT(earthRopeGap(), 0.0);
}

TEST(EarthRopeTest, GapEqualsOneOverTwoPi) {
    EXPECT_NEAR(earthRopeGap(), 0.159154943, 1e-7);
}

TEST(EarthRopeTest, GapAboutSixteenCentimeters) {
    const double gap = earthRopeGap();
=======
// ============== setArea ==============
TEST(CircleSetArea, UpdatesArea) {
    Circle c(1.0);
    c.setArea(200.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 200.0);
}

TEST(CircleSetArea, RecalculatesRadius) {
    Circle c(1.0);
    c.setArea(78.5398163397);
    EXPECT_NEAR(c.getRadius(), 5.0, EPSILON);
}

TEST(CircleSetArea, RecalculatesCircumference) {
    Circle c(1.0);
    c.setArea(254.469004941);
    EXPECT_NEAR(c.getCircumference(), 56.5486677646, EPSILON);
}

TEST(CircleSetArea, WithVerySmallValue) {
    Circle c(100.0);
    c.setArea(0.001);
    EXPECT_NEAR(c.getRadius(), 0.017841241, EPSILON);
    EXPECT_NEAR(c.getCircumference(), 0.112099, EPSILON);
}

// ============== Getters ==============
TEST(CircleGetters, GetRadius) {
    Circle c(12.5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 12.5);
}

TEST(CircleGetters, GetCircumference) {
    Circle c(3.0);
    EXPECT_NEAR(c.getCircumference(), 18.8495559215, EPSILON);
}

TEST(CircleGetters, GetArea) {
    Circle c(2.5);
    EXPECT_NEAR(c.getArea(), 19.6349540849, EPSILON);
}

// ============== Chain operations ==============
TEST(CircleOperations, RadiusToCircumferenceToArea) {
    Circle c(2.0);
    double area1 = c.getArea();
    c.setCircumference(c.getCircumference());
    EXPECT_NEAR(c.getArea(), area1, EPSILON);
}

TEST(CircleOperations, AreaToRadiusToCircumference) {
    Circle c(3.0);
    double circ1 = c.getCircumference();
    c.setArea(c.getArea());
    EXPECT_NEAR(c.getCircumference(), circ1, EPSILON);
}

TEST(CircleValidity, IsValidReturnsTrueForValidCircle) {
    Circle c(5.0);
    EXPECT_TRUE(c.isValid());
}

TEST(CircleValidity, IsValidWithNegativeArea) {
    Circle c(5.0);
    c.setArea(-10.0);
    EXPECT_FALSE(c.isValid());
}

// ============== Earth Task ==============
TEST(EarthTask, ReturnsPositiveGap) {
    double gap = CalculateEarthGap();
    EXPECT_GT(gap, 0.0);
}

TEST(EarthTask, GapValueCheck) {
    double gap = CalculateEarthGap();
    EXPECT_NEAR(gap, 0.159154943, 1e-7);
}

TEST(EarthTask, GapIsAbout16Centimeters) {
    double gap = CalculateEarthGap();
>>>>>>> b6db93efe28c710d4340d209f52c57582f464387
    EXPECT_GT(gap, 0.15);
    EXPECT_LT(gap, 0.17);
}

<<<<<<< HEAD
// --- Бассейн ---

TEST(PoolTest, FullCostAssignmentExample) {
    EXPECT_NEAR(poolMaterialsCost(3.0, 1.0, 1000.0, 2000.0), 72256.63, 0.1);
}

TEST(PoolTest, ConcreteOnly) {
    EXPECT_NEAR(poolMaterialsCost(3.0, 1.0, 1000.0, 0.0), 21991.14, 0.1);
}

TEST(PoolTest, FenceOnly) {
    EXPECT_NEAR(poolMaterialsCost(3.0, 1.0, 0.0, 2000.0), 50265.48, 0.1);
}

TEST(PoolTest, ZeroPathWidth) {
    EXPECT_NEAR(poolMaterialsCost(3.0, 0.0, 1000.0, 2000.0), 37699.11, 0.1);
}

TEST(PoolTest, LargerPoolAndPath) {
    EXPECT_NEAR(poolMaterialsCost(5.0, 2.0, 1000.0, 2000.0), 150796.44, 1.0);
=======
// ============== Pool Task ==============
TEST(PoolTask, TotalCostWithDefaultParams) {
    double cost = CalculatePoolCost(3.0, 1.0, 1000.0, 2000.0);
    EXPECT_NEAR(cost, 72256.63, 0.1);
}

TEST(PoolTask, OnlyConcreteCost) {
    double cost = CalculatePoolCost(3.0, 1.0, 1000.0, 0.0);
    EXPECT_NEAR(cost, 21991.14, 0.1);
}

TEST(PoolTask, OnlyFenceCost) {
    double cost = CalculatePoolCost(3.0, 1.0, 0.0, 2000.0);
    EXPECT_NEAR(cost, 50265.48, 0.1);
}

TEST(PoolTask, ZeroWidthPath) {
    double cost = CalculatePoolCost(3.0, 0.0, 1000.0, 2000.0);
    EXPECT_NEAR(cost, 37699.11, 0.1);
}

TEST(PoolTask, LargerPool) {
    double cost = CalculatePoolCost(5.0, 2.0, 1000.0, 2000.0);
    EXPECT_NEAR(cost, 150796.44, 1.0);
}

TEST(PoolTask, FreeConcrete) {
    double cost = CalculatePoolCost(3.0, 1.0, 0.0, 2000.0);
    EXPECT_NEAR(cost, 50265.48, 0.1);
}

TEST(PoolTask, FreeFence) {
    double cost = CalculatePoolCost(3.0, 1.0, 1000.0, 0.0);
    EXPECT_NEAR(cost, 21991.14, 0.1);
}

// ============== Additional tests ==============
TEST(EdgeCases, ExtremelyLargeRadius) {
    Circle c(1e10);
    EXPECT_GT(c.getArea(), 0);
}

TEST(EdgeCases, ExtremelySmallRadius) {
    Circle c(1e-10);
    EXPECT_NEAR(c.getCircumference(), 6.283185307e-10, 1e-20);
>>>>>>> b6db93efe28c710d4340d209f52c57582f464387
}
