#include "database/RecordsManager.h"
#include "datamodel/TreeItem.h"
#include "datamodel/GrantFundingTreeModel.h"

GrantFundingTreeModel::GrantFundingTreeModel(RecordsManager* db, QObject *parent) :
TreeModel(db, parent) {
}

GrantFundingTreeModel::~GrantFundingTreeModel() {
}

void GrantFundingTreeModel::setupModel(int yearStart, int yearEnd, std::vector<std::string> sortFields, char filterStart, char filterEnd, std::vector<std::string> filterNames) {
    rootItem = new TreeItem(dataObj->createHeadersListForGrants(sortFields[0]));
    setupModelData(dataObj->createQStringForGrants(yearStart, yearEnd, sortFields, filterStart,  filterEnd, filterNames).split(QString("\n")), rootItem);
}
