
DLUGOSC STRINGA
int dlugosc(char * tab)
{
 int sum=0;
 while (tab[sum]!=NULL)
  {
   sum+=1;
  }
 return sum;
}

FUNKCJA NA WPISYWANIE DO TABLICY TABLIC 
int**wpisz(int**tab,unsigned int n, unsigned int m){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%i",&tab[i][j]);
    }
  }
  return tab;
}

FUNKCJA NA ALOKACJĘ PAMIĘCI TABLICY TABLIC
int**aloc(unsigned int n, unsigned int m){
  int**tab=malloc(n*sizeof(int*));
  for(int i=0;i<m;i++){
    tab[i]=malloc(m*sizeof(int));
  }
  return tab;
}

FUNKCJA NA WYPISYWANIE WARTOŚCI Z TABLICY TABLIC
void wypisz(int**tab,unsigned int n, unsigned int m){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("%i",tab[i][j]);
    }
    printf("\n");
  }
}

FUNKCJA NA STWORZENIE PUSTEJ LISTY (po prostu stworzenie listy)
struct element *utworz(){
return NULL;
}


FUNKCJA NA DODANIE ELEMENTU DO LISTY
struct element *dodajNaPoczatek(struct element* e1, int a){
    struct element *wsk=malloc(sizeof(struct element));
    wsk->i=a;
    wsk->next=e1;
    return wsk;
}

FUNKCJA NA WYCZYSZCZENIE (usunięcie) LISTY
void wyczysc(struct element* Lista){
    struct element *wsk = Lista;
    while(Lista!=NULL){
        Lista=Lista->next;
        free(wsk);
        wsk=Lista;
    }
}

FUNKCJA NA DODANIE ELEMENTU DO LISTY (na koniec)
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

CZYSZCZENIE LISTY
void wyczyscListe(struct element* Lista){
    struct element *wsk = Lista;
    while(Lista!=NULL){
        Lista=Lista->next;
        free(wsk);
        wsk=Lista;
    }
}

WYPISYWANIE LISTY
void WypiszListe(struct element*Lista){
  int number=1;
  while(Lista!=NULL){
    printf("Element na indeksie %i to: %i\n",number,Lista->i);
    Lista=Lista->next;
    number++;
  }
}



//1.5.1
char* FormatujImie(char*Imie){
  int secondPart=-2;
  for(int i=0;i<dlugosc(Imie);i++){
    if(Imie[i]==32){
      secondPart=i;
      Imie[i]='.';
    }else if(i==0){
      if(Imie[i]>=97&&Imie[i]<=122){
        Imie[i]-=32;
      }
    }else if(i==secondPart+1){
      if(Imie[i]>=97&&Imie[i]<=122){
        Imie[i]-=32;
      }
    }else{
      if(Imie[i]>=97&&Imie[i]<=122){
        
      }else{
        Imie[i]+=32;
      }
    }
  }
  return Imie;
}

//1.11.2
char * dlugosc(char* napis)
{
    int dl = dlugosc(napis);
    char* nowy = malloc((dl + 1) * sizeof(char));
    int j = 0;
    char pomoc;

    for (int i = 0; i < dl; i++) {
        nowy[j] = napis[i];
        j++;

        if (i < dl - 1 && ((napis[i] - napis[i + 1]) == 1 || (napis[i] - napis[i + 1]) == -1)) {
            nowy = realloc(nowy, (dl + 2) * sizeof(char));
            pomoc = napis[i+1];
            nowy[j] = 'W';
            j++;
            nowy[j] = pomoc;
            j++;
            i++;
        }
    }

    nowy[j] = '\0';

    return nowy;
}

//1.11.3
int Slad(int**tab,unsigned int n){
  int suma=0;
  for(int i=0;i<n;i++){
    suma+=tab[i][i];
  }
  return suma;
}
int SumaParzystychNaKrancach(int**tab,unsigned int n, unsigned int m){
  int suma=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(i==0 && j==0){
        suma+=tab[i][j];
      }else if(i==n-1 && j==0){
        suma+=tab[i][j];
      }else if(i==0 && j==m-1){
        suma+=tab[i][j];
      }else if(i==n-1 && j==m-1){
        suma+=tab[i][j];
      }else{}
    }
  }
  return suma;
}
//drugi sposob
int suma_elementow_brzegowych(int m, int n, int** macierz) {
    int suma = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) { // Sprawdzanie, czy element jest na brzegu
                if (macierz[i][j] % 2 == 0) { // Sprawdzanie, czy element jest parzysty
                    suma += macierz[i][j];
                }
            }
        }
    }

    return suma;
}

//1.11.4a
void odwroc_wiersze2(unsigned int n, unsigned int m, int t[][m]){
      int i,j,pom;
for(i=0;i<n;i++)
{
    for(j=0;j<m/2;j++)
{
    pom=t[i][j];
   t[i][j]=t[i][m-1-j];
   t[i][m-1-j]=pom;
}
}
}

//1.11.4b
void shiftColumns(int arr[][100], int rows, int cols) {
    int temp1[rows], temp2[rows];
    for (int i = 0; i < rows; i++) {
        temp1[i] = arr[i][cols - 2];
        temp2[i] = arr[i][cols - 1];
    }
    for (int i = cols - 1; i >= 2; i--) {
        for (int j = 0; j < rows; j++) {
            arr[j][i] = arr[j][i - 2];
        }
    }
    for (int i = 0; i < rows; i++) {
        arr[i][0] = temp2[i];
        arr[i][1] = temp1[i];
    }
}


//1.12.5
void DodajEl(struct element** lista, int dane) {
    struct element* wsk = (struct element*)malloc(sizeof(struct element));
    wsk->i = dane;
    wsk->next = NULL;

    if (*lista == NULL) {
        *lista = wsk;
    } else {
        struct element* wsk2 = *lista;
        while (wsk2->next != NULL) {
            wsk2 = wsk2->next;
        }
        wsk2->next = wsk;
    }
}
struct element* coDrugiElement(struct element* lista) {
    if (lista == NULL) {
        return NULL;
    }

    struct element* wsk = NULL;
    struct element* wsk2 = lista;
    int jumpNum = 0;

    while (wsk2 != NULL) {
        if (jumpNum % 2 == 0) {
            DodajEl(&wsk, wsk2->i);
        }
        jumpNum++;
        wsk2 = wsk2->next;
    }

    return wsk;
}