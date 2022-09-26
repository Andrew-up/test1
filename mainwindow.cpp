#include "mainwindow.h"
#include <QMessageBox>
#include "./ui_mainwindow.h"
#include <string>
#include "foo.pb.h"
using namespace tree;
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test(std::string editText)
{

    ui->label->setText(editText.c_str());

}



void MainWindow::addTreeElement(TreeObjectW * parent, vector<TreeObjectW> * childs, int sizeChild)
{


    QString rootName;
    QString childName;
    rootName = QString::fromStdString(parent->objname());;
    QTreeWidgetItem * item;

    item = new QTreeWidgetItem(ui->treeWidget,QStringList(rootName));
    item->setExpanded(true);

    {

        //    for(int i = 0; i < sizeChild; ++i){
        //        childName = QString::fromStdString(childs->at(i).objname());;
        //        QTreeWidgetItem * newitem = new QTreeWidgetItem(item,QStringList(childName));
        //        newitem->addChild(item);

        //            for (int var = 0; var < 10; ++var) {
        //                jhjgsjhfsd = addChildForRoot(newitem, "childName: " + to_string(var));
        //                for (int var = 0; var < 10; ++var) {
        //                    QTreeWidgetItem * jhfdvjhdgj =  addChildForRoot(jhjgsjhfsd, "childName: " + to_string(var));

        //                    for (int var = 0; var < 10; ++var) {
        //                        addChildForRoot(jhfdvjhdgj, "childName: " + to_string(var));
        //                    }
        //                }
        //            }

    }

    childName = QString::fromStdString(parent->objname());
    vector<QTreeWidgetItem> child1 = addChildForRoot(item, childName);

    for (int var = 0; var < child1.size(); ++var) {
        addChildForRoot(&child1.at(var), childName);
    }


}



vector<QTreeWidgetItem> MainWindow::addChildForRoot(QTreeWidgetItem *parent, QString name)
{
    //  QString childName;
    // childName = QString::fromStdString(name);

    vector<QTreeWidgetItem> item;
    for (int var = 0; var < 10; ++var) {
        QTreeWidgetItem * item2 = new QTreeWidgetItem();
        item2->setText(0,name+"-"+QString::fromStdString(to_string(var)));
        parent->setExpanded(true);
        parent->addChild(item2);
        item.push_back(*item2);
    }


    //addTreeElement();

    return item;

}



























































