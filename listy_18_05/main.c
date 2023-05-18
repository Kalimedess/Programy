#include <stdio.h>
#include <stdlib.h>

struct element{
    int i;
    struct element* next;
};
struct element *utworz(){
    return NULL;
};

//7_3_2
void wyczysc(struct element* Lista){
    struct element *wsk = Lista;
    while(Lista!=NULL){
        Lista=Lista->next;
        free(wsk);
        wsk=Lista;
    }
}

struct element *DodajNaPoczatek(struct element * Lista,int a){
    struct element *wsk=malloc(sizeof(struct element));
    wsk->i=a;
    wsk->next=Lista;
    return wsk;
}
struct element* DodajNaKoniec(struct element*Lista,int a){
    struct element *wsk;
    if(Lista==NULL){
        Lista=wsk=malloc(sizeof(struct element));
    }else{
        wsk=Lista;
        while(wsk->next!=NULL){
            wsk=wsk->next;
        }
        wsk->next=malloc(sizeof(struct element));
        wsk=wsk->next;
    }
    wsk->i=a;
    wsk->next=NULL;
    return Lista;
}

struct element* WstawZaElem(struct element*Lista,struct element* elem,int a){
    struct element*wsk=malloc(sizeof(struct element));
    wsk->i=a;
    if(elem==NULL){
        wsk->next=Lista;
        Lista=wsk;
    }else{
        struct element *pom=malloc(sizeof(struct element));
        pom=elem;
        elem->next=wsk;
        wsk->next=pom;
    }
    return Lista;
}

void WypiszLista(struct element*Lista){
    int numer=1;
    while(Lista!=NULL){
        printf("Na pozycji %i znajduje sie liczba %i\n",numer,Lista->i);
        Lista=Lista->next;
        numer++;
    }
}
int SumaEl(struct element*Lista){
    int suma=0;
    if(Lista==NULL){
        return suma;
    }
    while(Lista!=NULL){
        suma+=Lista->i;
        Lista=Lista->next;
    }
    return suma;
}
void Zeruj(struct element*Lista){
    if(Lista==NULL){
        return;
    }
    while(Lista!=NULL){
        Lista->i=0;
        Lista=Lista->next;
    }
}
int Dlugosc(struct element*Lista){
    int suma=0;
    if(Lista==NULL){
        return suma;
    }
    while(Lista!=NULL){
        suma++;
        Lista=Lista->next;
    }
    return suma;
}
void WypiszAdresy(struct element*Lista){
    int pozycja=0;
    while(Lista!=NULL){
        pozycja++;
        printf("Adres na pozycji %i to: %p\n", pozycja, &Lista->i);
        Lista=Lista->next;
    }
}
int MinimumLista(struct element*Lista){
    if(Lista==NULL){
        return 0;
    }
    int min=Lista->i;
    int pom;
    while(Lista!=NULL){
        pom=Lista->i;
        if(min>pom){
            min=pom;
        }
        Lista=Lista->next;
    }
    return min;
}
struct element* AdresElementu(struct element*Lista,int a){
    while(Lista!=NULL){
        if(Lista->i==a){
            return Lista;
        }
        Lista=Lista->next;
    }
    return NULL;
}
struct element* Usun(struct element*Lista,int a){
    struct element*wsk,*wsk2;
    if(Lista==NULL){
        return NULL;
    }
    wsk=Lista;
    if(Lista->i==a){
        Lista=Lista->next;
        free(wsk);
    }else{
        while(wsk->next!=NULL && wsk->next->i!=a){
        wsk=wsk->next;
        }
        if(wsk->next!=NULL){
            wsk2=wsk->next;
            wsk->next=wsk2->next;
            free(wsk2);
        }
    }
    return Lista;
}
struct element* OdwrocListe(struct element*Lista){
    struct element *wsk,*wsk2;
    wsk=Lista;
    if(Lista==NULL || Dlugosc(Lista)==1){
        return Lista;
    }
    wsk=Lista->next;
    wsk2=wsk->next;
    Lista->next=NULL;
    wsk->next=Lista;
    while(wsk2!=NULL){
        Lista=wsk;
        wsk=wsk2;
        wsk2=wsk2->next;
        wsk->next=Lista;
    }
    return wsk;
}
struct element* ConcatLista(struct element*Lista,struct element*Lista2){
    struct element*wsk;
    wsk=Lista;
    while(wsk->next!=NULL){
        wsk=wsk->next;
    }
    wsk->next=Lista2;
    return Lista;
}
//Do przemyœlenia
struct element* ConcatListaNaprzemiennie(struct element*Lista,struct element*Lista2){
    struct element *wsk,*wsk2,*pom,*pom2;
    wsk=Lista;
    wsk2=Lista2;
    while(wsk2->next!=NULL){
        pom=wsk->next;
        wsk->next=wsk2;
        pom2=wsk2->next;
        wsk2->next=pom;
        wsk=pom;
        wsk2=pom2;
    }
    return Lista;
}


int main()
{
    struct element*lista=utworz();
    struct element*lista2=utworz();
    lista=DodajNaKoniec(lista,4);
    lista=DodajNaKoniec(lista,12);
    lista=DodajNaKoniec(lista,3);
    lista=DodajNaKoniec(lista,-7);
    lista2=DodajNaKoniec(lista,9);
    lista2=DodajNaKoniec(lista,-2);
    lista2=DodajNaKoniec(lista,6);
    lista2=DodajNaKoniec(lista,8);
    lista=ConcatListaNaprzemiennie(lista,lista2);
    WypiszLista(lista);

}
