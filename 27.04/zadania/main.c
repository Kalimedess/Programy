#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>

void ZamienSpacje(char*napis){
    int i;
    for(i=0;napis[i]!=0;i++){
        if(napis[i]==32){
            napis[i]=95;
        }
    }
}
void ConcatThree(char*napis1,char*napis2,char*napisWyn){
    int i;
    for(i=0;napis1[i]!=0;i++){
        napisWyn[i] = napis1[i];
    }
    int b;
    for(b=0;napis2[b]!=0;b++,i++){
        napisWyn[i]=napis2[b];
    }
}

void Capitalize(char*napis){
    for(int i=0;napis[i]!=0;i++){
        if(napis[i]>=97 && napis[i]<=122){
            napis[i]-=32;
        }
    }
}

void OneNumberHigher(char*napis,char*wynik){
    int i;
    int j=0;
    for(i=0;napis[i]!=0;i++,j++){
        if(napis[i]>=48 && napis[i]<=56){
            wynik[j]=napis[i]+1;
        }else if(napis[i]==57){
            wynik[j]=49;
            j++;
            wynik[j]=48;
        }else{
            wynik[j]=napis[i];
        }
    }
}

void Wytnij(char*napis,int n,int m){
    int j;
    for(j=0;napis[j]!=0;j++){}
    if(j+1>m){
        for(int i=0;i+m<j;i++){
            napis[n+i]=napis[m+i+1];
        }
    }else if(n<j && j+1<=m){
        napis[n]=0;
    }
}
bool porownaj(char*napis1,char*napis2,int n){
    int i;
    for(i=0;(napis1[i]!=0)&&napis2[i]!=0;i++){
        if(napis1[n+1]!=napis2[i]){
            return false;
        }
        if(napis2[i]==0){
            return true;
        }else{
            return false;
        }
    }
}
void Wytnij2(char*napis1,char*napis2){
    int i,dl;
    for(dl=0;napis2[dl]!=0;dl++){}
    for(i=0;napis1[i]!=0;i++){
        if(porownaj(napis1,napis2,i)){
            Wytnij(napis1,i,i+dl-1);
            return;
        }
    }
}
void WytnijWspolne(char*napis1,char*napis2){
    int j;
    for(int i=0;napis1[i]!=0;i++){
        if(napis1[i]!=napis2[i]){
            napis1[j]=napis1[i];
            j++;
        }
    }
    napis1[j]=0;
}
char* Czas(int godz,int min, int sek){
    /** TODO mo¿e zadzia³a, tylko nad tym posiedzieæ

    char czas[8];
    if(godz<10){
        czas[0]=48;
        czas[1]=godz;
    }else{
        czas[0]=godz/10;
        czas[1]=godz%10;
    }
    if(min<10){
        czas[3]=48;
        czas[4]=min;
    }else{
        czas[3]=min/10;
        czas[4]=min%10;
    }
    if(sek<10){
        czas[6]=48;
        czas[7]=sek;
    }else{
        czas[6]=sek/10;
        czas[7]=sek%10;
    }
    return czas;
     */

    char*wynik=malloc(9*sizeof(char));
    sprintf(wynik,"%02d:%02d:%02d",godz,min,sek);
    return wynik;
}

void ZamianaMalychNaDuze(char*napis){
    for(int i=0;napis[i]!=0;i++){
        napis[i]=towupper(napis[i]);
    }
}

char*sklejnapisy(char*napis1,char*napis2,char*napis3){
char*wynik=malloc((strlen(napis1)+strlen(napis2)+strlen(napis3)+1)*sizeof(char));

strcpy(wynik,napis1);
strcat(wynik,napis2);
strcat(wynik,napis3);
return wynik;
}

int main()
{
    char tekst[50]="arbuzek";
    char tekst2[50]="arbiter";
    char tekst3[50]="Koniec";
    char *test=sklejnapisy(tekst,tekst2,tekst3);
    printf(test);
}
