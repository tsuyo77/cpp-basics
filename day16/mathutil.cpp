#include "mathutil.h"


double clamp_range(double v, double lo, double hi)   // lo〜hi に収める
{
    return (v < lo) ? lo : (v > hi) ? hi : v;
}
double lerp_value(double a, double b, double t)      // a + (b - a) * t
{
    return a + (b - a) * t;
}