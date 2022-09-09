#pragma once
#include "main.h"
using namespace pros;

void setDrive(int left, int right);
void setDrive(int leftFv, int leftBv, int rightFv, int rightBv);

void resetDrive();
void resetDriveEncoders();

double avgDriveEncoders();

void driveCoast();
void driveBrake();

void driverControl();

void driveFor(double inches, double percent);
