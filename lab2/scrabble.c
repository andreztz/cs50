#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const char ascii_letters[26] = "abcdefghijklmnopqrstuvwxyz";

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int ord(char letter);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    printf("%i", score1);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int total = 0;

    for (int i=0, n=strlen(word); i < n; i++)
    {
        int index = ord(word[i]);
        int point = POINTS[index];
        total = total + point;
    }
    return total;
}

int ord(char letter)
{
    int index = -1;

    for (int i=0; i < 26; i++) {
        if (ascii_letters[i] == tolower(letter)) {
            index = i;
            break;
        }
    }
  return index;
}


