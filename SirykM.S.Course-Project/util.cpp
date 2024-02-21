#include "includes.h"

void pause() {
    cout << "\n Для продовження натисніть будь-яку клавішу...\n";
    cin.ignore();
}
int rootExist() {
    if (root == NULL) {
        cout << "дерево не існує!" << endl;
        pause();
    }
    return root != NULL;
}

int dishExist() {
    if (root->DishCount == 0) {
        cout << "кухня порожня, відсутні страви!" << endl;
        pause();
        return 0;
    }
    return 1;
}
char* getStr(const char* prompt) {
    cout << prompt;
    string s;
    fflush(stdin);
    getline(cin >> ws, s);
    char* cStr = (char*)malloc(s.length() + 1);
    strncpy(cStr, s.c_str(), s.length() + 1);
    return cStr;
}
int getInt(const char* prompt, int min, int max) {
    int num; string s;
    do {
        printf("%s(%d..%d) ", prompt, min, max);
        fflush(stdin);
        getline(cin, s);
        num = atoi(s.c_str());
    } while (num < min || num > max);
    return num;
}

int confirm(const char* message) {
    char choice;
    printf("%s (1 - так): ", message);
    fflush(stdin);
    int result = scanf("%c", &choice);
    fflush(stdin);
    if (result < 1) {
        return 0;
    }
    return choice == '1';
}

Dish* selectDish() {

    printf("\n --- Вибір страви ---\n");
    int nDish = root->DishCount;
    Dish** dAr = root->DishArray;
    for (int i = 0; i < nDish; i++) {
        printf("\n %2d. Страва %s", i + 1, dAr[i]->name);
    }
    printf("\n %2d. Вихід\n", nDish + 1);
    int num = getInt("Ведіть ваш вибір: ", 1, nDish + 1);
    if (num == nDish + 1)
        return NULL;
    return root->DishArray[num - 1];
}

Product* selectProduct() {

    printf("\n --- Вибір продукту ---\n");
    Dish* dish = selectDish();
    if (dish == NULL)
        return NULL;
    Product* product = dish->firstProduct;
    if (product == NULL)
        return NULL;
    int n = 0;
    while (product != NULL) {
        printf("\n %2d. Продукт %s", n + 1, product->name);
        product = product->nextProduct;
        n++;
    }
    printf("\n %2d. Вихід\n", n + 1);
    int num = getInt("Ведіть ваш вибір: ", 1, n + 1);
    if (num == n + 1)
        return NULL;
    product = dish->firstProduct;
    for (int i = 1; i < num; i++)
        product = product->nextProduct;
    return product;
}
