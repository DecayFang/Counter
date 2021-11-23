#ifndef DATACENTER_H
#define DATACENTER_H

#include <QObject>
#include <QList>
#include <QJsonDocument>

class QStringList;
class QString;

struct CellData {
    QString name;
    int count;
    QStringList timeStamps; // later time at the back.
};

class DataCenter : public QObject
{
    Q_OBJECT

public:
    explicit DataCenter(QObject *parent = nullptr);

    QList<CellData> data() const;
    void setData(const QList<CellData> &data);

    void save(int maxTimeStamp = 100);

private:
    QJsonDocument m_json;
    QList<CellData> m_data;

};

#endif // DATACENTER_H
