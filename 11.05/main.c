#include <stdio.h>
#include <stdlib.h>

void odwrocWeWszystkichWiersz(unsigned int n,unsigned int m,int tab[n][m]){
    int i,j;
    int pom;
    for(i=0;i<n;i++){
        for(j=0;j<m/2;j++){
            pom=tab[i][j];
            tab[i][j]=tab[i][m-1-j];
            tab[i][m-1-j]=pom;
        }
    }
}
//TODO: Zrob funkcje odwroc kolumny, albo odwroc wiersze z warunkiem
void wierszeWDol(int** tab,unsigned int n,unsigned int m){
    int i,j;
    int pom;
    for(j=0;j<m;j++){
        pom=tab[n-1][j];
        for(i=n-1;i>0;i--){
            tab[i][j]=tab[i-1][j];
            tab[0][j]=pom;
        }
    }
}
void wczytaj(int**tab,unsigned int n,unsigned int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&tab[i][j]);
        }
    }
}
void wypisz2(int** tab,unsigned int n,unsigned int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d\t",tab[i][j]);
        }
        printf("\n");
    }
}
void wypisz(unsigned int n,unsigned int m,int tab[n][m]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d\t",tab[i][j]);
        }
        printf("\n");
    }
}
int**alokuj(unsigned int n,unsigned int m){
    int** tab=malloc(n*sizeof(int*));
    int i;
    for(i=0;i<n;i++){
        tab[i]=malloc(m*sizeof(int));
    }
    return tab;
}
int main()
{
    int** tablica=alokuj(3,3);
    wczytaj(tablica,3,3);
    wierszeWDol(tablica,3,3);
    wypisz2(tablica,3,3);
}
