#ifndef TEST_H
#define TEST_H

#include <QObject>

class test : public QObject
{
    Q_OBJECT
public:
    int age;
    explicit test(QObject *parent = nullptr);

signals:

};

#endif // TEST_H
