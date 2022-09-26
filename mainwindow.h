#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "foo.pb.h"
#include "qtreewidget.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
using namespace tree;
using namespace std;

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void test(std::string editText);
    vector<QTreeWidgetItem> * addTreeElement(TreeObjectW * parent, vector<TreeObjectW> * childs,int sizeChild);
    void addChildForRoot(QTreeWidgetItem *parent);
private:
    Ui::MainWindow *ui;




};
#endif // MAINWINDOW_H