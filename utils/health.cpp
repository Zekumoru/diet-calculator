#include "health.h"
#include "units.h"

double Health::bmi(double weight, double height)
{
    const double CM2_TO_M2_FACTOR = 10000;
    return weight / (height * height / CM2_TO_M2_FACTOR);
}

Health::BMIState Health::stateFromBMI(double bmi)
{
    if (bmi < 18.5) {
        return Health::UNDERWEIGHT;
    } else if (bmi < 24.9) {
        return Health::HEALTHY;
    } else if (bmi < 29.9) {
        return Health::OVERWEIGHT;
    } else {
        return Health::OBESE;
    }
}

double Health::bmr(Sex sex, double age, double weight, double height)
{
    if (sex == MALE) {
        return 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    }

    return 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
}

double Health::caloriesBasedOnActivity(double bmr, ActivityLevel level)
{
    switch (level) {
    case SEDENTARY:
        return bmr * 1.2;
    case LIGHT:
        return bmr * 1.375;
    case MODERATE:
        return bmr * 1.55;
    case ACTIVE:
        return bmr * 1.725;
    case INTENSE:
        return bmr * 1.9;
    default:
        return bmr;
    }
}
