#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtSql>

#include "savemanager.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    qmlRegisterType<savemanager>("com.example.save",1,0,"Crudmanager");
    QSqlDatabase m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("C:/Users/manoj/OneDrive/Desktop/contact_db.db");


    if(!m_database.open()){
        qDebug()<<"Failed to open Database";

    }



    QSqlQuery query;
    if(query.exec("CREATE TABLE IF NOT EXISTS user(name TEXT, mobno TEXT"))
    {
        qDebug()<<"Failed to Create Table!";
        return -1;
    }


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
