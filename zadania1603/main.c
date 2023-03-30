#include <stdio.h>
#include <stdlib.h>

int funcRecur(n,m){
    if(n==0 && m==0)
        return 0;
    if(m==0)
        return n;
    if(n==0)
        return m;
    return funcRecur(n-1,m)+funcRecur(n,m-1)+funcRecur(n-1,m-1);
}

int recur2(int n){
    if(n<3)
        return 1;
    if(n%3==0)
        return recur2(n-1)+recur2(n-2);
    if(n%3==1)
        return 5*recur2(n-1)+4;
    if(n%3==2)
        return recur2(n-1)+1;
}
int recurNaPrzemiennie(int n){
    if(n<2)
        return 1;
    if(n%2==0)
        return recurNaPrzemiennie(n-1)+n;
    else
        return recurNaPrzemiennie(n-1)*n;
}
int recur(int n){
    int wyn=0;
    if(n==0)
        return 1;
    for(int i=0;i<n;i++){
        wyn+=recur(i);
    }
    return wyn;
}
float ciagFibonnacciego(int n){
    if(n<2)
        return 1;
    return ciagFibonnacciego(n-1)+ciagFibonnacciego(n-2);
}
int rekurCiag(int n){
    if(n==0 || n==1)
        return 1;
    return rekurCiag(n-1)+2*rekurCiag(n-2)+3;
}
void zlicz(int x){
    static int suma=0;
    suma+=x;
    printf("Funkcja zostala wywolana  na argumentach o lacznej wartosci %i \n",suma);
}
unsigned int sumaDzielnikow(unsigned int a){
    int wyn=0;
    for(int i=2;i<a;i++){
        if(najwiekszyWspolnyDzielnik(a,i)==1){
            wyn+=i;
        }
    }
    return wyn;
}
void max_sum(){
    int x=0;
    int i;
    int saveI;
    for(i=0;i<=999;i++){
        if(sumaDzielnikow(i)>x){
            x=sumaDzielnikow(i);
            saveI=i;
        }
    }
    printf("Maksymalna suma liczb wzglednie pierwszych od danej liczby w zakresie\n od 1 do 999 wynosi %i i jest osiagana dla %i\n",x,saveI);
}
void min_sum(){
    int x=sumaDzielnikow(997);
    int i;
    int saveI;
    for(i=100;i<1000;i++){
        if(sumaDzielnikow(i)<x){
            x=sumaDzielnikow(i);
            saveI=i;
        }
    }
    printf("Maksymalna suma liczb wzglednie pierwszych od danej liczby w zakresie\n od 100 do 999 wynosi %i i jest osiagana dla %i\n",x,saveI);
}
int najwiekszyWspolnyDzielnik(unsigned int a,unsigned int b){
    unsigned int temp;
    if(a>b){
        temp=b;
        b=a;
        a=temp;
    }
    while(a%b!=0){
       temp=a;
        a=b;
        b=temp%b;
    }
    return b;
}


int main()
{
    for(int i=4;i>=0;i--){
        for(int b=0;b<=4;b++){
            printf("f(%i,%i)=%i\t",b,i,funcRecur(b,i));
        }
        printf("\n");
    }

    return 0;
}
