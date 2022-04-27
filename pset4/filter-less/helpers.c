#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i < height; i++) 
    {
        for (int j=0; j < width; j++) 
        {
            BYTE avg = round(
                (float)(
                    image[i][j].rgbtRed +
                    image[i][j].rgbtBlue +
                    image[i][j].rgbtGreen
                ) / 3
            ); 
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    // sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    // sepiaBlue = 0,272 * originalRed + 0,534 * originalGreen + 0,131 * originalBlue 
    for (int i=0; i < height; i++)
    {
        for (int j=0; j < width; j++)
        {
            int sepia_red = round(
                (.393 * image[i][j].rgbtRed) + 
                (.769 * image[i][j].rgbtGreen) + 
                (.189 * image[i][j].rgbtBlue)
            );
            int sepia_green = round(
                (.349 * image[i][j].rgbtRed) +
                (.686 * image[i][j].rgbtGreen) +
                (.168 * image[i][j].rgbtBlue)
            );
            int sepia_blue =  round(
                (.272 * image[i][j].rgbtRed) +
                (.534 * image[i][j].rgbtGreen) +
                (.131 * image[i][j].rgbtBlue)
            );

            if (sepia_red > 255) 
            {
                sepia_red = 255;
            }
            if (sepia_green > 255 )
            {
                sepia_green= 255;
            }
            if (sepia_blue > 255) 
            {
                sepia_blue = 255;
            }
            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtBlue = sepia_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
