#include <iostream>
#include <vector>
#include "dni.h"
#include "metodos.h"

using namespace std;

typedef DNI TDATO;

int main(){
    int num;
    int n;
    int pruebas;

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "                     ESTADÍSTICA                     " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;
    cout << "Introduzca el número de elementos del Vector: ";
    cin >> n;
    cout << "Introduzca el número de Pruebas que desea realizar: ";
    cin >> pruebas;
    cout << "-----------------------------------------------------" << endl;
    
    //Creamos un vector de vectores para almacenar los vectores aleatorios.
    vector< vector<TDATO> > v;
    
    for (int i=0; i<pruebas; i++){
        vector<TDATO> v_aux;
        v_aux.resize(n);
        aleatorios(v_aux,n);
        v.resize(v.size()+1);
        v[i] = v_aux;
    }
    
    //Mostramos los vectores aleatorios generados
    cout << "Vectores aleatorios para realizar la estadística: " << endl;
    for (int i=0; i < v.size(); i++){
        for (int j=0; j < n; j++){
            cout << v[i][j] << " ";    
        }
        cout << endl;
    }
    
    // -----------------------------------------------------------------------------
    // Estadística para el método de Inserción.
    
    cout << "-----------------------------------------------------" << endl;
    DNI::comp = 0;
    //Variables para las comparaciones
    int mayor_insercion = 0;
    int menor_insercion = 10000;
    int suma_insercion = 0;
    double media_insercion = 0.0;
    vector <int> v_comp_insercion;
    v_comp_insercion.resize(n);
    cout << "ORDENACIÓN POR INSERCIÓN" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Contador inicial de comparaciones: " << DNI::comp ;
    for (int i=0; i < pruebas; i++){
        ord_Insercion(v[i],n);
        //cout << "Vector : " << i << "-> Comparaciones: " << DNI::comp << endl;
        v_comp_insercion[i] = DNI::comp;
        DNI::comp = 0;
    }
    
    for (int i=0; i<pruebas; i++){
        if (mayor_insercion < v_comp_insercion[i]){
            mayor_insercion = v_comp_insercion[i];
        }
        if (menor_insercion > v_comp_insercion[i]){
            menor_insercion = v_comp_insercion[i];
        }
        
        suma_insercion = suma_insercion + v_comp_insercion[i];
    }
    media_insercion = (suma_insercion / pruebas);
    cout << endl;
    cout << "Numero mayor de comparaciones: " << mayor_insercion << endl;
    cout << "Numero menor de comparaciones: " << menor_insercion << endl;
    cout << "Media de comparaciones: " << media_insercion << endl;
    cout << endl;
    
    
    // -----------------------------------------------------------------------------
    // Estadística para el método de la Burbuja.
    
    cout << "-----------------------------------------------------" << endl;
    DNI::comp = 0;
    //Variables para las comparaciones
    int mayor_burbuja = 0;
    int menor_burbuja = 10000;
    int suma_burbuja = 0;
    double media_burbuja = 0.0;
    vector <int> v_comp_burbuja;
    v_comp_burbuja.resize(n);
    cout << "MÉTODO DE LA BURBUJA" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Contador inicial de comparaciones: " << DNI::comp << endl;
    for (int i=0; i < pruebas; i++){
        ord_burbuja(v[i],n);
        //cout << "Vector : " << i << "-> Comparaciones: " << DNI::comp << endl;
        v_comp_burbuja[i] = DNI::comp;
        DNI::comp = 0;
    }

    for (int i=0; i<pruebas; i++){
        if (mayor_burbuja < v_comp_burbuja[i]){
            mayor_burbuja = v_comp_burbuja[i];
        }
        if (menor_burbuja > v_comp_burbuja[i]){
            menor_burbuja = v_comp_burbuja[i];
        }
        
        suma_burbuja = suma_burbuja + v_comp_burbuja[i];
    }
    media_burbuja = (suma_burbuja / pruebas);
    //cout << endl;
    cout << "Numero mayor de comparaciones: " << mayor_burbuja << endl;
    cout << "Numero menor de comparaciones: " << menor_burbuja << endl;
    cout << "Media de comparaciones: " << media_burbuja << endl;
    cout << endl;
    
    
    // -----------------------------------------------------------------------------
    // Estadística para el método de la ShellSort.
    
    cout << "-----------------------------------------------------" << endl;
    DNI::comp = 0;
    //Variables para las comparaciones
    int mayor_shell = 0;
    int menor_shell = 10000;
    int suma_shell = 0;
    double media_shell = 0.0;
    vector <int> v_comp_shell;
    v_comp_shell.resize(n);
    cout << "ORDENACIÓN POR SHELLSORT" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Contador inicial de comparaciones: " << DNI::comp << endl;
    int alpha = 0.5;
    cout << "Suponemos que el valor de alpha es 0.5 para la prueba estadística." << endl;
    for (int i=0; i < pruebas; i++){
        vector<TDATO> aux = v[i];
        ord_shellsort(aux,n,alpha);
        //cout << "Vector : " << i << "-> Comparaciones: " << DNI::comp << endl;
        v_comp_shell[i] = DNI::comp;
        DNI::comp = 0;
    }
    
    for (int i=0; i<pruebas; i++){
        if (mayor_shell < v_comp_shell[i]){
            mayor_shell = v_comp_shell[i];
        }
        if (menor_shell > v_comp_shell[i]){
            menor_shell = v_comp_shell[i];
        }
        
        suma_shell = suma_shell + v_comp_shell[i];
    }
    media_shell = (suma_shell / pruebas);
    cout << endl;
    cout << "Numero mayor de comparaciones: " << mayor_shell << endl;
    cout << "Numero menor de comparaciones: " << menor_shell << endl;
    cout << "Media de comparaciones: " << media_shell << endl;
    cout << endl;
    

    // -----------------------------------------------------------------------------
    // Estadística para el método de ordenación QuickSort.
    
    cout << "-----------------------------------------------------" << endl;
    DNI::comp = 0;
    //Variables para las comparaciones
    int mayor_quick = 0;
    int menor_quick = 10000;
    int suma_quick = 0;
    double media_quick = 0.0;
    vector <int> v_comp_quick;
    v_comp_quick.resize(pruebas);
    cout << "ORDENACIÓN POR QUICKSORT" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Contador inicial de comparaciones: " << DNI::comp << endl;
    
    for (int i=0; i < pruebas; i++){
        
        vector<TDATO> aux = v[i];
        ord_Qsort(aux, 0, n-1);
        //cout << "Vector : " << i << "-> Comparaciones: " << DNI::comp << endl;
        v_comp_quick[i] = DNI::comp;
        DNI::comp = 0;
    }
    
    for (int i=0; i<pruebas; i++){
        if (mayor_quick < v_comp_quick[i]){
            mayor_quick = v_comp_quick[i];
        }
        if (menor_quick > v_comp_quick[i]){
            menor_quick = v_comp_quick[i];
        }
        
        suma_quick = suma_quick + v_comp_quick[i];
    }
    media_quick = (suma_quick / pruebas);
    cout << endl;
    cout << "Numero mayor de comparaciones: " << mayor_quick << endl;
    cout << "Numero menor de comparaciones: " << menor_quick << endl;
    cout << "Media de comparaciones: " << media_quick << endl;
    cout << endl;
    
    
    // -----------------------------------------------------------------------------
    // Estadística para el método de ordenación MergeSort.
    
    cout << "-----------------------------------------------------" << endl;
    DNI::comp = 0;
    //Variables para las comparaciones
    int mayor_merge = 0;
    int menor_merge = 10000;
    int suma_merge = 0;
    double media_merge = 0.0;
    vector <int> v_comp_merge;
    v_comp_merge.resize(n);
    cout << "ORDENACIÓN POR MERGESORT" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Contador inicial de comparaciones: " << DNI::comp << endl;
    for (int i=0; i < pruebas; i++){
        vector<TDATO> aux = v[i];
        ord_Msort(aux, 0, n-1);
        //cout << "Vector : " << i << "-> Comparaciones: " << DNI::comp << endl;
        v_comp_merge[i] = DNI::comp;
        DNI::comp = 0;
    }
    
    for (int i=0; i<pruebas; i++){
        if (mayor_merge < v_comp_merge[i]){
            mayor_merge = v_comp_merge[i];
        }
        if (menor_merge > v_comp_merge[i]){
            menor_merge = v_comp_merge[i];
        }
        
        suma_merge = suma_merge + v_comp_merge[i];
    }
    media_merge = (suma_merge / pruebas);
    cout << endl;
    cout << "Numero mayor de comparaciones: " << mayor_merge << endl;
    cout << "Numero menor de comparaciones: " << menor_merge << endl;
    cout << "Media de comparaciones: " << media_merge << endl;
    cout << endl;
    
    
    //------------------------------------------------------------------------------------------
    //Tabla final
    cout << "-----------------------------------------------------" << endl;
    cout << "                       TABLA FINAL                   " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "\t\t" << "Mayor" << "\t" << "Menor" << "\t" << "Media" << endl;
    cout << "Inserción: " << "\t" << mayor_insercion << "\t" << menor_insercion << "\t" << media_insercion << endl;
    cout << "Burbuja: " << "\t" << mayor_burbuja << "\t" << menor_burbuja << "\t" << media_burbuja << endl;
    cout << "ShellSort: " << "\t" << mayor_shell << "\t" << menor_shell << "\t" << media_shell << endl;
    cout << "QuickSort: " << "\t" << mayor_quick << "\t" << menor_quick << "\t" << media_quick << endl;
    cout << "MergeSort: " << "\t" << mayor_merge << "\t" << menor_merge << "\t" << media_merge << endl;
    cout << "-----------------------------------------------------" << endl;
    
    return 0;
}