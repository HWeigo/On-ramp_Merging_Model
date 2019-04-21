#ifndef __CALCULATION_H
#define __CALCULATION_H

#include "onramp_merging.h"
#include "calculation.h"
#include <stdint.h>
#include <cmath>

using namespace std;

float calc_LineSafeDistance(Master_CarNode master, Other_CarNode other);
float calc_BrakeDistance(Master_CarNode master);
float calc_MMS(Master_CarNode master, Other_CarNode other);

//float calc_LineSafeDistance(Master_CarNode master, Other_CarNode other);
//
//
//float calc_BrakeDistance(Master_CarNode master);
//
//
//float calc_MMS(Master_CarNode master, Other_CarNode other);


#endif // !__CALCULATION

