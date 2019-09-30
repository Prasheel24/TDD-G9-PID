///*
// *
// * Copyright 2019 Prasheel Renkuntla
// *
// * @file         test.cpp
// * @author       Prasheel Renkuntla (Driver - Part 1)
// *               Suyash Yeotikar    (Navigator - Part 1)
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
 *  Check -- the individual x,y,z values are Greater than 0
 *  take a negative vector
 *  Check -- It should not be able to set negative vector
 *  Check -- If negative, then it should contain last value
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

/**
 *  @brief  Get KP Gain Positive
 *
 *  Check -- the individual x,y,z values are Greater than 0
 *  take a positive vector
 *  Check -- It should be able to set positive vector
 *  Check -- If positive, then it should contain new value
 *
 *  @param  none
 *  @return none
 */
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

/**
 *  @brief  Get Ki Gain Negative
 *
 *  Check -- the individual x,y,z values are Greater than 0
 *  take a negative vector
 *  Check -- It should not be able to set negative vector
 *  Check -- If negative, then it should contain last value
 *
 *  @param  none
 *  @return none
 */
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

/**
 *  @brief  Get Ki Gain Positive
 *
 *  Check -- the individual x,y,z values are Greater than 0
 *  take a positive vector
 *  Check -- It should be able to set positive vector
 *  Check -- If positive, then it should contain new value
 *
 *  @param  none
 *  @return none
 */
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

/**
 *  @brief  Get Kd Gain Negative
 *
 *  Check -- the individual x,y,z values are Greater than 0
 *  take a negative vector
 *  Check -- It should not be able to set negative vector
 *  Check -- If negative, then it should contain last value
 *
 *  @param  none
 *  @return none
 */
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

/**
 *  @brief  Get Ki Gain Positive
 *
 *  Check -- the individual x,y,z values are Greater than 0
 *  take a positive vector
 *  Check -- It should be able to set positive vector
 *  Check -- If positive, then it should contain new value
 *
 *  @param  none
 *  @return none
 */
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

/**
 *  @brief  Compute output velocity magnitude
 *
 *  Check -- if output velocity magnitude is less than max limit
 *
 *  @param  none
 *  @return none
 */
TEST(computeOutput, testComputeOutput) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> comOut = testObj.computeOutput();
  double sum = 0;
  for (auto i : *comOut) {
    sum += (i) * (i);
  }
  double newSum = sqrt(sum);
  ASSERT_LE(newSum, testObj.getMaxLimitVel());
}

/**
 *  @brief  Compute actual velocity magnitude
 *
 *  Check -- if actual velocity magnitude is less than max limit
 *
 *  @param  none
 *  @return none
 */
TEST(actualVelocity, testActualVelocity) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> actVel = testObj.getActualVelocity();
  double sum = 0;
  for (auto i : *actVel) {
    sum += (i) * (i);
  }
  double newSum = sqrt(sum);
  ASSERT_LE(newSum, testObj.getMaxLimitVel());
}

/**
 *  @brief  Compute target set point velocity magnitude
 *
 *  Check -- if target set point velocity magnitude is less than max limit
 *
 *  @param  none
 *  @return none
 */
TEST(targetSetPoint, testTargetSetPoint) {
  PIDController testObj = PIDController();
  std::shared_ptr<std::vector<double>> tgtSetPoint =
      testObj.getTargetSetPoint();
  double sum = 0;
  for (auto i : *tgtSetPoint) {
    sum += (i) * (i);
  }
  double newSum = sqrt(sum);
  ASSERT_LE(newSum, testObj.getMaxLimitVel());
}

/**
 *  @brief  Set Actual Velocity
 *
 *  Check -- if new velocity magnitude is less than max limit
 *
 *  @param  none
 *  @return none
 */
TEST(setActVelocity, testSetActVelocity) {
  PIDController testObj;
  std::shared_ptr<std::vector<double>> av =
      std::make_shared<std::vector<double>>(3, 1.1);
  double sum = 0;
  for (auto i : *av) {
    sum += (i) * (i);
  }
  double newSum = sqrt(sum);
  ASSERT_LE(newSum, testObj.getMaxLimitVel());
}

/**
 *  @brief  Get Actual Velocity Vector
 *
 *  Check -- magnitude of current vector is less than Max Limit
 *  take a positive vector
 *  Check -- it should be able to assign a positive vector
 *  Check -- if positive, it should contain the new value
 *
 *  @param  none
 *  @return none
 */
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

/**
 *  @brief  Get Actual Velocity Positive Vector
 *
 *  Check -- magnitude of current vector is less than Max Limit
 *  take a positive vector
 *  Check -- it should be able to assign a positive vector
 *  Check -- if positive, it should contain the new value
 *
 *  @param  none
 *  @return none
 */
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

/**
 *  @brief  Set Max Limit Range
 *
 *  Check -- set the max limit value
 *  Check -- if max limit is Greater than 0
 *
 *  @param  none
 *  @return none
 */
TEST(setMaxLimitVel, testSetMaxLimitVel) {
  PIDController testObj;
  double mx = 10;
  ASSERT_TRUE(testObj.setMaxLimitVel(mx));
  ASSERT_EQ(testObj.getMaxLimitVel(), 10);
}

/**
 *  @brief  Compute Output for one iteration
 *
 *  take Kp, Ki, Kd, Actual Velocity, Target Set point
 *  Check -- set the corresponding values
 *  Check -- the output velocity from PID
 *
 *  @param  none
 *  @return none
 */
TEST(computePIDIteration,testcomputePIDIteration) {
  PIDController testObj;
  std::shared_ptr<std::vector<double>> testKp = std::make_shared<
      std::vector<double>>(3, 0.1);
  std::shared_ptr<std::vector<double>> testKi = std::make_shared<
      std::vector<double>>(3, 0.1);
  std::shared_ptr<std::vector<double>> testKd = std::make_shared<
      std::vector<double>>(3, 0.1);
  std::shared_ptr<std::vector<double>> testVel = std::make_shared<
      std::vector<double>>(3, 0.5);
  std::shared_ptr<std::vector<double>> testTPT = std::make_shared<
      std::vector<double>>(3, 1);

  ASSERT_TRUE(testObj.setKpGain(testKp));
  ASSERT_TRUE(testObj.setKiGain(testKi));
  ASSERT_TRUE(testObj.setKdGain(testKd));
  ASSERT_TRUE(testObj.setActualVelocity(testVel));
  ASSERT_TRUE(testObj.setTargetSetPoint(testTPT));

  std::shared_ptr<std::vector<double>> outVel;

  outVel = testObj.computeOutput();
  ASSERT_EQ(0.55, (*outVel)[0]);
  ASSERT_EQ(0.55, (*outVel)[1]);
  ASSERT_EQ(0.55, (*outVel)[2]);
}

