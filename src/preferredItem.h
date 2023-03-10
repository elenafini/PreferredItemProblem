#pragma once

#include "item.h"
#include "brick.h"
#include "masterData.h"

using namespace std;

list<Item> getMatchingItems(list<Item> itemList, list<Brick> required);

Item PreferredItemService(list<Item> itemList, list<MasterData> mdList, list<Brick> required);