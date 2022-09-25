#include <stdio.h>
#include <stdlib.h>

char *get_string() {
    int size = 1024;
    char *str = (char*) malloc(size*sizeof(char));
    char c = getchar();
    int i = 0;
    
    while (c != EOF && c != '\n') {
        str[i++] = c;

        if (i >= size) {
            size *= 2;
            str = (char*) realloc(str, size*sizeof(char));
        }
        c = getchar();
    }
    str[size] = '0';
  
    return str;
}

int main() {
    char *str = get_string();
    printf("Hello, %s!\n", str);
    free(str);

    return 0;
}
