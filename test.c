#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list{
    char *str;
    int amount;
    struct list *next;
};

typedef struct list List;

struct output{
    char *str;
    int amount;
    struct output *next;
};

typedef struct output Output;

char *read_line(char **str){

    if(fgets(*str, 1024, stdin)){
        return *str;
    }else{
        return NULL;
    }
}
char *remove_first(char *str) {
    char *cur = str + 1;
    char *removed_str = malloc(strlen(str)+1);
    char *r = removed_str;
    while (*cur != '\0') {
        *r++ = *cur++;
    }
    *r = '\0';
    return removed_str;
}
void insert(List **first, char *str){
    List *new_node = malloc(sizeof(List));
    new_node->str = malloc(strlen(str)+1);
    if(new_node == NULL)printf("error");
    new_node->next = *first;
    new_node->amount = 1;
    if(strcmp(str, "\0") == 0){
        printf("is null");
    }
    strcpy(new_node->str, str);
    *first = new_node;
}

List *search(List *first, char *desired){
    List *cur = first;
    for(;cur!=NULL && strcmp(cur->str, desired) != 0;cur = cur->next);
    return cur;
}


int main(){
    if('\0' == NULL){
        printf("true");
    }
    return 0;
}

