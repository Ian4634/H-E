#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char *data;
    struct node *next;
    int count;
};

struct node *insert(struct node *list, char *word){
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    new_node->data = word;
    new_node->next = list;
    new_node->count = 1;
    return new_node;
}

struct node *search(struct node *list, char *word){
    while (list != NULL && strcmp(list->data, word)){
        list = list->next;
    }
    return list;
}

void print_reverse(struct node *list){
    if (list == NULL)
        return;
    print_reverse(list->next);
    printf("%s: %d\n", list->data, list->count);
}

struct node *read_words(struct node *list){
    char *word = NULL;
    struct node *word_in_list;

    while (1){
        word = (char*) malloc(sizeof(char)*1050);
        if (!fgets(word, 1050, stdin)){
            free(word);
            break;
        }
        word[strlen(word)-1] = '\0'; // 取代\n

        if (word[0] == '-'){
            word_in_list = search(list, &word[1]);
            if (word_in_list) // 有找到word
                (word_in_list->count)--;
            free(word);
        }
        else {
            word_in_list = search(list, word);
            if (word_in_list) {
                (word_in_list->count)++;
                free(word);
            }
            else
                list = insert(list, word);
        }
    }
    return list;
}


int main(){
    struct node *list = NULL;
    list = read_words(list);
    print_reverse(list);

    struct node *cur;
    while (list != NULL){
        cur = list;
        list = list->next;
        free(cur->data);
        free(cur);
    }

    return 0;
}

