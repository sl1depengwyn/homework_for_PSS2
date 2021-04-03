#pragma once

//#ifndef HW4_PERSON_H
//#define HW4_PERSON_H

#include <string>
#include <vector>
#include "order.h"

class user {
private:
    std::string name;
    double rating;
    std::vector<order> orderHistory;
};


//#endif //HW4_PERSON_H
