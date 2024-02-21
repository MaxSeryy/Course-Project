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
    fprintf_s(logFile, "\n�������� �� �������� � ������ %s", pk->name);

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
    fprintf_s(logFile, "\n�������� �� ������ � ���� %s", kn->name);
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
    printf("\n --- ��������� ������ %s ---", pD->name);
    showDishInfo(pD);
    if (confirm("�� ����� ������ �������� �� ������?")) {
        fprintf_s(logFile, "\n ��������� ������ %s", pD->name);
        delDish(pD);
        printf("\n ������ ��������");
        printf("\n ������ ����� ���� ���������");
        showDishList(pD->parent);
        pause();
        return 1;
    }
    return 0;
}
int delAllDishInMenu(void* ptr) {
    Kitchen* pK = (Kitchen*)ptr;
    printf("\n --- ��������� ��� ����� ---");
    if (confirm("\n�� ����� ������ �������� �� ������?")) {
        fprintf_s(logFile, "\n ��������� ��� �����");
        delAllDish(pK);
        printf("\n ������ ��������");
        pause();
    }
    return 0;
}

int delProductInMenu(void* ptr) {
    Product* pP = (Product*)ptr;
    printf("\n --- ��������� �������� %s ---", pP->name);
    showProductInfo(pP);
    if (confirm("�� ����� ������ �������� ��� �������?")) {
        fprintf_s(logFile, "\n ��������� �������� %s", pP->name);
        delProduct(pP);
        printf("\n ������� ��������");
        pause();
        return 1;
    }
    return 0;
}

int delAllProductInMenu(void* ptr) {
    Dish* pD = (Dish*)ptr;
    printf("\n --- ��������� ��� �������� ---");
    if (confirm("�� ����� ������ �������� �� ��������?")) {
        fprintf_s(logFile, "\n ��������� ��� ��������");
        delAllProducts(pD->parent);
        printf("\n �������� ��������");
        pause();
    }
    return 0;
}

int delKitchenInMenu(void* ptr) {
    Kitchen* pK = (Kitchen*)ptr;
    printf("\n --- ��������� ���� %s ---", pK->name);
    showKitchenInfo(pK);
    if (confirm("�� ����� ������ �������� ��� �����?")) {
        fprintf_s(logFile, "\n ��������� ���� %s", pK->name);
        delKitchen(pK);
        printf("\n ����� ��������");
        pause();
        return 1;
    }
    return 0;
}
