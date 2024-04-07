#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

void capitalize(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (i == 0 || isspace(str[i - 1])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    char str[100];

    printf("¬ведите строку: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; 
    capitalize(str)
        ;
    printf("–езультат: %s\n", str);

    return 0;
}
