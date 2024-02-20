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
        int v = getInt(" Введіть пункт: ", 1, cnt + 1);
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
    fprintf_s(logFile, "\nВиклик меню операцій з кухнею");
    MenuUnit menu[] = {
        {"Редагувати інформацію про кухню", editKitchenInfo},
        {"Видалити кухню", delKitchenInMenu},
        {"Видалити всі страви", delAllDishInMenu},
        {"Показати інформацію про кухню",showKitchenInfo},
        {"Показати список страв", showDishListInMenu},
        {"Додати страву", addDishInMenu},
        {"Повернутися до головного меню", NULL},
    };
    runMenu(menu, " Операції з кухнею ", root);
    return 0;
}

int menuTreeOperation(void* ptr) {
    fprintf_s(logFile, "\nВиклик меню операцій з деревом");
    MenuUnit menu[] = {
        {"Створити корінь", createRootInMenu},
        {"Створити дефолтне дерево", createDefTreeInMenu},
        {"Показати інформацію про проєкт", showProjectInfo},
        {"Показати дерево", showTree},
        {"Показати Log-файл", showLogFile},
        {"Зберегти у файл", saveTreeInMenu},
        {"Відновити з файлу", restoreTreeInMenu},
        {"Повернутися до головного меню", NULL} };
    runMenu(menu, " Операції з деревом ", root);
    return 0;
}

int menuDishOperation(void*) {
    if (!rootExist()) return 0;
    if (!dishExist()) return 0;
    Dish* pD = selectDish();
    if (pD == NULL) return 0;
    fprintf_s(logFile, "\n %s ", pD->name);
    MenuUnit menu[] = {
        {"Редагувати страву", editDishInfo},
        {"Видалити всі продукти", delAllProductInMenu},
        {"Додати продукт", addProductInMenu},
        {"Показати список продуктів", showProductListInMenu},
        {"До головного меню", NULL},
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
        {"Редагувати продукт", editProductInfo},
        {"Видалити продукт", delProductInMenu},
        {"Показати інформацію про продукт", showProductInfoInMenu},
        {"До головного меню", NULL},
    };
    runMenu(menu, pP->name, pP);
    return 0;
}

int menuQuertyOperation(void*) {
    fprintf_s(logFile, "\nВиклик меню операцій запитів");
    MenuUnit menu[] = {
        {"Знайти 3 найващі продукти страви", findNewestProductInMenu},
        {"Знайти найдорожчу страву та найдешевшу", findExpensiveCheapDish},
        {"Об'єм пам'яті, який займає все дерево", calcMemory},
        {"До головного меню", NULL},
    };
    runMenu(menu, " Операції запитів ", NULL);
    return 0;
}

int mainMenu(void* ptr) {
    fprintf_s(logFile, "\nВиклик головного меню застосунку");
    MenuUnit menu[] = {
        {"Операції з кухнею", menuKitchenOperation},
        {"Операції зі стравою", menuDishOperation},
        {"Операції з продуктом", menuProductOperation},
        {"Операції з деревом", menuTreeOperation},
        {"Операції запитів", menuQuertyOperation},
        {"Вийти з проєкту", NULL}
    };
    runMenu(menu, " Головне меню ", ptr);
    return 0;
}
