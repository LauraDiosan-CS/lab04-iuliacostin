//
//  Service.hpp
//  lab4-5
//
//  Created by Iulia Costin on 30/03/2020.
//  Copyright © 2020 Iulia Costin. All rights reserved.
//
#pragma once
#include "Repo.hpp"

class Service {
private:
    Repo repo;
public:
    Service();
    Service(Repo &repo);
    ~Service();
    void setRepo(Repo repo);
    
    void add(int nrAp, int sum, char* type);
    Expense* read();
    void update(Expense e, int newNrAp, int newSum, char* newType);
    void deleteExpense(Expense& e);
    
    int getSizeRepo();
    void deleteExpenseByAp(int nrAp);
    void deleteExpenseByAps(int startNrAp, int endNrAp);
    void deleteExpenseByType(char* type);
    void getExpenses();
    void getExpensesByNrAP(int nrAp);
    void getExpensesBySumBigger(int nr);
    void getExpensesBySumEq(int nr);
    void sumForType(char* type);
    void maxSumForAp();
    void sortExpensesByTypeAsc(const char* type);
    void filterByType(char* type);
    void filterBySumSmaller(int nr);
    
    
};



