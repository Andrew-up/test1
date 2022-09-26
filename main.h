#ifndef MAIN_H
#define MAIN_H
#include "foo.pb.h"
#include <list>
#include <string>
using namespace std;
using namespace tree;

TreeObjectW treeObj(int idObj, string objName, TreeObjectW * treeParent, vector<TreeObjectW> * child);

TreeObjectW * generateParent(int id, string nameParent);

vector<TreeObjectW> * generateChilds(int id, string nameChild);

//TreeObjectW treeObj(int id, string objName, objTest * treeParent, vector<objTest> * treeChild);

//objTest resultArray(int id, string objName);

#endif // MAIN_H
