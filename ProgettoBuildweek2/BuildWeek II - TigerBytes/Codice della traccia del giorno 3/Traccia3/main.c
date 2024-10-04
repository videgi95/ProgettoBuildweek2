#include "progetto.h"

int main() {
    int choice;

    do {
        choice = getMenuChoice();

        switch(choice) {
            case 1:
                errorProne();
                break;
            case 2:
                correct();
                break;
            case 3:
                printf("Programma terminato.\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (choice != 3);

    return 0;
}
