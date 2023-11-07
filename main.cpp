#include <QApplication>
#include "widgets/inputwidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    InputWidget input;
    input.show();

    return app.exec();
}
