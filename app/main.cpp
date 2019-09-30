///*
// * Copyright 2019 Prasheel Renkuntla
// *
// * @file         main.cpp
// * @author       Prasheel Renkuntla (Driver - Part 1)
// *               Suyash Yeotikar    (Navigator - Part 1)
// *               Rohan Singh        (Driver - Part 2)
// *               Kamakshi Jain      (Navigatior - Part 2)
// * @date         09/25/2019
// * @version      1.0
// *
// * @brief        Test Driven Development - Part 1
// *
// * @section      DESCRIPTION
// *
// * Implementation of PID Controller for Acme Robotics
// *
// */
#include <iostream>
#include "pid.hpp"

int main() {
  std::vector<double> kp {1, 2, 3};
  std::vector<double> ki {0.5, 1, 0.5};
  std::vector<double> kd {0.1, 0.2, 0.3};
  PIDController PID;

  if (PID.SetKpGain(std::make_shared<std::vector<double>>(kp))) {
    std::cout << "Initial Kp Set" << std::endl;
  }
  if (PID.SetKiGain(std::make_shared<std::vector<double>>(ki))) {
  std::cout << "Initial Ki Set" << std::endl;
  }
  if (PID.SetKdGain(std::make_shared<std::vector<double>>(kd))) {
  std::cout << "Initial Kd Set" << std::endl;
  }

  double temp;
  bool flag1 = true;

  while (flag1) {
    std::cout << std::endl << "The Kp Gains along x, y and z are : ";
    for (auto g : kp) {
      std::cout << g << " ";
    }
    std::cout << std::endl << "The Ki Gains along x, y and z are : ";
    for (auto g : ki) {
      std::cout << g << " ";
    }
    std::cout << std::endl << "The Kd Gains along x, y and z are : ";
    for (auto g : kd) {
      std::cout << g << " ";
    }

    /* Keep Taking Setpoint Velocity till given in correct format */
    bool stpFlag = true;
    while (stpFlag) {
      std::vector<double> setPointVel;
      std::cout << std::endl
                << "Enter setpoint velocities (space seperated) : ";
      /* Take input */
      while (std::cin >> temp) {
        setPointVel.push_back(temp);
      }
      std::cin.clear();
      /* Check if in correct format */
      if (PID.SetTargetSetPoint(
          std::make_shared<std::vector<double>>(setPointVel))) {
        stpFlag = false;
      } else {
        std::cout << std::endl << "Incorrect arguments";
      }
    }

    /* Keep Taking Actual Velocity till given in correct format */
    bool actFlag = true;
    while (actFlag) {
      std::vector<double> actVel;
      std::cout << std::endl
                << "Enter actual velocities (space seperated) : ";
      /* Take input */
      while (std::cin >> temp) {
        actVel.push_back(temp);
      }
      std::cin.clear();
      /* Check if in correct format */
      if (PID.SetActualVelocity(
          std::make_shared<std::vector<double>>(actVel))) {
        actFlag = false;
      } else {
        std::cout << std::endl << "Incorrect arguments";
      }
    }

    std::cout << std::endl << "The output velocities are : ";
    std::shared_ptr<std::vector<double>> comOut = PID.ComputeOutput();
    for (auto vel : *comOut) {
      std::cout << std::endl << vel;
    }
    std::string ans;
    std::cout << std::endl
              << "Update gains and continue (y/n) : ";
    std::cin >> ans;
    if (ans == "y") {
      /* Keep Taking Kp gain till given in correct format */
      bool kpFlag = true;
      while (kpFlag) {
        std::vector<double> kp;
        std::cout << std::endl
                  << "Enter Kp Gains (space seperated)";
        /* Take input */
        while (std::cin >> temp) {
          kp.push_back(temp);
        }
        std::cin.clear();
        /* Check if in correct format */
        if (PID.SetKpGain(
            std::make_shared<std::vector<double>>(kp))) {
          kpFlag = false;
        } else {
          std::cout << std::endl << "Incorrect arguments";
        }
      }

      /* Keep Taking Ki till given in correct format */
      bool kiFlag = true;
      while (kiFlag) {
        std::vector<double> ki;
        std::cout << std::endl
                  << "Enter Ki Gains (space seperated)";
        /* Take input */
        while (std::cin >> temp) {
          ki.push_back(temp);
        }
        std::cin.clear();
        /* Check if in correct format */
        if (PID.SetKiGain(
            std::make_shared<std::vector<double>>(ki))) {
          kiFlag = false;
        } else {
          std::cout << std::endl << "Incorrect arguments";
        }
      }

      /* Keep Taking Kd till given in correct format */
      bool kdFlag = true;
      while (kdFlag) {
        std::vector<double> kd;
        std::cout << std::endl
                  << "Enter Kd Gains (space seperated)";
        /* Take input */
        while (std::cin >> temp) {
          kd.push_back(temp);
        }
        std::cin.clear();
        /* Check if in correct format */
        if (PID.SetKdGain(
            std::make_shared<std::vector<double>>(kd))) {
          kdFlag = false;
        } else {
          std::cout << std::endl << "Incorrect arguments";
        }
      }
    } else {
      flag1 = false;
      }
    }
  return 0;
}
