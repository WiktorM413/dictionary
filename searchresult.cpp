#include "searchresult.h"
#include "ui_searchresult.h"

#include "mainwindow.h"

SearchResult::SearchResult(QList<DicItem*>* list, QMainWindow* ths ,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SearchResult)
{
    ui->setupUi(this);
    dicList = new QList<DicItem*>();

    for (int i = 0; i < list->length(); i++)
    {
        dicList->push_back(list->at(i)->copy());
        connect(dicList->at(dicList->length() - 1), &DicItem::objectDeleted, ths, &MainWindow::erase_not_wanted);
    }

    for (int i = 0; i < dicList->length(); i++)
    {
        ui->result->addWidget(static_cast<QWidget*>(*dicList->at(i)));
    }
}

SearchResult::~SearchResult()
{
    delete ui;
}
