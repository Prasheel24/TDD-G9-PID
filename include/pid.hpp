///*
// *
// * Copyright 2019 Prasheel Renkuntla
// *
// * @file         pid.hpp
// * @author       Prasheel Renkuntla (Driver)
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
#ifndef INCLUDE_PIDCONTROLLER_HPP_
#define INCLUDE_PIDCONTROLLER_HPP_

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
  std::vector<double> Kp, Ki, Kd;

  /* Declaration of target set point */
  std::vector<double> targetSetPoint;

  /* Declaration of final velocity */
  std::vector<double> finalVelocity;

  /* Declaration of actual velocity */
  std::vector<double> actualVelocity;

  /* Declaration of error sum */
  double errorSum;

  /* Declaration of last velocity */
  double lastVelocity;

  /* Declaration of maximum limit of velocity */
  double maxLimitVel;

  /* Declaration of maximum limit of position vector*/
  std::vector<double> maxLimitPos;

 public:

  /**
   *  @brief  Default constructor for PIDController
   *
   *  @param  none
   *  @return none
   */
  PIDController();

  /**
   *  @brief  Default destructor for PIDController
   *
   *  @param  none
   *  @return none
   */
  ~PIDController();

  /**
   *  @brief  Change Kp,Ki, Kd Gains for the controller
   *
   *  @param  shared pointer vector double of Kp gain
   *  @param  shared pointer vector double of Ki gain
   *  @param  shared pointer vector double of Kd gain
   *  @return none
   */
  void changeGain(std::shared_ptr<std::vector<double>>,
                  std::shared_ptr<std::vector<double>>,
                  std::shared_ptr<std::vector<double>>);

  /**
   *  @brief  Compute the output for the controller
   *
   *  @param  shared pointer vector double of actual velocity
   *  @return vector double of the final velocity
   */
  std::vector<double> computeOutput(std::vector<double>);

  /**
   *  @brief  Change set point
   *
   *  @param  shared pointer vector double of set point
   *  @return vector double of the new set point
   */
  std::vector<double> changeSetPoint(std::shared_ptr<std::vector<double>>);

  /**
   *  @brief  Update the error sum
   *
   *  @param  double value of error sum
   *  @return double value of new error sum
   */
  double updateErrorSum(double);

  /**
   *  @brief  Get KpGain
   *
   *  @param  none
   *  @return vector double of the Kp gain
   */
  std::vector<double> getKpGain();

  /**
   *  @brief  Set KpGain
   *
   *  @param  shared pointer vector double of updated Kp gain
   *  @return none
   */
  void setKpGain(std::shared_ptr<std::vector<double>>);

  /**
   *  @brief  Get KiGain
   *
   *  @param  none
   *  @return vector double of the Ki gain
   */
  std::vector<double> getKiGain();

  /**
   *  @brief  Set KiGain
   *
   *  @param  shared pointer vector double of updated Ki gain
   *  @return none
   */
  void setKiGain(std::shared_ptr<std::vector<double>>);

  /**
   *  @brief  Get KdGain
   *
   *  @param  none
   *  @return vector double of the Kd gain
   */
  std::vector<double> getKdGain();

  /**
   *  @brief  Set KdGain
   *
   *  @param  shared pointer vector double of updated Kd gain
   *  @return none
   */
  void setKdGain(std::shared_ptr<std::vector<double>>);

  /**
   *  @brief  Get Actual Velocity
   *
   *  @param  none
   *  @return vector double of the actual velocity
   */
  std::vector<double> getActualVelocity();

  /**
   *  @brief  Set Actual Velocity
   *
   *  @param  shared pointer vector double of updated actual velocity
   *  @return vector none
   */
  void setActualVelocity(std::shared_ptr<std::vector<double>>);

  /**
   *  @brief  Get Maximum Limit for Velocity
   *
   *  @param  none
   *  @return vector double of the velocity limit
   */
  std::vector<double> getMaxLimitVel();

  /**
   *  @brief  Set Maximum limit for velocity
   *
   *  @param  shared pointer vector double of updated velocity limit
   *  @return none
   */
  void setMaxLimitVel(std::shared_ptr<std::vector<double>>);

  /**
   *  @brief  Get Maximum Limit for position
   *
   *  @param  none
   *  @return vector double of the position limit
   */
  std::vector<double> getMaxLimitPos();

  /**
   *  @brief  set Maximum Limit for Velocity
   *
   *  @param  shared pointer vector double of updated position limit
   *  @return none
   */
  void setMaxLimitPos(std::shared_ptr<std::vector<double>>);

  /**
   *  @brief  Get target set point
   *
   *  @param  none
   *  @return vector double of the target set point
   */
  std::vector<double> getTargetSetPoint();

  /**
   *  @brief  Set target set point
   *
   *  @param  shared pointer vector double of target set point
   *  @return none
   */
  void setTargetSetPoint(std::shared_ptr<std::vector<double>>);

  /**
   *  @brief  Reset system
   *
   *  @param  none
   *  @return string of success message
   */
  std::string resetSystem();
};

#endif
