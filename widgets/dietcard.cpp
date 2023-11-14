#include "dietcard.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include "data/diet.h"
#include "utils/units.h"
#include "utils/health.h"

DietCard::DietCard(Diet *diet, QWidget *parent)
    : QWidget{parent}
{
    this->diet = diet;

    QLabel *ageLabel = new QLabel(tr("Age"));
    QLabel *ageValueLabel = new QLabel(QString::number(diet->age));

    QString sexValue = (diet->sex == MALE)? tr("Male") : tr("Female");
    QLabel *sexLabel = new QLabel(tr("Sex"));
    QLabel *sexValueLabel = new QLabel(sexValue);

    QLabel *weightLabel = new QLabel(tr("Weight"));
    weightValueLabel = new QLabel;
    onWeightUnitChanged(KILOGRAMS);

    QLabel *heightLabel = new QLabel(tr("Height"));
    heightValueLabel = new QLabel;
    onHeightUnitChanged(CENTIMETERS);

    QGridLayout *leftLayout = new QGridLayout;
    leftLayout->addWidget(ageLabel, 0, 0);
    leftLayout->addWidget(ageValueLabel, 1, 0);
    leftLayout->addWidget(sexLabel, 0, 1);
    leftLayout->addWidget(sexValueLabel, 1, 1);
    leftLayout->addWidget(weightLabel, 2, 0, 1, 2);
    leftLayout->addWidget(weightValueLabel, 3, 0, 1, 2);
    leftLayout->addWidget(heightLabel, 4, 0, 1, 2);
    leftLayout->addWidget(heightValueLabel, 5, 0, 1, 2);

    QLabel *bmiLabel = createBMILabel();

    double bmr = Health::bmr(diet->sex, diet->age, diet->weight, diet->height);
    QLabel *bmrLabel = new QLabel(tr("BMR: %1 kcal/day").arg(bmr));
    QLabel *sedentaryLabel = new QLabel(tr("Sedentary: %1 kcal/day").arg(Health::caloriesBasedOnActivity(bmr, Health::SEDENTARY)));
    QLabel *lightLabel = new QLabel(tr("Light: %1 kcal/day").arg(Health::caloriesBasedOnActivity(bmr, Health::LIGHT)));
    QLabel *moderateLabel = new QLabel(tr("Moderate: %1 kcal/day").arg(Health::caloriesBasedOnActivity(bmr, Health::MODERATE)));
    QLabel *activeLabel = new QLabel(tr("Active: %1 kcal/day").arg(Health::caloriesBasedOnActivity(bmr, Health::ACTIVE)));
    QLabel *intenseLabel = new QLabel(tr("Intense: %1 kcal/day").arg(Health::caloriesBasedOnActivity(bmr, Health::INTENSE)));

    QGridLayout *rightLayout = new QGridLayout;
    rightLayout->addWidget(bmiLabel);
    rightLayout->addWidget(bmrLabel);
    rightLayout->addWidget(sedentaryLabel);
    rightLayout->addWidget(lightLabel);
    rightLayout->addWidget(moderateLabel);
    rightLayout->addWidget(activeLabel);
    rightLayout->addWidget(intenseLabel);

    QPushButton *deleteButton = new QPushButton(tr("&Delete"));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(leftLayout, 0, 0);
    mainLayout->addLayout(rightLayout, 0, 1);
    mainLayout->addWidget(deleteButton, 1, 0, 1, 2);

    setLayout(mainLayout);

    connect(deleteButton, &QPushButton::clicked, this, [this]() {
        emit this->deleteClicked(this);
    });
}

void DietCard::onWeightUnitChanged(WeightUnit unit)
{
    double weight = diet->weight;
    QString *unitString;

    if (unit == POUNDS) {
        weight = kgToLbs(weight);
        unitString = new QString(tr("lbs"));
    } else {
        unitString = new QString(tr("kg"));
    }

    weightValueLabel->setText(QString::number(weight, 'f', 2) + " " + *unitString);
}

void DietCard::onHeightUnitChanged(HeightUnit unit)
{
    double height = diet->height;
    QString *unitString;

    if (unit == FEET) {
        height = cmToFeet(height);
        unitString = new QString(tr("ft"));
    } else {
        unitString = new QString(tr("cm"));
    }

    heightValueLabel->setText(QString::number(height, 'f', 2) + " " + *unitString);
}

QLabel *DietCard::createBMILabel()
{
    double bmi = Health::bmi(diet->weight, diet->height);
    QString *state;

    switch (Health::stateFromBMI(bmi)) {
    case Health::UNDERWEIGHT:
        state = new QString(tr("Underweight"));
        break;
    case Health::HEALTHY:
        state = new QString(tr("Healthy"));
        break;
    case Health::OVERWEIGHT:
        state = new QString(tr("Overweight"));
        break;
    case Health::OBESE:
        state = new QString(tr("Obese"));
        break;
    default:
        state = new QString(tr("Undefined"));
    }

    QLabel* bmiLabel = new QLabel(tr("BMI: %1 (%2)").arg(QString::number(bmi, 'f', 2)).arg(*state));

    return bmiLabel;
}
