#include "byterconver.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

ByterConver::ByterConver(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *mainLayout= new QVBoxLayout(this);
    QGridLayout *editLayout= new QGridLayout;
    QHBoxLayout *buttonlayout= new QHBoxLayout;
    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonlayout);
    QLabel *declabel=new QLabel(tr("十進位"));
    QLabel *hexlabel=new QLabel(tr("十六進位"));
    QLabel *binlabel=new QLabel(tr("二進位"));
    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;
    editLayout->addWidget (declabel,0,0);
    editLayout->addWidget(decEdit,0,1);
    editLayout->addWidget ( hexlabel,1,0);
    editLayout->addWidget (hexEdit,1,1);
    editLayout->addWidget (binlabel,2,0);
    editLayout->addWidget (binEdit,2,1);
    QPushButton* exitButton=new QPushButton("exit");
    buttonlayout->addStretch();\
    buttonlayout->addWidget(exitButton);
    connect(exitButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(decEdit,SIGNAL(textChanged(const QString&)),this,SLOT(decChanged(const QString&)));
    connect(hexEdit,SIGNAL(textChanged(const QString&)),this,SLOT(hexChanged(const QString&)));
    connect(binEdit,SIGNAL(textChanged(const QString&)),this,SLOT(binChanged(const QString&)));

}
void ByterConver::decChanged(const QString&  newValue) {
    bool ok;
    int num=newValue.toInt(&ok);
    if(ok){
        hexEdit->setText(QString::number(num,16));
        binEdit->setText(QString::number(num,2));
    }else{
        hexEdit->setText("");
        binEdit->setText("");
    }
}
void ByterConver::hexChanged(const QString&  newValue) {
    bool ok;
    int num=newValue.toInt(&ok,16);
    if(ok){
        decEdit->setText(QString::number(num,10));
        binEdit->setText(QString::number(num,2));
    }else{
        decEdit->setText("");
        binEdit->setText("");
    }
}
void ByterConver::binChanged(const QString&  newValue) {
    bool ok;
    int num=newValue.toInt(&ok,2);
    if(ok){
        hexEdit->setText(QString::number(num,16));
        decEdit->setText(QString::number(num,10));
    }else{
        hexEdit->setText("");
        decEdit->setText("");
    }
}
ByterConver::~ByterConver() {}
