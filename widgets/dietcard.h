#ifndef DIETCARD_H
#define DIETCARD_H

#include <QWidget>
#include "utils/units.h"
#include "data/diet.h"

class QLabel;

class DietCard : public QWidget
{
    Q_OBJECT
public:
    explicit DietCard(Diet *diet, QWidget *parent = nullptr);

public slots:
    void onWeightUnitChanged(WeightUnit unit);
    void onHeightUnitChanged(HeightUnit unit);

signals:
    void deleteClicked(DietCard *card);

private:
    Diet *diet;

    QLabel *weightValueLabel;
    QLabel *heightValueLabel;

};

#endif // DIETCARD_H
