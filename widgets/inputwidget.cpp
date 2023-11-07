#include "inputwidget.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include "utils/units.h"

InputWidget::InputWidget(QWidget *parent)
    : QWidget{parent}
{
    QLabel *ageLabel = new QLabel(tr("Age"));
    ageInput = new QLineEdit;
    ageInput->setPlaceholderText(tr("E.g. 22"));

    QGroupBox *sexRadioGroup = createBiRadioGroup(
        tr("Sex"),
        tr("&Male"),
        [this]() {
            this->diet.sex = MALE;
        },
        tr("&Female"),
        [this]() {
            this->diet.sex = FEMALE;
        });

    QLabel *weightLabel = new QLabel(tr("Weight"));
    weightInput = new QLineEdit;
    weightInput->setPlaceholderText(tr("E.g. 62.8"));

    QGroupBox *weightRadioGroup = createBiRadioGroup(
        tr(nullptr),
        tr("&kg"),
        [this]() {
            this->weightUnit = KILOGRAMS;
        },
        tr("&lbs"),
        [this]() {
            this->weightUnit = POUNDS;
        });

    QLabel *heightLabel = new QLabel(tr("Height"));
    heightInput = new QLineEdit;
    heightInput->setPlaceholderText(tr("E.g. 178.2"));

    QGroupBox *heightRadioGroup = createBiRadioGroup(
        tr(nullptr),
        tr("&cm"),
        [this]() {
            this->heightUnit = CENTIMETERS;
        },
        tr("&ft"),
        [this]() {
            this->heightUnit = FEET;
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

template<typename Func1, typename Func2>
QGroupBox *InputWidget::createBiRadioGroup(const QString title, const QString op1, Func1 &&op1Selected, const QString op2, Func2 &&op2Selected)
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

    return group;
}

void InputWidget::onSubmit()
{
    emit submitted(Diet(diet));
}
