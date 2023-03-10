#pragma once

#include <iostream>
#include <list>
#include "brick.h"

using namespace std;

class Item {

    private:
    int itemID;
    list<Brick> bricks;

    public:
    // Constructors
    Item();
    Item(int iID, list<Brick> bList);

    // Getters
    int getItemID();
    list<Brick> getBricks();

};