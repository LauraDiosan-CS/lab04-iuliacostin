//
//  TestService.cpp
//  lab4-5
//
//  Created by Iulia Costin on 03/04/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#include "TestService.hpp"
#include <iostream>
#include "Repo.hpp"
#include <assert.h>
#include "Service.hpp"
#include "string.h"

void testAddExpense()
{
    char* type1 = new char[10];
    strcpy(type1, "apa");
    
    Service s;
    
    s.add(1, 90, type1);
    assert(s.read()[0].getNrAp() == 1);
    assert(s.read()[0].getSum() == 90);
    
}

void testGetSizeRepo()
{
    char* type1 = new char[10];
    strcpy(type1, "apa");
    
    Service s;
    
    s.add(1, 90, type1);
    s.add(2, 100, type1);
    
    assert(s.getSizeRepo() == 2);
}

void testUpdateExpense()
{
    char* type1 = new char[10];
    char* type2 = new char[10];
    strcpy(type1, "apa");
    strcpy(type2, "gaz");
    
    Expense e1(1, 250, type1);
    

    Service s;

    s.add(1, 250, type1);
    s.update(e1, 2, 200, type2);

    assert(s.getSizeRepo() == 1);
    assert(s.read()[0].getNrAp() == 2);
    assert(s.read()[0].getSum() == 200);
    assert(s.read()[0].getType() == type2);
    
}

void testDeleteForAp()
{
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "apa");
    strcpy(type2, "gaz");
    strcpy(type3, "internet");
    
    Expense e1(1, 100, type1);
    Expense e2(2, 200, type2);
    Expense e3(3, 110, type3);

    Service s;

    s.add(1, 100, type1);
    s.add(2, 200, type2);
    s.add(3, 110, type3);

    s.deleteExpenseByAp(3);

    assert(s.getSizeRepo() == 2);
    /*assert(s.read()[0].getNrAp() == 1);
    assert(s.read()[0].getSum() == 100);
    assert(s.read()[0].getType() == type1);*/
}

void testDeleteForType()
{
    char* type1 = new char[10];
    char* type2 = new char[10];

    strcpy(type1, "apa");
    strcpy(type2, "gaz");
    

    Service s;

    s.add(1, 100, type1);
    s.add(2, 110, type2);
   

    s.deleteExpenseByType(type2);

    assert(s.getSizeRepo() == 1);
    
}

void testDeleteInterval()
{
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "apa");
    strcpy(type2, "gaz");
    strcpy(type3, "internet");

    Service s;

    s.add(1, 100, type1);
    s.add(2, 200, type2);
    s.add(3, 80, type3);

    s.deleteExpenseByAps(1, 3);

    assert(s.getSizeRepo() == 0);
}

void testDisplayAp()
{
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "apa");
    strcpy(type2, "gaz");
    strcpy(type3, "internet");

    Service s;

    s.add(1, 100, type1);
    s.add(2, 200, type2);
    s.add(3, 80, type3);
    
    s.getExpensesByNrAP(2);
    

}

void testDisplayBigger()
{
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "apa");
    strcpy(type2, "gaz");
    strcpy(type3, "internet");

    Service s;

    s.add(1, 100, type1);
    s.add(2, 200, type2);
    s.add(3, 80, type3);

    s.getExpensesBySumBigger(80);
    
}

void testDisplayEqual()
{
    char* type1 = new char[10];
    char* type2 = new char[10];

    strcpy(type1, "apa");
    strcpy(type2, "gaz");

    Service s;

    s.add(1, 100, type1);
    s.add(2, 200, type2);
    
    s.getExpensesBySumEq(100);
    
}

void testDisplaySumForType()
{
    char* type1 = new char[10];
    char* type2 = new char[10];

    strcpy(type1, "apa");
    strcpy(type2, "gaz");
    
    Service s;

    s.add(1, 100, type1);
    s.add(2, 200, type2);
    s.add(3, 20, type1);

    
}

void testFilterType()
{
    char* type1 = new char[10];
    char* type2 = new char[10];
    char* type3 = new char[10];

    strcpy(type1, "apa");
    strcpy(type2, "gaz");
    strcpy(type3, "internet");

    Service s;

    s.add(1, 100, type1);
    s.add(2, 90, type2);
    s.add(3, 200, type3);

    s.filterByType(type2);
    
}

void testService()
{
    testDisplayAp();
    testAddExpense();
    testDeleteForAp();
    testGetSizeRepo();
    testFilterType();
    testDeleteForType();
    testDisplayAp();
    testDisplayEqual();
    testDisplayBigger();
    
}
