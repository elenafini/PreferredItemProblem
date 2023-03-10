#include "masterData.h"

using namespace std;

MasterData::MasterData(int iID, float p, enum STATUS s) {
    itemID = iID;
    price = p;
    status = s;
};

int MasterData::getItemID() {
    return this->itemID;
};

float MasterData::getPrice() {
    return this->price;
};

STATUS MasterData::getStatus() {
    return this->status;
};