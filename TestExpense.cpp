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
    Expenses expenses[2];
    char* type1 = new char[10];
    char* type2 = new char[10];

    strcpy(type1, "gaz");
    Expenses e1(1, 480, type1);

    strcpy(type2, "apa");
    Expenses e2(2, 600, type2);

    assert(e1.get_nrAp() == 1);
    assert(e2.get_nrAp() == 2);
    assert(e1.get_sum() == 480);
    assert(e2.get_sum() == 600);
    assert(strcmp(e1.get_type(), "gaz") == 0);
    assert(strcmp(e2.get_type(), "apa")==0);
}

void testSetter()
{
    Expenses expenses[1];
    char* type1 = new char[10];
    char* newType = new char[10];

    strcpy(type1, "gaz");
    Expenses e1(1, 480, type1);

    e1.set_nrAp(7);
    assert(e1.get_nrAp() == 7);

    e1.set_sum(582);
    assert(e1.get_sum() == 582);

    strcpy(newType, "internet");
    e1.set_type(newType);
    assert(strcmp(e1.get_type(), "internet") == 0);
}

void testEq(){
    Expenses expenses[2];
    char* type1 = new char[10];
    
    strcpy(type1, "internet");
    Expenses e1(1, 480, type1), e2(7, 600, type1);
     
    
}

