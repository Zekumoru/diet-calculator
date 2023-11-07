#include <QApplication>
#include "widgets/inputwidget.h"
#include "widgets/dietcard.h"
#include "data/diet.h"
#include "utils/units.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    InputWidget input;
    input.show();

    DietCard card(Diet(22, MALE, 50, 170));
    card.show();

    return app.exec();
}
