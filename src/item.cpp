#include "item.h"

using namespace std;

Item::Item() {}

Item::Item(int iID, list<Brick> bList) {
    itemID = iID;
    bricks = bList;
}

int Item::getItemID() {
    return this->itemID;
}

list<Brick> Item::getBricks() {
    return this->bricks;
}