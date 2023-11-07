#include "dietcard.h"

#include <QGridLayout>
#include <QLabel>
#include <QWidget>
#include "data/diet.h"
#include "utils/units.h"

DietCard::DietCard(Diet diet, QWidget *parent)
    : QWidget{parent}
{
    this->diet = &diet;

    QLabel *ageLabel = new QLabel(tr("Age"));
    QLabel *ageValueLabel = new QLabel(QString::number(diet.age));

    QString sexValue = (diet.sex == MALE)? tr("Male") : tr("Female");
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

    QLabel *bmiLabel = new QLabel(tr("BMI: 17.3 (Underweight)"));
    QLabel *bmrLabel = new QLabel(tr("BMR: 1.458 kcal/day"));
    QLabel *sedentaryLabel = new QLabel(tr("Sedentary: 1.149 kcal/day"));
    QLabel *lightLabel = new QLabel(tr("Light: 1.149 kcal/day"));
    QLabel *moderateLabel = new QLabel(tr("Moderate: 1.149 kcal/day"));
    QLabel *activeLabel = new QLabel(tr("Active: 1.149 kcal/day"));
    QLabel *intenseLabel = new QLabel(tr("Intense: 1.149 kcal/day"));

    QGridLayout *rightLayout = new QGridLayout;
    rightLayout->addWidget(bmiLabel);
    rightLayout->addWidget(bmrLabel);
    rightLayout->addWidget(sedentaryLabel);
    rightLayout->addWidget(lightLabel);
    rightLayout->addWidget(moderateLabel);
    rightLayout->addWidget(activeLabel);
    rightLayout->addWidget(intenseLabel);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(leftLayout, 0, 0);
    mainLayout->addLayout(rightLayout, 0, 1);

    setLayout(mainLayout);
}

void DietCard::onWeightUnitChanged(WeightUnit unit)
{
    // TODO: Implement functions to convert kg to lbs and vice versa
    const double POUNDS_PER_KG = 2.20462;
    double weight = diet->weight;
    QString *unitString;

    if (unit == POUNDS) {
        weight *= POUNDS_PER_KG;
        unitString = new QString(tr("lbs"));
    } else {
        unitString = new QString(tr("kg"));
    }

    weightValueLabel->setText(QString::number(weight, 'f', 2) + " " + *unitString);
}

void DietCard::onHeightUnitChanged(HeightUnit unit)
{
    // TODO: Implement functions to convert cm to ft and vice versa
    const double CM_PER_FOOT = 30.48;
    double height = diet->height;
    QString *unitString;

    if (unit == FEET) {
        height *= (1 / CM_PER_FOOT);
        unitString = new QString(tr("ft"));
    } else {
        unitString = new QString(tr("cm"));
    }

    heightValueLabel->setText(QString::number(height, 'f', 2) + " " + *unitString);
}
