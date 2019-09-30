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
#include <algorithm>
#include <cmath>
#include "pid.hpp"

/**
 *  @brief  Compute the output for the controller
 *  Link (for vector multiplication)-
 *  https://stackoverflow.com/questions/13728430/element-wise-multiplication-of-two-vectors-in-c
 *
 *  @param  none
 *  @return shared pointer vector double of the final velocity
 */
std::shared_ptr<std::vector<double>> PIDController::ComputeOutput() {
  /* Calculate Current Error */
  std::vector<double> errorCurr;
  std::transform(targetSetPoint.begin(), targetSetPoint.end(),
    actualVelocity.begin(), std::back_inserter(errorCurr),
    std::minus<double>());

  /* Update Error Sum */
  std::shared_ptr<std::vector<double>> errSumPtr;
  errSumPtr = UpdateErrorSum();

  /* Calculate Error Differential */
  std::vector<double> errorDiff;
  std::transform(errorCurr.begin(), errorCurr.end(),
    targetSetPoint.begin(), std::back_inserter(errorDiff),
    std::minus<double>());

  std::transform(errorDiff.begin(), errorDiff.end(),
    lastVelocity.begin(), errorDiff.begin(),
    std::plus<double>());

  /* Update Last Velocity */
  std::shared_ptr<std::vector<double>> lastVelPtr;
  lastVelPtr = UpdateLastVel();

  /* Calculate proportional, integral and differential terms */
  std::vector<double> Pterm;
  std::transform(Kp.begin(), Kp.end(),
    errorCurr.begin(), std::back_inserter(Pterm),
    std::multiplies<double>());

  std::vector<double> Iterm;
  std::transform(Ki.begin(), Ki.end(),
    errorSum.begin(), std::back_inserter(Iterm),
    std::multiplies<double>());

  std::vector<double> Dterm;
  std::transform(Kd.begin(), Kd.end(),
    errorDiff.begin(), std::back_inserter(Dterm),
    std::multiplies<double>());

  /* Calculate final velocity */
  std::transform(Pterm.begin(), Pterm.end(),
    Iterm.begin(), finalVelocity.begin(),
    std::plus<double>());

  std::transform(finalVelocity.begin(), finalVelocity.end(),
    Dterm.begin(), finalVelocity.begin(),
    std::plus<double>());

  std::transform(finalVelocity.begin(), finalVelocity.end(),
    actualVelocity.begin(), finalVelocity.begin(),
    std::plus<double>());

  return std::make_shared<std::vector<double>>(finalVelocity);
}

/**
 *  @brief  Update the last velocity
 *
 *  @param  none
 *  @return double value of new last Velocity
 */
std::shared_ptr<std::vector<double>> PIDController::UpdateLastVel() {
  lastVelocity = actualVelocity;
  return std::make_shared<std::vector<double>>(lastVelocity);
}
/*
 *  @brief  Update the error sum
 *
 *  @param  none
 *  @return shared pointer vector double value of new error sum
 */
std::shared_ptr<std::vector<double>> PIDController::UpdateErrorSum() {
  std::vector<double> errorCurr;
  std::transform(targetSetPoint.begin(), targetSetPoint.end(),
    actualVelocity.begin(), std::back_inserter(errorCurr),
    std::minus<double>());
  std::transform(errorSum.begin(), errorSum.end(),
    errorCurr.begin(), errorSum.begin(),
    std::plus<double>());
  return std::make_shared<std::vector<double>>(errorSum);
}

/**
 *  @brief  Set KpGain
 *
 *  @param  shared pointer vector double of updated Kp gain
 *  @return bool
 */
bool PIDController::SetKpGain(std::shared_ptr<std::vector<double>> kp) {
  bool flag = true;
  for (auto gain : *kp) {
    if (gain < 0.0) {
      flag = false;
    }
  }
  if (flag == true) {
    Kp = *kp;
  }
  return flag;
}
/**
 *  @brief  Get KpGain
 *
 *  @param  none
 *  @return shared pointer vector double of the Kp gain
 */
std::shared_ptr<std::vector<double>> PIDController::GetKpGain() {
  return std::make_shared<std::vector<double>>(Kp);
}

/**
 *  @brief  Set KiGain
 *
 *  @param  shared pointer vector double of updated Ki gain
 *  @return bool
 */
bool PIDController::SetKiGain(std::shared_ptr<std::vector<double>> ki) {
  bool flag = true;
  for (auto gain : *ki) {
    if (gain < 0.0) {
      flag = false;
    }
  }
  if (flag == true) {
    Ki = *ki;
  }
  return flag;
}

/**
 *  @brief  Get KiGain
 *
 *  @param  none
 *  @return shared pointer vector double of the Ki gain
 */
std::shared_ptr<std::vector<double>> PIDController::GetKiGain() {
  return std::make_shared<std::vector<double>>(Ki);
}

/**
 *  @brief  Set KdGain
 *
 *  @param  shared pointer vector double of updated Kd gain
 *  @return bool
 */
bool PIDController::SetKdGain(std::shared_ptr<std::vector<double>> kd) {
  bool flag = true;
  for (auto gain : *kd) {
    if (gain < 0.0) {
      flag = false;
    }
  }
  if (flag == true) {
    Kd = *kd;
  }
  return flag;
}

/**
 *  @brief  Get KdGain
 *
 *  @param  none
 *  @return shared pointer vector double of the Kd gain
 */
std::shared_ptr<std::vector<double>> PIDController::GetKdGain() {
  return std::make_shared<std::vector<double>>(Kd);
}

/**
 *  @brief  Set Actual Velocity
 *
 *  @param  shared pointer vector double of updated actual velocity
 *  @return bool
 */
bool PIDController::SetActualVelocity(
    std::shared_ptr<std::vector<double>> actVel) {
  double sumOfSquare = 0;
  for (auto vel : *actVel) {
    sumOfSquare += std::pow(vel, 2);
  }
  double velMag = std::pow(sumOfSquare, 0.5);
  if (velMag <= maxLimitVel) {
    actualVelocity = *actVel;
    return true;
  } else {
    return false;
  }
}

/**
 *  @brief  Get Actual Velocity
 *
 *  @param  none
 *  @return shared pointer vector double of the actual velocity
 */
std::shared_ptr<std::vector<double>> PIDController::GetActualVelocity() {
  return std::make_shared<std::vector<double>>(actualVelocity);
}

/**
 *  @brief  Set Maximum limit for velocity
 *
 *  @param  double of updated velocity limit
 *  @return bool
 */
bool PIDController::SetMaxLimitVel(double maxLimVel) {
  maxLimitVel = maxLimVel;
  return true;
}

/**
 *  @brief  Get Maximum Limit for Velocity
 *
 *  @param  none
 *  @return double of max limit Vel
 */
double PIDController::GetMaxLimitVel() {
  return maxLimitVel;
}

/**
 *  @brief  Set target set point
 *
 *  @param  shared pointer vector double of target set point
 *  @return bool
 */
bool PIDController::SetTargetSetPoint(
  std::shared_ptr<std::vector<double>> setPointPtr) {
  double sumOfSquare = 0;
  /* Calculate sum of velocity squares */
  for (auto vel : *setPointPtr) {
    sumOfSquare += std::pow(vel, 2);
  }
  double velMag = std::pow(sumOfSquare, 0.5);
  if (velMag <= maxLimitVel) {
    targetSetPoint = *setPointPtr;
    return true;
  } else {
    return false;
  }
}

/**
 *  @brief  Get target set point
 *
 *  @param  none
 *  @return shared pointer vector double of the target set point
 */
std::shared_ptr<std::vector<double>> PIDController::GetTargetSetPoint() {
  return std::make_shared<std::vector<double>>(targetSetPoint);
}

