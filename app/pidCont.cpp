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
 *  Link (for vector multiplication)-
 *  https://stackoverflow.com/questions/13728430/element-wise-multiplication-of-two-vectors-in-c
 *
 *  @param  none
 *  @return shared pointer vector double of the final velocity
 */
std::shared_ptr<std::vector<double>> PIDController::computeOutput() {
}

/**
 *  @brief  Update the last velocity
 *
 *  @param  none
 *  @return double value of new last Velocity
 */
std::shared_ptr<std::vector<double>> updateLastVel() {
}
/**
 *  @brief  Update the error sum
 *
 *  @param  none
 *  @return shared pointer vector double value of new error sum
 */
std::shared_ptr<std::vector<double>> PIDController::updateErrorSum() {
}

/**
 *  @brief  Set KpGain
 *
 *  @param  shared pointer vector double of updated Kp gain
 *  @return bool
 */
bool PIDController::setKpGain(std::shared_ptr<std::vector<double>> kp) {
  return false;
}
/**
 *  @brief  Get KpGain
 *
 *  @param  none
 *  @return shared pointer vector double of the Kp gain
 */
std::shared_ptr<std::vector<double>> PIDController::getKpGain() {
}

/**
 *  @brief  Set KiGain
 *
 *  @param  shared pointer vector double of updated Ki gain
 *  @return bool
 */
bool PIDController::setKiGain(std::shared_ptr<std::vector<double>> ki) {
  return false;
}

/**
 *  @brief  Get KiGain
 *
 *  @param  none
 *  @return shared pointer vector double of the Ki gain
 */
std::shared_ptr<std::vector<double>> PIDController::getKiGain() {
}

/**
 *  @brief  Set KdGain
 *
 *  @param  shared pointer vector double of updated Kd gain
 *  @return bool
 */
bool PIDController::setKdGain(std::shared_ptr<std::vector<double>> kd) {
  return false;
}

/**
 *  @brief  Get KdGain
 *
 *  @param  none
 *  @return shared pointer vector double of the Kd gain
 */
std::shared_ptr<std::vector<double>> PIDController::getKdGain() {
}

/**
 *  @brief  Set Actual Velocity
 *
 *  @param  shared pointer vector double of updated actual velocity
 *  @return bool
 */
bool PIDController::setActualVelocity(
    std::shared_ptr<std::vector<double>> actVel) {
  return false;
}

/**
 *  @brief  Get Actual Velocity
 *
 *  @param  none
 *  @return shared pointer vector double of the actual velocity
 */
std::shared_ptr<std::vector<double>> PIDController::getActualVelocity() {
}

/**
 *  @brief  Set Maximum limit for velocity
 *
 *  @param  double of updated velocity limit
 *  @return bool
 */
bool PIDController::setMaxLimitVel(double maxLimVel) {
  return false;
}

/**
 *  @brief  Get Maximum Limit for Velocity
 *
 *  @param  none
 *  @return double of max limit Vel
 */
double PIDController::getMaxLimitVel() {
}

/**
 *  @brief  Set target set point
 *
 *  @param  shared pointer vector double of target set point
 *  @return bool
 */
bool PIDController::setTargetSetPoint(std::shared_ptr<std::vector<double>>) {
  return false;
}

/**
 *  @brief  Get target set point
 *
 *  @param  none
 *  @return shared pointer vector double of the target set point
 */
std::shared_ptr<std::vector<double>> PIDController::getTargetSetPoint() {
}

