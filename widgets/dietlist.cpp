#include "dietlist.h"

#include <QScrollArea>
#include <QVBoxLayout>
#include <QGridLayout>
#include "widgets/dietcard.h"

DietList::DietList(QWidget *parent)
    : QWidget{parent}
{
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
    resize(460, 380);
}

void DietList::add(Diet diet)
{
    listView->insertWidget(0, new DietCard(diet));
}
