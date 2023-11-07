#ifndef DIETLIST_H
#define DIETLIST_H

#include <QWidget>
#include "data/diet.h"
#include "utils/units.h"

class QVBoxLayout;

class DietList : public QWidget
{
    Q_OBJECT

public:
    explicit DietList(QWidget *parent = nullptr);

public slots:
    void add(Diet *diet);
    void onWeightUnitChanged(WeightUnit unit);
    void onHeightUnitChanged(HeightUnit unit);

signals:
    void weightUnitChanged(WeightUnit unit);
    void heightUnitChanged(HeightUnit unit);

private:
    WeightUnit weightUnit;
    HeightUnit heightUnit;

    QVBoxLayout *listView;

};

#endif // DIETLIST_H
