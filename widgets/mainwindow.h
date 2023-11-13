#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

/**
 * @class MainWindow
 * @brief Represents the main window of the application.
 * @inherits QWidget
 *
 * The MainWindow class is a QWidget representing the main window of the application.
 */
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for the MainWindow class.
     * @param parent A pointer to the parent widget (default is nullptr).
     */
    explicit MainWindow(QWidget *parent = nullptr);
};


#endif // MAINWINDOW_H
