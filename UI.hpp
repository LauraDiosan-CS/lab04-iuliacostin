//
//  UI.hpp
//  lab4-5
//
//  Created by Iulia Costin on 30/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#pragma once
#include "Service.hpp"

class UI
{
private:
    Service service;
    int n;
    Expense expense[100];
    void displayMenu();
    void op1();
    void op2();
    void op3();
    void op4();
    void op5();
    void op6();
    void op7();
    void op8();
    void op9();
    void op10();
    void op11();
    void op12();
    void op13();
    void op14();
    void op15();
    void upUndo();
    void undo();
public:
    UI();
    UI(Service& service);
    ~UI();
    void runUI();
};
