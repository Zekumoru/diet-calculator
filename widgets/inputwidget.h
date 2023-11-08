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

class InputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InputWidget(QWidget *parent = nullptr);

signals:
    void weightUnitChanged(WeightUnit unit);
    void heightUnitChanged(HeightUnit unit);
    void submitted(Diet *diet);

private:
    const double exampleWeight = 62.8;
    const double exampleHeight = 178.2;

    Sex sex;
    WeightUnit weightUnit;
    HeightUnit heightUnit;

    QLineEdit *ageInput;
    QLineEdit *weightInput;
    QLineEdit *heightInput;
    QRadioButton *maleButton;

    void clear();
    void updateWeightUnit(WeightUnit unit);
    void updateHeightUnit(HeightUnit unit);

    template<typename Func1, typename Func2>
    QGroupBox *createBiRadioGroup(const QString title, const QString op1, Func1 &&op1Selected, const QString op2, Func2 &&op2Selected);

    template<typename Func1, typename Func2, typename Func3>
    QGroupBox *createBiRadioGroup(const QString title, const QString op1, Func1 &&op1Selected, const QString op2, Func2 &&op2Selected, Func3 &&opButtons);

private slots:
    void onSubmit();

};

#endif // INPUTWIDGET_H
