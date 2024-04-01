// Program to count number of vowels, consonants and spaces 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE_PARA 500

void nCountVowel(char*);
void nCountConso(char*);
void nCountSpace(char*);

int main()
{
    int userChoice;
    char paragraph[SIZE_PARA];

    while(1)
    {
        printf("\n");
        printf("Press - 1 - to count number of vowel\n");
        printf("Press - 2 - to count number of consonants\n");
        printf("Press - 3 - to count number of spaces\n");
        printf("Press - 0 - to exit the program\n");
        printf("---------------------------------------------------\n");

        // taking contents from the user
        printf("Enter your paragraph below \n");
        scanf(" %[^\n]s",paragraph);

        try_again:
        // User input to choose the number of operation
        printf("Enter number from the above to perform operation\n");
        scanf("%d",&userChoice);

        // validate user choice
        if(userChoice>=0 || userChoice<=3)
        {
            switch (userChoice)
            {
                case 0:
                    printf("\n\n================== END ==================\n\n");
                    exit(0);
                    break;
                case 1:
                    nCountVowel(paragraph);
                    printf("---------------------------------------------------\n\n");
                    break;
                case 2:
                    nCountConso(paragraph);
                    printf("---------------------------------------------------\n\n");
                    break;
                case 3:
                    nCountSpace(paragraph);
                    printf("---------------------------------------------------\n\n");
                    break;
                default:
                    printf("Some error occur!\n");
                    printf("Try after some time!\n");            
            }
        }
        else
        {
            printf("Please enter a valid operation number\n");
            goto try_again;
        }

    }

    return 0;
}

void nCountVowel(char para[])
{
    int i = 0;
    int vowel_count = 0;
    while(para[i] != '\0')
    {
        if(isalpha(para[i]))
        {
        char c = toupper(para[i]);
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            vowel_count++;
        }

        i++; 
    }

    printf("Number of vowels = %d\n",vowel_count);
}

void nCountConso(char para[])
{
    char consonant[] = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};
    int i = 0;
    int conso_count = 0;
    while(para[i] != '\0')
    {
        if(isalpha(para[i]))
        {
            char c = toupper(para[i]);

            for(int j = 0; j<21; j++)

                if(c == consonant[j])

                    conso_count++;
        }

        i++;
    }

    printf("Number of consonants = %d\n",conso_count);
}

void nCountSpace(char para[])
{
    int i = 0;
    int space_count = 0;
    while(para[i] != '\0')
    {
        char c = para[i];
        if(c == ' ' || c == '\t')
            space_count++;

            i++;
    }

    printf("Number of spaces = %d\n",space_count);
}