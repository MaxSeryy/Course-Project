#include "includes.h"
Product* sortProductsByMass(Product* head) {
    if (head == NULL || head->nextProduct == NULL) {
        return head;
    }
    Product* sorted = NULL;
    Product* current = head;
    while (current != NULL) {
        Product* next = current->nextProduct;
        if (sorted == NULL || current->mass > sorted->mass) {
            current->nextProduct = sorted;
            sorted = current;
        } else {
            Product* temp = sorted;
            while (temp->nextProduct != NULL && temp->nextProduct->mass > current->mass) {
                temp = temp->nextProduct;
            }
            current->nextProduct = temp->nextProduct;
            temp->nextProduct = current;
        }
        current = next;
    }
    return sorted;
}

int calcProductDish(Dish* ptr) {
    int count = 0;
    Product* pD = ptr->firstProduct;
    while (pD != NULL) {
        count++;
        pD = pD->nextProduct;
    }
    return count;
}

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
    printf("\nОб'єм пам'яті, який займає(-ють):");
    printf("\nДерево: %d байт", totalSize + dishSize + productSize);
    printf("\nКухня: %d байт", sizeof(Kitchen) + strlen(root->name) + 1);
    printf("\nСтрави: %d байт", dishSize);
    printf("\nПродукти: %d байт", productSize);
    pause();
    return 0;
}
