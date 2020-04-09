//
//  TestRepo.cpp
//  lab4-5
//
//  Created by Iulia Costin on 23/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#include "TestRepo.hpp"
#include "Expenses.hpp"
#include "Repo.hpp"
#include <stdio.h>
#include <assert.h>


void testGetSize(){
    char* type1 = new char[10];
    char* type2 = new char[10];

    strcpy(type1, "apa");
    Expense e1(1, 150, type1);

    strcpy(type2, "gaz");
    Expense e2(3, 220, type2);

    Repo rep;
    rep.addExpense(e1);
    assert(rep.getSize() == 1);

    rep.addExpense(e2);
    assert(rep.getSize() == 2);

    assert(rep.getAll()[0] == e1);
    assert(rep.getAll()[1] == e2);
}

void testAddExpese()
{
    char* type1 = new char[10];
    char* type2 = new char[10];

    strcpy(type1, "apa");
    Expense e1(1, 150, type1);

    strcpy(type2, "gaz");
    Expense e2(2, 220, type2);

    Repo rep;
    rep.addExpense(e1);
    rep.addExpense(e2);

    assert(rep.getAll()[0] == e1);
    assert(rep.getAll()[1] == e2);
}


void testUpdatdeExpense()
{
    char* type1 = new char[10];

    strcpy(type1, "apa");
    Expense e1(1, 150, type1);


    Repo rep;
    rep.addExpense(e1);

    //rep.updateExpense(e1, 1, 300, "altele");

    assert(rep.getAll()[0].getNrAp() == 1);
    assert(rep.getAll()[0].getSum() == 300);
    assert(strcmp(rep.getAll()[0].getType(), "altele") == 0);
}

void testDeleteExpense()
{
    char* type1 = new char[10];
    char* type2 = new char[10];

    strcpy(type1, "apa");
    Expense e1(1, 150, type1);

    strcpy(type2, "gaz");
    Expense e2(1, 220, type2);

    Repo rep;
    rep.addExpense(e1);
    rep.addExpense(e2);

   // rep.deleteExpense(e1);
   // assert(rep.getSize() == 1);

}
