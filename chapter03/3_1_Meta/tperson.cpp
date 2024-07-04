#include "tperson.h"
#include <QDebug>

TPerson::TPerson(QString name, QObject *parent)
    : QObject{parent}, m_name{name}
{
}

TPerson::~TPerson()
{
    qDebug()<<"TPerson类对象被删除";
}

int TPerson::age()
{
    return m_age;
}

void TPerson::setAge(quint8 ageValue)
{ // 设置age
    if (m_age != ageValue)
    {
        this->m_age = ageValue;
        emit ageChanged(this->m_age); // 发射信号
    }

}

void TPerson::incAge()
{
    this->m_age++;
    emit ageChanged(this->m_age);
}
