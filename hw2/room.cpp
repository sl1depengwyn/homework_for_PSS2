#include <vector>
#include <string>
#include "common.h"
#include "person.h"

using namespace std;

room::room() {
    micBatteriesCharge = true;
    markersReserveFullness = true;
    cleaned = true;
}

room::room(int rNumber) {
    roomNumber = rNumber;
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

void room::setAccess(person& smone) {
    additionalAccess[smone.getId()] = true;
}

void room::rejectAccess(person& smone) {
    additionalAccess[smone.getId()] = false;
}

void room::ban(person& smoneBad) {
    banned[smoneBad.getId()] = true;
}

void room::unban(person& smoneNotBatAnymore) {
    banned[smoneNotBatAnymore.getId()] = false;
}

bool room::openDoor(person& smone) {
    if (!banned[smone.getId()] && (additionalAccess[smone.getId()] || smone.getAccess() >= accessLevel)) return true;
    return false;
}

