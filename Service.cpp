//
//  Service.cpp
//  lab4-5
//
//  Created by Iulia Costin on 30/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#include "Repo.hpp"
#include "TestExpense.hpp"
#include "Service.hpp"
#include "Expenses.hpp"
#include <iostream>


using namespace std;

Service::Service()
{
    
}

Service::Service(Repo &repo)
{
    this->repo = repo;
}

Service::~Service()
{
    
}

void Service::setRepo(Repo repo)
{
    this->repo = repo;
}

int Service::getSizeRepo()
{
    return this->repo.getSize();
}

void Service::add(int nrAp, int sum, char* type)
{
    Expense exp(nrAp, sum, type);
    this->repo.addExpense(exp);
}

Expense* Service::read()
{
    return this->repo.getAll();
}

void Service::update(Expense e, int newNrAp, int newSum, char* newType)
{
    repo.updateExpense(e, newNrAp, newSum, newType);
}

void Service::deleteExpense(Expense& e)
{
    int length = this->repo.getSize();
    for (int i = 0; i < length; i++)
    {
        if (this->repo.getAll()[i] == e)
        {
            this->repo.deleteExpense(e, 1);
        }
    }
}

void Service::deleteExpenseByAp(int nrAp)
{
    int lenght = this->repo.getSize();
    for (int i = 0; i < lenght; i++)
    {
        if (this->repo.getAll()[i].getNrAp() == nrAp)
        {
            this->repo.deleteExpense(repo.getAll()[i], 2);
        }
    }
}

void Service::deleteExpenseByAps(int startNrAp, int endNrAp)
{
    int lenght = this->repo.getSize();
    for (int c = startNrAp; c <= endNrAp; c++)
    {
        for (int i = 0; i < lenght; i++)
        {
            if (this->repo.getAll()[i].getNrAp() == c)
            {
                this->repo.deleteExpense(repo.getAll()[i], 2);
            }
        }
    }
}
void Service::deleteExpenseByType(char* type)
{
    int lenght = this->repo.getSize();
    for (int i = 0; i < lenght; i++)
    {
        if (strcmp(this->read()[i].getType(), type) == 0)
        {
            this->repo.deleteExpense(this->read()[i], 3);
        }
    }
}

void Service::getExpenses()
{
    cout << "Size = " << this->getSizeRepo() << endl;
    for (int i = 0; i < this->getSizeRepo(); i++)
    {
        if (i == this->getSizeRepo() - 1)
        {
            cout<< this->read()[i].getNrAp() << " " << this->read()[i].getSum() << " " << this->read()[i].getType() << endl;
        }
        else
        {
            cout << this->read()[i].getNrAp() << " " << this->read()[i].getSum() << " " << this->read()[i].getType() << endl;
        }
    }
}

void Service::getExpensesByNrAP(int nrAp)
{
    cout << "Payments for <" << nrAp << "> are : ";
        
    for (int i = 0; i < this->getSizeRepo(); i++)
    {
        if (this->read()[i].getNrAp() == nrAp)
        {
            cout << this->read()[i].getNrAp() << " " << this->read()[i].getSum() << " " << this->read()[i].getType() << " ";
        }
    }
        
    cout << endl;
}

void Service::getExpensesBySumBigger(int nr)
{
    int lenght = this->repo.getSize();
    for (int i = 0; i < lenght; i++)
    {
        if (this->repo.getAll()[i].getSum() > nr)
        {
            cout << this->read()[i].getNrAp() << " " << this->read()[i].getSum() << " " << this->read()[i].getType() << " ";
        }
    }
}

void Service::getExpensesBySumEq(int nr)
{
    int lenght = this->repo.getSize();
    for (int i = 0; i < lenght; i++)
    {
        if (this->repo.getAll()[i].getSum() == nr)
        {
            cout << this->read()[i].getNrAp() << " " << this->read()[i].getSum() << " " << this->read()[i].getType() << " ";
        }
    }
}

void Service::sumForType(char *type)
{
    int sum = 0;
    int n = this->getSizeRepo();
    for (int i = 0; i < n; i++)
    {
        if(strcmp(this->read()[i].getType(), type) == 0)
        {
            sum += this->read()[i].getSum();
        }
    }
    
    cout << "The amount spent on <" << type << "> is : " << sum << endl;
}

void Service::maxSumForAp()
{
    int max_nrAp = 0;
    int sum_max= 0;
    int n = this->getSizeRepo();
    int lenght = repo.getSize();
    for (int c = 1; c <= lenght; c++)
    {
        int sum_nrAp = 0;
        for (int i = 0; i < n; i++)
        {
            if (this->read()[i].getNrAp() == c)
                sum_nrAp += this->read()[i].getSum();
        }
        if (sum_nrAp > sum_max)
        {
            sum_max = sum_nrAp;
            max_nrAp = c;
        }
    }
    
    cout << "The day you spent the most money is : " << max_nrAp << endl;
}

void Service::sortExpensesByTypeAsc(const char* type)
{
    int lenght = this->repo.getSize();
    for (int i = 0; i < lenght; i++)
    {
        Expense e1 = this->repo.getAll()[i];
        if (strcmp(e1.getType(), type) == 0)
            for (int j= i+1; j < lenght; j++)
            {
                Expense e2 = this->repo.getAll()[j];
                if (e1.getSum() < e2.getSum() && strcmp(e2.getType(), type) == 0)
                {
                    this->repo.setPosElem(i, e1);
                    this->repo.setPosElem(j, e2);
                    e1 = e2;
                }
            }
    }
    
}

void Service::filterByType(char *type)
{
    int i = 0;
    
    while (i < this->getSizeRepo())
    {
        if (strcmp(this->read()[i].getType(), type) != 0)
        {
            this->deleteExpense(this->read()[i]);
        }
        else
        {
            i++;
        }
    }
}

void Service::filterBySumSmaller(int nr)
{
    int lenght = this->repo.getSize();
    
    for (int i = 0; i < lenght; i++)
    {
        if (this->read()[i].getSum() >= nr)
        {
            this->deleteExpense(this->read()[i]);
        }
        else
        {
            i++;
        }
    }
}

