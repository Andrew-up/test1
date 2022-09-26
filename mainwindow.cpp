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



vector<QTreeWidgetItem> * MainWindow::addTreeElement(TreeObjectW * parent, vector<TreeObjectW> * childs, int sizeChild)
{

    vector<QTreeWidgetItem> * listItem = new vector<QTreeWidgetItem>;
    QString rootName;
    QString childName;
    rootName = QString::fromStdString(parent->objname());;
    QTreeWidgetItem * item;
    item = new QTreeWidgetItem(ui->treeWidget,QStringList(rootName));

    for(int i = 0; i < sizeChild; ++i){
        childName = QString::fromStdString(childs->at(i).objname());;
        QTreeWidgetItem* newitem = new QTreeWidgetItem(item,QStringList(childName));
        listItem->push_back(*newitem);
        newitem->addChild(item);
    }

    return listItem;

}

void MainWindow::addChildForRoot(QTreeWidgetItem *parent)
{

    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0,"name");
    parent->addChild(item);
}


