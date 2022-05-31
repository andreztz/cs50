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
    for (int i=0; i < height; i++)
    {
        for (int j=0, k=width - 1; j < (width / 2); j++, k--)
        {
            RGBTRIPLE tmp_pixel = image[i][k];
            image[i][k] = image[i][j];
            image[i][j] = tmp_pixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i=0; i < height; i++)
    {
        for (int j=0; j < width; j++)
        {
            float sum_red = 0;
            float sum_blue = 0;
            float sum_green = 0;
            int counter = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    sum_red += temp[i + k][j + l].rgbtRed;
                    sum_blue += temp[i + k][j + l].rgbtBlue;
                    sum_green += temp[i + k][j + l].rgbtGreen;
                    counter++;
                }
            }
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
    return;
}
