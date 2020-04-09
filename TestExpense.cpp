//
//  TestExpense.cpp
//  lab4-5
//
//  Created by Iulia Costin on 23/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#include "TestExpense.hpp"
#include"Expenses.hpp"
#include <stdio.h>
#include<assert.h>
#include<cstring>

void testGetter()
{
    char* type1 = new char[10];
    char* type2 = new char[10];

    strcpy(type1, "gaz");
    Expense e1(1, 480, type1);

    strcpy(type2, "apa");
    Expense e2(2, 600, type2);

    assert(e1.getNrAp() == 1);
    assert(e2.getNrAp() == 2);
    assert(e1.getSum() == 480);
    assert(e2.getSum() == 600);
    assert(strcmp(e1.getType(), "gaz") == 0);
    assert(strcmp(e2.getType(), "apa")==0);
}

void testSetter()
{
    char* type1 = new char[10];
    char* newType = new char[10];

    strcpy(type1, "gaz");
    Expense e1(1, 480, type1);

    e1.setNrAp(7);
    assert(e1.getNrAp() == 7);

    e1.setSum(582);
    assert(e1.getSum() == 582);

    strcpy(newType, "internet");
    e1.setType(newType);
    assert(strcmp(e1.getType(), "internet") == 0);
}

void testEq()
{
    char* type1 = new char[10];
    
    strcpy(type1, "internet");
    Expense e1(1, 480, type1), e2(7, 600, type1);
}

