#include "includes.h"
int showProjectInfo(void*) {

    cout << "����� '�����'.\n"
        "��������� ѳ��� �.�., ʲ-233\n";
    cout << "\n�����: �����\n"
        "\t����: �����, ������� ����������\n"
        "1-� �����: ������ \n"
        "\t����: �����, ��� ������������, ����\n"
        "2-� �����: ������� \n"
        "\t ����: �����, ����\n";
    pause();
    return 0;
}
int showTree(void*) {
    if (!rootExist()) return 0;
    fprintf_s(logFile, "\n ������������ ������.");

    cout << "\n\t--- ��������� ������ ---\n";
    cout << "\n����� ��������� " << root->name << ", \n������� ����������: "
        << root->workers;
    Dish** dAr = root->DishArray;
    for (int i = 0; i < root->DishCount; i++) {
        cout << "\n\t������: " << dAr[i]->name << ",\n\t ��� ������������: "
            << dAr[i]->minutes << " ��., " << "ֳ��: "
            << dAr[i]->price << " ���.";
        Product* pP = dAr[i]->firstProduct;
        while (pP != NULL) {
            cout << " \n\t\t" << pP->name << ": " << pP->mass << " ��.";
            pP = pP->nextProduct;
        }
    }
    pause();
    fprintf_s(logFile, "\n������������ ������ ���������");
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
        cout << "\n\t����� \"" << root->name << "\" �������, ������ ������.";
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
    cout << "\n������ ����� ���� \"" << root->name << "\":";

    for (int i = 0; i < n; i++) {
        printf("\n ������: %s, ��� ���������: %d ������, ֳ��: %d ���.",
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
        printf("\n\t %s, ���� %d ��.",
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
    printf(" \n ����� ������: %s\n", ptr->name);
    printf(" ��� ������������: %d ������\n", ptr->minutes);
    printf(" ֳ��: %d\n", ptr->price);
    pause();
    return 0;
}

int showDishInfoInMenu(void* ptr) {
    Dish* DP = (Dish*)ptr;

    cout << " - ���������� ��� ������ - \n";
    cout << " ������ " << DP->parent->name << endl;
    showDishInfo(DP);
    cout << " ������ �������� � ����� " << calcProductDish(DP) << "\n";
    pause();
    return 0;
}
int showProductInfo(Product* ptr) {
    cout << " ����� ��������: " << ptr->name << endl;
    cout << " ���� ��������: " << ptr->mass << endl;
    pause();
    return 0;
}

int showProductInfoInMenu(void* ptr) {
    Product* DP = (Product*)ptr;

    cout << " - ���������� ��� ������� - \n";
    cout << " ������ " << DP->parent->name << endl;
    showProductInfo(DP);
    pause();
    return 0;
}

int showKitchenInfo(void* ptr) {
    Kitchen* pK = (Kitchen*)ptr;
    if (pK == NULL) {
        fprintf_s(logFile, "\n�������: ������� �������� �� �����");
        return 0;
    }
    printf("\n���������� ��� ����� \"%s\":", pK->name);
    printf("\nʳ������ ���������� ����: %d", pK->workers);
    int n = pK->DishCount;
    Dish** dAr = pK->DishArray;
    if (n > 0) {
        printf("\nʳ������ �����: %d", n);
    }
    else {
        printf("\n����� �������, ������ ������.");
    }
    printf("\n");
    pause();
    return 0;
}
