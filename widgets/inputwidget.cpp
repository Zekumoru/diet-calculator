#include "inputwidget.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QString>
#include <cstdbool>
#include "utils/units.h"

InputWidget::InputWidget(QWidget *parent)
    : QWidget{parent}
{
    QRegularExpressionValidator *intRegex = new QRegularExpressionValidator(QRegularExpression("^(0|[1-9]\\d{0,2})$"));
    QRegularExpressionValidator *doubleRegex = new QRegularExpressionValidator(QRegularExpression("^(0|[1-9]\\d{0,2})?(\\.\\d{0,2})?$"));

    sex = MALE;

    QLabel *ageLabel = new QLabel(tr("Age"));
    ageInput = new QLineEdit;
    ageInput->setValidator(intRegex);
    ageInput->setPlaceholderText(tr("E.g. 22"));

    QGroupBox *sexRadioGroup = createBiRadioGroup(
        tr("Sex"),
        tr("&Male"),
        [this]() {
            this->sex = MALE;
        },
        tr("&Female"),
        [this]() {
            this->sex = FEMALE;
        },
        [this](QRadioButton *maleButton, QRadioButton*) {
            this->maleButton = maleButton;
        });

    QLabel *weightLabel = new QLabel(tr("Weight"));
    weightInput = new QLineEdit;
    weightInput->setValidator(doubleRegex);
    weightInput->setPlaceholderText(tr("E.g. 62.8"));
    weightInput->setValidator(doubleRegex);

    QGroupBox *weightRadioGroup = createBiRadioGroup(
        tr(nullptr),
        tr("&kg"),
        [this]() {
            this->updateWeightUnit(KILOGRAMS);;
        },
        tr("&lbs"),
        [this]() {
            this->updateWeightUnit(POUNDS);;
        });

    QLabel *heightLabel = new QLabel(tr("Height"));
    heightInput = new QLineEdit;
    heightInput->setValidator(doubleRegex);
    heightInput->setPlaceholderText(tr("E.g. 178.2"));

    QGroupBox *heightRadioGroup = createBiRadioGroup(
        tr(nullptr),
        tr("&cm"),
        [this]() {
            this->updateHeightUnit(CENTIMETERS);
        },
        tr("&ft"),
        [this]() {
            this->updateHeightUnit(FEET);
        });

    QPushButton *submitButton = new QPushButton(tr("&Submit"));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(ageLabel, 0, 0);
    mainLayout->addWidget(ageInput, 1, 0);
    mainLayout->addWidget(sexRadioGroup, 2, 0);
    mainLayout->addWidget(weightLabel, 3, 0);
    mainLayout->addWidget(weightInput, 4, 0);
    mainLayout->addWidget(weightRadioGroup, 5, 0);
    mainLayout->addWidget(heightLabel, 6, 0);
    mainLayout->addWidget(heightInput, 7, 0);
    mainLayout->addWidget(heightRadioGroup, 8, 0);
    mainLayout->addWidget(submitButton, 9, 0);

    setLayout(mainLayout);

    connect(submitButton, SIGNAL (clicked()), this, SLOT (onSubmit()));
}

void InputWidget::updateWeightUnit(WeightUnit unit)
{
    // TODO: Implement functions to convert kg to lbs and vice versa
    const double POUNDS_PER_KG = 2.20462;
    const bool inputWasEmpty = weightInput->text().isEmpty();
    double weight = weightInput->text().toDouble();

    weightUnit = unit;
    emit weightUnitChanged(unit);

    if (unit == KILOGRAMS) {
        weightInput->setPlaceholderText("E.g. 62.8");
        weight *= (1.0 / POUNDS_PER_KG);
    } else {
        weightInput->setPlaceholderText("E.g. 138.45");
        weight *= POUNDS_PER_KG;
    }

    if (inputWasEmpty) return;
    weightInput->setText(QString::number(weight, 'f', 2));
}

void InputWidget::updateHeightUnit(HeightUnit unit)
{
    // TODO: Implement functions to convert cm to ft and vice versa
    const double CM_PER_FOOT = 30.48;
    const bool inputWasEmpty = heightInput->text().isEmpty();
    double height = heightInput->text().toDouble();

    heightUnit = unit;
    emit heightUnitChanged(unit);

    if (unit == CENTIMETERS) {
        heightInput->setPlaceholderText("E.g. 178.2");
        height *= CM_PER_FOOT;
    } else {
        heightInput->setPlaceholderText("E.g. 5.85");
        height *= (1.0 / CM_PER_FOOT);
    }

    if (inputWasEmpty) return;
    heightInput->setText(QString::number(height, 'f', 2));
}


template<typename Func1, typename Func2>
QGroupBox *InputWidget::createBiRadioGroup(const QString title, const QString op1, Func1 &&op1Selected, const QString op2, Func2 &&op2Selected)
{
    return createBiRadioGroup(title, op1, op1Selected, op2, op2Selected, [](QRadioButton*, QRadioButton*){});
}

template<typename Func1, typename Func2, typename Func3>
QGroupBox *InputWidget::createBiRadioGroup(const QString title, const QString op1, Func1 &&op1Selected, const QString op2, Func2 &&op2Selected, Func3 &&opButtons)
{
    QGroupBox *group = new QGroupBox(title);
    QRadioButton *op1Radio = new QRadioButton(op1);
    QRadioButton *op2Radio = new QRadioButton(op2);
    op1Radio->setChecked(true);

    connect(op1Radio, &QRadioButton::toggled, this, [this, op1Selected] (bool checked) {
        if (!checked) return;
        op1Selected();
    });
    connect(op2Radio, &QRadioButton::toggled, this, [this, op2Selected] (bool checked) {
        if (!checked) return;
        op2Selected();
    });

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(op1Radio);
    layout->addWidget(op2Radio);
    group->setLayout(layout);

    opButtons(op1Radio, op2Radio);

    return group;
}

void InputWidget::clear()
{
    sex = MALE;
    maleButton->setChecked(true);

    ageInput->clear();
    weightInput->clear();
    heightInput->clear();
}

void InputWidget::onSubmit()
{
    // TODO: use conversion functions when they become implemented
    const double POUNDS_PER_KG = 2.20462;
    const double CM_PER_FOOT = 30.48;

    int age = ageInput->text().toInt();
    double weight = weightInput->text().toDouble();
    double height = heightInput->text().toDouble();

    if (weightUnit == POUNDS) {
        weight *= (1 / POUNDS_PER_KG);
    }

    if (heightUnit == FEET) {
        height *= CM_PER_FOOT;
    }

    emit submitted(new Diet(age, this->sex, weight, height));
    clear();
}
