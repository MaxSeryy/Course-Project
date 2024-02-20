#include "includes.h"
int showProjectInfo(void*) {

    cout << "Проєкт 'Кухня'.\n"
        "Розробник Сірик М.С., КІ-233\n";
    cout << "\nКорінь: Кухня\n"
        "\tПоля: назва, кількість працівників\n"
        "1-й рівень: Страва \n"
        "\tПоля: назва, час приготування, ціна\n"
        "2-й рівень: продукт \n"
        "\t Поля: назва, вага\n";
    pause();
    return 0;
}
int showTree(void*) {
    if (!rootExist()) return 0;
    fprintf_s(logFile, "\n Демонстрація дерева.");

    cout << "\n\t--- Структура дерева ---\n";
    cout << "\nКухня ресторану " << root->name << ", \nкількість працівників: "
        << root->workers;
    Dish** dAr = root->DishArray;
    for (int i = 0; i < root->DishCount; i++) {
        cout << "\n\tСтрава: " << dAr[i]->name << ",\n\t Час приготування: "
            << dAr[i]->minutes << " хв., " << "Ціна: "
            << dAr[i]->price << " грн.";
        Product* pP = dAr[i]->firstProduct;
        while (pP != NULL) {
            cout << " \n\t\t" << pP->name << ": " << pP->mass << " гр.";
            pP = pP->nextProduct;
        }
    }
    pause();
    fprintf_s(logFile, "\nДемонстрацію дерева завершено");
    return 0;
}

int showLogFile(void*) {

    char buf[512];
    rewind(logFile);
    while (fgets(buf, 512, logFile) != NULL) {
        cout << buf;
    }
    pause();
    return 0;
}

int showDishList(void*) {
    int n = root->DishCount;
    Dish** dAr = root->DishArray;
    if (n == 0) {
        cout << "\n\tКухня \"" << root->name << "\" порожня, відсутні страви.";
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dAr[j]->price < dAr[j + 1]->price) {
                Dish* temp = dAr[j];
                dAr[j] = dAr[j + 1];
                dAr[j + 1] = temp;
            }
        }
    }
    cout << "\nПерелік страв кухні \"" << root->name << "\":";

    for (int i = 0; i < n; i++) {
        printf("\n Страва: %s, Час готування: %d хвилин, Ціна: %d грн.",
            dAr[i]->name, dAr[i]->minutes, dAr[i]->price);
    }
    printf("\n");
    return 0;
}

int showDishListInMenu(void*) {
    showDishList(NULL);
    printf("\n");
    pause();
    return 0;
}

int showProductList(Dish* ptr) {
    Dish* dish = (Dish*)ptr;
    Product* product = sortProductsByMass(dish->firstProduct);
    while (product != NULL) {
        printf("\n\t %s, вага %d гр.",
            product->name, product->mass);
        product = product->nextProduct;
    }
    return 0;
}

int showProductListInMenu(void* ptr) {
    Dish* dish = (Dish*)ptr;
    printf("\n%s:", dish->name);
    showProductList(dish);
    pause();
    return 0;
}

int showDishInfo(Dish* ptr) {
    printf(" \n Назва страви: %s\n", ptr->name);
    printf(" Час приготування: %d хвилин\n", ptr->minutes);
    printf(" Ціна: %d\n", ptr->price);
    pause();
    return 0;
}

int showDishInfoInMenu(void* ptr) {
    Dish* DP = (Dish*)ptr;

    cout << " - Інформація про страву - \n";
    cout << " Страва " << DP->parent->name << endl;
    showDishInfo(DP);
    cout << " Всього продуктів у страві " << calcProductDish(DP) << "\n";
    pause();
    return 0;
}
int showProductInfo(Product* ptr) {
    cout << " Назва продукту: " << ptr->name << endl;
    cout << " Вага продукту: " << ptr->mass << endl;
    pause();
    return 0;
}

int showProductInfoInMenu(void* ptr) {
    Product* DP = (Product*)ptr;

    cout << " - Інформація про продукт - \n";
    cout << " Страва " << DP->parent->name << endl;
    showProductInfo(DP);
    pause();
    return 0;
}

int showKitchenInfo(void* ptr) {
    Kitchen* pK = (Kitchen*)ptr;
    if (pK == NULL) {
        fprintf_s(logFile, "\nПомилка: Невірний вказівник на кухню");
        return 0;
    }
    printf("\nІнформація про кухню \"%s\":", pK->name);
    printf("\nКількість працівників кухні: %d", pK->workers);
    int n = pK->DishCount;
    Dish** dAr = pK->DishArray;
    if (n > 0) {
        printf("\nКількість страв: %d", n);
    }
    else {
        printf("\nкухня порожня, відсутні страви.");
    }
    printf("\n");
    pause();
    return 0;
}
