#ifndef BYTERCONVER_H
#define BYTERCONVER_H

#include <QDialog>
class QLineEdit;
class ByterConver : public QDialog
{
    Q_OBJECT

public:
    ByterConver(QWidget *parent = nullptr);
    ~ByterConver();
private:
    QLineEdit *decEdit;
    QLineEdit *hexEdit;
    QLineEdit *binEdit;
private slots:
    void decChanged(const QString&);
    void hexChanged(const QString&);
    void binChanged(const QString&);
};

#endif // BYTERCONVER_H
