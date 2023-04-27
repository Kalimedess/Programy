#include <stdio.h>
#include <stdlib.h>

int ** alokuj(unsigned int n,unsigned int m){
    int**t=malloc(n*sizeof(int));
    int i;
    for(i=0;i<n;i++){
        t[i]=malloc(m*sizeof(int));
    }
    return t;
}
int(* alokuj2(unsigned int n,unsigned int m))[]{
    return malloc(n*sizeof(int[m]));
}
void wypisz(int **t,unsigned int n,unsigned int m){
    for(int i=0;i<n;i++){
        for(int b=0;b<m;b++){
            printf("%i",t[n][m]);
        }
        printf("\n");
    }
}
void wypisz2(unsigned int n,unsigned int m,int t[][m]){
    for(int i=0;i<n;i++){
        for(int b=0;b<m;b++){
            printf("%i ",t[n][m]);
        }
        printf("\n");
    }
}
void wczytaj(int **t,unsigned int n,unsigned int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%i",&t[i][j]);
        }
    }
}
//to samo
void wczytaj2(unsigned int n,unsigned int m, int t[][m]){
   for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%i",&t[i][j]);
        }
    }
}

int main()
{
    int t[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    wypisz2(3,3,t);


}
