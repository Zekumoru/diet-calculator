#include <QApplication>
#include <QObject>
#include "widgets/inputwidget.h"
#include "widgets/dietcard.h"
#include "data/diet.h"
#include "utils/units.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    InputWidget *input = new InputWidget;
    input->show();

    DietCard *card = new DietCard(Diet(22, MALE, 50, 170));
    card->show();

    QObject::connect(input, SIGNAL (weightUnitChanged(WeightUnit)), card, SLOT (onWeightUnitChanged(WeightUnit)));
    QObject::connect(input, SIGNAL (heightUnitChanged(HeightUnit)), card, SLOT (onHeightUnitChanged(HeightUnit)));

    return app.exec();
}
