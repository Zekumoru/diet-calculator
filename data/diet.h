#ifndef DIET_H
#define DIET_H

#include "utils/units.h"

/**
 * @class Diet
 * @brief Represents information about an individual's age, sex, weight, and height in the context of a diet.
 */
class Diet
{
public:
    /**
     * @brief Default constructor for the Diet class.
     *
     * Creates a Diet object with sex set to MALE and age, weight, and height set to 0.
     */
    explicit Diet();

    /**
     * @brief Copy constructor for the Diet class.
     *
     * Creates a new Diet object with its data copied from the given `diet` reference object.
     *
     * @param diet A reference to another Diet object to copy from.
     */
    Diet(const Diet& diet);

    /**
     * @brief Parameterized constructor for the Diet class.
     *
     * Creates a new Diet object initialized with the age, sex, weight, and height of the individual.
     *
     * @param age The age of the individual.
     * @param sex The gender of the individual.
     * @param weight The weight of the individual.
     * @param height The height of the individual.
     */
    Diet(int age, Sex sex, double weight, double height);

    int age; /**< Represents the age of the individual. */
    double weight; /**< Represents the weight of the individual. */
    double height; /**< Represents the height of the individual. */
    Sex sex; /**< Represents the gender of the individual. */
};

#endif // DIET_H
