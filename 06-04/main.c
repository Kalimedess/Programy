#include <stdio.h>
#include <stdlib.h>

void wpiszSume(int n,int*tab1,int*tab2,int*tab3){
    for(int i=0;i<n;i++){
        tab3[i]=tab1[i]+tab2[i];
    }
}
void maksima(int n,int*tab1,int*tab2,int*tab3){
    for(int i=0;i<n;i++){
        if(tab2[i]>tab1[i]){
            tab3[i]=tab2[i];
        }else{
            tab3[i]=tab1[i];
        }
    }
}
void cykl(int n,int*tab1,int*tab2,int*tab3){
    int temp=0;
    for(int i=0;i<n;i++){
        temp=tab2[i];
        tab2[i]=tab1[i];
        tab1[i]=tab3[i];
        tab3[i]=temp;
    }
}
void concat(int n,int*tab1,int*tab2, int*tab3){
    for(int i=0;i<n;i++){
        tab3[i]=tab1[i];
    }
    for(int i=n;i<2*n;i++){
        tab3[i]=tab2[i-n];
    }
}
void concatNaprzemian(int n,int*tab1,int*tab2, int*tab3){
    for(int i=0;i<n*2;i++){
        if(i%2!=0){
            tab3[i]=tab1[i/2];
        }else{
            tab3[i]=tab2[i/2];
        }
    }

}
void sort(int n,int*tab1,int*tab2, int*tab3){
    int max,srod,min;
    for(int i=0;i<n;i++){
        if(tab1[i]<tab2[i] && tab3[i]>tab1[i]){
            min=tab1[i];
        }else if(tab2[i]>tab3[i]){
            min=tab3[i];
        }else{
            min=tab2[i];
        }
        if(tab1[i]>tab2[i] && tab1[i]>tab3[i]){
            max=tab1[i];
        }else if(tab2[i]>tab3[i]){
            max=tab2[i];
        }else{
            max=tab3[i];
        }
        if(tab1[i]<max && tab1[i]>min){
            srod=tab1[i];
        }else if(tab2[i]<max && tab2[i]>min){
            srod=tab2[i];
        }else{
            srod=tab3[i];
        }
        tab1[i]=max;
        tab2[i]=srod;
        tab3[i]=min;
    }
}
int max(unsigned int n,int*tab){
    int temp=tab[0];
    for(int i=1;i<n;i++){
        if(tab[i]>temp){
            temp=tab[i];
        }
    }
    return temp;
}
int maxIndex(unsigned int n,int*tab){
    int max=tab[0];
    int temp=0;
    for(int i=1;i<n;i++){
        if(tab[i]>max){
            max=tab[i];
            temp=i;
        }
    }
    return temp;
}
void shoveLeft(unsigned int n,int*tab){
    int temp=tab[0];
    for(int i=1;i<n;i++){
        tab[i-1]=tab[i];
    }
    tab[n-1]=temp;
}
int main()
{
    int rozmiar=4;
    int tab[4]={7,9,1,3};
    int tab2[4]={5,4,2,7};
    int tab3[4]={1,8,6,5};
    shoveLeft(rozmiar,tab);
    for(int i=0;i<4;i++){
        printf("%i ",tab[i]);
    }
}
