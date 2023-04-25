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
    strcpy(new_node->str, str);
    *first = new_node;
}

List *search(List *first, char *desired){
    List *cur = first;
    for(;cur!=NULL && strcmp(cur->str, desired) != 0;cur = cur->next);
    return cur;
}


int main(){
    List *first = NULL;
    char *temp = malloc(1025);
    while (fgets(temp, 1025, stdin) != NULL) {
        if (temp[strlen(temp) - 1] == '\n')
            temp[strlen(temp) - 1] = '\0';

        List *searched_without_remove = search(first,temp);
        if(*temp == '-'){
            char *removed = remove_first(temp);
            List *searched = search(first,removed);
            if(searched && searched->amount > 0){
                (searched->amount)--;
            }
            free(removed);
        }else if(searched_without_remove){
            (searched_without_remove->amount)++;
        }else{
            insert(&first, temp);
        }
    }


    // copy to output
    List *first_output = NULL;
    for(List *p = first;p;p = p->next){
        insert(&first_output, p->str);
        first_output->amount = p->amount;
    }

    for(List *p = first_output;p;p = p->next){
        printf("%s: %d\n", p->str, p->amount);
    }

    // freeing memory
    for(List *p = first;p;p = p->next){
        free(p->str);
        free(p);
    }

    for(List *p = first_output;p;p = p->next){
        free(p->str);
        free(p);
    }

    free(temp);
    return 0;
}

