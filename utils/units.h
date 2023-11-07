#ifndef UNITS_H
#define UNITS_H

enum Sex {
    MALE,
    FEMALE
};

enum WeightUnit {
    KILOGRAMS,
    POUNDS
};

enum HeightUnit {
    CENTIMETERS,
    FEET
};

extern const double POUNDS_PER_KG;
extern const double CM_PER_FOOT;

double kgToLbs(double kg);
double lbsToKg(double lbs);

double cmToFeet(double cm);
double feetToCm(double feet);

#endif // UNITS_H
