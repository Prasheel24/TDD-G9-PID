///*
// * Copyright 2019 Prasheel Renkuntla
// *
// * @file         pidCont.cpp
// * @author       Prasheel Renkuntla (Driver - Part 1)
// *               Suyash Yeotikar    (Navigator - Part 1)
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
 *  @brief  Compute the output for the controller
 *
 *  @param  shared pointer vector
 *  double of actual velocity
 *  @return vector double of the final velocity
 */
std::shared_ptr<std::vector<double>> PIDController::computeOutput() {
}

/**
 *  @brief  Change set point
 *
 *  @param  shared pointer vector double of set point
 *  @return vector double of the new set point
 */
std::shared_ptr<std::vector<double>> changeSetPoint(
    std::shared_ptr<std::vector<double>> actSetPoint) {
}

/**
 *  @brief  Update the error sum
 *
 *  @param  double value of error sum
 *  @return double value of new error sum
 */
double PIDController::updateErrorSum() {
}

/**
 *  @brief  Set KpGain
 *
 *  @param  shared pointer vector double of updated Kp gain
 *  @return none
 */
bool PIDController::setKpGain(std::shared_ptr<std::vector<double>> kp) {
  return false;
}
/**
 *  @brief  Get KpGain
 *
 *  @param  none
 *  @return vector double of the Kp gain
 */
std::shared_ptr<std::vector<double>> PIDController::getKpGain() {
}

/**
 *  @brief  Set KiGain
 *
 *  @param  shared pointer vector double of updated Ki gain
 *  @return none
 */
bool PIDController::setKiGain(std::shared_ptr<std::vector<double>> ki) {
  return false;
}

/**
 *  @brief  Get KiGain
 *
 *  @param  none
 *  @return vector double of the Ki gain
 */
std::shared_ptr<std::vector<double>> PIDController::getKiGain() {
}

/**
 *  @brief  Set KdGain
 *
 *  @param  shared pointer vector double of updated Kd gain
 *  @return none
 */
bool PIDController::setKdGain(std::shared_ptr<std::vector<double>> kd) {
  return false;
}

/**
 *  @brief  Get KdGain
 *
 *  @param  none
 *  @return vector double of the Kd gain
 */
std::shared_ptr<std::vector<double>> PIDController::getKdGain() {
}

/**
 *  @brief  Set Actual Velocity
 *
 *  @param  shared pointer vector double of updated actual velocity
 *  @return vector none
 */
bool PIDController::setActualVelocity(
    std::shared_ptr<std::vector<double>> actVel) {
  return false;
}

/**
 *  @brief  Get Actual Velocity
 *
 *  @param  none
 *  @return vector double of the actual velocity
 */
std::shared_ptr<std::vector<double>> PIDController::getActualVelocity() {
}

/**
 *  @brief  Set Maximum limit for velocity
 *
 *  @param  shared pointer vector double of updated velocity limit
 *  @return none
 */
bool PIDController::setMaxLimitVel(double maxLimVel) {
  return false;
}

/**
 *  @brief  Get Maximum Limit for Velocity
 *
 *  @param  none
 *  @return vector double of the velocity limit
 */
double PIDController::getMaxLimitVel() {
}

/**
 *  @brief  Set target set point
 *
 *  @param  shared pointer vector double of target set point
 *  @return none
 */
bool PIDController::setTargetSetPoint(std::shared_ptr<std::vector<double>>) {
  return false;
}

/**
 *  @brief  Get target set point
 *
 *  @param  none
 *  @return vector double of the target set point
 */
std::shared_ptr<std::vector<double>> PIDController::getTargetSetPoint() {
}

