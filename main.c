#include <stdio.h>
#include <ctype.h>

int main() 
{
    //Arrayer för namn, poäng och medelvärde.
    char names[5][11];
    int scores[5][13];
    double avg[5];

    // Läser in namn och poäng, samt beräknar medelvärdet.
    for (int i = 0; i < 5; i++) 
    {
        scanf("%s", names[i]);

        int sum = 0;

        for (int j = 0; j < 13; j++) {
            scanf("%d", &scores[i][j]);
            sum += scores[i][j];
        }

        
        avg[i] = (double)sum / 13;
    }

    //Här hittar jag eleven med högst medelvärde.
    int maxIndex = 0;
    for (int i = 1; i < 5; i++) 
    {
        if (avg[i] > avg[maxIndex]) 
        {
            maxIndex = i;
        }
    }

    // Beräknar gruppens medelvärde.
    double total = 0;
    for (int i = 0; i < 5; i++) 
    {
        total += avg[i];
    }
    double groupAvg = total / 5;

    //Stor bokstav samt skriver ut eleven med högst medelvärde.
    names[maxIndex][0] = toupper(names[maxIndex][0]);
    for (int i = 1; names[maxIndex][i] != '\0'; i++) 
    {
        names[maxIndex][i] = tolower(names[maxIndex][i]);
    }
    printf("%s\n", names[maxIndex]);

    // Skriver ut eleverna som har under medelvärdet.
    for (int i = 0; i < 5; i++) 
    {
        if (i != maxIndex && avg[i] < groupAvg) 
        {

            names[i][0] = toupper(names[i][0]);
            for (int j = 1; names[i][j] != '\0'; j++) 
            {
                names[i][j] = tolower(names[i][j]);
            }

            printf("%s\n", names[i]);
        }
    }

    return 0;
}