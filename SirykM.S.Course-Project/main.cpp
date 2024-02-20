#include "includes.h"
Kitchen* root;
FILE* logFile;
int main(int argc, char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    logFile = fopen("logSiryk", "wt+");
    fprintf(logFile, "\nПроєкт 'Кухня' стартував.\n");
    showProjectInfo(NULL);
    root = createDefTree();
    showTree(NULL);
    mainMenu(root);
    fprintf(logFile, "\nРоботу з проєктом 'Кухня' завершено.\n");
    showLogFile(NULL);
    fclose(logFile);
    return 0;
}
