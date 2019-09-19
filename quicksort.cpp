/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Una función para cambiar dos elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Esta función toma el último elemento como pivote, lo coloca en su posición
correcta en el arreglo y posiciona todos los elementos menores a la izquierda y los
mayores a la derecha de el mismo */
int partition (int arr[], int low, int high) {
    int pivot = arr[high]; // pivote
    int i = (low - 1); // posición del primer elemento
    
    for (int j = low; j <= high - 1; j++) {
        // Si el el elemento actual es menor que el pivote
        if (arr[j] < pivot) {
            i++; // incrementar el index del menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* La función principal que corre QuickSort
arr[] --> arreglo a ordenar,
low --> límite inicial,
high --> límite final */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /*pi es la partición del índice, arr[p] está en el lugar correcto */
        int pi = partition(arr, low, high);
        // Ordenando separadamente los elementos antes y después de la partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Función para imprimir arreglo */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void missingNumber(int arr[], int size) {
    int aux = 1;
    for (int i = 0; i < size; i++) {
        bool flag = 0;
        while (arr[i] >= 2*aux) {
            arr[i] = arr[i] - 1;
            flag = 1;
        }
        if (flag == 1){
            aux++;
        }
    }
    cout<< endl << "The smallest positive number which is a multiple of 2 that is not present in the array A is: " << 2 * aux << endl << endl;
}

// Código principal para utilizarlo
int main() {
    int t;
    cout << "Cases: ";
    cin >> t;

    int n;

    for (int i = 0; i < t; i++) {
        cout << "------------ Case " << i + 1 << " ------------" << endl;
        cout << "Size of the array: ";
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j++) {
            cout << ": ";
            cin >> arr[j];
        }
        cout << endl;
        
        quickSort(arr, 0, n-1);
        printArray(arr, n);
        missingNumber(arr, n);
    }
    
    return 0;
}
