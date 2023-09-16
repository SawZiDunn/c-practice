//
// Created by User on 9/16/2023.
//

#include<stdio.h>

void draw_pyramid(int height);

int main(void)
{
    int height;
    printf("Enter the pyramid height:");
    scanf("%d", &height);
    draw_pyramid(height);

}

void draw_pyramid(int height)
{
    if (height <= 0)
    {
        return;
    }

    draw_pyramid(height - 1);

    for (int i = 0; i < height; i++)
    {
        printf("#");
    }
    printf("\n");
}
