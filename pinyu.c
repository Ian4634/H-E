#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 1025
struct node{
    char word[MAX_WORD_LENGTH];
    int number;
    struct node* next;
};

struct node *first=NULL;//initialize the head of the linked list to null

struct node *insert(char* word){
    struct node* new_node=malloc(sizeof(struct node));
    strcpy(new_node->word,word);//copy the word into the new word
    new_node->number=1;//set its number to 1
    
    new_node->next=NULL;
    if(first==NULL){//the linked list is null
        first=new_node;
    }
    else{
        struct node* cur=first;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=new_node;
    }
    return new_node;
};

struct node *search(char* word){
    struct node* cur=first;
    while(cur!=NULL&& strcmp(cur->word,word)!=0){//try to find the node
        cur=cur->next;
    }
    if(cur!=NULL&&strcmp(cur->word,word)==0){//if find it
        return cur;
    }
    else return NULL;//if not find it
};

int main(){
    char* word=malloc(MAX_WORD_LENGTH*sizeof(char));
    while(fgets(word,MAX_WORD_LENGTH,stdin)!=NULL){
        if(word[strlen(word)-1]=='\n'){//delete the '\n'
            word[strlen(word)-1]='\0';
        }
        
        if(word[0]=='-'){//If there is a "-" at the beginning of the word
            struct node* node=search(word+1);
            if(node!=NULL) node->number--;
        }
        
        else{
            struct node* node=search(word);
            if(node!=NULL){//if find the word
                node->number++;
            }
            else{//if not find the word
                insert(word);
            }
        }
    }
    
    struct node* cur=first;
    struct node* temp;
    while(cur!=NULL){//print out the number of each word
        printf("%s: %d\n",cur->word,cur->number);
        temp=cur;
        cur=cur->next;
        free(temp);
    }
    free(word);
    return 0;
}
