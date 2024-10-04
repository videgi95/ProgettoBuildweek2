#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define VECTOR_SIZE 10

void errorProne();
void correct();
int getMenuChoice();

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

int getMenuChoice() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Esegui versione con errore\n");
    printf("2. Esegui versione corretta\n");
    printf("3. Esci\n");
    printf("Inserisci la tua scelta: ");
    scanf("%d", &choice);
    return choice;
}

void errorProne() {
    int vector[10], i, j, k;
    int swap_var;
    
    printf("Inserire 10 interi:\n");
    for (i = 0; i < 15; i++) {
        int c = i + 1;
        printf("[%d]:", c);
        scanf("%d", &vector[i]);
    }
    
    printf ("Il vettore inserito e':\n");
    for ( i = 0 ; i < 10 ; i++){
        int t= i+1;
        printf("[%d]: %d", t, vector[i]);
	    printf("\n");
	}


    for (j = 0 ; j < 10 - 1; j++){
	    for (k = 0 ; k < 10 - j - 1; k++){
			if (vector[k] > vector[k+1])
			{
			swap_var=vector[k];
			vector[k]=vector[k+1];
			vector[k+1]=swap_var;
			}
		}
	}
    printf("Il vettore ordinato e':\n");
    for (j = 0; j < 10; j++){
	     int g = j+1;
	     printf("[%d]:", g);
	     printf("%d\n", vector[j]);
	}
}


void correct() {
    int vector[VECTOR_SIZE],i,j,k,c;
    char buffer[100];
    long input;
    char *endptr;
    int swap_var;

    // Pulisce il buffer di input da eventuali caratteri residui
    while ((c = getchar()) != '\n' && c != EOF);

    // Ciclo per inserire VECTOR_SIZE numeri nell'array
    for (i = 0; i < VECTOR_SIZE; i++) {
    // Ciclo infinito per gestire input non validi
	    while (1) {
	        // Prompt per l'inserimento del numero
	        printf("Inserisci il numero %d (su %d): ", i + 1, VECTOR_SIZE);
	        
	        // Legge l'input dell'utente in modo sicuro
	        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
	            printf("Errore di input. Riprova.\n");
	            continue;  // Richiede nuovo input in caso di errore
	        }
	        
	        // Rimuove il carattere newline dalla fine dell'input
	        buffer[strcspn(buffer, "\n")] = 0;
	        
	        // Ignora l'input vuoto
	        if (strlen(buffer) == 0) {
	            continue;  // Richiede nuovo input se la stringa è vuota
	        }
	        
	        // Converte la stringa in numero long int
	        input = strtol(buffer, &endptr, 10);
	        
	        // Verifica se la conversione è avvenuta correttamente
	        if (endptr == buffer || *endptr != '\0') {
	            printf("Input non valido. Inserisci un numero intero.\n");
	            continue;  // Richiede nuovo input se non è un numero valido
	        }
	        
	        // Controlla se il numero è nel range degli int
	        if (input > INT_MAX || input < INT_MIN) {
	            printf("Numero fuori dal range degli interi. Riprova.\n");
	            continue;  // Richiede nuovo input se fuori dal range
	        }
	        
	        // Assegna il valore convertito all'array
	        vector[i] = (int)input;
	        break;  // Esce dal ciclo while se l'input è valido
	    }
    }

    printf("Vettore inserito:\n");
    for (i = 0; i < VECTOR_SIZE; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    
    for (j = 0 ; j < 10 - 1; j++){
	    for (k = 0 ; k < 10 - j - 1; k++){
			if (vector[k] > vector[k+1])
			{
			swap_var=vector[k];
			vector[k]=vector[k+1];
			vector[k+1]=swap_var;
			}
		}
	}
    printf("Il vettore ordinato e':\n");
    for (j = 0; j < 10; j++){
	     int g = j+1;
	     printf("[%d]:", g);
	     printf("%d\n", vector[j]);
	}
}



