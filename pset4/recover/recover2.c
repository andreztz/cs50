#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 512


typedef uint8_t BYTE;


// header -> 0xff, 0xd8, 0xff, last byte is 0xe0 | 0xe1 | 0xe2 | ... | 0xef 
bool is_jpeg_header(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}

int main(int argc, char *argv[])
{
    // Check comand line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image.raw\n");
        return 1;
    }

    char * image_name = argv[1];
    // Read raw file
    FILE * file = fopen(image_name, "r");

    if (file == NULL)
    {
        printf("Could not open %s\n", image_name);
        return 1;
    }
    
    BYTE buffer[BUFFER_SIZE];
    FILE * picture = NULL;
    int counter = 0;
    bool found = false;

    while (fread(buffer, BUFFER_SIZE, 1, file))
    {
        // Looking for a beginning of a JPEG
        if (is_jpeg_header(buffer))
        {
            if (found)
            {
                fclose(picture);
                counter++;
            }
            else 
            {
                found = true;
            }
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);
            picture = fopen(filename, "a");

        }
        if (found) {
            fwrite(&buffer, BUFFER_SIZE, 1, picture);
        }
    }
    fclose(file);
    fclose(picture);
    return 0;
}
