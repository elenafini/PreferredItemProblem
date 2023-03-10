#pragma once

#include "brick.h"
#include "item.h"
#include "masterdata.h"
using namespace std;

// This files provides the functions to initialize test data.

class ServiceFunctions {

    public:

    static Brick brick1;
	static Brick brick2;

    static list<Item> ItemService();

    static list<MasterData> MasterDataService();

};