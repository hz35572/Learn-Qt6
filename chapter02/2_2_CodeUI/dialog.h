#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
private:
    // 字体选择按钮
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;

    // 颜色选择按钮
    QRadioButton *radioBlack;
    QRadioButton *radioRed;
    QRadioButton *radioBlue;

    QPlainTextEdit *txtEdit;

    QPushButton *btnOk;
    QPushButton *btnCancel;
    QPushButton *btnClose;

private slots:
    void do_chkBoxUnder(bool checked);
    void do_chkBoxItalic(bool checked);
    void do_chkBoxBold(bool checked);
    void do_setFontColor();

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
