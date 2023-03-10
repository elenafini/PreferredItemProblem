#include <bits/stdc++.h>
#include <utility>
#include "preferredItem.h"

using namespace std;

/*
Rules to choose the item:
1 - BEST STATUS: Normal > Novelty > Outgoing
2 - LOWEST PRICE
*/

Item PreferredItemService(list<Item> itemList, list<MasterData> mdList, list<Brick> requiredBricks) {

    list<Item> matchingItems = getMatchingItems(itemList, requiredBricks);

    if (matchingItems.empty()) {
        return Item(-1, {});
    }

    unordered_map<int, pair<int, float>> masterDataMap;
    for (MasterData md : mdList) {
        masterDataMap[md.getItemID()] = pair(md.getStatus(), md.getPrice());
    }

    Item preferredItem = matchingItems.front();
    int status1, status2, price1, price2;

    for (Item i : matchingItems) {
        status1 = masterDataMap[preferredItem.getItemID()].first;
        status2 = masterDataMap[i.getItemID()].first;
        price1 = masterDataMap[preferredItem.getItemID()].second;
        price2 = masterDataMap[i.getItemID()].second;

        if (status2 > status1) {
            preferredItem = i;
        }
        if (status2 == status1) {
            if (price2 < price1) {
                preferredItem = i;
            }
        }
    }

    return preferredItem;

}

list<Item> getMatchingItems(list<Item> itemList, list<Brick> requiredBricks) {
    list<Item> returnList;
    for (Item i : itemList) {
        if (Brick::doBrickListsMatch(i.getBricks(), requiredBricks)) {
            returnList.push_back(i);
        }
    }
    return returnList;
}