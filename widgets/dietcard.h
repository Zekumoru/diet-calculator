#ifndef DIETCARD_H
#define DIETCARD_H

#include <QWidget>

class Diet;

class DietCard : public QWidget
{
    Q_OBJECT
public:
    explicit DietCard(Diet diet, QWidget *parent = nullptr);

private:


};

#endif // DIETCARD_H
