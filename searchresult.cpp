#include "searchresult.h"
#include "ui_searchresult.h"

SearchResult::SearchResult(QList<DicItem*>* list, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SearchResult)
{
    ui->setupUi(this);
    dicList = new QList<DicItem*>();

    for (int i = 0; i < list->length(); i++)
    {
        dicList->push_back(list->at(i)->copy());
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
