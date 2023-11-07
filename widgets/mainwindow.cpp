#include "mainwindow.h"

#include "inputwidget.h"
#include "dietlist.h"
#include "utils/units.h"

#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent}
{
    InputWidget *inputWidget = new InputWidget;
    DietList *dietList = new DietList;

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(inputWidget, 0, 0);
    mainLayout->addWidget(dietList, 0, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("Diet Calculator"));

    connect(inputWidget, SIGNAL (weightUnitChanged(WeightUnit)), dietList, SLOT (onWeightUnitChanged(WeightUnit)));
    connect(inputWidget, SIGNAL (heightUnitChanged(HeightUnit)), dietList, SLOT (onHeightUnitChanged(HeightUnit)));
    connect(inputWidget, SIGNAL (submitted(Diet*)), dietList, SLOT (add(Diet*)));
}
