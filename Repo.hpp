//
//  Repo.hpp
//  lab4-5
//
//  Created by Iulia Costin on 22/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#pragma once
#include "Expenses.hpp"

class Repo
{
private:
    Expenses expenses[100];
    int n;
public:
    Repo();
    ~Repo();
    Expenses* getAll();
    int getSize();
    void insertExpenses(Expenses &e);
    void addExpense(int nrAp, int sum, char* type);
};

