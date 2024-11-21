//
//  list.h
//  TareaListasLigadas
//
//  Created by Ximena Perez Escalante (A01751827) on 18/09/24.
//

#ifndef list_h
#define list_h

#include <sstream>

template <class T> class List;

template <class T>
class Node{
private:
    T value;
    Node<T> * next;
    
    Node(T);
    Node(T,Node<T>*);
    Node(const Node<T>&);
    
    
    friend class List<T>;
};

template <class T>
Node<T>::Node(T val){
    value = val;
    next = NULL;
}

template <class T>
Node<T>::Node(T val, Node<T> *nxt){
    value = val;
    next = nxt;
}

template <class T>
Node<T>::Node(const Node<T>& nxt){
    value = nxt.value;
    next = nxt.next;
}

template <class T>
class List{
private:
    Node<T> *head;
    int size;
public:
    List();
    List(const List<T>&) ;
    ~List();
    void insertion(int);
    T search(int);
    void update(int,int);
    void deleteAt(int);
    std::string toString() const;
};

template <class T>
List<T>::List(){
    head = 0;
    size = 0;
}

template <class T>
List<T>::List(const List<T>& lista){
    head = lista->head;
    size = lista->size;
}

template <class T>
List<T>::~List(){
    size = 0;
    head->value = 0;
    head->next = NULL;
    head = NULL;
}

template <class T>
void List<T>::insertion(int val){
    if (head != 0){
        Node<T> *p = head;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = new Node<T>(val);
    }
    else{
        head = new Node<T>(val);
    }
    size++;
}

template <class T>
T List<T>::search(int val){
    if (head->value == val){
        return 0;
    }
    else{
        Node<T> *p = head;
        T res = -1;
        T cont = 0;
        T continuar = true;
        while (p->next != NULL && continuar == true){
            if (p->next->value == val){
                res = cont + 1;
                continuar = false;
            }
            cont = cont + 1;
            p = p->next;
        }
        return res;
    }
}

template <class T>
void List<T>::update(int index,int val){
    if (head != 0){
        Node<T> *p = head;
        T cont = 0;
        while (p->next != NULL && cont != index){
            cont = cont + 1;
            p = p->next;
        }
        p->value = val;
    }
}

template <class T>
void List<T>::deleteAt(int index){
    if (head != 0){
        if (index == 0){
            Node<T> *aux = head;
            head = head->next;
            delete aux;
        }
        else{
            Node<T> *p = head;
            Node<T> *aux = head;
            T cont = 0;
            while (p->next != NULL && cont < index - 1){
                cont = cont + 1;
                p = p->next;
            }
            aux = p->next;
            p->next = aux->next;
            delete aux;
        }
        
    }
}

template <class T>
std::string List<T>::toString() const {
    std::stringstream aux;
    Node<T> *p;
    p = head;
    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}
#endif /* list_h */
