#pragma once

//#ifndef ASSIGNMENTS_ROOM_H
//#define ASSIGNMENTS_ROOM_H

#include <string>
#include <vector>
#include <map>
#include "common.h"

class person;

class room {
protected:
    unsigned int roomNumber;
    access accessLevel;
    std::vector<std::pair<date, std::string>> cleaningJournal;
    bool micBatteriesCharge;
    bool markersReserveFullness;
    bool cleaned;
    std::map<int, bool> additionalAccess;
    std::map<int, bool> banned;
public:
    room();

    room(int rNumber);

    bool isClean();

    bool hasMarkers();

    bool hasMicBatteries();

    void addMarkers();

    void changeBattaries();

    void NowCleaned(std::string name, date dt);

    void setAccess(person& smone);

    void rejectAccess(person& smone);

    void ban(person& smoneBad);

    void unban(person& smoneNotBatAnymore);

    bool openDoor(person& smone);

};


//#endif //ASSIGNMENTS_ROOM_H
