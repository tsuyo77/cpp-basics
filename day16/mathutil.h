#pragma once

#include <iostream>

double clamp_range(double v, double lo, double hi);   // lo〜hi に収める
double lerp_value(double a, double b, double t);      // a + (b - a) * t