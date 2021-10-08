


#ifndef MYUUIDWIDGET_H
#define MYUUIDWIDGET_H

#include <QWidget>

namespace Ui
{
    class MyUuidWidget;
}

class MyUuidWidget : public QWidget
{
    Q_OBJECT

public:

    MyUuidWidget(QWidget* parent=0);
    virtual ~MyUuidWidget();

public slots:

    void generate() const;
    void add() const;
    void remove() const;

    void lineSelectionChanged() const;
    void listSelectionChanged() const;

private:

    Ui::MyUuidWidget* ui;
};

#endif // MYUUIDWIDGET_H