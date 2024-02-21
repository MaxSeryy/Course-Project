#include "includes.h"
int findNewestProductInMenu(void* ptr) {
    if (!rootExist()) return 0;
    if (!dishExist()) return 0;
    Dish* pD = selectDish();
    if (pD == NULL) return 0;
    fprintf_s(logFile, "\n %s ", pD->name);
    Product* pP = pD->firstProduct;
    if (pP == NULL) {
        printf("\n������� ������ �� �� ��������");
        pause();
        return 0;
    }
    Product* p1 = NULL;
    Product* p2 = NULL;
    Product* p3 = NULL;
    while (pP != NULL) {
        if (p1 == NULL || pP->mass > p1->mass) {
            p3 = p2;
            p2 = p1;
            p1 = pP;
        }
        else if (p2 == NULL || pP->mass > p2->mass) {
            p3 = p2;
            p2 = pP;
        }
        else if (p3 == NULL || pP->mass > p3->mass) {
            p3 = pP;
        }
        pP = pP->nextProduct;
    }
    printf("\n3 ������� �������� ������ %s:", pD->name);
    if (p1 != NULL) printf("\n1. %s, %d ��.", p1->name, p1->mass);
    if (p2 != NULL) printf("\n2. %s, %d ��.", p2->name, p2->mass);
    if (p3 != NULL) printf("\n3. %s, %d ��.", p3->name, p3->mass);
    pause();
    return 0;
}

int findExpensiveCheapDish(void* ptr) {
    if (!rootExist()) return 0;
    if (!dishExist()) return 0;
    Dish** dAr = root->DishArray;
    int n = root->DishCount;
    if (n == 0) {
        printf("\n����� �������, ������ ������");
        pause();
        return 0;
    }
    Dish* p1 = dAr[0];
    Dish* p2 = dAr[0];
    for (int i = 1; i < n; i++) {
        if (dAr[i]->price > p1->price) p1 = dAr[i];
        if (dAr[i]->price < p2->price) p2 = dAr[i];
    }
    printf("\n���������� ������: %s, %d ���.", p1->name, p1->price);
    printf("\n���������� ������: %s, %d ���.", p2->name, p2->price);
    pause();
    return 0;
}
