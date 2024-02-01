#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#ifndef HIQ_CODE_TEST_USER_H
#define HIQ_CODE_TEST_USER_H


class User {
public:
    // METHODS
    vector<int> getStartPosition();

    vector<char> getCommands();

    vector<int> getRoomSize();
};


#endif //HIQ_CODE_TEST_USER_H
