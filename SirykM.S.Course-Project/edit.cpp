#include "includes.h"
int editKitchenInfo(void* ptr) {
    Kitchen* k = (Kitchen*)ptr;
    printf("\n --- Ğåäàãóâàííÿ ³íôîğìàö³¿ ïğî êóõíş ---");
    printf("\n Äàí³, ÿê³ ìîæíà çì³íèòè:\n");
    showKitchenInfo(k);
    if (confirm("Âè ä³éñíî õî÷åòå çì³íèòè ö³ äàí³?")) {
        fprintf_s(logFile, "\nĞåäàãóâàííÿ äàíèõ ïğî êóõíş");
        fprintf_s(logFile, "\nÁóëî: %s, %d", k->name, k->workers);
        free(k->name);
        k->name = getStr("Íîâà íàçâà êóõí³:");
        k->workers = getInt("Íîâà ê³ëüê³ñòü ïğàö³âíèê³â:", 0, 100);
        fprintf_s(logFile, "\nÑòàëî: %s, %d", k->name, k->workers);
        printf("\n Äàí³ ï³ñëÿ ğåäàãóâàííÿ");
        showKitchenInfo(k);
    }
    return 0;
}

int editDishInfo(void* ptr) {
    Dish* pD = (Dish*)ptr;
    printf("\n --- Ğåäàãóâàííÿ ³íôîğìàö³¿ ïğî ñòğàâó ---");
    printf("\n Äàí³, ÿê³ ìîæíà çì³íèòè:\n");
    showDishInfo(pD);
    if (confirm("Âè ä³éñíî õî÷åòå çì³íèòè ö³ äàí³?")) {
        fprintf_s(logFile, "\nĞåäàãóâàííÿ ³íôîğìàö³¿ ïğî ñòğàâó");
        fprintf_s(logFile, "\nÁóëî: %s, %d, %d",
            pD->name, pD->minutes, pD->price);
        char* newName = getStr("Íîâà íàçâà ñòğàâè: ");
        pD->name = (char*)realloc(pD->name, strlen(newName) + 1);
        strcpy(pD->name, newName);
        free(newName);
        pD->minutes = getInt("Íîâèé ÷àñ ïğèãîòóâàííÿ â õâèëèíàõ: ", 1, 1000);
        pD->price = getInt("Íîâà ö³íà â ãğèâíÿõ: ", 0, 5000);
        fprintf_s(logFile, "\nÑòàëî: %s, %d, %d",
            pD->name, pD->minutes, pD->price);
        printf("\n Äàí³ ï³ñëÿ ğåäàãóâàííÿ");
        showDishList(pD->parent);
        pause();
    }
    return 0;
}

int editProductInfo(void* ptr) {
    Product* pD = (Product*)ptr;
    printf("\n --- Ğåäàãóâàííÿ ³íôîğìàö³¿ ïğî ïğîäóêò ---");
    printf("\n Äàí³, ùî ìîæíà çì³íèòè:\n");
    showProductInfo(pD);
    if (confirm("Âè ä³éñíî õî÷åòå çì³íèòè ö³ äàí³?")) {
        fprintf_s(logFile, "\nĞåäàãóâàííÿ ³íôîğìàö³¿ ïğî ïğîäóêò");
        fprintf_s(logFile, "\nÁóëî: %s, %d",
            pD->name, pD->mass);
        char* newName = getStr("Íîâà íàçâà ïğîäóêòó: ");
        pD->name = (char*)realloc(pD->name, strlen(newName) + 1);
        strcpy(pD->name, newName);
        free(newName);
        pD->mass = getInt("Íîâà ìàñà â ãğàìàõ: ", 1, 10000);
        fprintf_s(logFile, "\nÑòàëî: %s, %d",
            pD->name, pD->mass);
        printf("\n Äàí³ ï³ñëÿ ğåäàãóâàííÿ");
        showDishList(pD->parent);
        pause();
        return 0;
    }
    return 0;
}
