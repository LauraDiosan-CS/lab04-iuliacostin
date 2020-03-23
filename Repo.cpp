//
//  Repo.cpp
//  lab4-5
//
//  Created by Iulia Costin on 22/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#include "Repo.hpp"

using namespace std;

Repo::Repo()
{
    this->n = 0;
}
Repo::~Repo()
{
    this->n = 0;
}

void Repo::insertExpenses(Expenses &e)
{
    this->expenses[this->n++] = e;
}

Expenses* Repo::getAll()
{
    return this->expenses;
}

int Repo::getSize()
{
    return this->n;
}

void Repo::addExpense(int nrAp, int sum,char *type)
{
    Expenses e(nrAp, sum, type);
    this->expenses[this->n++] = e;
}

