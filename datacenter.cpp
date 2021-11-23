#include "datacenter.h"
#include <QFile>
#include <QStringList>
#include <QList>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

DataCenter::DataCenter(QObject *parent) :
    QObject(parent)
{
    QString fileName = "data.json";

    QFile fileRead(fileName);
    if(!fileRead.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "cannot open file for reading: " << fileName;
        return;
    }
    m_json = QJsonDocument::fromJson(fileRead.readAll());

    QJsonArray arr = m_json.array();
    for(int i = 0, n = arr.size(); i < n; ++i)
        m_data.append(CellData());
    for(int i = 0, n = arr.size(); i < n; ++i) {
        QJsonObject obj = arr[i].toObject();
        QJsonArray time = obj["time"].toArray();
        QStringList timeStamps;
        for(int j = 0, nj = time.size(); j < nj; ++j)
            timeStamps.append(time[j].toString());

        int id = obj["id"].toInt();
        QString name = obj["name"].toString();
        int count = obj["count"].toInt();
        m_data[id] = CellData{name, count, timeStamps};
    }
    fileRead.close();
}

QList<CellData> DataCenter::data() const
{
    return m_data;
}

void DataCenter::setData(const QList<CellData> &data)
{
    m_data = data;
}

void DataCenter::save()
{
    QString fileName = "data.json";

    QFile fileWrite(fileName);
    if(!fileWrite.open(QFile::WriteOnly | QFile::Truncate)) {
        qDebug() << "cannot open file for writing: " << fileName;
        return;
    }
    QJsonArray content;
    for(int i = 0, n = m_data.size(); i < n; ++i) {
        QJsonObject obj;
        obj["id"] = QJsonValue::fromVariant(i);
        obj["name"] = QJsonValue::fromVariant(m_data[i].name);
        obj["count"] = QJsonValue::fromVariant(m_data[i].count);
        obj["time"] = QJsonValue::fromVariant(m_data[i].timeStamps);
        content.append(obj);
    }

    QJsonDocument result;
    result.setArray(content);
    fileWrite.write(result.toJson());
    fileWrite.close();
}
