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
    std::map<unsigned int, DicItem*> currentList;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_clicked();
    void erase_not_wanted(const unsigned int i);

    void on_search_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
