#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dictionary->setAlignment(Qt::AlignTop);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_clicked()
{
    if (ui->original->text().isEmpty() || ui->translation->text().isEmpty())
    {
        return;
    }

    DicItem *item = new DicItem(ui->original->text(), ui->translation->text());
    items[item->getIndex()] = item;

    ui->dictionary->insertWidget(items.size(), static_cast<QWidget*>(*item));
    connect(item, &DicItem::objectDeleted, this, &MainWindow::erase_not_wanted);

    ui->original->setText("");
    ui->translation->setText("");
}




// slots
void MainWindow::erase_not_wanted(const unsigned int i)
{
    ui->dictionary->removeWidget(static_cast<QWidget*>(*items.at(i)));
    items.erase(i);

    qDebug() << "item of" << i << "index deleted" << Qt::endl;

}


void MainWindow::on_search_clicked()
{
    if (ui->searchInput->text().isEmpty())
    {
        currentList = items;
        return;
    }

    QList<DicItem*> dicList;
    for (auto& item : items)
    {
        if (item.second->getOriginal()->text().contains(ui->searchInput->text()) ||
            item.second->getTranslation()->text().contains(ui->searchInput->text()))
        {
            dicList.push_back(item.second);
            qDebug() << item.second->getTranslation()->text();
        }
    }

}

