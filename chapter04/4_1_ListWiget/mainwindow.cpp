#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 按钮与action关联
    ui->tBtnListIni->setDefaultAction(ui->actListlni);
    ui->tBtnListInsert->setDefaultAction(ui->actListInsert);
    ui->tBtnListAppend->setDefaultAction(ui->actListAppend);
    ui->tBtnListDelete->setDefaultAction(ui->actListDelete);
    ui->tBtnListClear->setDefaultAction(ui->actListClear);

    ui->tBtnSelALL->setDefaultAction(ui->actSelAll);
    ui->tBtnSelNone->setDefaultAction(ui->actSelNone);
    ui->tBtnSelInvs->setDefaultAction(ui->actSelInvs);

    QMenu *menuSelection = new QMenu(this);
    menuSelection->addAction(ui->actSelAll);
    menuSelection->addAction(ui->actSelNone);
    menuSelection->addAction(ui->actSelInvs);

    ui->tBtnSelectItem->setPopupMode(QToolButton::MenuButtonPopup); // 下拉式菜单
    ui->tBtnSelectItem->setMenu(menuSelection);

    QToolButton *aBtn = new QToolButton(this);
    aBtn->setPopupMode(QToolButton::InstantPopup); // 下拉式菜单
    aBtn->setText("选择选项");
    aBtn->setIcon(QIcon(":/images/icons/424.bmp"));
    aBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    aBtn->setMenu(menuSelection);
    ui->toolBar->addWidget(aBtn);

    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actQuit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actListlni_triggered()
{
    QListWidgetItem *aItem;
    ui->listWidget->clear();
    QIcon aIcon;
    aIcon.addFile(":/images/icons/check2.ico");
    bool chk = ui->chkBoxEditable->isCheckable();
    for (int i = 0; i < 10; i++)
    {
        aItem = new QListWidgetItem();
        aItem->setText("Item" + QString::number(i));
        aItem->setIcon(aIcon);
        aItem->setCheckState(Qt::Checked);

        if (chk)
            aItem->setFlags(Qt::ItemIsEditable|Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        else
            aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);

        ui->listWidget->addItem(aItem);
    }
}


void MainWindow::on_actListInsert_triggered()
{
    QListWidgetItem *aItem;
    QIcon aIcon(":/images/icons/check2.ico");
    bool chk = ui->chkBoxEditable->isCheckable();

    aItem = new QListWidgetItem();
    aItem->setText("Item Inserted");
    aItem->setIcon(aIcon);
    aItem->setCheckState(Qt::Checked);

    if (chk)
        aItem->setFlags(Qt::ItemIsEditable|Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
    else
        aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);

    ui->listWidget->insertItem(ui->listWidget->currentRow(), aItem);

}


void MainWindow::on_actListAppend_triggered()
{
    QListWidgetItem *aItem;
    QIcon aIcon(":/images/icons/check2.ico");
    bool chk = ui->chkBoxEditable->isCheckable();

    aItem = new QListWidgetItem();
    aItem->setText("Item added");
    aItem->setIcon(aIcon);
    aItem->setCheckState(Qt::Checked);

    if (chk)
        aItem->setFlags(Qt::ItemIsEditable|Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
    else
        aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);

    ui->listWidget->addItem(aItem);
}


void MainWindow::on_actListDelete_triggered()
{
    int row = ui->listWidget->currentRow();
    delete ui->listWidget->takeItem(row);
}


void MainWindow::on_actListClear_triggered()
{
    ui->listWidget->clear();
}


void MainWindow::on_actSelAll_triggered()
{
    int cnt = ui->listWidget->count();
    for (int i = 0; i < cnt; i++)
    {
        QListWidgetItem *aItem = ui->listWidget->item(i);
        aItem->setCheckState(Qt::Checked);
    }
}


void MainWindow::on_actSelNone_triggered()
{
    int cnt = ui->listWidget->count();
    for (int i = 0; i < cnt; i++)
    {
        QListWidgetItem *aItem = ui->listWidget->item(i);
        aItem->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_actSelInvs_triggered()
{
    int cnt = ui->listWidget->count();
    for (int i = 0; i < cnt; i++)
    {
        QListWidgetItem *aItem = ui->listWidget->item(i);
        if (aItem->checkState() == Qt::Checked)
            aItem->setCheckState(Qt::Unchecked);
        else
             aItem->setCheckState(Qt::Checked);

    }
}


void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    QString str;
    if (current != NULL)
    {

        if (previous == NULL)
            str = "当前项：" + current->text();
        else
            str = "前一项：" + previous->text()+";当前项:"+current->text();
         ui->editCutItemTet->setText(str);
    }

    ui->plainTextEdit->appendPlainText("currentItemChanged()信号被发射");

}


void MainWindow::on_checkBox_clicked(bool checked)
{
    ui->listWidget->setSortingEnabled(checked); // 是否允许排序
}


void MainWindow::on_tBtnSortAsc_clicked()
{
    ui->listWidget->sortItems(Qt::AscendingOrder); // 升序排序
}


void MainWindow::on_tBtnSortDes_clicked()
{
    ui->listWidget->sortItems(Qt::DescendingOrder); // 降序排序
}


void MainWindow::on_tBtnClearText_clicked()
{
    ui->plainTextEdit->clear();
}


void MainWindow::on_tBtnAddLine_clicked()
{
    ui->plainTextEdit->appendPlainText("");
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->plainTextEdit->appendPlainText("itemClicked信号被发射，"+item->text());
}




void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    QMenu *menuList = new QMenu();
    menuList->addAction(ui->actListlni);
    menuList->addAction(ui->actListClear);
    menuList->addAction(ui->actListInsert);
    menuList->addAction(ui->actListAppend);
    menuList->addAction(ui->actListDelete);
    menuList->addSeparator();
    menuList->addAction(ui->actSelAll);
    menuList->addAction(ui->actSelNone);
    menuList->addAction(ui->actSelInvs);
    menuList->exec(QCursor::pos());
    delete menuList;
}

