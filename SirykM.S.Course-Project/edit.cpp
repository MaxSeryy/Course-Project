#include "includes.h"
int editKitchenInfo(void* ptr) {
    Kitchen* k = (Kitchen*)ptr;
    printf("\n --- ����������� ���������� ��� ����� ---");
    printf("\n ���, �� ����� ������:\n");
    showKitchenInfo(k);
    if (confirm("�� ����� ������ ������ �� ���?")) {
        fprintf_s(logFile, "\n����������� ����� ��� �����");
        fprintf_s(logFile, "\n����: %s, %d", k->name, k->workers);
        free(k->name);
        k->name = getStr("���� ����� ����:");
        k->workers = getInt("���� ������� ����������:", 0, 100);
        fprintf_s(logFile, "\n�����: %s, %d", k->name, k->workers);
        printf("\n ��� ���� �����������");
        showKitchenInfo(k);
    }
    return 0;
}

int editDishInfo(void* ptr) {
    Dish* pD = (Dish*)ptr;
    printf("\n --- ����������� ���������� ��� ������ ---");
    printf("\n ���, �� ����� ������:\n");
    showDishInfo(pD);
    if (confirm("�� ����� ������ ������ �� ���?")) {
        fprintf_s(logFile, "\n����������� ���������� ��� ������");
        fprintf_s(logFile, "\n����: %s, %d, %d",
            pD->name, pD->minutes, pD->price);
        char* newName = getStr("���� ����� ������: ");
        pD->name = (char*)realloc(pD->name, strlen(newName) + 1);
        strcpy(pD->name, newName);
        free(newName);
        pD->minutes = getInt("����� ��� ������������ � ��������: ", 1, 1000);
        pD->price = getInt("���� ���� � �������: ", 0, 5000);
        fprintf_s(logFile, "\n�����: %s, %d, %d",
            pD->name, pD->minutes, pD->price);
        printf("\n ��� ���� �����������");
        showDishList(pD->parent);
        pause();
    }
    return 0;
}

int editProductInfo(void* ptr) {
    Product* pD = (Product*)ptr;
    printf("\n --- ����������� ���������� ��� ������� ---");
    printf("\n ���, �� ����� ������:\n");
    showProductInfo(pD);
    if (confirm("�� ����� ������ ������ �� ���?")) {
        fprintf_s(logFile, "\n����������� ���������� ��� �������");
        fprintf_s(logFile, "\n����: %s, %d",
            pD->name, pD->mass);
        char* newName = getStr("���� ����� ��������: ");
        pD->name = (char*)realloc(pD->name, strlen(newName) + 1);
        strcpy(pD->name, newName);
        free(newName);
        pD->mass = getInt("���� ���� � ������: ", 1, 10000);
        fprintf_s(logFile, "\n�����: %s, %d",
            pD->name, pD->mass);
        printf("\n ��� ���� �����������");
        showDishList(pD->parent);
        pause();
        return 0;
    }
    return 0;
}
