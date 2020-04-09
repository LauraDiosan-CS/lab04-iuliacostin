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

class Expense
{
private:
    char* type;
    int nrAp;
    int sum;
public:
    Expense();
    Expense(int nrAp, int sum, char* type);
    Expense(const Expense& e);
    ~Expense();
    char* getType();
    int getNrAp();
    int getSum();
    void setType(char* type);
    void setNrAp(int nrAp);
    void setSum(int sum);
    Expense& operator=(const Expense& e);
    bool operator==(const Expense& e);
    friend ostream& operator<<(ostream& os, const Expense& e);
};
