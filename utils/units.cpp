#include "units.h"

const double POUNDS_PER_KG = 2.20462;
const double CM_PER_FOOT = 30.48;

double kgToLbs(double kg)
{
    return kg * POUNDS_PER_KG;
}

double lbsToKg(double lbs)
{
    return lbs * (1 / POUNDS_PER_KG);
}

double cmToFeet(double cm)
{
    return cm * (1 / CM_PER_FOOT);
}

double feetToCm(double feet)
{
    return feet * CM_PER_FOOT;
}
