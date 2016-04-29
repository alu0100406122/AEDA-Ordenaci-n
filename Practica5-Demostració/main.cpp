#include <iostream>
#include <vector>
#include "dni.h"
#include "metodos.h"

using namespace std;

typedef DNI TDATO;

int main(){
    int num;
    int n;
    int opcion;
    vector<TDATO> v1;
    vector<TDATO> v_aux;
    cout << endl;
    cout << "Introduzca el número de elementos: ";
    cin >> n;
    v1.resize(n);
    aleatorios(v1,n);
    v_aux.resize(n);
    //Copia del vector aleatorio inicial en un vector auxiliar.
    for (int i=0; i<n; i++){
        v_aux[i] = v1[i];
    }
    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "               MÉTODOS DE ORDENACIÓN                " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << endl;
    cout << "1. Ordenación por Inserción. " << endl;
    cout << "2. Método de la Burbuja. " << endl;
    cout << "3. ShellSort. " << endl;
    cout << "4. QuickSort. " << endl;
    cout << "5. MergeSort. " << endl;
    cout << "0. Salir. " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Introduzca el método que desea emplear: ";
    cin >> opcion;
    cout << "----------------------------------------------------" << endl;
    cout << endl;
    switch(opcion){
        case 1:
            cout << "Ordenación por inserción." << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Vector desordenado... " << endl;
            imprimir(v1);
            cout << endl;
            ord_Insercion(v1, n); //No modifica el vector, lo ordena dentro y lo muestra.
            break;
        case 2: 
            cout << "Vector Desordenado: " << endl;
            imprimir(v1);
            cout << endl;
            cout << "Método de la burbuja. " << endl;
            cout << "----------------------------------------------------" << endl;
            ord_burbuja(v1, n);
            break;
        case 3:
            cout << "Ordenación por Incrementos decrecientes. ShellSort." << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Vector Desordenado... " << endl;
            imprimir(v1);
            cout << endl;
            ord_shellsort(v1, n);
            cout << "Vector ordenado... " << endl;
            imprimir(v1);
            break;
        case 4:
            cout << "Ordenación rápida. QuickSort. " << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Vector Desordenado... " << endl;
            imprimir(v1);
            cout << endl;
            ord_Qsort(v1,0,(n - 1));
            cout << "Vector Ordenado: " << endl;
            imprimir(v1);
            break;
        case 5:
            cout << "Ordenación por mezcla. MergeSort. " << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Vector Desordenado... " << endl;
            imprimir(v1);
            cout << endl;
            ord_Msort(v1, 0, (n - 1));
            cout << "Vector Ordenado... " << endl;
            imprimir(v1);
            break;
        case 0:
            exit(0);
    }
    
    return 0;
}