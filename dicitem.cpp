#include "dicitem.h"

#include <QWidget>
#include <QHBoxLayout>

unsigned int DicItem::preIndex = 0;

DicItem::DicItem(QString original, QString translation)
{
    index = preIndex++;
    qDebug() << index << Qt::endl;
    this->original = new QLabel();
    this->translation = new QLabel();
    this->erase = new QPushButton();

    this->original->setText(original);
    this->translation->setText(translation);
    this->erase->setText("delete");

    connect(erase, &QPushButton::clicked, [this]() {
        delete this;
    });

}
DicItem::~DicItem()
{
    emit objectDeleted(index);
    delete original;
    delete translation;
    delete erase;
}

DicItem::operator QWidget *()
{
    QWidget * line = new QWidget();

    // setting line as parent
    erase->setParent(line);
    erase->setText("delete");
    original->setParent(line);
    translation->setParent(line);

    QHBoxLayout *lineLayout = new QHBoxLayout();

    //creating the layout
    lineLayout->addWidget(original);
    lineLayout->addWidget(translation);
    lineLayout->addWidget(erase);
    line->setLayout(lineLayout);

    return line;
}

unsigned int DicItem::getIndex()
{
    return index;
}

