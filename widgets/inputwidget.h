#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include "data/diet.h"
#include "utils/units.h"

class QLabel;
class QLineEdit;
class QGroupBox;
class QString;

class InputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InputWidget(QWidget *parent = nullptr);

signals:
    void submitted(Diet diet);

private:
    Diet diet;

    QLineEdit *ageInput;
    QLineEdit *weightInput;
    QLineEdit *heightInput;

    void updateWeightUnit(WeightUnit unit);
    void updateHeightUnit(HeightUnit unit);

    template<typename Func1, typename Func2>
    QGroupBox *createBiRadioGroup(const QString title, const QString op1, Func1 &&op1Selected, const QString op2, Func2 &&op2Selected);

private slots:
    void onSubmit();

};

#endif // INPUTWIDGET_H
