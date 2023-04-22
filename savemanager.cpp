#include "savemanager.h"

#include <QMessageBox>

QString word = "";
savemanager::savemanager(QObject *parent) : QObject(parent)
{

}

//function for saving the data to database

bool savemanager::save(QString text1, QString text2)
{
    QSqlQuery query1;
    query1.prepare("INSERT INTO user ("
                   "name,"
                   "mobno)"
                   "VALUES(?,?);");
    query1.addBindValue(text1);
    query1.addBindValue(text2);
    if(query1.exec()){
        qDebug()<<"Inserted Successfully";
        return true;
    }
    else{
        qDebug()<<"Failed";
        return false;
    }
}

//function for reading the data from database

bool savemanager::read(QString text1)
{
    QSqlQuery query2;
    query2.prepare("SELECT * FROM user WHERE name ='"+text1+"'");
    if(query2.exec()){
        while(query2.next()){
            qDebug()<<"Retreived data Successfully";
            qDebug()<<query2.value(0);
            qDebug()<<query2.value(1);
        }
        return true;
    }
    else{
        qDebug()<<"Failed";
        return false;
    }
}

//function for deleting the data from database
bool savemanager::remove(QString text1)
{
       QSqlQuery query3;
       query3.prepare("DELETE FROM user WHERE name = '"+text1+"' AND name == '"+text1+"'");
       query3.bindValue(":name",text1);


       if(query3.exec() && query3.numRowsAffected()>0){
           qDebug() <<"Contact Deleted";
           return true;
       } else {
           return false;
       }
       return true;

}

bool savemanager::update(QString text1,QString text2)
{
    QSqlQuery query4;
    query4.prepare("UPDATE user SET name = '"+text2+"' WHERE name ='"+text1+"'");
    if(query4.exec()){
        qDebug()<<"Updated Successfully";
        return true;
    }
    else{
        qDebug()<<"Failed";
        return false;
    }
}

//MANOJ KUMAR V
