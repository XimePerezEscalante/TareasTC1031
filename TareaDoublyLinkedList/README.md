##Correcciones
En esta tarea me confundí, ya que al resolverla volví a agregar el main de la tarea de listas simples, por lo que mi archivo tenía el nombre "list.h", no tenía las funciones "toStringForward" y "to StringBackward". Además, detecté un error en la función "insertion", en esta parte del código: 
'''
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
'''
