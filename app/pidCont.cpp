///*
// * Copyright 2019 Prasheel Renkuntla
// *
// * @file         pidCont.cpp
// * @author       Prasheel Renkuntla (Driver)
// * @date         09/25/2019
// * @version      1.0
// *
// * @brief        Test Driven Development - Part 1
// *
// * @section      DESCRIPTION
// *
// * Class Implementation of PID Controller
// *
// */

#include <iostream>
#include "pid.hpp"

/**
 *  @brief  Default constructor for PIDController
 *
 *  @param  none
 *  @return none
 */
PIDController::PIDController() {
  Kp = { 0.1 };
  Ki = { 0.1 };
  Kd = { 0.1 };
  targetSetPoint = { 0 };
  finalVelocity = { 0 };
  actualVelocity = { 0 };
  errorSum = 0;
  lastVelocity = 0;
  maxLimitVel = 0;
  maxLimitPos = { 0 };
}

/**
 *  @brief  Default destructor for PIDController
 *
 *  @param  none
 *  @return none
 */
PIDController::~PIDController() {
}

/**
 *  @brief  Change Kp,Ki, Kd Gains for the controller
 *
 *  @param  shared pointer vector double of Kp gain
 *  @param  shared pointer vector double of Ki gain
 *  @param  shared pointer vector double of Kd gain
 *  @return none
 */
void PIDController::changeGain(std::shared_ptr<std::vector<double>> Kp,
                               std::shared_ptr<std::vector<double>> Ki,
                               std::shared_ptr<std::vector<double>> Kd) {

  std::shared_ptr<std::vector<double>> funcKp = Kp;
  std::shared_ptr<std::vector<double>> funcKi = Ki;
  std::shared_ptr<std::vector<double>> funcKd = Kd;
}

/**
 *  @brief  Compute the output for the controller
 *
 *  @param  shared pointer vector double of actual velocity
 *  @return vector double of the final velocity
 */
std::vector<double> PIDController::computeOutput(std::vector<double> actVel) {

  std::vector<double> newVel = actVel;
  return {0.123};
}

/**
 *  @brief  Change set point
 *
 *  @param  shared pointer vector double of set point
 *  @return vector double of the new set point
 */
std::vector<double> PIDController::changeSetPoint(
    std::shared_ptr<std::vector<double>> stpt) {
  std::shared_ptr<std::vector<double>> targetSetPoint = stpt;
  return {0.001};
}

/**
 *  @brief  Update the error sum
 *
 *  @param  double value of error sum
 *  @return double value of new error sum
 */
double PIDController::updateErrorSum(double errsum) {
  double errorSum = errsum;
  errorSum = 1;
  return errorSum;
}

/**
 *  @brief  Set KpGain
 *
 *  @param  shared pointer vector double of updated Kp gain
 *  @return none
 */
void PIDController::setKpGain(std::shared_ptr<std::vector<double>>) {
}
/**
 *  @brief  Get KpGain
 *
 *  @param  none
 *  @return vector double of the Kp gain
 */
std::vector<double> PIDController::getKpGain() {
  return {-0.001};
}

/**
 *  @brief  Set KiGain
 *
 *  @param  shared pointer vector double of updated Ki gain
 *  @return none
 */
void PIDController::setKiGain(std::shared_ptr<std::vector<double>>) {
}

/**
 *  @brief  Get KiGain
 *
 *  @param  none
 *  @return vector double of the Ki gain
 */
std::vector<double> PIDController::getKiGain() {
  return {0.001};
}

/**
 *  @brief  Set KdGain
 *
 *  @param  shared pointer vector double of updated Kd gain
 *  @return none
 */
void PIDController::setKdGain(std::shared_ptr<std::vector<double>>) {
}

/**
 *  @brief  Get KdGain
 *
 *  @param  none
 *  @return vector double of the Kd gain
 */
std::vector<double> PIDController::getKdGain() {
  return {0.001};
}

/**
 *  @brief  Set Actual Velocity
 *
 *  @param  shared pointer vector double of updated actual velocity
 *  @return vector none
 */
void PIDController::setActualVelocity(std::shared_ptr<std::vector<double>>) {
}

/**
 *  @brief  Get Actual Velocity
 *
 *  @param  none
 *  @return vector double of the actual velocity
 */
std::vector<double> PIDController::getActualVelocity() {
  return {1.10};
}

/**
 *  @brief  Set Maximum limit for velocity
 *
 *  @param  shared pointer vector double of updated velocity limit
 *  @return none
 */
void PIDController::setMaxLimitVel(std::shared_ptr<std::vector<double>>) {
}

/**
 *  @brief  Get Maximum Limit for Velocity
 *
 *  @param  none
 *  @return vector double of the velocity limit
 */
std::vector<double> PIDController::getMaxLimitVel() {
  return {0.01};
}

/**
 *  @brief  set Maximum Limit for Velocity
 *
 *  @param  shared pointer vector double of updated position limit
 *  @return none
 */
void PIDController::setMaxLimitPos(std::shared_ptr<std::vector<double>>) {
}

/**
 *  @brief  Get Maximum Limit for position
 *
 *  @param  none
 *  @return vector double of the position limit
 */
std::vector<double> PIDController::getMaxLimitPos() {
  return {0.01, 0.1};
}

/**
 *  @brief  Set target set point
 *
 *  @param  shared pointer vector double of target set point
 *  @return none
 */
void PIDController::setTargetSetPoint(std::shared_ptr<std::vector<double>>) {
}

/**
 *  @brief  Get target set point
 *
 *  @param  none
 *  @return vector double of the target set point
 */
std::vector<double> PIDController::getTargetSetPoint() {
  return {0.1, 0.1};
}

/**
 *  @brief  Reset system
 *
 *  @param  none
 *  @return string of success message
 */
std::string PIDController::resetSystem() {
  return "Reset System not working";
}

