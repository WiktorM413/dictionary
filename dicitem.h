#ifndef DICITEM_H
#define DICITEM_H


#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class DicItem: public QObject
{
    Q_OBJECT

private:
    static unsigned int preIndex;
    unsigned int index;
    QLabel* original;
    QLabel* translation;

public:
    QPushButton* erase;

    DicItem(QString original, QString translation);
    DicItem(QWidget* line);
    ~DicItem();
    explicit operator QWidget*();
    unsigned int getIndex();
    QLabel* getOriginal();
    QLabel* getTranslation();
    DicItem* copy();

signals:
    void objectDeleted(const unsigned int i);
};
#endif // DICITEM_H
