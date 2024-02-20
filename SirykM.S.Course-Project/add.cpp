#include "includes.h"
int cmpDish(Dish* d1, Dish* d2) {
    if (d1->price != d2->price)
        return d2->price;
    return strcmp(d1->name, d2->name);

}

int cmpProduct(Product* f1, Product* f2) {
    return f1->mass < f2->mass;

}

void growDishAr(Kitchen* pU) {
    int newSize = 1.5 * pU->arrSize + 0.5;
    Dish** newAr = new Dish * [newSize];
    memcpy(newAr, pU->DishArray, pU->arrSize * sizeof(Dish*));
    pU->arrSize = newSize;
    Dish** oldAr = pU->DishArray;
    pU->DishArray = newAr;
    delete[] oldAr;
    fprintf_s(logFile, "\n����� ������ ����� �������� �� %d", newSize);
}

void addDish(Kitchen* pU, Dish* pD) {
    pD->parent = pU;
    if (pU->arrSize == pU->DishCount)
        growDishAr(pU);
    int n = pU->DishCount;
    while (n > 0 && cmpDish(pU->DishArray[n - 1], pD) > 0) {
        pU->DishArray[n] = pU->DishArray[n - 1];
        n--;
    }
    pU->DishArray[n] = pD;
    pU->DishCount++;
    fprintf_s(logFile, "\n������ ������ %s ", pD->name);
}

void addProduct(Dish* pD, Product* pT) {
    pT->parent = pD;
    if (pD->firstProduct == nullptr)
        pD->firstProduct = pT;
    else if (cmpProduct(pT, pD->firstProduct) < 0) {
        pT->nextProduct = pD->firstProduct;
        pD->firstProduct = pT;
    }
    else {
        Product* p = pD->firstProduct;
        while (p->nextProduct != nullptr &&
            cmpProduct(pT, p->nextProduct) >= 0)
            p = p->nextProduct;
        pT->nextProduct = p->nextProduct;
        p->nextProduct = pT;
    }
    fprintf_s(logFile, "\n������ ������� %s �� ������ %s ",
        pT->name, pD->name);
}

int addDishInMenu(void* ptr) {

    cout << "--- ��������� ���� ������ ---\n";
    if (root == NULL) {
        cout << "������ �� ���� ��������!\n";
        pause();
        return 1;
    }
    char* name = getStr(" ����� ������: ");
    int minutes = getInt(" ��� ������������ � ��������: ", 1, 1000);
    int price = getInt(" ֳ�� � �������: ", 1, 5000);
    Dish* dish = createDish(name, minutes, price);
    addDish(root, dish);
    cout << "\n������ ����� ���� ���������";
    showDishList(NULL);
    pause();
    return 0;
}

int addProductInMenu(void* ptr) {
    Dish* dish = (Dish*)ptr;
    cout << "\n --- ��������� ������ �������� ---\n";
    char* name = getStr(" �������: ");
    int mass = getInt(" ���� � ������:", 1, 3000);
    Product* product = createProduct(name, mass);
    addProduct(dish, product);
    cout << "\n ������ �������� ���� ���:";
    showProductList(dish);
    pause();
    return 0;
}
