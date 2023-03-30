#include <stdio.h>
#include <stdlib.h>

int podwoj(int *x){
    *x=2**x;
    return *x;
}

int* mniejsza(int *a,int *b){
    if(*a<*b)
        return *a;
    return *b;
}
int adresMniejsza(int *a,int *b){
    if(*a<*b)
        return a;
    return b;
}
void swap(int *a,int *b){
    int *x=malloc(sizeof(int));
    *x=*a;
    *a=*b;
    *b=*x;
}
void swapIf(int *a, int *b){
    if(*a>*b){
        int *x=malloc(sizeof(int));
        *x=*a;
        *a=*b;
        *b=*x;
    }
}
int sumaStalych(int const *a, int const *b){
    return *a+*b;
}

void rewriteAddress(int n, int *w){
    *w=n;
}
int* rezerwuj(){
    return malloc(sizeof(int));
}
int* rezerwujTab(int n){
    return malloc(n*sizeof(int));
}
int func1(int n){
    return n-1;
}
int func2(int n){
    return n-1*n-1*n-1;
}
int func3(int (*f)(int x),int (*f2)(int b),int n){
    for(int i=0;i<=n;i++){
        if(f(i)!=f2(i))
            return 0;
    }
        return 1;
}

int main()
{
    int a=17;
    int b=9;

    printf("\n%i\n",a);
    printf("%i\n",b);
    printf("%i",func3(&func1,&func2,1));

    return 0;
}
