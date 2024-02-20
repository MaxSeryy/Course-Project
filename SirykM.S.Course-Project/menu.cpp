#include "includes.h"
typedef int MenuFunc(void*);

struct MenuUnit{
     const char *text;
     MenuFunc *func;

 };

void runMenu(MenuUnit menu[], const char* title, void* ptr) {
    while (true) {

        printf("\n=== %s ===\n", title);
        int cnt = 0;
        for (;; cnt++) {
            printf("%2d. %s\n", cnt + 1, menu[cnt].text);
            if (menu[cnt].func == NULL)
                break;
        }
        int v = getInt(" ������ �����: ", 1, cnt + 1);
        if (menu[v - 1].func == NULL)
            return;
        int result = menu[v - 1].func(ptr);
        if (result != 0) {
            return;
        }
    }
}

int menuKitchenOperation(void*) {
    if (!rootExist()) return 0;
    fprintf_s(logFile, "\n������ ���� �������� � ������");
    MenuUnit menu[] = {
        {"���������� ���������� ��� �����", editKitchenInfo},
        {"�������� �����", delKitchenInMenu},
        {"�������� �� ������", delAllDishInMenu},
        {"�������� ���������� ��� �����",showKitchenInfo},
        {"�������� ������ �����", showDishListInMenu},
        {"������ ������", addDishInMenu},
        {"����������� �� ��������� ����", NULL},
    };
    runMenu(menu, " �������� � ������ ", root);
    return 0;
}

int menuTreeOperation(void* ptr) {
    fprintf_s(logFile, "\n������ ���� �������� � �������");
    MenuUnit menu[] = {
        {"�������� �����", createRootInMenu},
        {"�������� �������� ������", createDefTreeInMenu},
        {"�������� ���������� ��� �����", showProjectInfo},
        {"�������� ������", showTree},
        {"�������� Log-����", showLogFile},
        {"�������� � ����", saveTreeInMenu},
        {"³������� � �����", restoreTreeInMenu},
        {"����������� �� ��������� ����", NULL} };
    runMenu(menu, " �������� � ������� ", root);
    return 0;
}

int menuDishOperation(void*) {
    if (!rootExist()) return 0;
    if (!dishExist()) return 0;
    Dish* pD = selectDish();
    if (pD == NULL) return 0;
    fprintf_s(logFile, "\n %s ", pD->name);
    MenuUnit menu[] = {
        {"���������� ������", editDishInfo},
        {"�������� �� ��������", delAllProductInMenu},
        {"������ �������", addProductInMenu},
        {"�������� ������ ��������", showProductListInMenu},
        {"�� ��������� ����", NULL},
    };
    runMenu(menu, pD->name, pD);
    return 0;
}

int menuProductOperation(void*) {
    if (!rootExist()) return 0;
    if (!dishExist()) return 0;
    Product* pP = selectProduct();
    if (pP == NULL) return 0;
    fprintf_s(logFile, "\n %s ", pP->name);
    MenuUnit menu[] = {
        {"���������� �������", editProductInfo},
        {"�������� �������", delProductInMenu},
        {"�������� ���������� ��� �������", showProductInfoInMenu},
        {"�� ��������� ����", NULL},
    };
    runMenu(menu, pP->name, pP);
    return 0;
}

int menuQuertyOperation(void*) {
    fprintf_s(logFile, "\n������ ���� �������� ������");
    MenuUnit menu[] = {
        {"������ 3 ������� �������� ������", findNewestProductInMenu},
        {"������ ���������� ������ �� ����������", findExpensiveCheapDish},
        {"��'�� ���'��, ���� ����� ��� ������", calcMemory},
        {"�� ��������� ����", NULL},
    };
    runMenu(menu, " �������� ������ ", NULL);
    return 0;
}

int mainMenu(void* ptr) {
    fprintf_s(logFile, "\n������ ��������� ���� ����������");
    MenuUnit menu[] = {
        {"�������� � ������", menuKitchenOperation},
        {"�������� � �������", menuDishOperation},
        {"�������� � ���������", menuProductOperation},
        {"�������� � �������", menuTreeOperation},
        {"�������� ������", menuQuertyOperation},
        {"����� � ������", NULL}
    };
    runMenu(menu, " ������� ���� ", ptr);
    return 0;
}
