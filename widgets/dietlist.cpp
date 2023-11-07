#include "dietlist.h"

#include <QScrollArea>
#include <QVBoxLayout>
#include <QGridLayout>
#include "widgets/dietcard.h"

DietList::DietList(QWidget *parent)
    : QWidget{parent}
{
    weightUnit = KILOGRAMS;
    heightUnit = CENTIMETERS;

    listView = new QVBoxLayout;
    listView->addStretch();

    QWidget *scrollAreaContent = new QWidget;
    scrollAreaContent->setLayout(listView);

    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollAreaContent);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(scrollArea, 0, 0);

    setLayout(mainLayout);
    setMinimumWidth(480);
}

void DietList::add(Diet *diet)
{
    DietCard *card = new DietCard(diet);
    card->onWeightUnitChanged(weightUnit);
    card->onHeightUnitChanged(heightUnit);

    listView->insertWidget(0, card);

    connect(this, SIGNAL (weightUnitChanged(WeightUnit)), card, SLOT (onWeightUnitChanged(WeightUnit)));
    connect(this, SIGNAL (heightUnitChanged(HeightUnit)), card, SLOT (onHeightUnitChanged(HeightUnit)));
    connect(card, &DietCard::deleteClicked, this, [this](DietCard *card) {
        this->listView->removeWidget(card);
        delete card;
    });
}

void DietList::onWeightUnitChanged(WeightUnit unit)
{
    weightUnit = unit;
    emit weightUnitChanged(unit);
}

void DietList::onHeightUnitChanged(HeightUnit unit)
{
    heightUnit = unit;
    emit heightUnitChanged(unit);
}
