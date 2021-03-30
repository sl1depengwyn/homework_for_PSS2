#include <vector>
#include <string>
#include "common.h"
#include "person.h"
#include "room.h"


using namespace std;

bool room::isEmergency = false;

room::room(unsigned int rNumber, int floor) {
    roomNumber = rNumber;
    this->floor = floor;
}

bool room::isClean() {
    return cleaned;
}

void room::NowCleaned(std::string name, date dt) {
    pair<date, string> temp(dt, name);
    cleaningJournal.push_back(temp);
    cleaned = true;
}

bool room::hasMarkers() {
    return markersReserveFullness;
}

bool room::hasMicBatteries() {
    return micBatteriesCharge;
}

void room::addMarkers() {
    markersReserveFullness = true;
}

void room::changeBattaries() {
    micBatteriesCharge = true;
}

void room::setAccess(person &smone) {
    additionalAccess[smone.getId()] = true;
}

void room::rejectAccess(person &smone) {
    additionalAccess[smone.getId()] = false;
}

void room::ban(person &smoneBad) {
    banned[smoneBad.getId()] = true;
}

void room::unban(person &smoneNotBatAnymore) {
    banned[smoneNotBatAnymore.getId()] = false;
}

bool room::openDoor(person &smone) {
    if (isEmergency ||
        (!banned[smone.getId()] && (additionalAccess[smone.getId()] || smone.getAccess() >= accessLevel)))
        return true;
    return false;
}

void room::emergency() {
    isEmergency = true;
}

void room::calm() {
    isEmergency = false;
}

