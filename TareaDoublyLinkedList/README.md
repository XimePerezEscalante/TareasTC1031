## Correcciones
En esta tarea me confundí, ya que al resolverla volví a agregar el main de la tarea de listas simples, por lo que mi archivo tenía el nombre "list.h", no tenía las funciones "toStringForward" y "to StringBackward". Además, detecté un error en la función "insertion", en esta parte del código: 
```
if (head == tail){
  head->next = aux;
  tail->previous = head;
  tail = aux;
}
else{
    p->next = aux;
    aux->previous = p;
    tail = aux;
}
```
Ya que cuando mandaba a llamar a "toStringBackward" no se imprimía la cabeza de la lista. Lo cambié y quedó así:
```
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
        p->next = aux;
        aux->previous = p;
        tail = aux;
    }
    size = size + 1;
}
```
Se simplificó el código porque no era necesario ese condicional y ahora únicamente hago que "tail" y "next" del último nodo sea igual a "aux", así como "previous" de aux sea el (ahora) penúltimo nodo.
