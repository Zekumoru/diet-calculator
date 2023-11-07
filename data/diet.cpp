#include "diet.h"
#include "utils/units.h"

Diet::Diet()
{
    age = 0;
    weight = 0.0;
    height = 0.0;
    sex = MALE;
}

Diet::Diet(const Diet& diet)
{
    age = diet.age;
    weight = diet.weight;
    height = diet.height;
    sex = diet.sex;
}

Diet::Diet(int _age, Sex _sex, double _weight, double _height)
{
    age = _age;
    weight = _weight;
    height = _height;
    sex = _sex;
}
