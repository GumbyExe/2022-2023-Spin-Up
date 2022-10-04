#pragma once

#include "EZ-Template/drive/drive.hpp"

extern Drive chassis;

double conv(double i);

void default_constants();
void tuning_constants();
void tune_PID();
void winpointRED();
void winpointBLUE();