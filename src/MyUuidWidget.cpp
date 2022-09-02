

#include "MyUuidWidget.h"

#include "ui_MyUuidWidget.h"

#include <QUuid>
#include <QListWidgetItem>
#include <QDebug>
#include <QMenu>
#include <QClipBoard>

#include <iostream>


MyUuidWidget::MyUuidWidget(QWidget* parent)
:
    QWidget(parent),
    ui(new Ui::MyUuidWidget)
{
    ui->setupUi(this);


    connect(ui->m_generatePushButton, SIGNAL(pressed()),
            this, SLOT(generate()));
            
    connect(ui->m_addToolButton, SIGNAL(pressed()),
            this, SLOT(add()));
            
    connect(ui->m_removeToolButton, SIGNAL(pressed()),
            this, SLOT(remove()));

    connect(ui->m_listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(listSelectionChanged()));
            
    connect(ui->m_lineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(lineSelectionChanged()));

    ui->m_uuidLabel->setStyleSheet("padding: 8px;");
    ui->m_lineEdit->setStyleSheet("padding: 8px;");
    ui->m_generatePushButton->setStyleSheet("padding: 17px;");
    ui->m_removeToolButton->setStyleSheet("padding: 12px;");
    ui->m_addToolButton->setStyleSheet("padding: 12px;");

    ui->m_addToolButton->setEnabled(false);
    ui->m_removeToolButton->setEnabled(false);


    // auto actInsert = new QAction("Insert", this);
    auto actCopy   = new QAction("Copy", this);
    auto actRemove = new QAction("Remove", this);

    // connect(actInsert, SIGNAL(triggered()), this, SLOT(insertItem()));
    connect(actCopy,   SIGNAL(triggered()), this, SLOT(copyItem()));
    connect(actRemove, SIGNAL(triggered()), this, SLOT(removeItem()));

    ui->m_listWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->m_listWidget->addActions({ actCopy, actRemove });
}

MyUuidWidget::~MyUuidWidget()
{
    delete ui;
}

void MyUuidWidget::generate() const
{
    QUuid uuid = QUuid::createUuid();
    QString uuidStr = uuid.toString();
    uuidStr = uuidStr.remove(QRegularExpression("[{}]"));
    uuidStr = uuidStr.toUpper();

    QStringList tokens = uuidStr.split(
        QString("-"), Qt::SkipEmptyParts);
    // for (int i = 0; i < tokens.size(); ++i)
    // {
    
    // }
    ui->m_lineEdit->setText(tokens[0] + " " +
                            tokens[1] + " " +
                            tokens[2] + " " +
                            tokens[3] + " " +
                            tokens[4]);

    
    ui->m_removeToolButton->setEnabled(false);
    ui->m_addToolButton->setEnabled(true);
}

void MyUuidWidget::add() const
{
    if (ui->m_lineEdit->text().isEmpty()) return;

    QListWidgetItem* item = new QListWidgetItem(
        ui->m_lineEdit->text());
    ui->m_listWidget->addItem(item);
    ui->m_lineEdit->clear();

    ui->m_removeToolButton->setEnabled(false);
    ui->m_addToolButton->setEnabled(false);
}

void MyUuidWidget::remove() const
{
    QList<QListWidgetItem*> selectedItemsList = ui->m_listWidget->selectedItems();
    if (selectedItemsList.empty()) return;

    qDeleteAll(ui->m_listWidget->selectedItems());

    if (ui->m_listWidget->count() == 0)
    {
        ui->m_removeToolButton->setEnabled(false);
    }
}

void MyUuidWidget::lineSelectionChanged() const
{
    if (ui->m_lineEdit->text().isEmpty())
    {
        ui->m_addToolButton->setEnabled(false);
    }
    else
    {
        ui->m_addToolButton->setEnabled(true);
    }
}

void MyUuidWidget::listSelectionChanged() const
{
    // if (ui->m_listWidget->count() &&
    if (ui->m_listWidget->selectedItems().size() >= 1)
    {
        ui->m_removeToolButton->setEnabled(true);
    }
    else
    {
        ui->m_removeToolButton->setEnabled(false);
    }
}

void MyUuidWidget::keyPressEvent(QKeyEvent* e)
{
    if(e->key() == Qt::Key_Escape)
    {
        switch(e->key())
        {
        case Qt::Key_Escape:
            close();
            break;
        default:
            QWidget::keyPressEvent(e);
        }
    }
    else
    {
        QWidget::keyPressEvent(e);
    }
}

void MyUuidWidget::copyItem()
{
    // QListWidgetItem* selectedItem = ui->m_listWidget->currentItem();
    QList<QListWidgetItem*> items = ui->m_listWidget->selectedItems();
    QString uuidString;
    
    foreach(QListWidgetItem* item, items)
    {
        uuidString.append(item->text() + "\n");
    }
    QClipboard* clipboard = QGuiApplication::clipboard();
    clipboard->setText(uuidString);
}

void MyUuidWidget::removeItem()
{
    QList<QListWidgetItem*> items = ui->m_listWidget->selectedItems();
    foreach(QListWidgetItem* item, items)
    {
        delete ui->m_listWidget->takeItem(ui->m_listWidget->row(item));
    }
}