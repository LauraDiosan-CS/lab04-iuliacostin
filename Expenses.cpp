//
//  Expenses.cpp
//  lab4-5
//
//  Created by Iulia Costin on 22/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#include "Expenses.hpp"


#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

Expense::Expense()
{
    this->nrAp = 0;
    this->sum = 0;
    this->type = NULL;
}

Expense::Expense(int nrAp, int sum, char* type)
{
    this->nrAp = nrAp;
    this->sum = sum;
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

Expense::Expense(const Expense& e)
{
    cout << "copy constructor"<<endl;
    this->type = new char[strlen(e.type) + 1];
    strcpy(this->type, e.type);
    this->nrAp = e.nrAp;
    this->sum = e.sum;
}

Expense::~Expense()
{
    if (this->type)
    {
        delete[] this->type;
        this->type = NULL;
    }
}


int Expense::getNrAp()
{
    return this->nrAp;
}

int Expense::getSum()
{
    return this->sum;
}

char* Expense::getType()
{
    return this->type;
}

void Expense::setType(char* type)
{
    if (this->type) {
        delete[] this->type;
    }
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

void Expense::setNrAp(int nrAp)
{
    this->nrAp = nrAp;
}

void Expense::setSum(int sum)
{
    this->sum = sum;
}

Expense& Expense::operator=(const Expense& e)
{
    this->setType(e.type);
    this->setNrAp(e.nrAp);
    this->setSum(e.sum);
    return *this;
}

bool Expense:: operator==(const Expense& e)
{
    return strcmp(this->type, e.type) == 0 && this->nrAp == e.nrAp && this->sum == e.sum;
}

ostream& operator<<(ostream& os, const Expense& e)
{
    os << e.nrAp << " " <<e.sum<<" "<<e.type;
    return os;
}

