#ifndef TPERSON_H
#define TPERSON_H

#include <QObject>

class TPerson : public QObject
{
    Q_OBJECT

    Q_CLASSINFO("author", "He") // 定义附加类信息
    Q_CLASSINFO("company", "UPC")
    Q_CLASSINFO("version", "2.0.0")

    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged) //定义属性age
    Q_PROPERTY(QString name MEMBER m_name) //定义属性name
    Q_PROPERTY(int score MEMBER m_score) // 定义属性score
public:
    explicit TPerson(QString name, QObject *parent = nullptr);
    ~TPerson();
    int age();
    void setAge(quint8 ageValue);
    void incAge();

signals:
    void ageChanged(int value); // 自定义信号
private:
    QString m_name;
    quint8 m_age = 10;
    quint8 m_score = 79;
};

#endif // TPERSON_H
