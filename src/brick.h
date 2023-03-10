#pragma once

#include <list>
using namespace std;

class Brick {

    private:
    int designID;
    list<int> colorCodes;

    public:
    // Constructors
    Brick();
    Brick(int dID, list<int> cCodes);

    // Operator overload
    bool operator==(const Brick& anotherBrick) const;
    
    // Returns true if two lists of bricks (that may contain multiple copies of the same element)
    // contain the same elements, otherwise returns false
    static bool doBrickListsMatch(list<Brick> bList1, list<Brick> bList2);
    
};