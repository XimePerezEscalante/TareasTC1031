//
//  funciones.h
//  TareaRecursion
//
//  Created by Ximena Perez Escalante on 05/08/24.
//

#ifndef funciones_h
#define funciones_h

class Funciones{
public:
    int sumaIterativa(int);
    int sumaRecursiva(int);
    int sumaDirecta(int);
};

int Funciones::sumaIterativa(int n){
    int acum = 0;
    if (n > 1){
        for (int i = 0; i <= n; i++){
            acum = acum + i;
        }
        return acum;
    }
    else if (n == 1){
        return n;
    }
    else{
        return 0;
    }
}

int Funciones::sumaRecursiva(int n){
    if (n > 1){
        return n + sumaRecursiva(n - 1);
        
    }
    else if (n == 1){
        return n;
    }
    else{
        return 0;
    }
    
}

int Funciones::sumaDirecta(int n){
    
    if (n == 1){
        return 1;
    }
    else{
        return (n * (n + 1)) / 2;
    }
}

#endif /* funciones_h */
