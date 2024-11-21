//
//  heap.h
//  TareaHeap
//
//  Created by Ximena Perez Escalante on 16/10/24.
//  A0175827
//

#ifndef heap_h
#define heap_h

#include <sstream>
#include <cstring>
#include <string>

template <class T>
class Heap{
private:
    T *data;
    unsigned int sze;
    unsigned int count;
    
    unsigned int parent(unsigned int) const;
    unsigned int left(unsigned int) const;
    unsigned int right(unsigned int) const;
    void swap(unsigned int, unsigned int);
    
    void heapify(unsigned int);
public:
    Heap(int);
    void push(int);
    void pop();
    int empty();
    int top();
    int size();
    std::string toString() const;
    
};

template <class T>
Heap<T>::Heap(int tamaño){
    data = new T[sze];
    sze = tamaño;
    count = 1;
}

template <class T>
unsigned int Heap<T>::parent(unsigned int index) const{
    return index / 2;
}

template <class T>
unsigned int Heap<T>::left(unsigned int index) const{
    return index * 2;
}

template <class T>
unsigned int Heap<T>::right(unsigned int index) const{
    return index * 2 + 1;
}

template <class T>
void Heap<T>::swap(unsigned int first, unsigned int second){
    unsigned int aux = data[first];
    data[first] = data[second];
    data[second] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int index){

    while (index < count){
      
        if (data[left(index)] < data[index] && data[left(index)] != 0 && (data[left(index)] < data[right(index)] || data[right(index)] == 0)){
            swap(index, left(index));
        }
        else if(data[right(index)] < data[index] && data[right(index)] != 0 && (data[right(index)] < data[left(index)] || data[left(index)] == 0)){
            swap(index, right(index));
        }
        index = index + 1;
    }
    
    index = 1;
    
    while (index < count){
        
        if (data[left(index)] < data[index] && data[left(index)] != 0 && data[left(index)] < data[right(index)]){
            swap(index, left(index));
        }
        else if(data[right(index)] < data[index] && data[right(index)] != 0 && data[right(index)] < data[left(index)]){
            swap(index, right(index));
        }
        index = index + 1;
        
    }

}

template <class T>
void Heap<T>::push(int value){
    data[count] = value;
    count = count + 1;
    heapify(1);
}

template <class T>
void Heap<T>::pop(){
    data[1] = 0;
    swap(1,count - 1);
    count = count - 1;
    heapify(1);
}

template <class T>
int Heap<T>::empty(){
    if (count > 1){
        return 0;
    }
    else{
        return 1;
    }
}

template <class T>
int Heap<T>::top(){
    return data[1];
}

template <class T>
int Heap<T>::size(){
    return count - 1;
}

template <class T>
std::string Heap<T>::toString() const {
    std::stringstream auxiliar;
    
    auxiliar << "[";

    for (int i = 1;i < count; i++){
        auxiliar << data[i];
        if (i != count - 1){
            auxiliar << " ";
        }
    }
    auxiliar << "]";

    return auxiliar.str();
}


#endif /* heap_h */

