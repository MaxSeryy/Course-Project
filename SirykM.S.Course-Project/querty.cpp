#include "includes.h"
int calcProductDish(Dish* ptr) {
    int count = 0;
    Product* pD = ptr->firstProduct;
    while (pD != NULL) {
        count++;
        pD = pD->nextProduct;
    }
    return count;
}

//������� ��� ��������� ��'��� ���'�� ���� ����� ��� ������, ������ �����, ������ �� ������, ������ �� ��������
int calcMemory(void* ptr) {
    if (!rootExist()) return 0;
    int totalSize = sizeof(Kitchen) + strlen(root->name) + 1;
    int dishSize = 0;
    int productSize = 0;
    Dish** dAr = root->DishArray;
    int n = root->DishCount;
    for (int i = 0; i < n; i++) {
        dishSize += sizeof(Dish) + strlen(dAr[i]->name) + 1;
        Product* pP = dAr[i]->firstProduct;
        while (pP != NULL) {
            productSize += sizeof(Product) + strlen(pP->name) + 1;
            pP = pP->nextProduct;
        }
    }
    printf("\n��'�� ���'��, ���� �����(-���):");
    printf("\n������: %d ����", totalSize + dishSize + productSize);
    printf("\n�����: %d ����", sizeof(Kitchen) + strlen(root->name) + 1);
    printf("\n������: %d ����", dishSize);
    printf("\n��������: %d ����", productSize);
    pause();
    return 0;
}
