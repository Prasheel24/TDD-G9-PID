
///*
// *
// * Copyright 2019 Prasheel Renkuntla
// *
// * @file         pid.hpp
// * @author       Prasheel Renkuntla (Driver - Part 1)
// *               Suyash Yeotikar    (Navigator - Part 1)
// * @date         09/25/2019
// * @version      1.0
// *
// * @brief        Test Driven Development - Part 1
// *
// * @section      DESCRIPTION
// *
// * PID Controller class declaration
// *
// */
#ifndef INCLUDE_PID_HPP_
#define INCLUDE_PID_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include <string>

///**
// * @brief PID Controller Class
// *
// * Class used to implement PID Controller
// *
// */
class PIDController {
 private:
  /* Declaration of different PID gain factors  */
  std::vector<double> Kp = std::vector<double>(3, 0.0);

  std::vector<double> Ki = std::vector<double>(3, 0.0);

  std::vector<double> Kd = std::vector<double>(3, 0.0);

  /* Declaration of target set point(velocity) */
  std::vector<double> targetSetPoint = std::vector<double>(3, 0.0);

  /* Declaration of final velocity(computed) */
  std::vector<double> finalVelocity = std::vector<double>(3, 0.0);

  /* Declaration of actual velocity */
  std::vector<double> actualVelocity = std::vector<double>(3, 0.0);

  /* Declaration of error sum */
  std::vector<double> errorSum = std::vector<double>(3, 0.0);

  /* Declaration of last velocity */
  std::vector<double> lastVelocity = std::vector<double>(3, 0.0);

  /* Declaration of maximum limit of velocity */
  double maxLimitVel = 10;

 public:
  /**
   *  @brief  Compute the output for the controller
   *  @param  none
   *  @return vector double of the finalVelocity
   */
  std::shared_ptr<std::vector<double>> computeOutput();

  /**
   *  @brief  Update the error sum
   *  Compute errorSum += targetSetPoint - actualVelocity
   *
   *  @param  none
   *  @return double value of new error sum
   */
  std::shared_ptr<std::vector<double>> updateErrorSum();

  /**
   *  @brief  Update the last velocity
   *
   *  @param  none
   *  @return double value of new last Velocity
   */
  std::shared_ptr<std::vector<double>> updateLastVel();

  /**
   *  @brief  Set KpGain
   *
   *  @param  shared pointer vector double of updated Kpx, Kpy, Kpz gain
   *  @return bool
   */
  bool setKpGain(std::shared_ptr<std::vector<double>> kp);

  /**
   *  @brief  Get KpGain
   *  Kpx, Kpy, Kpz as the elements
   *
   *  @param  none
   *  @return shared pointer vector double of the Kp gain
   */
  std::shared_ptr<std::vector<double>> getKpGain();

  /**
   *  @brief  Set KiGain
   *
   *  @param  shared pointer vector double of updated Kix, Kiy, Kiz gain
   *  @return bool
   */
  bool setKiGain(std::shared_ptr<std::vector<double>> ki);

  /**
   *  @brief  Get KiGain
   *  Kix, Kiy, Kiz as the elements
   *
   *  @param  none
   *  @return shared pointer vector double of the Ki gain
   */
  std::shared_ptr<std::vector<double>> getKiGain();

  /**
   *  @brief  Set KdGain
   *
   *  @param  shared pointer vector double of updated Kdx, Kdy, Kdz gain
   *  @return bool
   */
  bool setKdGain(std::shared_ptr<std::vector<double>> kd);

  /**
   *  @brief  Get KdGain
   *  Kdx, Kdy, Kdz as the elements
   *
   *  @param  none
   *  @return shared pointer vector double of the Kd gain
   */
  std::shared_ptr<std::vector<double>> getKdGain();

  /**
   *  @brief  Set Actual Velocity
   *
   *  @param  shared pointer vector double of updated Ux, Uy, Uz
   *  @return bool
   */
  bool setActualVelocity(std::shared_ptr<std::vector<double>> actVel);

  /**
   *  @brief  Get Actual Velocity
   *  Ux, Uy, Uz as the elements
   *  @param  none
   *  @return shared pointer vector double of the actual velocity
   */
  std::shared_ptr<std::vector<double>> getActualVelocity();

  /**
   *  @brief  Set Maximum limit for velocity
   *
   *  @param  double of updated velocity limit
   *  @return bool
   */
  bool setMaxLimitVel(double maxLimVel);

  /**
   *  @brief  Get Maximum Limit for Velocity
   *
   *  @param  none
   *  @return double
   */
  double getMaxLimitVel();

  /**
   *  @brief  Set target set point
   *
   *  @param  shared pointer shared pointer vector double of target set point
   *  @return bool
   */
  bool setTargetSetPoint(std::shared_ptr<std::vector<double>>);

  /**
   *  @brief  Get target set point
   *
   *  @param  none
   *  @return shared pointer vector double of the target set point
   */
  std::shared_ptr<std::vector<double>> getTargetSetPoint();
};


#endif  // INCLUDE_PID_HPP_
