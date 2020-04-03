//
//  UI.cpp
//  lab4-5
//
//  Created by Iulia Costin on 30/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//

#include "UI.hpp"
#include <iostream>
#include <string>
#include <string.h>

UI::UI()
{
    
}

UI::UI(Service& service)
{
    this->service = service;
}

UI::~UI()
{
    
}

void UI::displayMenu()
{
    cout << " 1. Add a new expense. " << endl;
    cout << " 2. Delete expenses for one apartment. " << endl;
    cout << " 3. Delete expenses between two apartment numbers " << endl;
    cout << " 4. Delete expenses for one type. " << endl;
    cout << " 6. Display all expenses for this month. " << endl;
    cout << " 7. Display all expenses for one apartment. " << endl;
    cout << " 8. Display all expenses bigger than a number. " << endl;
    cout << " 9. Display all expenses equal with a number. " << endl;
    cout << " 10. Display the sum for all expenses of the same type. " << endl;
    cout << " 11. Display the apartment with the highest sum. " << endl;
    cout << " 12. Display the expenses for one type, ascending. " << endl;
    cout << " 13. Type filter. " << endl;
    cout << " 14. Type filter with an amount smaller than a number " << endl;
    cout << " 15. Undo. " << endl;
    cout << " 0. EXIT! " << endl;
}

void UI::op1()
{
    int nrAp, sum;
    char* type = new char[20];
    char t[20];
    cout << " nrAp = ";
    cin >> nrAp;
    cout << " sum = ";
    cin >> sum;
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->service.add(nrAp, sum, type);
}

void UI::op2()
{
    int nrAp;
    cout << " nrAp = ";
    cin >> nrAp;
    this->service.deleteExpenseByAp(nrAp);
}

void UI::op3()
{
    int startNrAp;
    int endNrAp;
    cout << " start nrAp = ";
    cin >> startNrAp;
    cout << " end nrAp = ";
    cin >> endNrAp;
    this->service.deleteExpenseByAps(startNrAp, endNrAp);
}

void UI::op4()
{
    char* type = new char[20];
    char t[20];
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->service.deleteExpenseByType(type);
}

void UI::op6()
{
    this->service.getExpenses();
}

void UI::op7()
{
    int nrAp;
    cout << " nrAp = ";
    cin >> nrAp;
    this->service.getExpensesByNrAP(nrAp);
}

void UI::op8()
{
    int nr;
    cout << "Number: ";
    cin >> nr;
    this->service.getExpensesBySumBigger(nr);
}

void UI::op9()
{
    int nr;
    cout << "Number: ";
    cin >> nr;
    this->service.getExpensesBySumEq(nr);
}
void UI::op10()
{
    char* type = new char[20];
    char t[20];
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->service.sumForType(type);
}

void UI::op11()
{
    this->service.maxSumForAp();
}

void UI::op12()
{
    char* type = new char;
    cout << "Type of expense that needs to be sorted: ";
    cin >> type;
    this->service.sortExpensesByTypeAsc(type);
}

void UI::op13()
{
    char* type = new char[20];
    char t[20];
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->service.filterByType(type);
}

void UI::op14()
{
    int nr;
    cout << "Number: ";
    cin >> nr;
    this->service.filterBySumSmaller(nr);
}
void UI::upUndo()
{
    this->n = this->service.getSizeRepo();
    for (int i = 0; i< n; i++)
    {
        this->expense[i] = this->service.read()[i];
    }
}

void UI::undo()
{
    int i = 0;
    while (i < service.getSizeRepo())
    {
        this->service.deleteExpense(this->service.read()[i]);
    }
    for (int j = 0; j < this->n; j++)
    {
        this->service.add(this->expense[j].getNrAp(), this->expense[j].getSum(), this->expense[j].getType());
    }
}

void UI::runUI()
{
    int op = -1;
    
    while (op != 0)
    {
        displayMenu();
        cout << "Choose an option: ";
        cin >> op;
        switch (op) {
            case 1:
                this->upUndo();
                this->op1();
                break;
            case 2:
                this->upUndo();
                this->op2();
                break;
            case 3:
                this->upUndo();
                this->op3();
                break;
            case 4:
                this->upUndo();
                this->op4();
                break;
            case 6:
                this->op6();
                break;
            case 7:
                this->op7();
                break;
            case 8:
                this->op8();
                break;
            case 9:
                this->op9();
                break;
            case 10:
                this->op10();
                break;
            case 11:
                this->op11();
                break;
            case 12:
                this->op12();
             break;
            case 13:
                this->upUndo();
                this->op13();
                break;
            case 14:
                this->upUndo();
                this->op14();
                break;
            case 15:
                this->undo();
                break;
    
            default:
                break;
        }
    }
}
