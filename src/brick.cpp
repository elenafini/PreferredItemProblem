#include "brick.h"

using namespace std;

Brick::Brick() {}

Brick::Brick(int dID, list<int> cCodes) {
    designID = dID;
    colorCodes = cCodes;
}

bool Brick::operator==(const Brick& anotherBrick) const {
    if (designID == anotherBrick.designID && colorCodes == anotherBrick.colorCodes) {
        return true;
    }
    return false;
}

bool Brick::doBrickListsMatch(list<Brick> bList1, list<Brick> bList2) {
    bool match = false;
    if (bList1.size() != bList2.size()) {
        return false;
    }
    for (auto i = bList1.begin(); i != bList1.end();) {
        for (auto j = bList2.begin(); j != bList2.end();) {
            if (*i == *j) {
                i = bList1.erase(i);
                j = bList2.erase(j);
                match = true;
                break;
            }
            j++;
        }
        if (!match) {
            i++;
        }
        match = false;
    }
    if (bList1.empty() && bList2.empty()) {
        return true;
    }
    return false;
}