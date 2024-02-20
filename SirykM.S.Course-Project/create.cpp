#include "includes.h"

Kitchen* createKitchen(char* name, int workers) {
    Kitchen* kitchen = new Kitchen();
    kitchen->name = _strdup(name);
    kitchen->workers = workers;
    kitchen->arrSize = 2;
    kitchen->DishArray = new Dish * [kitchen->arrSize];
    kitchen->DishCount = 0;
    fprintf_s(logFile, "\nСтворено кухню %s", kitchen->name);
    return kitchen;
}

Dish* createDish(char* name, int minutes, int price) {
    Dish* dish = new Dish();
    dish->name = _strdup(name);
    dish->minutes = minutes;
    dish->price = price;
    dish->firstProduct = NULL;
    dish->parent = NULL;
    fprintf_s(logFile, "\nСтворено страву %s", dish->name);
    return dish;
}

Product* createProduct(char* name, int mass) {
    Product* product = new Product();
    product->name = _strdup(name);
    product->mass = mass;
    product->parent = NULL;
    product->nextProduct = NULL;
    fprintf_s(logFile, "\nСтворено продукт %s", product->name);
    return product;

}

Kitchen* createDefTree() {
    fprintf_s(logFile, "\nПочинаємо створювати дефолтне дерево\n");
    char* name = _strdup("\"Смачно, та й годі\"");
    Kitchen* kitchen = createKitchen(name, 1);
    Dish* dish1 = createDish(_strdup("Паста"), 20, 50);
    Dish* dish2 = createDish(_strdup("Голубці з фаршем і рисом"), 120, 130);
    addDish(kitchen, dish1);
    addDish(kitchen, dish2);
    Product* p1 = createProduct(_strdup("Спагеті"), 250);
    Product* p2 = createProduct(_strdup("Бекон"), 120);
    Product* p3 = createProduct(_strdup("Цибуля"), 50);
    Product* p4 = createProduct(_strdup("Петрушка"), 20);
    Product* p5 = createProduct(_strdup("Часник"), 10);
    Product* p6 = createProduct(_strdup("Сіль"), 20);
    Product* g1 = createProduct(_strdup("Капуста білокачанна"), 500);
    Product* g2 = createProduct(_strdup("Фарш"), 200);
    Product* g6 = createProduct(_strdup("Сметана"), 150);
    Product* g3 = createProduct(_strdup("Рис"), 100);
    Product* g7 = createProduct(_strdup("Томатна паста"), 100);
    Product* g4 = createProduct(_strdup("Цибуля"), 50);
    Product* g5 = createProduct(_strdup("Морква"), 50);
    Product* g8 = createProduct(_strdup("Сіль"), 20);
    addProduct(dish1, p1);
    addProduct(dish1, p2);
    addProduct(dish1, p3);
    addProduct(dish1, p4);
    addProduct(dish1, p5);
    addProduct(dish1, p6);
    addProduct(dish2, g1);
    addProduct(dish2, g2);
    addProduct(dish2, g3);
    addProduct(dish2, g4);
    addProduct(dish2, g5);
    addProduct(dish2, g6);
    addProduct(dish2, g7);
    addProduct(dish2, g8);
    fprintf_s(logFile, "\nДефолтне дерево створено\n");
    return kitchen;
}

int createDefTreeInMenu(void*) {
    if (root != NULL) {
        if (confirm("Дерево вже існує. Хочете його змінити?")) {
            delKitchen(root);
            fprintf_s(logFile, "\nДерево видалено");
        }
        else return 0;
    }
    root = createDefTree();
    fprintf_s(logFile, "\nСтворено дефолтне дерево");
    showTree(NULL);
    return 0;
}

int createRootInMenu(void*) {
    if (root != NULL) {
        if (confirm("Дерево вже існує. Хочете його змінити?")) {
            delKitchen(root);
            fprintf_s(logFile, "\nДерево видалено");
        }
        else return 0;
    }
    char* name = getStr("Назва кухні: ");
    int workers = getInt("Кількість працівників: ", 0, 100);
    root = createKitchen(name, workers);
    fprintf_s(logFile, "\nСтворено кухню %s", root->name);
    showTree(NULL);
    return 0;
}
