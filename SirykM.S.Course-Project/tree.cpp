#include "includes.h"
void saveText(char* text, FILE* file) {
    int l = strlen(text) + 1;
    fwrite(&l, sizeof(int), 1, file);
    fwrite(text, sizeof(char), l, file);
}

void saveTree(FILE* file, Kitchen* root) {
    fwrite(root, sizeof(Kitchen), 1, file);
    saveText(root->name, file);
    Dish** DishAr = root->DishArray;
    for (int i = 0; i < root->DishCount; i++)
    {
        fwrite(DishAr[i], sizeof(Dish), 1, file);
        saveText(DishAr[i]->name, file);
        Product* p = DishAr[i]->firstProduct;
        while (p != NULL) {
            fwrite(p, sizeof(Product), 1, file);
            saveText(p->name, file);
            p = p->nextProduct;
        }
    }
}

int saveTreeInMenu(void* ptr) {
    printf("\n - ���������� ������ � ���� ---");
    if (root == NULL) {
        printf("\n������ �� ����.");
        pause();
        return 0;
    }
    char* fileName = getStr("\n������ ����� �����: ");
    FILE* f = fopen(fileName, "wb");
    if (f == NULL) {
        printf("\nHe������� ������� ���� %s", fileName);
        pause();
    }
    else {
        saveTree(f, root);
        printf("\n������ ��������� � ���� %s", fileName);
        fprintf_s(logFile, "\n������ ��������� � ���� %s", fileName);
        fclose(f);
        pause();
    }
    return 0;
}

char* restoreText(FILE* file) {
    int l;
    fread(&l, sizeof(int), 1, file);
    char* text = new char[l];
    fread(text, sizeof(char), l, file);
    return text;
}

Product* restoreProduct(FILE* file, Dish* parent) {
    Product* product = new Product;
    product->parent = parent;
    fread(product, sizeof(Product), 1, file);
    if (product == NULL)
        return NULL;
    product->name = restoreText(file);
    return product;
}

void restoreTree(FILE* file) {
    root = new Kitchen();
    fread(root, sizeof(Kitchen), 1, file);
    root->name = restoreText(file);
    Dish** dishArr = new Dish * [root->arrSize];
    root->DishArray = dishArr;
    for (int i = 0; i < root->DishCount; i++) {
        dishArr[i] = new Dish();
        fread(dishArr[i], sizeof(Dish), 1, file);
        dishArr[i]->name = restoreText(file);
        if (dishArr[i]->firstProduct != NULL) {
            dishArr[i]->firstProduct = restoreProduct(file, dishArr[i]);
            Product* product = dishArr[i]->firstProduct;

            while (product->nextProduct != NULL) {
                product->nextProduct = restoreProduct(file, dishArr[i]);
                product = product->nextProduct;
            }
        }
    }
}

int restoreTreeInMenu(void*) {

    cout << "\n\t --- ³������� ������ � ����� ---\n";
    char* fileName = getStr("������ ����� �����: ");
    FILE* f = fopen(fileName, "rb");
    if (f == NULL) {
        cout << " ������� �������� �����" << fileName << endl;
        pause();
        return 1;
    }
    restoreTree(f);
    fclose(f);
    cout << " ������ ��������� � ����� " << fileName << endl;
    fprintf_s(logFile, "\n %s ", fileName);
    pause();
    showTree(NULL);
    return 0;
}
