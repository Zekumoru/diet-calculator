#ifndef DIETLIST_H
#define DIETLIST_H

#include <QWidget>
#include "data/diet.h"
#include "utils/units.h"

class QVBoxLayout;

/**
 * @class DietList
 * @brief Widget representing a list of Diet objects with support for unit changes.
 * @inherits QWidget
 *
 * The DietList class is a widget designed to display a list of Diet objects and
 * provides slots to handle adding a new diet and responding to changes in weight
 * and height units. It emits signals when the unit values are changed.
 */
class DietList : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the DietList class.
     * @param parent A pointer to the parent widget (default is nullptr).
     */
    explicit DietList(QWidget *parent = nullptr);

public slots:
    /**
     * @brief Slot to handle adding a new Diet to the list.
     * @param diet A pointer to the Diet object to be added.
     */
    void add(Diet *diet);

    /**
     * @brief Slot to handle changes in weight units.
     * @param unit The new WeightUnit value representing the selected unit.
     */
    void onWeightUnitChanged(WeightUnit unit);

    /**
     * @brief Slot to handle changes in height units.
     * @param unit The new HeightUnit value representing the selected unit.
     */
    void onHeightUnitChanged(HeightUnit unit);

signals:
    /**
     * @brief Signal emitted when the weight unit is changed.
     * @param unit The new WeightUnit value.
     */
    void weightUnitChanged(WeightUnit unit);

    /**
     * @brief Signal emitted when the height unit is changed.
     * @param unit The new HeightUnit value.
     */
    void heightUnitChanged(HeightUnit unit);

private:
    WeightUnit weightUnit; /**< Represents the current unit for weight. */
    HeightUnit heightUnit; /**< Represents the current unit for height. */

    QVBoxLayout *listView; /**< Vertical layout for displaying the list of Diet objects. */
};

#endif // DIETLIST_H
