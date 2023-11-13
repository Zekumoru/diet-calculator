#ifndef HEALTH_H
#define HEALTH_H

#include "units.h"

/**
 * @namespace Health
 * @brief Namespace encapsulating functionality related to health calculations.
 *
 * The Health namespace provides functionality for health-related calculations,
 * including Body Mass Index (BMI), BMI State determination, Basal Metabolic Rate (BMR),
 * and calorie estimation based on activity level.
 */
namespace Health {
    /**
     * @enum BMIState
     * @brief Enumerated type representing different states based on Body Mass Index (BMI).
     */
    enum BMIState {
        UNDERWEIGHT, /**< Represents an underweight BMI state. */
        HEALTHY,     /**< Represents a healthy BMI state. */
        OVERWEIGHT,  /**< Represents an overweight BMI state. */
        OBESE        /**< Represents an obese BMI state. */
    };

    /**
     * @enum ActivityLevel
     * @brief Enumerated type representing different levels of physical activity.
     */
    enum ActivityLevel {
        SEDENTARY, /**< Represents a sedentary level of physical activity. */
        LIGHT,     /**< Represents a light level of physical activity. */
        MODERATE,  /**< Represents a moderate level of physical activity. */
        ACTIVE,    /**< Represents an active level of physical activity. */
        INTENSE    /**< Represents an intense level of physical activity. */
    };

    /**
     * @brief Calculate Body Mass Index (BMI) based on weight and height.
     *
     * @param weight The weight of the individual.
     * @param height The height of the individual.
     * @return The calculated BMI.
     */
    double bmi(double weight, double height);

    /**
     * @brief Determine BMI State based on the provided BMI value.
     *
     * @param bmi The Body Mass Index (BMI) value.
     * @return The corresponding BMI state (UNDERWEIGHT, HEALTHY, OVERWEIGHT, OBESE).
     */
    BMIState stateFromBMI(double bmi);

    /**
     * @brief Calculate Basal Metabolic Rate (BMR) based on sex, age, weight, and height.
     *
     * @param sex The gender of the individual (Sex enum).
     * @param age The age of the individual.
     * @param weight The weight of the individual.
     * @param height The height of the individual.
     * @return The calculated BMR.
     */
    double bmr(Sex sex, double age, double weight, double height);

    /**
     * @brief Estimate daily calorie needs based on Basal Metabolic Rate (BMR) and activity level.
     *
     * @param bmr The Basal Metabolic Rate (BMR) of the individual.
     * @param level The level of physical activity (ActivityLevel enum).
     * @return The estimated daily calorie needs.
     */
    double caloriesBasedOnActivity(double bmr, ActivityLevel level);

} // namespace Health

#endif // HEALTH_H
