// Computes the approximate grade level needed to comprehend some text

// Include header files
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Declares that there is code under the main function to consider
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float compute_index(int letters, int words, int sentences);

// Main program
int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float index = compute_index(letters, words, sentences);
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %.0f\n", round(index));
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// Count number of letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

// Count number of words
int count_words(string text)
{
    int spaces = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            spaces += 1;
        }
    }
    // We consider that the number words equals the number of spaces plus one
    int words = spaces + 1;
    return words;
}

// Count number of sentences
int count_sentences(string text)
{
    int punctuations = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            punctuations += 1;
        }
    }
    // We consider that the number sentences equals the number of punctations
    int sentences = punctuations;
    return sentences;
}

// Compute index
float compute_index(int letters, int words, int sentences)
{
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}