#include "includes.h"
//------------------ REMOVE ------------------------
void removeProduct(Product* pP) {
    Dish* parent = pP->parent;
    if (pP->parent->firstProduct == pP) {
        pP->parent->firstProduct = pP->nextProduct;
    }
    else {
        Product* p = pP->parent->firstProduct;
        while (p->nextProduct != pP && p != NULL) {
            p = p->nextProduct;
        }
        if (p == NULL)
            return;
        p->nextProduct = pP->nextProduct;
    }
}

void removeDish(Dish* pD) {
    if (pD->parent != NULL) {
        if (pD->parent->DishArray[0] == pD) {
            pD->parent->DishArray[0] = pD->parent->DishArray[pD->parent->DishCount - 1];
            pD->parent->DishArray[pD->parent->DishCount - 1] = NULL;
        }
        else {
            for (int i = 0; i < pD->parent->DishCount; i++) {
                if (pD->parent->DishArray[i] == pD) {
                    pD->parent->DishArray[i] = pD->parent->DishArray[pD->parent->DishCount - 1];
                    pD->parent->DishArray[pD->parent->DishCount - 1] = NULL;
                }
            }
        }
        pD->parent->DishCount--;
    }
    pD->parent = NULL;
}


//------------------- DEL ---------------------------
void delProduct(Product* pP) {
    removeProduct(pP);
    free(pP->name);
    delete pP;
}
void delAllProducts(Kitchen* pk) {

    Product* pD, * p;
    for (size_t i = 0; i < pk->DishCount; i++) {
        pD = pk->DishArray[i]->firstProduct;
        if (pk->DishArray[i]->firstProduct != NULL) {
            while (pk->DishArray[i]->firstProduct != NULL) {
                p = pk->DishArray[i]->firstProduct;
                free(p->name);
                pD = pD->nextProduct;
                pk->DishArray[i]->firstProduct = pD;
                delete p;
            }
        }
        else {
            continue;
        }
    }
    fprintf_s(logFile, "\nВидалено всі продукти зі страви %s", pk->name);

}
void delDish(Dish* pD) {
    delAllProducts(pD->parent);
    removeDish(pD);
    free(pD->name);
    delete pD;
}
void delAllDish(Kitchen* kn) {
    delAllProducts(kn);
    int size = kn->DishCount;
    for (size_t i = 0; i < size; i++) {
        delete[] kn->DishArray[i]->name;
        delete kn->DishArray[i];
        kn->DishCount--;
    }
    fprintf_s(logFile, "\nВидалено всі страви з кухні %s", kn->name);
}
void delKitchen(Kitchen* pK) {

    delAllDish(pK);
    delete[] pK->DishArray;
    free(pK->name);
    delete pK;
    root = NULL;
}
//----------------- DEL IN MENU ------------------------------
    Dish* pD = (Dish*)ptr;
    printf("\n --- Видалення страви %s ---", pD->name);
    showDishInfo(pD);
    if (confirm("Ви дійсно хочете видалити цю страву?")) {
        fprintf_s(logFile, "\n Видалення страви %s", pD->name);
        delDish(pD);
        printf("\n Страву видалено");
        printf("\n Список страв після видалення");
        showDishList(pD->parent);
        pause();
        return 1;
    }
    return 0;
}
int delAllDishInMenu(void* ptr) {
    Kitchen* pK = (Kitchen*)ptr;
    printf("\n --- Видалення всіх страв ---");
    if (confirm("\nВи дійсно хочете видалити всі страви?")) {
        fprintf_s(logFile, "\n Видалення всіх страв");
        delAllDish(pK);
        printf("\n Страви видалено");
        pause();
    }
    return 0;
}

int delProductInMenu(void* ptr) {
    Product* pP = (Product*)ptr;
    printf("\n --- Видалення продукту %s ---", pP->name);
    showProductInfo(pP);
    if (confirm("Ви дійсно хочете видалити цей продукт?")) {
        fprintf_s(logFile, "\n Видалення продукту %s", pP->name);
        delProduct(pP);
        printf("\n Продукт видалено");
        pause();
        return 1;
    }
    return 0;
}

int delAllProductInMenu(void* ptr) {
    Dish* pD = (Dish*)ptr;
    printf("\n --- Видалення всіх продуктів ---");
    if (confirm("Ви дійсно хочете видалити всі продукти?")) {
        fprintf_s(logFile, "\n Видалення всіх продуктів");
        delAllProducts(pD->parent);
        printf("\n Продукти видалено");
        pause();
    }
    return 0;
}

int delKitchenInMenu(void* ptr) {
    Kitchen* pK = (Kitchen*)ptr;
    printf("\n --- Видалення кухні %s ---", pK->name);
    showKitchenInfo(pK);
    if (confirm("Ви дійсно хочете видалити цей кухню?")) {
        fprintf_s(logFile, "\n Видалення кухні %s", pK->name);
        delKitchen(pK);
        printf("\n кухню видалено");
        pause();
        return 1;
    }
    return 0;
}
