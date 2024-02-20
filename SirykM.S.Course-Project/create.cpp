#include "includes.h"

Kitchen* createKitchen(char* name, int workers) {
    Kitchen* kitchen = new Kitchen();
    kitchen->name = _strdup(name);
    kitchen->workers = workers;
    kitchen->arrSize = 2;
    kitchen->DishArray = new Dish * [kitchen->arrSize];
    kitchen->DishCount = 0;
    fprintf_s(logFile, "\n�������� ����� %s", kitchen->name);
    return kitchen;
}

Dish* createDish(char* name, int minutes, int price) {
    Dish* dish = new Dish();
    dish->name = _strdup(name);
    dish->minutes = minutes;
    dish->price = price;
    dish->firstProduct = NULL;
    dish->parent = NULL;
    fprintf_s(logFile, "\n�������� ������ %s", dish->name);
    return dish;
}

Product* createProduct(char* name, int mass) {
    Product* product = new Product();
    product->name = _strdup(name);
    product->mass = mass;
    product->parent = NULL;
    product->nextProduct = NULL;
    fprintf_s(logFile, "\n�������� ������� %s", product->name);
    return product;

}

Kitchen* createDefTree() {
    fprintf_s(logFile, "\n�������� ���������� �������� ������\n");
    char* name = _strdup("\"������, �� � ���\"");
    Kitchen* kitchen = createKitchen(name, 1);
    Dish* dish1 = createDish(_strdup("�����"), 20, 50);
    Dish* dish2 = createDish(_strdup("������� � ������ � �����"), 120, 130);
    addDish(kitchen, dish1);
    addDish(kitchen, dish2);
    Product* p1 = createProduct(_strdup("������"), 250);
    Product* p2 = createProduct(_strdup("�����"), 120);
    Product* p3 = createProduct(_strdup("������"), 50);
    Product* p4 = createProduct(_strdup("��������"), 20);
    Product* p5 = createProduct(_strdup("������"), 10);
    Product* p6 = createProduct(_strdup("ѳ��"), 20);
    Product* g1 = createProduct(_strdup("������� ����������"), 500);
    Product* g2 = createProduct(_strdup("����"), 200);
    Product* g6 = createProduct(_strdup("�������"), 150);
    Product* g3 = createProduct(_strdup("���"), 100);
    Product* g7 = createProduct(_strdup("������� �����"), 100);
    Product* g4 = createProduct(_strdup("������"), 50);
    Product* g5 = createProduct(_strdup("������"), 50);
    Product* g8 = createProduct(_strdup("ѳ��"), 20);
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
    fprintf_s(logFile, "\n�������� ������ ��������\n");
    return kitchen;
}

int createDefTreeInMenu(void*) {
    if (root != NULL) {
        if (confirm("������ ��� ����. ������ ���� ������?")) {
            delKitchen(root);
            fprintf_s(logFile, "\n������ ��������");
        }
        else return 0;
    }
    root = createDefTree();
    fprintf_s(logFile, "\n�������� �������� ������");
    showTree(NULL);
    return 0;
}

int createRootInMenu(void*) {
    if (root != NULL) {
        if (confirm("������ ��� ����. ������ ���� ������?")) {
            delKitchen(root);
            fprintf_s(logFile, "\n������ ��������");
        }
        else return 0;
    }
    char* name = getStr("����� ����: ");
    int workers = getInt("ʳ������ ����������: ", 0, 100);
    root = createKitchen(name, workers);
    fprintf_s(logFile, "\n�������� ����� %s", root->name);
    showTree(NULL);
    return 0;
}
