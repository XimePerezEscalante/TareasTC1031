//
//  sorts.h
//  TareaBusquedas
//
//  Created by Ximena Perez Escalante A01751827 on 19/08/24.
//

#ifndef sorts_h
#define sorts_h

#include <vector>
#include <list>

template <class T>
class Sorts{
private:
    void swap(std::vector<T>&, int, int);
    void copyArray(std::vector<T>&, std::vector<T>&, int, int);
    void mergeArray(std::vector<T> &,std::vector<T> &, int, int, int);
    void mergeSplit( std::vector<T> &,std::vector<T> &, int, int);
public:
    void ordenaSeleccion(std::vector<T>&);
    void ordenaBurbuja(std::vector<T>&);
    void ordenaMerge( std::vector<T>&);
    int busqSecuencial(const std::vector<T>&, int);
    int busqBinaria(const std::vector<T>&, int);
    
};


template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &source, std::vector<T> &tmp, int low, int high) {
    for (int i = low; i <= high; i++) {
        source[i] = tmp[i];
    }
}


template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &v){
    T min;
    T ind;
    
    for (int j = 0; j < v.size(); j++){
        
        min = 1000;
        
        for (int i = v.size() - 1; i >= j; i--){
            if (v[i] < min){
                min = v[i];
                ind = i;
            }
        }
        swap(v, ind, j);
    }
}

template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T> &v){
    
    for (int j = v.size(); j >= 0; j--){
        
        for (int i = 0;i < j - 1; i++){
            
            if (v[i] > v[i + 1]){
                swap(v, i, i + 1);
            }
        }
    }
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &source, std::vector<T> &temp, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (source[i] < source[j]) {
            temp[k] = source[i];
            i++;
        }
        
        else {
            temp[k] = source[j];
            j++;
        }
        
        k++;
    }
    
    if (i > mid) {
        
        for (; j <= high; j++) {
            temp[k++] = source[j];
        }
        
    }
    
    else {
        
        for (; i <= mid; i++) {
            temp[k++] = source[i];
        }
    }
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &source, std::vector<T> &temp, int low, int high) {
    int mid;

    if ( (high - low) < 1 ) {
        return;
    }
    mid = (high + low) / 2;
    mergeSplit(source, temp, low, mid);
    mergeSplit(source, temp, mid + 1, high);
    mergeArray(source, temp, low, mid, high);
    copyArray(source, temp, low, high);
}


template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &source) {
    std::vector<T> tmp(source.size());

    mergeSplit(source, tmp, 0, source.size() - 1);
}

template <class T>
int Sorts<T>::busqSecuencial(const std::vector<T> &source, int find){
    T index = -1;
    for (int i = 0;i < source.size();i++){
        
        if (source[i] == find){
            index = i;
        } 
    }
    return index;
}

template <class T>
int Sorts<T>::busqBinaria(const std::vector<T> &source, int find){
    T low = 0;
    T high = source.size();
    T mid = (high + low) / 2;
    T index = -1;
    
    if (source[mid] == find){
        index = mid;
    }
    else if (source[mid] > find){
        for (int i = low;i < mid;i++){
            if (source[i] == find){
                index = i;
            }
        }
    }
    else{
        for (int i = mid;i < high;i++){
            if (source[i] == find){
                index = i;
            }
        }
    }
    return index;
}



#endif /* sorts_h */
