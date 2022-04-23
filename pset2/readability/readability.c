#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


/* 464.28571428571433 * 100 = 46428.571428571435    */
/* 46428.571428571435 + .5 = 46429.071428571435     */
/* for rounding off value then type cast to int so  */
/* value is 46429 then divided by 100 so the value  */
/* converted into 464.29                            */
float round_float(float number)
{
    float value = (int)(number * 100 + .5);
    return (float)value / 100;
}


/* Calculate Coleman-Liau Index Score                               */
/*                                                                  */
/* The Coleman-Liau Index is calculated with the following formula: */
/*     `CLI = 0.0588L - 0.296S - 15.8`                              */
/*     - `L` is the average number of letters per 100 words.        */
/*     - `S` is the average number of sentences per 100 words.      */
int calculate_coleman_liau_index(float n_letters, float n_sentences)
{
    float value = 0.0588 * n_letters - 0.296 * n_sentences - 15.8;

    return (int) round(value);

}


/* Calculate average number of letters per 100 words. */
float avg_letters(float n_letters, float n_words)
{
    return n_letters / n_words * 100;
}


/* Calculate average number of sentences per 100 words. */
float avg_sentences(float n_sentences, float n_words)
{
    return n_sentences / n_words * 100;
}



int check_text_readability(string text)
{

    int sentences = 0;
    int letters = 0;
    int words = 0;
    int text_length = strlen(text);

    char punctuation[3] = {'!', '?', '.'};


    // Count letters
    for (int i=0; i < text_length; ++i)
    {
        if (isalpha(text[i]) || isdigit(text[i]))
        {
            letters++;
        }
    }

    // Count sentences
    for (int i=0; i < 3; ++i)
    {
        for (int j=0; j < text_length; ++j)
        {
            if (punctuation[i] == text[j])
                sentences++;
        }
    }

    // Count words
    for (int i=0; i <= text_length; ++i)
    {
        if (isspace(text[i]) || text[i] == '\0')
        {
            words++;
        }
    }

    float avg_l = avg_letters(letters, words);
    float avg_s = avg_sentences(sentences, words);
    return calculate_coleman_liau_index(avg_l, avg_s);;
}


int main(int argc, string argv[])
{

    string text = get_string("Text: ");

    int cli = check_text_readability(text);


    if (cli >= 16)
    {
      printf("Grade 16+\n");
    }
    else if(cli < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", cli);
    }
    return 0;
}
