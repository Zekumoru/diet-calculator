#ifndef HEALTH_H
#define HEALTH_H

#include "units.h"

namespace Health
{
    enum BMIState {
        UNDERWEIGHT,
        HEALTHY,
        OVERWEIGHT,
        OBESE
    };

    enum ActivityLevel {
        SEDENTARY,
        LIGHT,
        MODERATE,
        ACTIVE,
        INTENSE
    };

    double bmi(double weight, double height);
    BMIState stateFromBMI(double bmi);

    double bmr(Sex sex, double age, double weight, double height);
    double caloriesBasedOnActivity(double bmr, ActivityLevel level);
}

#endif // HEALTH_H
