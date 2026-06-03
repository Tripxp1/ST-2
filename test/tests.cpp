// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>

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
    Circle c(10.0);
    c.setRadius(5.0);
    c.setRadius(2.5);
    c.setRadius(7.5);
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
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

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
    EXPECT_NEAR(c.getFerence(), 6.283185307e-10, 1e-19);
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
    EXPECT_GT(gap, 0.15);
    EXPECT_LT(gap, 0.17);
}

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
    EXPECT_NEAR(poolMaterialsCost(5.0, 2.0, 1000.0, 2000.0), 163362.82, 0.1);
}
