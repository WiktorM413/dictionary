#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "dicitem.h"
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::map<unsigned int, DicItem*> items;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void erase_not_wanted(const unsigned int i);

private slots:
    void on_add_clicked();

    void on_search_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
