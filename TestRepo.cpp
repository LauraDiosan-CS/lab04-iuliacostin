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

void testRepo()
{
    char type[] = "gaz";
    Expenses e(1, 64, type);
    
    Repo exp;
    
    assert(exp.getSize() == 0);
    exp.addExpense(56, 369, type);
    assert(exp.getSize() == 1);
    exp.insertExpenses(e);
    assert(exp.getSize() == 2);
    
    Expenses* test = new Expenses[exp.getSize()];
    test = exp.getAll();
    
    assert(test[1] == e);
}
