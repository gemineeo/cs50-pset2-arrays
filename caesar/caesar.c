// Cypher text using a key

// Include header files
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Verify there is only 1 argument
    if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // Verify argument is a digit
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        //Convert argument from string to int
        int key = atoi(argv[1]);

        // Promt plaintext
        string plaintext = get_string("plaintext: ");

        // Print ciphertext
        printf("ciphertext: ");
        int c = 0;

        // Shift character by key
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            char p = plaintext[i];
            if (isupper(p))
            {
                c = (p - 65 + key) % 26 + 65;
            }
            else if (islower(p))
            {
                c = (p - 97 + key) % 26 + 97;
            }
            else
            {
                c = p;
            }
            printf("%c", c);
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}