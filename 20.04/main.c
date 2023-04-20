#include <stdio.h>
#include <stdlib.h>
void wyczysc(char *napis){
    napis[0]=0;
}
char* bezSpacji(char *napis){
    int i=0;
    char* wyn=malloc((napis));
    int j=0;
    while(napis[i]!=0){
        if(napis[i]!=32){
            wyn[j]=napis[i];
            j++;
        }
        i++;
    }
    wyn[j]==0;
    return wyn;
}
void podkreslniki2(char *napis){
    int i=0;
    while(napis[i]!=0){
        if(napis[i]==32){
            napis[i] = 95;
        }
        i++;
    }
}

char* podkreslniki(char *napis){
    int i=0;
    char* wyn=malloc((napis));
    while(napis[i]!=0){
        if(napis[i]!=32){
            wyn[i]=napis[i];
        }else{
            wyn[i]=95;
        }
        i++;
    }
    wyn[i]==0;
    return wyn;
}
int czyRowne(char*napis,char*napis2){
    int i=0;
    if(sizeof(napis)!=sizeof(napis2)){
        return 0;
    }else{
        while(napis[i]!=0){
            if(napis[i]!=napis2[i]){
                return 0;
            }
            i++;
        }
        return 1;
    }
}
//Przepisane z lekcji, ale nie dzia³a w ogóle jak powinno, nie wiem czemu tak po prostu
int porownanieSlownikowo(char*napis,char*napis2){
    int i;
    if(czyRowne(napis,napis2)==1){
        return 0;
    }
    for(i=0;napis[i]!=0 || napis2[i]!=0;i++){
            if(napis[i]!=napis2[i]){
                if(napis[i]<napis2[i]){
                    return 1;
                }else if(napis[i]>napis2[i]){
                    return 0;
                }
            }
        }
    if(napis[i]!=0){
        return 0;
    }
    if(napis2[i]!=0){
        return 1;
    }
}
//z jakiegoœ powodu nie dzia³a dla wiêkszych liczb?
void przepisz(char*napis,char*napis2){
    int i;
    for(i=0;i<sizeof(napis);i++){
        napis2[i]=napis[i];
    }
    napis2[sizeof(napis)]=0;
}
void copyN(char*napis,char*napis2,int n){
    int i;
    for(i=0;i<n;i++){
        napis2[i]=napis[i];
    }
    napis2[n]=0;
}
int main()
{
    char *napis="mate";
    char *napis2=malloc(sizeof(napis));
    copyN(napis,napis2,5);
    printf(napis2);


    return 0;
}
