#include <locale.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void capitalize(char* str) {
    int i = 0;
    int capitalize_next = 1;

    while (str[i]) {
        if (capitalize_next && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            capitalize_next = 0;
        }
        else if (str[i] == ' ') {
            capitalize_next = 1;
        }
        else {
            capitalize_next = 0;
        }
        i++;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    char str[] = "hello world. this is a test.";
    capitalize(str);
    printf("%s\n", str);
    return 0;
}