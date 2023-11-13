#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include "data/diet.h"
#include "utils/units.h"

class QLabel;
class QLineEdit;
class QGroupBox;
class QString;
class QRadioButton;

/**
 * @class InputWidget
 * @brief Widget for entering diet-related information including age, sex, weight, and height.
 * @inherits QWidget
 *
 * The InputWidget class is designed to allow users to input information such as age, sex, weight, and height
 * for creating a new Diet object. It emits signals for changes in weight and height units, as well as when
 * the user submits the entered information.
 */
class InputWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the InputWidget class.
     * @param parent A pointer to the parent widget (default is nullptr).
     */
    explicit InputWidget(QWidget *parent = nullptr);

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

    /**
     * @brief Signal emitted when the user submits the entered information.
     * @param diet A pointer to the created Diet object.
     */
    void submitted(Diet *diet);

private:
    const double exampleWeight = 62.8; /**< Example weight value for UI placeholder display. */
    const double exampleHeight = 178.2; /**< Example height value for UI placeholder display. */

    Sex sex; /**< Represents the gender selected by the user. */
    WeightUnit weightUnit; /**< Represents the selected unit for weight. */
    HeightUnit heightUnit; /**< Represents the selected unit for height. */

    QLineEdit *ageInput; /**< Line edit for entering age information. */
    QLineEdit *weightInput; /**< Line edit for entering weight information. */
    QLineEdit *heightInput; /**< Line edit for entering height information. */
    QRadioButton *maleButton; /**< Radio button for selecting male gender. */

    /**
     * @brief Clears the input fields and resets the UI.
     */
    void clear();

    /**
     * @brief Updates the displayed weight unit and emits the corresponding signal.
     * @param unit The new WeightUnit value.
     */
    void updateWeightUnit(WeightUnit unit);

    /**
     * @brief Updates the displayed height unit and emits the corresponding signal.
     * @param unit The new HeightUnit value.
     */
    void updateHeightUnit(HeightUnit unit);

    /**
     * @brief Creates a radio button group with two options.
     *
     * A helper function to avoid duplicating code creating a component
     * with two radio buttons. It calls its three template function params
     * counterpart which is used if the needs to obtain or further
     * configure the two radio buttons arises.
     *
     * @tparam Func1 Callable type for the first option's selected signal.
     * @tparam Func2 Callable type for the second option's selected signal.
     * @param title The title of the radio button group.
     * @param op1 The text label for the first option.
     * @param op1Selected The signal for the first option's selection.
     * @param op2 The text label for the second option.
     * @param op2Selected The signal for the second option's selection.
     * @return A pointer to the created radio button group.
     */
    template<typename Func1, typename Func2>
    QGroupBox *createBiRadioGroup(const QString title, const QString op1, Func1 &&op1Selected, const QString op2, Func2 &&op2Selected);

    /**
     * @brief Creates a radio button group with two options and calls the third function containing the two radio buttons.
     *
     * A helper function to avoid duplicating code creating a component
     * with two radio buttons. Its last function parameter can be used
     * to obtain the two radio buttons and further configure them or get
     * their references.
     *
     * @tparam Func1 Callable type for the first option's selected signal.
     * @tparam Func2 Callable type for the second option's selected signal.
     * @tparam Func3 Callable type to obtain the two radio buttons through its parameters.
     * @param title The title of the radio button group.
     * @param op1 The text label for the first option.
     * @param op1Selected The signal for the first option's selection.
     * @param op2 The text label for the second option.
     * @param op2Selected The signal for the second option's selection.
     * @param opButtons A callable function for obtaining or configuring the two option buttons.
     * @return A pointer to the created radio button group.
     */
    template<typename Func1, typename Func2, typename Func3>
    QGroupBox *createBiRadioGroup(const QString title, const QString op1, Func1 &&op1Selected, const QString op2, Func2 &&op2Selected, Func3 &&opButtons);

private slots:
    /**
     * @brief Slot called when the user submits the entered information.
     */
    void onSubmit();
};


#endif // INPUTWIDGET_H
