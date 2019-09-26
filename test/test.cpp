///*
// *
// * Copyright 2019 Prasheel Renkuntla
// *
// * @file         test.cpp
// * @author       Prasheel Renkuntla (Driver)
// * @date         09/25/2019
// * @version      1.0
// *
// * @brief        Test Driven Development - Part 1
// *
// * @section      DESCRIPTION
// *
// * Test the functionality of the PID Controller
// *
// */
#include <gtest/gtest.h>
#include "pid.hpp"

PIDController testObj;

TEST(getKpGain, testgetKpGain) {
  std::vector<double> t1 = { 0 };
  std::vector<double> tKGain = testObj.getKpGain();
  EXPECT_LT(t1, tKGain);
}

TEST(computeOutput, testComputeOutput) {
  std::vector<double> tAVel = testObj.getActualVelocity();
  std::vector<double> t2 = { 0.1 };
  EXPECT_EQ(t2, tAVel);
}

