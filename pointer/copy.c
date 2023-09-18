//
// Created by User on 9/18/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// this program works the same way as strcpy()

int main(void)
{
    char *t = "hey";
    char *s = malloc(strlen(t) + 1);

    for (int i = 0, n = strlen(t) + 1; i < n; i++)  // +1 is for the nul(not null) char, '\0'
    {
        s[i] = t[i];
    }

    if (strlen(s) > 0)
    {
        s[0] = toupper(s[0]);  // this won't capitalize the first char of t
    }                              // since we are not dealing with memory address

    printf("t: %s\n", t);
    printf("s: %s\n", s);

    free(s); // deleting the memory allocated with malloc

    return 0;
}


