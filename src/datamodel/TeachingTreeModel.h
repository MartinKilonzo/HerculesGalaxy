#ifndef TEACHINGTREEMODEL_H
#define TEACHINGTREEMODEL_H

#include "datamodel/TreeModel.h"

class TeachingTreeModel : public TreeModel
{
public:
    TeachingTreeModel(RecordsManager*, QObject *parent=0);
    ~TeachingTreeModel();
    void setupModel(int start, int end, std::vector<std::string> sortFields, char filterStart, char filterEnd, std::vector<std::string> filterNames);
};

#endif // TEACHINGTREEMODEL_H
