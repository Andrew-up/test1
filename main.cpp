#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <string>
#include <iostream>

using namespace std;

int  sizeTreeChild = 3;

int  countRoot = 10;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    vector<TreeObjectW*> parents = generateParents(countRoot,0);

    for (int var = 0; var < parents.size(); ++var) {
         w.addTreeElement(parents.at(var), sizeTreeChild,countRoot);
    }


   // GenerateObj(&w);
    w.show();
    return a.exec();
}

void GenerateObj(MainWindow * w){
    w->test();
}

