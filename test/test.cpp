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
#include <memory>
#include "pid.hpp"
#include <math.h>

/**
 *  @brief  Get KP Gain Negative
 *
 *  Check if the individual x,y,z values are Greater than 0
 *  if
 *
 *  @param  none
 *  @return none
 */
TEST(getKpGainNeg, testgetKpGainNeg) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> kp = testObj.getKpGain();
  for (auto i : *kp) {
    ASSERT_GE(i, 0);
  }
  std::shared_ptr<std::vector<double>> testNeg = std::make_shared<
      std::vector<double>>(3, -1);
  ASSERT_FALSE(testObj.setKpGain(testNeg));

  ASSERT_EQ((*testObj.getKpGain())[0], (*kp)[0]);
  ASSERT_EQ((*testObj.getKpGain())[1], (*kp)[1]);
  ASSERT_EQ((*testObj.getKpGain())[2], (*kp)[2]);
}

TEST (getKpGainPos, testGetKpGainPos) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> kp = testObj.getKpGain();
  for (auto i : *kp) {
    ASSERT_GE(i, 0);
  }
  std::shared_ptr<std::vector<double>> testPos = std::make_shared<
      std::vector<double>>(3, 1);
  ASSERT_TRUE(testObj.setKpGain(testPos));

  ASSERT_EQ((*testObj.getKpGain())[0], (*testPos)[0]);
  ASSERT_EQ((*testObj.getKpGain())[1], (*testPos)[1]);
  ASSERT_EQ((*testObj.getKpGain())[2], (*testPos)[2]);
}

TEST(getKiGainNeg, testgetKiGainNeg) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> ki = testObj.getKiGain();
  for (auto i : *ki) {
    ASSERT_GE(i, 0);
  }
  std::shared_ptr<std::vector<double>> testNeg = std::make_shared<
      std::vector<double>>(3, -1);
  ASSERT_FALSE(testObj.setKiGain(testNeg));

  ASSERT_EQ((*testObj.getKiGain())[0], (*ki)[0]);
  ASSERT_EQ((*testObj.getKiGain())[1], (*ki)[1]);
  ASSERT_EQ((*testObj.getKiGain())[2], (*ki)[2]);
}
TEST (getKiGainPos, testGetKiGainPos) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> ki = testObj.getKiGain();
  for (auto i : *ki) {
    ASSERT_GE(i, 0);
  }
  std::shared_ptr<std::vector<double>> testPos = std::make_shared<
      std::vector<double>>(3, 1);
  ASSERT_TRUE(testObj.setKiGain(testPos));

  ASSERT_EQ((*testObj.getKiGain())[0], (*testPos)[0]);
  ASSERT_EQ((*testObj.getKiGain())[1], (*testPos)[1]);
  ASSERT_EQ((*testObj.getKiGain())[2], (*testPos)[2]);
}
TEST(getKdGainNeg, testgetKdGainNeg) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> kd = testObj.getKdGain();
  for (auto i : *kd) {
    ASSERT_GE(i, 0);
  }
  std::shared_ptr<std::vector<double>> testNeg = std::make_shared<
      std::vector<double>>(3, -1);
  ASSERT_FALSE(testObj.setKdGain(testNeg));

  ASSERT_EQ((*testObj.getKdGain())[0], (*kd)[0]);
  ASSERT_EQ((*testObj.getKdGain())[1], (*kd)[1]);
  ASSERT_EQ((*testObj.getKdGain())[2], (*kd)[2]);
}
TEST (getKdGainPos, testGetKdGainPos) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> kd = testObj.getKdGain();
  for (auto i : *kd) {
    ASSERT_GE(i, 0);
  }
  std::shared_ptr<std::vector<double>> testPos = std::make_shared<
      std::vector<double>>(3, 1);
  ASSERT_TRUE(testObj.setKdGain(testPos));

  ASSERT_EQ((*testObj.getKdGain())[0], (*testPos)[0]);
  ASSERT_EQ((*testObj.getKdGain())[1], (*testPos)[1]);
  ASSERT_EQ((*testObj.getKdGain())[2], (*testPos)[2]);
}

TEST(computeOutput, testComputeOutput) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> comOut = testObj.computeOutput();
  double sum = 0;
  for (auto i : *comOut) {
    sum += (i) * (i);
  }
  double newSum = sqrt(sum);
  EXPECT_LT(newSum, testObj.getMaxLimitVel());
}

TEST(actualVelocity, testActualVelocity) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> actVel = testObj.getActualVelocity();
  double sum = 0;
  for (auto i : *actVel) {
    sum += (i) * (i);
  }
  double newSum = sqrt(sum);
  EXPECT_LT(newSum, testObj.getMaxLimitVel());
}

TEST(targetSetPoint, testTargetSetPoint) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> tgtSetPoint =
      testObj.getTargetSetPoint();
  double sum = 0;
  for (auto i : *tgtSetPoint) {
    sum += (i) * (i);
  }
  double newSum = sqrt(sum);
  EXPECT_LT(newSum, testObj.getMaxLimitVel());
}

TEST(setActVelocity, testSetActVelocity) {
  PIDController testObj;
  std::shared_ptr<std::vector<double>> av =
      std::make_shared<std::vector<double>>(3, 1.1);
  double sum = 0;
  for (auto i : *av) {
    sum += (i) * (i);
  }
  double newSum = sqrt(sum);
  EXPECT_LT(newSum, testObj.getMaxLimitVel());
}

TEST(getActualVelNeg, testgetActualVelNeg) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> av = testObj.getActualVelocity();
  double sum = 0;
  for (auto i : *av) {
    sum += (i) * (i);
  }
  double newSum = sqrt(sum);
  ASSERT_LE(newSum, testObj.getMaxLimitVel());
  std::shared_ptr<std::vector<double>> testNeg = std::make_shared<
      std::vector<double>>(3, -5);
  ASSERT_FALSE(testObj.setActualVelocity(testNeg));

  ASSERT_EQ((*testObj.getActualVelocity())[0], (*av)[0]);
  ASSERT_EQ((*testObj.getActualVelocity())[1], (*av)[1]);
  ASSERT_EQ((*testObj.getActualVelocity())[2], (*av)[2]);
}

TEST(getActualVelPos, testgetActualVelPos) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> av = testObj.getActualVelocity();
  double sum = 0;
  for (auto i : *av) {
    sum += (i) * (i);
  }
  double newSum = sqrt(sum);
  ASSERT_LE(newSum, testObj.getMaxLimitVel());
  std::shared_ptr<std::vector<double>> testPos = std::make_shared<
      std::vector<double>>(3, 3);
  ASSERT_TRUE(testObj.setActualVelocity(testPos));

  ASSERT_EQ((*testObj.getActualVelocity())[0], (*testPos)[0]);
  ASSERT_EQ((*testObj.getActualVelocity())[1], (*testPos)[1]);
  ASSERT_EQ((*testObj.getActualVelocity())[2], (*testPos)[2]);
}

TEST(getTgtSetPointNeg, testGetTgtSetPointNeg) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> tpt = testObj.getTargetSetPoint();
  double sum = 0;
  for (auto i : *tpt) {
    sum += (i) * (i);
  }
  double newSum = sqrt(sum);
  ASSERT_LE(newSum, testObj.getMaxLimitVel());
  std::shared_ptr<std::vector<double>> testNeg = std::make_shared<
      std::vector<double>>(3, -5);
  ASSERT_FALSE(testObj.setTargetSetPoint(testNeg));

  ASSERT_EQ((*testObj.getTargetSetPoint())[0], (*tpt)[0]);
  ASSERT_EQ((*testObj.getTargetSetPoint())[1], (*tpt)[1]);
  ASSERT_EQ((*testObj.getTargetSetPoint())[2], (*tpt)[2]);
}

TEST(getTgtSetPointPos, testGetTgtSetPointPos) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> tpt = testObj.getTargetSetPoint();
  double sum = 0;
  for (auto i : *tpt) {
    sum += (i) * (i);
  }
  double newSum = sqrt(sum);
  ASSERT_LE(newSum, testObj.getMaxLimitVel());
  std::shared_ptr<std::vector<double>> testPos = std::make_shared<
      std::vector<double>>(3, 3);
  ASSERT_FALSE(testObj.setTargetSetPoint(testPos));

  ASSERT_EQ((*testObj.getTargetSetPoint())[0], (*testPos)[0]);
  ASSERT_EQ((*testObj.getTargetSetPoint())[1], (*testPos)[1]);
  ASSERT_EQ((*testObj.getTargetSetPoint())[2], (*testPos)[2]);
}

TEST(setMaxLimitVel, testSetMaxLimitVel) {
  PIDController testObj;
  double mx = 10;
  ASSERT_TRUE(testObj.setMaxLimitVel(mx));
  ASSERT_LT(testObj.getMaxLimitVel(), 0);
}

TEST(setTrgtStPoint, testSetTrgtStPoint) {
  PIDController testObj;
  std::shared_ptr<std::vector<double>> stpt = std::make_shared<
      std::vector<double>>(3, 1.1);
  ASSERT_TRUE(testObj.setTargetSetPoint(stpt));
}

