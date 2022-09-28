#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "qtreewidget.h"
#include <QMainWindow>
#include <QKeyEvent>
#include "service/TreeGenerator.h"

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
    void addTreeElement(TreeObjectW * parent,int sizeChild,int countRoot);
    void fillTreeBranch(int n, QTreeWidgetItem * item,int countRoot);
    void findParent(QString findTextItem);
    void findChild(QString findItem);
    void findNeighbor(QString findTextItem);
    void findAndOpenPath(QString findTextItem);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;







};
#endif // MAINWINDOW_H
