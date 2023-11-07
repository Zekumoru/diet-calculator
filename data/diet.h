#ifndef DIET_H
#define DIET_H

#include "utils/units.h"

class Diet
{
public:
    explicit Diet();
    Diet(const Diet& diet);
    Diet(int age, Sex sex, double weight, double height);

    int age;
    double weight;
    double height;
    Sex sex;
};

#endif // DIET_H
