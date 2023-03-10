#pragma once

using namespace std;

enum STATUS {Discontinued = 0, Outgoing = 1, Novelty = 2, Normal = 3};

class MasterData {

    private:
    int itemID;
    float price;
    STATUS status;


    public:
    // Constructors
    MasterData(int iID, float p, enum STATUS s);

    // Getters
    int getItemID();
    float getPrice();
    STATUS getStatus();

};