#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void wypisz(unsigned int n,unsigned int m,int tab[n][m]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d\t",tab[i][j]);
        }
        printf("\n");
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

void zeruj(unsigned int n,unsigned int m,int tab[n][m]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            tab[i][j]=0;
        }
    }
}
void zeruj2(int**tab,unsigned int n,unsigned int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            tab[i][j]=0;
        }
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
void wczytaj(int**tab,unsigned int n,unsigned int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&tab[i][j]);
        }
    }
}
int sumaEl(unsigned int n,unsigned int m,int tab[n][m]){
    int i,j;
    int suma=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            suma+=tab[i][j];
        }
    }
    return suma;
}
//TODO: dokoñcz(zwraca int)
void sumaEl2(int**tab,unsigned int n,unsigned int m){

}

int maxAvgIndex(unsigned int n,unsigned int m,int tab[n][m]){
    int i,j,index;
    int max=0;
    int suma=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            suma+=tab[i][j];

        }
        if(i==0){
            max=suma;
            index=0;
        }
        if(suma>max){
            max=suma;
            index=i;
        }
         suma=0;
        }
    return index;
}

float maxAvg(unsigned int n,unsigned int m,int tab[n][m]){
    int i,j;
    int max=0;
    int suma=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            suma+=tab[i][j];

        }
        if(i==0){
            max=suma;
        }
        if(suma>max){
            max=suma;
        }
         suma=0;
        }
    return (float)(max)/m;
}

void przepisz(int**tab,int**tab2,unsigned int n,unsigned int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
                tab2[i][j]=tab[i][j];
        }
    }
}
void zamiana(int**tab,int**tab2,unsigned int n,unsigned int m){
    int i,j,pom;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
                pom=tab2[i][j];
                tab2[i][j]=tab[i][j];
                tab[i][j]=pom;
        }
    }
}

void tarczaDoRzutek(int **tab,unsigned int n){
    int i,j;
    tab=alokuj(n,n);
    for(i=0;i<n;i++){
        for(j=0;j<=n/2;j++){
            /**
                mo¿e zadzia³a
              if(i==0||i==n-1){
                tab[i][j]=1;
                }else if(i>0 && j>0 && j<n-1){
                    tab[i][j]=2;
                }else{
                    tab[i][j]=1;
                }
             */
            if(i<(n+1)/2&&j<(n+1)/2){
                tab[i][j]=fmin(i,j)+1;
            }else if(i>0 && i<n-1 && j>0 && j<n-1){
                tab[i][j]=n-i;
            }else{
                tab[i][j]=1;
            }
        }
    }
    for(i=(n+1)/2;i<n;i++){
        for(j=0;j<(n+1)/2;j++){
            tab[i][j]=tab[n-i-1][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=(n+1)/2;j<n;j++){
            tab[i][j]=tab[i][n-j-1];
        }
    }

    wypisz2(tab,n,n);
}
int min4(int x,int y,int z,int w){
    if(x>=y&&z>=y&&w>=y){
        return y;
    }else if(y>=x&&z>=x&&w>=x){
        return x;
    }else if(x>=z&&y>=z&&w>=z){
        return z;
    }else{
        return w;
    }
}
void tarczaDoRzutek2(int **tab,unsigned int n){
    int i,j;
    tab=alokuj(n,n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            tab[i][j]=min4(i,j,n-i-1,n-j-1)+1;
        }
    }
    wypisz2(tab,n,n);
}
//TODO zrobiæ drug¹ wersjê, ALSO nie dzia³a
void odwrocWeWszystkichWiersz(unsigned int n,unsigned int m,int tab[n][m]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m/2;j++){
            tab[i][j]=tab[i][m-j-1];
        }
    }
}

int main()
{
    int tab[2][3]={{1,2,3},{4,5,6}};
    odwrocWeWszystkichWiersz(2,3,tab);
    wypisz(2,3,tab);
}
