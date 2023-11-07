#include "dietcard.h"

#include <QGridLayout>
#include <QLabel>
#include <QWidget>
#include "data/diet.h"
#include "utils/units.h"

DietCard::DietCard(Diet diet, QWidget *parent)
    : QWidget{parent}
{
    QLabel *ageLabel = new QLabel(tr("Age"));
    QLabel *ageValueLabel = new QLabel(QString::number(diet.age));

    QString sexValue = (diet.sex == MALE)? tr("Male") : tr("Female");
    QLabel *sexLabel = new QLabel(tr("Sex"));
    QLabel *sexValueLabel = new QLabel(sexValue);

    QLabel *weightLabel = new QLabel(tr("Weight"));
    QLabel *weightValueLabel = new QLabel(QString::number(diet.weight, 'f', 2) + " kg");

    QLabel *heightLabel = new QLabel(tr("Height"));
    QLabel *heightValueLabel = new QLabel(QString::number(diet.height, 'f', 2) + " cm");

    QGridLayout *leftLayout = new QGridLayout;
    leftLayout->addWidget(ageLabel, 0, 0);
    leftLayout->addWidget(ageValueLabel, 1, 0);
    leftLayout->addWidget(sexLabel, 0, 1);
    leftLayout->addWidget(sexValueLabel, 1, 1);
    leftLayout->addWidget(weightLabel, 2, 0);
    leftLayout->addWidget(weightValueLabel, 3, 0);
    leftLayout->addWidget(heightLabel, 4, 0);
    leftLayout->addWidget(heightValueLabel, 5, 0);

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
