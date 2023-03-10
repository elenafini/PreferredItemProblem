#include "serviceFunctions.h"

using namespace std;

Brick ServiceFunctions::brick1 = Brick(1, {30});
Brick ServiceFunctions::brick2 = Brick(4, {30, 40});

list<Item> ServiceFunctions::ItemService() {
    list<Item> returnList;
    returnList.push_back(Item(1, {brick1}));
    returnList.push_back(Item(2, {brick1}));
    returnList.push_back(Item(3, {brick1}));
    returnList.push_back(Item(4, {brick1, brick1}));
    returnList.push_back(Item(5, {brick1, brick1, brick2}));
    returnList.push_back(Item(6, {brick1, brick2, brick2}));
    returnList.push_back(Item(7, {brick1, brick1}));
    returnList.push_back(Item(8, {brick1, brick1}));
    returnList.push_back(Item(9, {brick1, brick1, brick2}));
    returnList.push_back(Item(10, {brick2, brick1, brick1}));
    returnList.push_back(Item(11, {brick2}));
    returnList.push_back(Item(12, {brick1}));

    return returnList;
}

list<MasterData> ServiceFunctions::MasterDataService() {
    list<MasterData> returnList;
    returnList.push_back(MasterData(1, 8.0, Normal));
    returnList.push_back(MasterData(2, 6.0, Normal));
    returnList.push_back(MasterData(3, 3.0, Outgoing));
    returnList.push_back(MasterData(4, 8.0, Outgoing));
    returnList.push_back(MasterData(5, 1.0, Discontinued));
    returnList.push_back(MasterData(6, 10.0, Novelty));
    returnList.push_back(MasterData(7, 3.0, Outgoing));
    returnList.push_back(MasterData(8, 1.0, Discontinued));
    returnList.push_back(MasterData(9, 9.0, Novelty));
    returnList.push_back(MasterData(10, 7.0, Normal));
    returnList.push_back(MasterData(11, 5.0, Normal));
    returnList.push_back(MasterData(12, 12.0, Normal));

    return returnList;
}