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
    fprintf_s(logFile, "\nРозмір масиву страв збільшено до %d", newSize);
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
    fprintf_s(logFile, "\nДодано страву %s ", pD->name);
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
    fprintf_s(logFile, "\nДодано продукт %s до страви %s ",
        pT->name, pD->name);
}

int addDishInMenu(void* ptr) {

    cout << "--- Додавання нової страви ---\n";
    if (root == NULL) {
        cout << "Дерево не було створено!\n";
        pause();
        return 1;
    }
    char* name = getStr(" Назва страви: ");
    int minutes = getInt(" Час приготування в хвилинах: ", 1, 1000);
    int price = getInt(" Ціна в гривнях: ", 1, 5000);
    Dish* dish = createDish(name, minutes, price);
    addDish(root, dish);
    cout << "\nСписок страв після додавання";
    showDishList(NULL);
    pause();
    return 0;
}

int addProductInMenu(void* ptr) {
    Dish* dish = (Dish*)ptr;
    cout << "\n --- Додавання нового продукту ---\n";
    char* name = getStr(" Продукт: ");
    int mass = getInt(" Вага в грамах:", 1, 3000);
    Product* product = createProduct(name, mass);
    addProduct(dish, product);
    cout << "\n Список продуктів після змін:";
    showProductList(dish);
    pause();
    return 0;
}
