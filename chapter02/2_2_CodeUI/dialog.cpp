#include "dialog.h"
#include "ui_dialog.h"
#include <QHBoxLayout>
#include <QPalette>

void Dialog::do_chkBoxUnder(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void Dialog::do_setFontColor()
{
    QPalette plet = txtEdit->palette(); // 获取调色板
    if (radioBlack->isChecked())
        plet.setColor(QPalette::Text, Qt::black);
    if (radioBlue->isChecked())
        plet.setColor(QPalette::Text, Qt::blue);
    if (radioRed->isChecked())
        plet.setColor(QPalette::Text, Qt::red);
    txtEdit->setPalette(plet);
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    chkBoxUnder = new QCheckBox("下划线");
    chkBoxItalic = new QCheckBox("斜体");
    chkBoxBold = new QCheckBox("加粗");
    QHBoxLayout *HLayl = new QHBoxLayout();
    HLayl->addWidget(chkBoxUnder);
    HLayl->addWidget(chkBoxItalic);
    HLayl->addWidget(chkBoxBold);

    radioBlack = new QRadioButton("黑色");
    radioBlue = new QRadioButton("蓝色");
    radioRed = new QRadioButton("红色");
    QHBoxLayout *HLayl2 = new QHBoxLayout();
    HLayl2->addWidget(radioBlack);
    HLayl2->addWidget(radioBlue);
    HLayl2->addWidget(radioRed);

    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hello world\n 手工创建！");
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    btnOk = new QPushButton("确定");
    btnCancel = new QPushButton("取消");
    btnClose = new QPushButton("退出");
    QHBoxLayout *HLayl3 = new QHBoxLayout();
    HLayl3->addStretch();
    HLayl3->addWidget(btnOk);
    HLayl3->addStretch();
    HLayl3->addWidget(btnCancel);
    HLayl3->addWidget(btnClose);


    QVBoxLayout *Vlayl = new QVBoxLayout();
    Vlayl->addLayout(HLayl);
    Vlayl->addLayout(HLayl2);
    Vlayl->addWidget(txtEdit);
    Vlayl->addLayout(HLayl3);

    setLayout(Vlayl);
    this->setGeometry(300, 60, 360, 530);

    connect(chkBoxUnder, SIGNAL(clicked(bool)), this, SLOT(do_chkBoxUnder(bool)));
    connect(chkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(do_chkBoxItalic(bool)));
    connect(chkBoxBold, SIGNAL(clicked(bool)), this, SLOT(do_chkBoxBold(bool)));

    connect(radioBlack, SIGNAL(clicked(bool)), this, SLOT(do_setFontColor()));
    connect(radioRed, SIGNAL(clicked(bool)), this, SLOT(do_setFontColor()));
    connect(radioBlue, SIGNAL(clicked(bool)), this, SLOT(do_setFontColor()));

    connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));

    setWindowTitle("手工打造UI");
}

Dialog::~Dialog()
{
    delete ui;
}
