#include"head.h"

int main(){
    char *first, *last;
    read_first(&first); // stores user first name in first
    read_last(&last); // stores user last name in last

    printf("%s %s", first, last);
    return 0;
}
