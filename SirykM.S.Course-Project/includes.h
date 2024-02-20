#ifndef INCLUDES_H_INCLUDED
#define INCLUDES_H_INCLUDED
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "type.h"
using namespace std;
//----------- ROOT & LOG -------------------
extern Kitchen* root;
extern FILE* logFile;
//----------- STRUCTURE --------------------
Kitchen* createDefTree();
Dish *createDish(char *name, int minutes, int price);
Product *createProduct(char *name, int mass);
Dish *selectDish();
Product* selectProduct();
//-----------
int mainMenu(void*);
//----------- SHOW -------------------------
int showProjectInfo(void*);
int showTree(void*);
int showLogFile(void*);
int showDishList(void*);
int showDishListInMenu(void*);
int showDishInfo(Dish*);
int showProductList(Dish*);
int showProductListInMenu(void*);
int showProductInfo(Product*);
int showProductInfoInMenu(void* ptr);
int showKitchenInfo(void*);
//----------- UTILITIES ---------------------
void pause();
int rootExist();
int dishExist();
int getInt(const char* promt, int min, int max);
char* getStr(const char* promt);
int confirm(const char* question);
//-----------
int cmpDish(Dish* d1, Dish* d2);
int cmpProduct(Product* f1, Product* f2);
void growDishAr(Kitchen* pU);
//----------- ADD ---------------------------
void addDish(Kitchen* pU, Dish* pD);
void addProduct(Dish* pD, Product* pT);
int addDishInMenu(void*);
int addProductInMenu(void*);
//-----------  DEL --------------------------
int delAllDishInMenu(void*);
int delAllProductInMenu(void*);
int delKitchenInMenu(void*);
void delKitchen(Kitchen*);
int delProductInMenu(void*);
//----------- REMOVE ------------------------
void removeDish(Dish* pD);
void removeProduct(Product*);
//----------- CREATE ------------------------
int createDefTreeInMenu(void*);
int createRootInMenu(void*);
//----------- EDIT --------------------------
int editProductInfo(void* ptr);
int editDishInfo(void* ptr);
//----------- SAVE RESTORE ------------------
int saveTreeInMenu(void*);
int restoreTreeInMenu(void*);
//----------- FIND --------------------------
int findNewestProductInMenu(void*);
int findExpensiveCheapDish(void*);
Product* sortProductsByMass(Product* head);
//----------- EDIT --------------------------
int editKitchenInfo(void*);
int editDishInfo(void*);
//----------- QUERY ------------------------
int calcProductDish(Dish* ptr);
int calcMemory(void* ptr);

#endif // INCLUDES_H_INCLUDED
