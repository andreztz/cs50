#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>


int main(void)
{
    char space_char[] = " ";
    char block_char[] = "#";

    int size;
    int blocks = 1;

    while (true)
    {
        size = get_int("Size: ");
        if (size <= 8){
            break;
        }
    }


    while (true)
    {
        int spaces = size - 1;

        for (int i=0; i < spaces; i++)
        {
            printf("%c", space_char[0]);
        }

        for (int i=0; i < blocks; i++)
        {
            printf("%c", block_char[0]);
        }

        printf("  ");

        for (int i=0; i < blocks; i++)
        {
            printf("%c", block_char[0]);
        }

        printf("\n");

        size -= 1;
        blocks = blocks + 1;

        if (size == 0)
        {
            break;
        }
    }
}

