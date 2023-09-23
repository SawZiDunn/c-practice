//
// Created by User on 9/21/2023.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *list = malloc(3 * sizeof(int));
    if (list == NULL) {  // malloc returns NULL when there's no memory to allocate in the computer
        return 1;
    }

    *list = 1; // list[0]
    *(list + 1) = 2; //list[1]
    *(list + 2) = 3;

    //...

//    int *temp = malloc(4 * sizeof(int));
    int *temp = realloc(list, 4 * sizeof(int));
    // realloc allows you to move the previous memory to the new one

    if (temp == NULL) {
        free(list);
        return 1;
    }
// you no longer need to move one by one like this anymore
// if you use realloc

//    for (int i = 0; i < 3; i++)
//    {
//        temp[i] = list[i];
//    }

    list = temp;
    temp[3] = 4;

    // no longer necessary to free list if you use realloc
//    free(list);  // freeing the old memory pointed by list pointer
    list = temp; // list pointer is pointing now to the memory temp pinter is pointing to

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list); // this one is for freeing the new memory of int size 4
                        // the old one is already freed
                        // free(temp) would also work

    return 0;
}
