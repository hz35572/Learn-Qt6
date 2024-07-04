#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText("你好！");
    ui->btnClose->setText("关闭");
}

Widget::~Widget()
{
    delete ui;
}
