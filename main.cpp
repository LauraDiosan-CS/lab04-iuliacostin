//
//  main.cpp
//  lab4-5
//
//  Created by Iulia Costin on 22/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#include <iostream>
#include "Repo.hpp"
#include "Expenses.hpp"
#include "TestRepo.hpp"
#include "TestExpense.hpp"

using namespace std;

int main()
{
    testRepo();
    testGetter();
    testSetter();
    testEq();
    
    Repo exp;
    
    char type1[] = "gaz", type2[] = "apa", type3[] = "internet";
    
    Expenses e1(3, 390, type2), e2(37, 700, type3);
    
    exp.insertExpenses(e1);
    exp.insertExpenses(e2);
    
    Expenses* test = new Expenses[exp.getSize()];
    
    test = exp.getAll();
    
    for (int i = 0; i < exp.getSize(); i++)
        {
            if  (i == exp.getSize() - 1)
            {
                cout << test[i] << endl;
            }
            else
            {
                cout << test[i] << " , ";
            }
        }
        cout << "Size = " << exp.getSize() << endl;
        
        exp.addExpense(3, 260, type1);
        test = exp.getAll();
        
        for (int i = 0; i < exp.getSize(); i++)
        {
            if  (i == exp.getSize() - 1)
            {
                cout << test[i] << endl;
            }
            else
            {
                cout << test[i] << " , ";
            }
        }
        cout << "Size = " << exp.getSize() << endl;
        cout << exp.getSize() << endl;
        
        return 0;
    
}
