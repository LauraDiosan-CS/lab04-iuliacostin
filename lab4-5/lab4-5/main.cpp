//
//  main.cpp
//  lab4-5
//
//  Created by Iulia Costin on 22/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#include"TestExpense.hpp"
#include"TestRepo.hpp"
#include"TestService.hpp"
#include <iostream>
#include "UI.hpp"

using namespace std;

int main()
{
    testGetter();
    testSetter();
    testEq();
    testGetSize();
    testDeleteExpense();
    testService();

    
    UI u;
    u.runUI();
    
    return 0;
}
