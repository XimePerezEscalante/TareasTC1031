//
//  list.h
//  TareaDoublyLinkedList
//
//  Created by Ximena Perez Escalante A01751827 on 24/09/24.
//

#ifndef dlist_h
#define dlist_h
#include <cstring>
#include <sstream>

template <class T> class DList;

template <class T>
class Link{
private:
    T value;
    Link<T> * previous;
    Link<T> * next;
public:
    Link(int);
    //Link(const Link<T>);
    friend class DList<T>;
};

template <class T>
Link<T>::Link(int val){
    value = val;
    previous = NULL;
    next = NULL;
}

template <class T>
class DList{
private:
    T size;
    Link<T> * head;
    Link<T> * tail;
public:
    DList();
    DList(T);
    DList(const DList<T>&);
    ~DList();
    void insertion(int);
    T search(int);
    void update(int, int);
    void deleteAt(int);
    std::string toStringForward() const;
    std::string toStringBackward() const;
};

template <class T>
DList<T>::DList(){
    size = 0;
    head = NULL;
    tail = NULL;
}

template <class T>
DList<T>::~DList(){
    size = 0;
    head = NULL;
    tail = NULL;
}

template <class T>
void DList<T>::insertion(int val){
    if (head == 0){
        head = new Link<T>(val);
        tail = head;
    }
    else{
        Link<T> *p = head;
        while (p->next != NULL){
            p = p->next;
        }
        Link<T> *aux = new Link<T>(val);
        /*if (head == tail){
            head->next = aux;
            tail->previous = head;
            tail = aux;
        }
        else{
            p->next = aux;
            aux->previous = p;
            tail = aux;
        }*/
        p->next = aux;
        aux->previous = p;
        tail = aux;
    }
    size = size + 1;
    
}

template <class T>
T DList<T>::search(int val){
    T res = -1;
    if (head != 0){
        Link<T> *p = head;
        T cont = 0;
        while(p->next != NULL){
            if (p->value == val){
                res = cont;
            }
            
            p = p->next;
            cont = cont + 1;
            
            if (p->next == NULL && p->value == val){
                res = cont;
            }
        }
       
    }
    return res;
}

template <class T>
void DList<T>::update(int index, int val){
    if (head != 0){
        Link<T> *p = head;
        T cont = 0;
        while (p->next != NULL){
            if (cont == index){
                p->value = val;
            }
            
            p = p->next;
            cont = cont + 1;
            
            if (p->next == NULL && cont == index){
                p->value = val;
            }
        }
    }
}

template <class T>
void DList<T>::deleteAt(int index){
    if (head != 0){
        
        if (index == 0){
            Link<T> *aux = head;
            head = aux->next;
            head->previous = NULL;
            delete aux;
        }
        else if (index == size - 1){
            Link<T> *aux = tail;
            tail = aux->previous;
            tail->next = NULL;
            delete aux;
        }
        else{
            Link<T> *p = head;
            T cont = 0;
            
            while (p->next != NULL){
                
                if (cont == index){
                    Link<T> *aux = p->next;
                    
                    p->previous->next = aux;
                    aux->previous = p->previous;
                    
                }
                
                p = p->next;
                cont = cont + 1;
            }
        }
    }
}

template <class T>
std::string DList<T>::toStringForward() const {
    std::stringstream aux;
    Link<T> *p;

    p = head;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        //std::cout << "p value: " << p->value << std::endl;
        if (p->next != 0) {
            aux << ", ";
            //std::cout << "p next value: " << p->next->value << std::endl;
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

template <class T>
std::string DList<T>::toStringBackward() const{
    std::stringstream aux;
    Link<T> *p;

    p = tail;
    aux << "[";
    while (p != 0) {
        //std::cout << "p value: " << p->value << std::endl;
        aux << p->value;
        if (p->previous != 0) {
            aux << ", ";
            //std::cout << "p previous value: " << p->previous->value << std::endl;
        }
        p = p->previous;
    }
    aux << "]";
    return aux.str();
}

#endif /* list_h */
