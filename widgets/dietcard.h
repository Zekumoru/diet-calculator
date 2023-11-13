#ifndef DIETCARD_H
#define DIETCARD_H

#include <QWidget>
#include "utils/units.h"
#include "data/diet.h"

class QLabel;

/**
 * @class DietCard
 * @brief Widget representing a diet card with age, sex, weight, height, BMI, and BMR information.
 * @inherits QWidget
 *
 * The DietCard class is a widget designed to display information related to a Diet object,
 * including age, sex, weight, height, and the calculated BMI and BMR. It provides slots
 * for handling unit changes and emits a signal when the user clicks on the delete button.
 */
class DietCard : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the DietCard class.
     *
     * @param diet A pointer to the Diet object associated with the card.
     * @param parent A pointer to the parent widget (default is nullptr).
     */
    explicit DietCard(Diet *diet, QWidget *parent = nullptr);

public slots:
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
     * @brief Signal emitted when the delete button on this card is clicked.
     * @param card A pointer to this DietCard object.
     */
    void deleteClicked(DietCard *card);

private:
    Diet *diet; /**< Pointer to the associated Diet object. */

    QLabel *weightValueLabel; /**< Label to display the weight value. */
    QLabel *heightValueLabel; /**< Label to display the height value. */

    /**
     * @brief Create and return a QLabel displaying the BMI value.
     * @return A pointer to the created QLabel.
     */
    QLabel *createBMILabel();
};

#endif // DIETCARD_H
