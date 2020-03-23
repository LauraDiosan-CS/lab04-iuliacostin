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

Expenses::Expenses()
{
    this->nrAp = 0;
    this->sum = 0;
    this->type = NULL;
}

Expenses::Expenses(int nrAp, int sum, char* type)
{
    this->nrAp = nrAp;
    this->sum = sum;
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

Expenses::Expenses(const Expenses& e)
{
    cout << "copy constructor"<<endl;
    this->type = new char[strlen(e.type) + 1];
    strcpy(this->type, e.type);
    this->nrAp = e.nrAp;
    this->sum = e.sum;
}

Expenses::~Expenses()
{
    if (this->type)
    {
        delete[] this->type;
        this->type = NULL;
    }
}


int Expenses::get_nrAp()
{
    return this->nrAp;
}

int Expenses::get_sum()
{
    return this->sum;
}

char* Expenses::get_type()
{
    return this->type;
}

void Expenses::set_type(char* type)
{
    if (this->type) {
        delete[] this->type;
    }
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

void Expenses::set_nrAp(int nrAp)
{
    this->nrAp = nrAp;
}

void Expenses::set_sum(int sum)
{
    this->sum = sum;
}

Expenses& Expenses::operator=(const Expenses& e)
{
    this->set_type(e.type);
    this->set_nrAp(e.nrAp);
    this->set_sum(e.sum);
    return *this;
}

bool Expenses:: operator==(const Expenses& e)
{
    return strcmp(this->type, e.type) == 0 && this->nrAp == e.nrAp && this->sum == e.sum;
}

ostream& operator<<(ostream& os, const Expenses& e)
{
    os << e.nrAp << " " <<e.sum<<" "<<e.type;
    return os;
}

