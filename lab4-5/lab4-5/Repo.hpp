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
    Expense expenses[100];
    int n;
public:
    Repo();
    ~Repo();
    Expense* getAll();
    int getSize();
    void addExpense(Expense e);
    void updateExpense(Expense e, int newNrAp, int newSum, char* newType);
    void deleteExpense(Expense& e, int op);
    int search(const Expense& e);
    int searchNrAp(int nrAp);
    int searchType(char* Type);
    void setPosElem(int i, Expense& e);
};

