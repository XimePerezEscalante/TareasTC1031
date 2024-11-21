## Correcciones
En esta entrega subí un archivo incorrecto (el archivo donde realizaba todas mis pruebas) y el Merge Sort no estaba terminado, por lo que también tuve mal la parte de búsquedas. Cuando realicé las pruebas, el Selection Sort me marcaba success así que no estoy segura sobre por qué tuve 0. A continuación adjunto el Merge Sort terminado.


En esta función se realiza la comparación de los elementos del vector, recibiendo como parámetros el vector original, uno temporal donde se van a realizar los cambios y los valores de los índices low (primer elemento), mid (elemento de en medio) y high (último elemento). Mientras que i, j y k van a servir para recorrer los índices y mientras no sean iguales, continúan las comparaciones.

```c++
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

mergeSplit es una función recursiva que recibe como parámetros el vector original, uno temporal donde se van a realizar los cambios y los valores de los índices low (primer elemento) y high (último elemento). En ella se tiene el caso base para saber si el valor de low es mayor que el de high porque esto significaría que el vector ya no puede dividirse más. Después se divide el arreglo del inicio a la mitad y de la mitad al inicio, para llamar a mergeArray y por último copyArray que se encarga de pasar los valores del vector temporal al original.

```c++
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

