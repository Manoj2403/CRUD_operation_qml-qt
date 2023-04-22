#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <QObject>
#include <QWidget>
#include <QtSql>
#include<QFile>
#include<QDebug>


class savemanager : public QObject
{
    Q_OBJECT
public:
    explicit savemanager(QObject *parent = nullptr);

signals:


public slots:
    bool save(QString text1,QString text2);
    bool read(QString text1);
    bool remove(QString text1);
    bool update(QString text1,QString text2);
private:
    QSqlDatabase m_database;
};

#endif // SAVEMANAGER_H
