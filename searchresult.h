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
    const QList<DicItem*>* dicList;

public:
    SearchResult(const QList<DicItem*>* list);
    explicit SearchResult(QWidget *parent = nullptr);
    ~SearchResult();

private:
    Ui::SearchResult *ui;
};

#endif // SEARCHRESULT_H
