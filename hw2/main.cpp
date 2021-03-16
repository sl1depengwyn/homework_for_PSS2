#include <iostream>
#include <string>

#include "admin.h"
#include "director.h"
#include "labEmployee.h"
#include "professor.h"
#include "student.h"
#include "cabinet.h"
#include "classRoom.h"
#include "conferenceRoom.h"
#include "directorCabinet.h"
#include "lectureRoom.h"

using namespace std;

int main() {
    // generating
    director boss("Kirill", "Semenikhin", "kirillse@innopolis.ru", "+7 843 203-92-53", 28, 8, 1978);
    admin anon("admin", "admin", "admin@innopolis.ru");
    admin secondaryAdmin("admin", "admin", "admin@innopolis.university");
    professor pss("Eugene", "Zuev", "e.zuev.innopolis.ru");
    professor calculus("Ivan", "Konyukhov", "i.konyukhov@innopolis.ru");
    professor dsa("Adil", "Khan", "a.khan@innopolis.ru");
    professor tcs("Manuel", "Mazzara", "m.mazzara@innopolis.ru");
    vector<string> Fnames = {"Zoya", "Gala", "Yuliana", "Afanasiia", "Dunya", "Klara"};
    vector<string> FsecondNames = {"Sokoloa", "Tarasova", "Volkova", "Antonova", "Smirnova", "Osipova"};
    vector<string> Mnames = {"Andrei", "Onisim", "Isai", "Alik", "Feliks", "Yuli"};
    vector<string> MsecondNames = {"Tarasov", "Novikov", "Vlasov", "Frolov", "Kozlov", "Zakharov"};
    vector<labEmployee> labEmployees;
    for (int i = 0; i < 16; i++) {
        string name, secondName;
        if (rand() % 2 == 0) {
            name = Fnames[rand() % Fnames.size()];
            secondName = FsecondNames[rand() % FsecondNames.size()];
        } else {
            name = Mnames[rand() % Fnames.size()];
            secondName = MsecondNames[rand() % FsecondNames.size()];
        }
        string email;
        email += name;
        email += '.';
        email += secondName;
        email += "@innopolis.ru";
        labEmployee le(name, secondName, email);
        labEmployees.push_back(le);
    }
    vector<student> students;
    for (int i = 0; i < 32; i++) {
        string name, secondName;
        if (rand() % 2 == 0) {
            name = Fnames[rand() % Fnames.size()];
            secondName = FsecondNames[rand() % FsecondNames.size()];
        } else {
            name = Mnames[rand() % Fnames.size()];
            secondName = MsecondNames[rand() % FsecondNames.size()];
        }
        string email;
        email += name;
        email += '.';
        email += secondName;
        email += "@innopolis.university";
        student s(name, secondName, email);
        students.push_back(s);
    }

    lectureRoom room108(108);
    directorCabinet room424(424);
    classRoom room313(313);

    pss.setFavJoke("programs in 2100: auto auto auto auto auto auto auto auto auto auto auto auto auto auto auto");
    pss.provideFavJoke();

    if (pss.getAccessToRoom(room424)) {
        cout << "Professor Zuev have access to director cabinet 0.o" << endl;
    } else {
        cout << "Professor Zuev have no access to director cabinet" << endl;
    }

    boss.wishHappybirthday({28, 8, 2020});

    anon.setAccess(pss, room424);

    if (pss.getAccessToRoom(room424)) {
        cout << "Professor Zuev have access to director cabinet 0.o";
    } else {
        cout << "Professor Zuev have no access to director cabinet";
    }
    /* also admin can ban, cancel additional access, and unban
     * students can niyt' and shushukatsa
     * director can decrease scholarship and sign papers
     *
     * you know whether room has markers(and add), whether batteries in mic(and add), is it clean or not
     * and you know who cleaned the room
     */

    return 0;
}
