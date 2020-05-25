#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool check_valid_key(string s); //saying to the system that there is a function called check_valid_key

int main(int argc, string argv[])
{
    if (argc != 2 || !check_valid_key(argv[1])) //checks if key is valid
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]); // "12" -> 12

    string plaintext = get_string("plaintext: "); //gets plaintext

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plaintext); i < len; i++)  //converts the plaintext to ciphertext
    {
        char c = plaintext[i];
        if (isalpha(c)) //checks if the char is a letter
        {
            char m = 'A';
            if (islower(c)) //checks if its lower
            {
                m = 'a';
            }
            printf("%c", (c - m + key) % 26 + m); //converting the plain chars to cipher chars
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}

bool check_valid_key(string s) //checks if key is valid
{
    for (int i = 0, len =  strlen(s); i < len; i++)
    {
        if (!isdigit(s[i])) //checks if it is a number
        {
            return false;
        }
    }
    return true;
}
