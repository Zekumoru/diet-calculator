#ifndef DIETLIST_H
#define DIETLIST_H

#include <QWidget>
#include "data/diet.h"

class QVBoxLayout;

class DietList : public QWidget
{
    Q_OBJECT

public:
    explicit DietList(QWidget *parent = nullptr);

public slots:
    void add(Diet diet);

private:
    QVBoxLayout *listView;

};

#endif // DIETLIST_H
