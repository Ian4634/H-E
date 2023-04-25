
#include"head.h"
void convert(char *first,char *input){
    if(*input >= 97 || *input <= 122) *first++ = *input++ - 32;
    while(*input){
        *first ++ = *input++;
    }
    *first = '\0';
}
void read_first(char **first){
    char *temp = malloc(100);
    printf("first name: ");
    scanf("%s", temp);
    *first = malloc(strlen(temp) + 1);  // allocate memory to *first according to len of input
    convert(*first, temp); // copy input to *first
    free(temp);
}

void read_last(char **last){
    char *temp = malloc(100);
    printf("Last name: ");
    scanf("%s", temp);
    *last = malloc(strlen(temp) + 1);  // allocate memory to *last according to len of input
    convert(*last, temp); // copy input to *last
    free(temp);
}

