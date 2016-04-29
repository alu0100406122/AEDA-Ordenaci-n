
#include <iostream>
#include <vector>

#include "dni.h"

using namespace std;
typedef DNI TDATO;

//Generar DNI's aleatorios
template<class TDATO>
void aleatorios(vector<TDATO> &v, int tam){
    for (int i=0; i<tam; i++){
        srand(clock());
        int num = 30000000+rand()%(80000001-30000000);  //variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
        DNI aux;
        aux.set_Dni(num);
        v[i]=aux;
        //vector1.push_back(num);
    }
}

template<class TDATO>
void imprimir(vector<TDATO> v){
    for (int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}


template<class TDATO>
void ord_Insercion(vector<TDATO> v, int tam){
    for (int i=1; i<tam; i++) {
        TDATO temp = v[i];
        int j = i - 1;
        while ( (v[j] > temp) && (j >= 0)) {
            cout << "Cambio: " << v[j] << " con " <<  v[j+1] << endl;
            v[j+1] = v[j];
            j--;
            v[j+1] = temp;
            cout << endl;
            cout << "Vector después del cambio: ";
            imprimir(v);
        }
    }
    cout << endl;
    cout << "VECTOR ORDENADO... " << endl;
    imprimir(v);
    cout << endl;
};


template<class TDATO> 
void ord_burbuja(vector<TDATO> v, int tam) {
    TDATO x;
    for (int i = 1; i < tam; i++) { 
        for (int j = tam-1; j >= i; j--) {
            if (v[j] < v[j-1]) {
                cout << "Cambio: " << v[j-1] << " con " <<  v[j] << endl;
                x = v[j-1] ;
                v[j-1] = v[j] ;
                v[j] = x ;
                cout << "Vector después del cambio: ";
                imprimir(v);
                cout << endl;
            }
        }
    }
    cout << endl;
    cout << "VECTOR ORDENADO... " << endl;
    imprimir(v);
    cout << endl;
}

template<class TDATO> 
void deltasort(int d, vector<TDATO> &v, int n ){
    for (int i = d; i < n; i++){ 
        TDATO x = v[i];
        int j = i;
        while ((j >= d) && (x < v[j-d])){ 
            cout << "Cambio: " << v[j-d] << " con " <<  v[i] << endl; 
            v[j] = v[j-d];
            j = (j - d);

        } 
        //cout << "Comparación: " << v[j] << " y " << x << endl;
        v[j] = x;
        cout << "Vector -->  ";
        imprimir(v);
        cout << endl;
    }
    
}

template<class TDATO> 
void ord_shellsort(vector<TDATO> &v, int tam, double alpha){
    int del = tam;
    while (del > 1) {
        del = del * alpha;
        deltasort(del,v,tam);
    }
}

/*
template<class TDATO>
void ord_shellsort(vector<TDATO> v, int n){
    int i, j, inc;
    TDATO aux;
    inc = n/2 - 1;
 
    while(inc > 0){
        i = 0;
        while(i < n){
            j = i, aux = v[i];
            while (j >= inc && v[j-inc] > aux){
                v[j] = v[j-inc];
                j = j-inc;
            }
            v[j] = aux, i++;
        }
        inc = inc/2;
    }
    cout << "Vector ordenado... " << endl;
    imprimir(v);
}
*/

template<class TDATO>
void ord_Qsort(vector<TDATO> &v, int ini, int fin){
    int i = ini; 
    int f = fin;
    TDATO p = v[(i+f)/2];
    while (i <= f){
        while (v[i] < p){
            i++;
        }
        while (v[f] > p){
            f--;
        }
        if (i <= f){ 
            cout << "Cambio: " << v[i] << " con " <<  v[f] << endl;
            TDATO x = v[i] ;
            v[i] = v[f] ;
            v[f] = x;
            i++ ; 
            f-- ;
            cout << "Vector después del cambio: ";
            imprimir(v);
            cout << endl;
        }
    }
    if (ini < f){
        ord_Qsort(v, ini, f);  
    } 
    if (i < fin){
        ord_Qsort(v, i, fin);    
    } 
} 

template<class TDATO> 
void Mezcla (vector<TDATO> &v, int ini, int cen, int fin){ 
    int i = ini; 
    int j = cen + 1; 
    int k = ini;
    vector<TDATO> aux;
    aux.resize(v.size());
    while ((i <= cen) && (j <= fin)){ 
        if (v[i] < v[j]){ 
            aux[k] = v[i];
            i++;
        }
        else{ 
            aux[k] = v[j];
            j++;
        }
        k++ ;
    }
    if (i > cen){
        while (j <= fin){
            aux[k] = v[j];
            j++; 
            k++;
        }
    }
    else{
        while (i <= cen){ 
            aux[k] = v[i];
            i++; 
            k++;
        }
    }
    
    for (int k = ini; k <= fin; k++){
        v[k] = aux[k];
    }
    cout << "Vector después del cambio: " << endl;
    imprimir(v);
    cout << endl;
}

template<class TDATO> 
void ord_Msort (vector<TDATO> &v, int ini, int fin){ 
    int cen;
    if (ini < fin){
        cen = (ini + fin) / 2;
        ord_Msort(v, ini, cen);
        ord_Msort(v, cen+1, fin);
        Mezcla(v, ini, cen, fin);
    }
}


