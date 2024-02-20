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

//функція для обрахунку об'єму пам'яті якиу займає все дерево, окремо кухня, окремо всі страви, окремо всі продукти
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
