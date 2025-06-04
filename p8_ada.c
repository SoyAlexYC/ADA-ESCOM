#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// verifica si dos cad tienen los mismos caracteres
bool mismChars(const char *s1, const char *s2, int len)
{
    int count[26] = {0}; // verificaremos q al final todos los indices tengan 0.
    for (int i = 0; i < len; i++)
    {
        count[s1[i] - 'a']++; // s1 tiene x char
        count[s2[i] - 'a']--; // s2 tiene x char, si coinciden, tenemos balance
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
            return false;
    }
    return true;
}

char *strndup(char *s, int n)
{
    char *copy = malloc(n + 1);
    if (!copy)
        return NULL;
    strncpy(copy, s, n);
    copy[n] = '\0'; // la cad termina en nulo
    return copy;
}

bool isScramble(char *s1, char *s2)
{
    int len = strlen(s1);
    if (len != strlen(s2))
    {
        return false;
    }

    if (strcmp(s1, s2) == 0)
    { // misma cadena
        return true;
    }

    if (!mismChars(s1, s2, len))
    { // para q sea un "scramble", debe tener mism chars
        return false;
    }

    for (int i = 1; i < len; i++)
    {
        // sin cambio a+b
        if (isScramble(strndup(s1, i), strndup(s2, i)) && isScramble(s1 + i, s2 + i)) //si los primeros i char de ambos son scramble y tmb los ultimos
        {
            return true;
        }
        // Con cambio b+a
        if (isScramble(strndup(s1, i), strndup(s2 + len - i, i)) && isScramble(s1 + i, strndup(s2, len - i))) /*los primeros i char de s1 son scramb de los
                                                                                                             ultimos i de s2 y tmb los ultimos de s1 con
                                                                                                             los prim de s2*/
        {
            return true;
        }
    }
    return false;
}

int main()
{
    char temp[20];
    char s1[31], s2[31];

    printf("Introduce la cadena s1: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0';
    printf("Introduce la cadena s2: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0';
    if (isScramble(s1, s2))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    return 0;
}