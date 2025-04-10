#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <QMainWindow>
#include "dicitem.h"

namespace Ui {
class SearchResult;
}

class SearchResult : public QMainWindow
{
    Q_OBJECT
private:
    QList<DicItem*>* dicList;

public:
    explicit SearchResult(QList<DicItem*>* list, QWidget *parent = nullptr);
    ~SearchResult();

private:
    Ui::SearchResult *ui;
};

#endif // SEARCHRESULT_H
