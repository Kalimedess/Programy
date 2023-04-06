#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void wypiszTab(unsigned int n,int *tab){
    for(int i=0;i<n;i++){
        printf("%d\t",tab[i]);
    }
    printf("\n");
}
void nadajZero(unsigned int n,int *tab){
    for(int i=0;i<n;i++){
        tab[i]=0;
    }
}
void nadajIndex(unsigned int n,int *tab){
    for(int i=0;i<n;i++){
        tab[i]=i;
    }
}
void podwojElementy(unsigned int n,int *tab){
    for(int i=0;i<n;i++){
        tab[i]+=tab[i];
    }
}
void wyzerujIPodwoj(unsigned int n,int *tab){
    int mid;
    if(n%2!=0){
        mid=(n+1)/2;
    }else{
        mid=n/2;
    }
    for(int i=0;i<=mid;i++){
        tab[i]+=tab[i];
    }
    for(int b=mid;b<=n;b++){
        tab[b]=0;
    }
}
void absolute(unsigned int n,int *tab){
    for(int i=0;i<n;i++){
        tab[i]=abs(tab[i]);
    }
}
int sumaElementow(unsigned int n, int *tab){
    int wyn=0;
    for(int i=0;i<n;i++){
        wyn+=tab[i];
    }
    return wyn;
}
int sumaKwadratow(unsigned int n,int *tab){
    int wyn=0;
        for(int i=0;i<n;i++){
            wyn+=tab[i]*tab[i];
        }
        return wyn;
}
float sredniaElementow(unsigned int n,int *tab){
    int suma=0;
    float wyn=0;
        for(int i=0;i<n;i++){
            suma+=tab[i];
        }
    wyn=(float)suma/n;
    return wyn;
}
float sredniaGeometryczna(unsigned int n,unsigned int *tab){
    int iloczyn=1;
    float wyn=1;
        for(int i=0;i<n;i++){
            iloczyn*=tab[i];
        }
    wyn=pow(iloczyn,1.0/n);
    return wyn;
}
float sredniaHarmoniczna(unsigned int n,unsigned int *tab){
    float suma=0;
        for(int i=0;i<n;i++){
            suma+=(1.0/tab[i]);
        }
    return n/suma;
}
//Wzór do wykrywania liczb pierwszych
void sitoErastotenesa(unsigned int n){
    bool tab[n];
    int lastTrue=0;
    int ile=0;
    for(int i=0;i<n;i++){
        tab[i]=true;
    }
    tab[0]=false;
    tab[1]=false;

    for(int b=2;b<n;b++){
        if(tab[b]){
            lastTrue=b;
            ile++;
            for(int i=2*b;i<n;i+=b){
                tab[i]=false;
            }
            if(tab[b+2]){
                printf("blizniaczo pierwsze: %i i %i\n",b,b+2);
            }
        }
    }
    printf("Razem liczb pierwszych jest: %i\n",ile);
}
void replaceTab(unsigned int n,int *tab1,int *tab2){
    int j=n-1;
    for(int i=0;i<n;i++,j--){
        tab2[j]=tab1[i];
    }
}

int main()
{
    int tab[]={2,3,4,5,6};
    int tab2[]={1,9,8,7,10};
    wypiszTab(5,tab);
    wypiszTab(5,tab2);
    replaceTab(5,tab,tab2);
    wypiszTab(5,tab);
    wypiszTab(5,tab2);
    /**
     *int tab[4]={7,1,5,2};
      printf("%.2f\n",sredniaHarmoniczna(sizeof(tab)/sizeof(int),tab));
     *
     *nadajIndex(sizeof(tab)/sizeof(int),tab);
        wypiszTab(sizeof(tab)/sizeof(int),tab);
     *int tab2[5]={2,3,5,7,4};
        wyzerujIPodwoj(4,tab);
        wypiszTab(4,tab);
        wyzerujIPodwoj(5,tab2);
        wypiszTab(5,tab2);
     *printf("%i\n",sizeof(tab)/sizeof(int));
     */

}
