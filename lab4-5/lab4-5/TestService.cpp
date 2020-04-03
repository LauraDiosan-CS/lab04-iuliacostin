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

void testService()
{
    Service service;
    char* type1 = new char[20];
    strcpy(type1, "apa");
    char* type2 = new char[20];
    strcpy(type2, "internet");
    
    service.add(1, 70, type1);
    Expense e1(1, 70, type1), e2(2, 130, type2);
    
    assert(*service.read() == e1);
    strcpy(type1, "gaz");
    service.update(e2, 2, 130, type1);
    
    service.add(2, 130, type1);
    service.add(3, 200, type1);
    service.add(4, 100, type2);
    
    assert(service.getSizeRepo() == 4);
    
    service.deleteExpenseByAp(2);
    assert(service.getSizeRepo() == 3);
    
    service.filterBySumSmaller(200);
    assert(service.getSizeRepo() == 3);
    
    service.deleteExpenseByType(type1);
    assert(service.getSizeRepo() == 2);
}
