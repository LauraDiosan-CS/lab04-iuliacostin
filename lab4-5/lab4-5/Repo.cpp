//
//  Repo.cpp
//  lab4-5
//
//  Created by Iulia Costin on 22/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#include "Repo.hpp"
#include "Expenses.hpp"

using namespace std;

Repo::Repo()
{
    this->n = 0;
}

Repo::~Repo()
{
    this->n = 0;
}

void Repo::addExpense(Expense e)
{
    this->expenses[this->n++] = e;
}

Expense* Repo::getAll()
{
    return this->expenses;
}

int Repo::getSize()
{
    return this->n;
}

void Repo::updateExpense(Expense e, int newNrAp, int newSum, char* newType )
{
    for (int i = 0; i < this->n; i++)
        if (this->expenses[i] == e)
        {
            this->expenses[i].setNrAp(newNrAp);
            this->expenses[i].setSum(newSum);
            this->expenses[i].setType(newType);
        }
    
}

void Repo::deleteExpense(Expense& e, int op)
{
    int pos;
    if (op == 1)
    {
        pos = this->search(e);
    }
    else if (op == 2)
    {
        pos = this->searchNrAp(e.getNrAp());
    }
    else
    {
        pos = this->searchType(e.getType());
    }
    int nr = this->getSize();
    if (pos != -1)
    {
        for (int i = pos; i < nr - 1; i++)
            this->expenses[i] = this->expenses[i + 1];
        this->n = nr - 1;
    }
}
int Repo::search(const Expense& p)
{
    int lenght = this->getSize();
    for (int i = 0; i < lenght; i++)
    {
        if (this->expenses[i] == p)
            return i;
    }
    return -1;
}

int Repo::searchNrAp(int nrAp)
{
    int lenght = this->getSize();
    for (int i = 0; i < lenght; i++)
    {
        if (this->expenses[i].getNrAp() == nrAp)
            return i;
    }
    return -1;
}

int Repo::searchType(char* type)
{
    int n = this->getSize();
    for (int i = 0; i < n; i++)
    {
        if (strcmp(this->expenses[i].getType(), type) == 0)
            return i;
    }
    return -1;
}

void Repo::setPosElem(int i, Expense& e)
{
    this->expenses[i] = e;
}
