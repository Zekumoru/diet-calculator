#include <QApplication>
#include <QObject>
#include "widgets/inputwidget.h"
#include "widgets/dietlist.h"
#include "data/diet.h"
#include "utils/units.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    InputWidget *input = new InputWidget;
    input->show();

    DietList *list = new DietList;
    list->show();

    QObject::connect(input, SIGNAL (submitted(Diet)), list, SLOT (add(Diet)));

    /*
    QObject::connect(input, SIGNAL (weightUnitChanged(WeightUnit)), card, SLOT (onWeightUnitChanged(WeightUnit)));
    QObject::connect(input, SIGNAL (heightUnitChanged(HeightUnit)), card, SLOT (onHeightUnitChanged(HeightUnit)));
    */

    return app.exec();
}
