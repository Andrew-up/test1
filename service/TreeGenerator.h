
//add this library
/*
 #include "service/TreeGenerator.h"
*/

#include "foo.pb.h"


tree::TreeObjectW treeObj(int idObj, std::string objName, tree::TreeObjectW * treeParent, std::vector<tree::TreeObjectW> * child);

std::vector<tree::TreeObjectW*> generateParents(int countParents,int parentNameInt);

std::vector<tree::TreeObjectW> * generateChilds(int id, std::string nameChild);
