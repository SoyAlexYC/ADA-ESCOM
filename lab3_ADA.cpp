#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char *telefono[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

// Función recursiva para generar combinaciones
void seg(char *digitos, int index, char *actual, char **resultado, int *count) {
   
    if (digitos[index] == '\0') {
        resultado[*count] = strdup(actual);
        (*count)++;
        return;
    }


    int digito = digitos[index] - '0';
    const char *letra = telefono[digito];

    // Iterar sobre las letras disponibles y llamar recursivamente
    for (int i = 0; letra[i] != '\0'; i++) {
        actual[index] = letra[i]; 
        actual[index + 1] = '\0';
        seg(digitos, index + 1, actual, resultado, count);
    }
}

// Función principal para generar las combinaciones
char **combinacion(char *digitos, int *regreso) {
    *regreso = 0;

   
    if (digitos[0] == '\0') {
        return NULL;
    }

    int combinacionMax = 1;
    for (int i = 0; digitos[i] != '\0'; i++) {
        int digito = digitos[i] - '0';
        combinacionMax *= strlen(telefono[digito]); 
    }

   
    char **resultado = (char **)malloc(combinacionMax * sizeof(char *));
    if (resultado == NULL) {
        printf("Error al asignar memoria.\n");
        return NULL;
    }

    char actual[5] = {0};
   
    seg(digitos, 0, actual, resultado, regreso);

    return resultado;
}


int main() {
    char digitos[] = "786";
    int regreso;
    
    char **combinaciones = combinacion(digitos, &regreso);

    if (combinaciones == NULL) {
        printf("No se generaron combinaciones.\n");
        return 1;
    }

    // Imprimir los resultados
    printf("Combinaciones de los digitos: %s\n", digitos);
    for (int i = 0; i < regreso; i++) {
        printf("%s\n", combinaciones[i]);
        free(combinaciones[i]); 
    }
    free(combinaciones); 

    return 0;
}

