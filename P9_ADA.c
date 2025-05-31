#include <stdio.h>
#include <stdlib.h>

int calagua(int* mapa, int mapaSize) {
    if (mapaSize <= 2) return 0; // no hay mapa suficiente para comparar

    int *max_izq = malloc(mapaSize * sizeof(int));
    int *max_der = malloc(mapaSize * sizeof(int));
    int agua = 0;

    // max izq para saber si a la izq hay un bloque mas alto o no 
    max_izq[0] = mapa[0]; //el maximo por la izq del indice 0 es si mismo
    for (int i = 1; i < mapaSize; i++) {
        max_izq[i] = (mapa[i] > max_izq[i - 1]) ? mapa[i] : max_izq[i - 1]; /** si el indice donde estamos es mayor que el max por izq del anterior 
                                                                       i es el maximo por la izq de si mismo, si no, es pq el anterior es su maximoizq */
    }

    // max der para saber si a la der hay un bloque mas alto o no 
    max_der[mapaSize - 1] = mapa[mapaSize - 1]; //el maximo por la der del indice ultimo es si mismo
    for (int i = mapaSize - 2; i >= 0; i--) {
        max_der[i] = (mapa[i] > max_der[i + 1]) ? mapa[i] : max_der[i + 1]; /** si el indice donde estamos es mayor que el max por der del siguiente 
                                                                       i es el maximo por la der de si mismo, si no, es pq el siguiente es su maximoder */
    }

    // Calcular agua atrapada
    for (int i = 0; i < mapaSize; i++) {
        int min_mapa = (max_izq[i] < max_der[i]) ? max_izq[i] : max_der[i]; /*para cada indice buscamos cual de los max es menor,para saber si habra agua*/
        if (min_mapa > mapa[i]) {
            agua += min_mapa - mapa[i]; //si el min es mayor a mapa de i, es pq a los extremos tenemos bloques mas grandes q el actual, habra agua
        }
    }

    free(max_izq);
    free(max_der);
    return agua;
}

int main() {
    // Ejemplo 1
    int mapa1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int size1 = sizeof(mapa1) / sizeof(mapa1[0]);
    printf("Agua 1: %d\n", calagua(mapa1, size1)); 

    // Ejemplo 2
    int mapa2[] = {4,2,0,3,2,5};
    int size2 = sizeof(mapa2) / sizeof(mapa2[0]);
    printf("Agua 2: %d\n", calagua(mapa2, size2)); 

    return 0;
}
