#ifndef UNITS_H
#define UNITS_H

/**
 * @enum Sex
 * @brief Enumerated type representing different sexes.
 */
enum Sex {
    MALE,   /**< Represents the male sex. */
    FEMALE  /**< Represents the female sex. */
};

/**
 * @enum WeightUnit
 * @brief Enumerated type representing different units of weight.
 */
enum WeightUnit {
    KILOGRAMS, /**< Represents kilograms as the unit of weight. */
    POUNDS     /**< Represents pounds as the unit of weight. */
};

/**
 * @enum HeightUnit
 * @brief Enumerated type representing different units of height.
 */
enum HeightUnit {
    CENTIMETERS, /**< Represents centimeters as the unit of height. */
    FEET         /**< Represents feet as the unit of height. */
};

/**
 * @brief Conversion factor from kilograms to pounds.
 *
 * The conversion factor from kilograms to pounds which is equivalent to 2.20462.
 */
extern const double POUNDS_PER_KG;

/**
 * @brief Conversion factor from centimeters to feet.
 *
 * The conversion factor from centimeters to feet which is equivalent to 30.48.
 */
extern const double CM_PER_FOOT;

/**
 * @brief Convert weight from kilograms to pounds.
 *
 * @param kg The weight in kilograms.
 * @return The weight converted to pounds.
 */
double kgToLbs(double kg);

/**
 * @brief Convert weight from pounds to kilograms.
 *
 * @param lbs The weight in pounds.
 * @return The weight converted to kilograms.
 */
double lbsToKg(double lbs);

/**
 * @brief Convert height from centimeters to feet.
 *
 * @param cm The height in centimeters.
 * @return The height converted to feet.
 */
double cmToFeet(double cm);

/**
 * @brief Convert height from feet to centimeters.
 *
 * @param feet The height in feet.
 * @return The height converted to centimeters.
 */
double feetToCm(double feet);


#endif // UNITS_H
