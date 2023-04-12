#include <stdio.h>
#include <stdlib.h>

int main() {
    int tabela[] = {3, 3, 2, 3, 3, 3, 3, 3, 8}; 
    int rozmiar = sizeof(tabela) / sizeof(tabela[0]);

    printf("Tabela przed zamiana: ");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", tabela[i]);
    }
    printf("\n");

    int lewy = 0; 
    int prawy = rozmiar - 1; 
    int znaleziono_pierwsza_parzysta = 0;
    int znaleziono_druga_parzysta = 0;

    while (lewy < prawy) {
        if (!znaleziono_pierwsza_parzysta && tabela[lewy] % 2 == 0) {
            znaleziono_pierwsza_parzysta = 1;
        }
        if (!znaleziono_druga_parzysta && tabela[prawy] % 2 == 0) {
            znaleziono_druga_parzysta = 1;
        }

        if (znaleziono_pierwsza_parzysta && znaleziono_druga_parzysta) {
            break;
        }

        if (!znaleziono_pierwsza_parzysta) {
            lewy++;
        }
        if (!znaleziono_druga_parzysta) {
            prawy--;
        }
    }

    if (znaleziono_pierwsza_parzysta && znaleziono_druga_parzysta) {
        int temp = tabela[lewy];
        tabela[lewy] = tabela[prawy];
        tabela[prawy] = temp;
    }

    printf("Tabela po zamianie: ");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d ", tabela[i]);
    }
    printf("\n");

    return 0;
}