//
//  Expenses.hpp
//  lab4-5
//
//  Created by Iulia Costin on 22/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#pragma once
#include <ostream>
using namespace std;

class Expenses
{
private:
    char* type;
    int nrAp;
    int sum;
public:
    Expenses();
    Expenses(int nrAp, int sum, char* type);
    Expenses(const Expenses& e);
    ~Expenses();
    char* get_type();
    int get_nrAp();
    int get_sum();
    void set_type(char* type);
    void set_nrAp(int nrAp);
    void set_sum(int sum);
    Expenses& operator=(const Expenses& e);
    bool operator==(const Expenses& e);
    friend ostream& operator<<(ostream& os, const Expenses& e);
};
