#include "searchresult.h"
#include "ui_searchresult.h"

SearchResult::SearchResult(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SearchResult)
{
    ui->setupUi(this);
}

SearchResult::SearchResult(const QList<DicItem*>* list): dicList(list)
{
    ui->setupUi(this);
    ui->centralwidget->layout()->setAlignment(Qt::AlignTop);
}

SearchResult::~SearchResult()
{
    delete ui;
}
