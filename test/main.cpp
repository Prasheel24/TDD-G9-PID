///*
// *
// * Copyright 2019 Prasheel Renkuntla
// *
// * @file         main.cpp
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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
