#include "mainwindow.h"
#include "foo.pb.h"
#include <QApplication>
#include <QLabel>
#include <string>
#include "main.h"
#include <iostream>
using namespace tree;
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    for (int i = 0; i < 1; ++i) {
        TreeObjectW * parent = generateParent(i, to_string(i));
        vector<TreeObjectW> * child = generateChilds(i, to_string(i));;
       w.addTreeElement(parent, child,child->size());
//        w.addChildForRoot(&listTreeObjectW->at(0));
    }

    w.show();
    return a.exec();
}


TreeObjectW * generateParent(int idParent, string nameParent)
{
    TreeObjectW * parent = new TreeObjectW();
    parent->set_id(idParent);
    parent->set_objname(nameParent);
    return parent;
}

vector<TreeObjectW> * generateChilds(int id, string nameChild)
{
    vector<TreeObjectW> * child = new vector<TreeObjectW>();
    TreeObjectW * iii = new TreeObjectW();
    for (int var = 0; var < 10; ++var) {
        iii->set_objname(nameChild +"_"+to_string(var));
        child->push_back(*iii);
    }
    return child;
}
