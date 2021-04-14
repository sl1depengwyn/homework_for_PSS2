#include <sqlite_orm/sqlite_orm.h>
#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <unordered_map>

using std::cout;
using std::endl;

struct User {
    int id;
    std::string name;
    std::vector<char> hash;  //  binary format
};

struct temp {
    int id;
    bool asd;
};

int main(int, char **) {
    using namespace sqlite_orm;
    auto storage = make_storage("../db/users.sqlite",
                                make_table("users",
                                           make_column("id", &User::id, primary_key()),
                                           make_column("name", &User::name),
                                           make_column("hash", &User::hash)),
                                make_table("temp",
                                           make_column("id", &temp::id, primary_key())));
    storage.sync_schema();
//    storage.remove_all<User>();
//

    temp t{0, true};

//    t.id = storage.insert(t);

    User alex{
            0,
            "Alex",
            {0x10, 0x20, 0x30, 0x40},
    };
//    alex.id = storage.insert(alex);

    cout << "users count = " << storage.count<User>() << endl;

    cout << "alex = " << storage.dump(storage.get<User>(1)) << endl;

    cout << storage.dump(storage.get_all<temp>()[0]);

    std::hash<std::string> hasher;
    cout << hasher("asd");
    return 0;
}