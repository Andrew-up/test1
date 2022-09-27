#include "service/TreeGenerator.h"
using namespace std;

vector<tree::TreeObjectW*> generateParents(int countParents,int parentStartNameInt)
{
    int name =parentStartNameInt;
    vector<tree::TreeObjectW*> parents;

    for (int var = 0; var < countParents; ++var) {
        tree::TreeObjectW * iii= new tree::TreeObjectW();
        iii->set_objname(to_string(parentStartNameInt));
        parents.push_back(iii);
        parentStartNameInt++;
    }
    return parents;
}

vector<tree::TreeObjectW> * generateChilds(int id, string nameChild)
{
    vector<tree::TreeObjectW> * child = new vector<tree::TreeObjectW>();
    tree::TreeObjectW * iii = new tree::TreeObjectW();
    for (int var = 0; var < 10; ++var) {
        iii->set_objname(nameChild +"_"+to_string(var));
        child->push_back(*iii);
    }
    return child;
}
