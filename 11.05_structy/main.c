#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/** zadania z trojkatami

struct trojkat{
    double a,b,c;
};
double obwod(struct trojkat t){
    return t.a+t.b+t.c;
}
double Pole(struct trojkat t2){
    double h;
    if(t2.a==t2.b && t2.a==t2.c){
        h=t2.a*sqrt(2);
    }else{
        h=(t2.a+t2.b+t2.c)/2;
    }
    return (t2.a*h)/2;
}

bool czyTworzaTrojkat(struct trojkat t3){
    if(t3.a>0&&t3.b>0&&t3.c>0){
        if(t3.a+t3.b>t3.c || t3.b+t3.c>t3.a || t3.c+t3.a>t3.b){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

void przepiszPodWskaznik(struct trojkat t4,struct trojkat * twsk){
    *twsk=t4;
}
void wypiszWskaznik(struct trojkat twsk){
    printf("%f\n",twsk.a);
    printf("%f\n",twsk.b);
    printf("%f\n",twsk.c);

}

int main(){
    struct trojkat t1;
    t1.a=4;
    t1.b=4;
    t1.c=5;
    struct trojkat t2;
    t2.a=1;
    t2.b=2;
    t2.c=3;
    struct trojkat *wsk2=&t2;
    przepiszPodWskaznik(t1,wsk2);
    wypiszWskaznik(*wsk2);
}
 */
/** STRUCTY PUNKTÓW ORAZ ZESPOLONEJ LICZBY
struct punkt{
    double x,y,z;
};
struct zespolona{
    double re,im;
};
void wypiszZespolona(struct zespolona z){
    printf("%f+%fi\n",z.re,z.im);
}
void wczytajZespolona(struct zespolona z){
    scanf("%f",&z.re);
    scanf("%f",&z.im);
}
struct zespolona dodaj(struct zespolona liczba1,struct zespolona liczba2){
    struct zespolona suma;
    suma.re=liczba1.re+liczba2.re;
    suma.im=liczba1.im+liczba2.im;
    return suma;
};
//TODO nwm czy dziala
struct zespolona mnozenie(struct zespolona liczba1,struct zespolona liczba2){
    struct zespolona wynik;
    wynik.re=liczba1.re*liczba2.re-liczba1.im*liczba2.im;
    wynik.im=liczba1.re*liczba2.im+liczba1.im*liczba2.re;
    return wynik;
};
struct zespolona dzielenie(struct zespolona z1,struct zespolona z2){
    struct zespolona wynik;
    wynik.re=(z1.re*z2.re+z1.im*z2.im)/pow(z2.re+z2.im,2);
    wynik.im=(z1.im*z2.re-z1.re*z2.im)/(pow(z2.re+z2.im,2));
    return wynik;
}

double modul(struct zespolona z){
    return sqrt(pow(z.re,2)+pow(z.im,2));
}
double odleglosc(struct punkt p1,struct punkt p2){
    return sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2)+pow((p2.z-p1.z),2));
}
double minimum(struct punkt tab[],unsigned int n){
    int i,j;
    double pom;
    double min=odleglosc(tab[0],tab[1]);
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            pom=odleglosc(tab[i],tab[j]);
        }
        if(pom<min){
            min=pom;
        }
    }
    return min;
}
 */
struct element{
    int i;
    struct element *next;
};
struct element *dodajNaPoczatek(struct element* e1, int a){
    struct element *wsk=malloc(sizeof(struct element));
    wsk->i=a;
    wsk->next=e1;
    return wsk;
}
struct element *utworz(){
return NULL;
};
int main(){

    /**
    struct punkt p1;
    p1.x=1;
    p1.y=3;
    p1.z=5;
    struct punkt p2;
    p2.x=4;
    p2.y=2;
    p2.z=9;
    struct punkt p3;
    p3.x=5;
    p3.x=0;
    p3.x=0;
    struct punkt tab[3]={p1,p2,p3};
    printf("%f",minimum(tab,3));

    ZESPOLONE
    struct zespolona z1;
    z1.re=2;
    z1.im=7;
    struct zespolona z2;
    z2.re=2;
    z2.re=7;
    wypiszZespolona(z1);
    printf("Modul:%f\n",modul(z1));
    struct zespolona z3=dodaj(z1,z2);
    wypiszZespolona(z3);
    struct zespolona z4=mnozenie(z1,z2);
    wypiszZespolona(z4);
    struct zespolona z5=dzielenie(z1,z2);
    wypiszZespolona(z5);
     */

}
