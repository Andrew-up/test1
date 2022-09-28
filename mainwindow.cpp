#include "mainwindow.h"
#include <QMessageBox>
#include "./ui_mainwindow.h"
#include <string>
#include <QKeyEvent>

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




void MainWindow::addTreeElement(TreeObjectW * parent, int sizeTreeChild, int countRoot)
{
    QString rootName;
    rootName = QString::fromStdString(parent->objname());;
    QTreeWidgetItem * root = new QTreeWidgetItem(ui->treeWidget,QStringList(rootName));
    fillTreeBranch(sizeTreeChild,root,countRoot);
}

void MainWindow::fillTreeBranch(int size, QTreeWidgetItem * parent,int countRoot){

    QList<QTreeWidgetItem*> itemList;
    if(size>0){
        for (int var = 0; var < countRoot; ++var) {
            QTreeWidgetItem * child = new QTreeWidgetItem();
            child->setText(0, parent->text(0) +"" + QString::fromStdString(to_string(var)));
            itemList.append(child);
        }
    }
    if(size>0){
        for (int var = 0; var < itemList.size()-1; ++var) {
            fillTreeBranch(size-1,itemList.at(var),countRoot);
        }
        parent->addChildren(itemList);
        return  fillTreeBranch(size-1,itemList.last(),countRoot);
    }
}

void MainWindow::test(){

}

void MainWindow::findParent(QString findTextItem)
{
    QList<QTreeWidgetItem*> clist = ui->treeWidget->findItems(findTextItem, Qt::MatchExactly|Qt::MatchRecursive, 0);
    QTreeWidget * thisTreeWidget = ui->treeWidget_2;
    QTreeWidgetItem * item2;
    foreach(QTreeWidgetItem* item, clist)
    {
        while(item->parent()!=0){
            item2 = new QTreeWidgetItem();
            item2->setText(0,item->parent()->text(0));
            thisTreeWidget->addTopLevelItem(item2);
            item = item->parent();
        }
        thisTreeWidget->sortItems(0,Qt::DescendingOrder);
    }
}

void MainWindow::findChild(QString findItem)
{

    // qDebug() << "findNeighbor: "+findItem;
    QList<QTreeWidgetItem*> clist = ui->treeWidget->findItems(findItem, Qt::MatchExactly|Qt::MatchRecursive, 0);
    foreach(QTreeWidgetItem* item, clist)
    {
        QString rootName;
        QTreeWidget * thisTreeWidget = ui->treeWidget_4;
        QTreeWidgetItem * childsItem = new QTreeWidgetItem();
        childsItem->setText(0,clist.at(0)->text(0));
        for (int var = 0; var < clist.at(0)->childCount(); ++var) {
            QTreeWidgetItem * qt2 = new QTreeWidgetItem();
            rootName = QString::fromStdString(clist.at(0)->child(var)->text(0).toStdString());;
            qt2->setText(0, rootName);
            childsItem->addChild(qt2);
        }
        thisTreeWidget->addTopLevelItem(childsItem);
        thisTreeWidget->expandAll();
    }
}

void MainWindow::findNeighbor(QString findTextItem)
{

    QList<QTreeWidgetItem*> clist = ui->treeWidget->findItems(findTextItem, Qt::MatchExactly|Qt::MatchRecursive, 0);

    foreach(QTreeWidgetItem* item, clist)
    {
        QTreeWidget * thisTreeWidget= ui->treeWidget_3;
        QTreeWidgetItem * neighbor;
        if(item->parent()!=0){
            for (int var = 0; var < item->parent()->childCount(); ++var) {
                neighbor= new QTreeWidgetItem();
                neighbor->setText(0,item->parent()->child(var)->text(0));

                thisTreeWidget->addTopLevelItem(neighbor);
            }
            QList<QTreeWidgetItem*> deleteItem = thisTreeWidget->findItems(findTextItem, Qt::MatchExactly|Qt::MatchRecursive, 0);
            delete deleteItem.at(0);
        }

    }

}

void MainWindow::findAndOpenPath(QString findTextItem)
{
    QList<QTreeWidgetItem*> clist = ui->treeWidget->findItems(findTextItem, Qt::MatchExactly|Qt::MatchRecursive, 0);
    foreach(QTreeWidgetItem* item, clist)
    {
        bool isColor = false;
        while(item->parent()!=0){
            // qDebug() << "openParent "+ item->text(0);
            item->treeWidget()->expandItem(item);
            if(!isColor){
                  item->setBackground(0,Qt::gray);
                  isColor = true;
            }
            item = item->parent();
        }
        item->treeWidget()->expandItem(item);
    }
}





void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if(event->key()==Qt::Key_Alt){
        ui->treeWidget_2->clear();
        ui->treeWidget_3->clear();
        ui->treeWidget_4->clear();
        findParent(ui->lineEdit_2->text());
        findChild(ui->lineEdit_2->text());
        findNeighbor(ui->lineEdit_2->text());
        findAndOpenPath(ui->lineEdit_2->text());
    }

    if(event->key()==Qt::Key_Control){
        QString text =  ui->lineEdit->text();
        if(text=="0"){
            ui->treeWidget->clear();
            ui->label->setText("введен 0, очистка дерева");
            return;
        }
        if(text.toInt()){
            int number = text.toInt();
            if(number<0){
                ui->label->setText("Число не должно быть отрицательным");
                return;
            }
            if(number<=6){
                ui->treeWidget->clear();
                vector<TreeObjectW*> parents = generateParents(10,0);
                for (int var = 0; var < parents.size(); ++var) {
                    addTreeElement(parents.at(var), text.toInt(),10);
                }
                ui->label->setText("кол-во вложенностей: "+text);
            }
            else{
                ui->label->setText("Слишком много, максимум 6");
            }
        }
        else{
            ui->label->setText("Введите число");
        }
    }



}






