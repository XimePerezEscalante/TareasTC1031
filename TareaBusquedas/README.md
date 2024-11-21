## Correcciones
En esta entrega subí un archivo incorrecto (el archivo donde realizaba todas mis pruebas) y el Merge Sort no estaba terminado, por lo que también tuve mal la parte de búsquedas. Cuando realicé las pruebas, el Selection Sort me marcaba success así que no estoy segura sobre por qué tuve 0. A continuaión muestro el Merge Sort terminado:
```
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

```

```
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
```

```
template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &source) {
    std::vector<T> tmp(source.size());

    mergeSplit(source, tmp, 0, source.size() - 1);
}
```
