#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    enum {
        ROCK = 1,
        PAPER = 2,
        SCICCORS = 3,
        LOSS = 0,
        DRAW = 3,
        WIN = 6
    };

    fp = fopen("input.txt", "r");
    if (fp == NULL) return 1;

    long int score1 = 0;
    long int score2 = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        score1 += line[2] == 'X' ? ROCK : line[2] == 'Y' ? PAPER : line[2] == 'Z' ? SCICCORS : 0;
        
        //Score 1
        // ROCK vs ROCK, PAPER, SCICCORS
        if(line[2] == 'X' && line[0] == 'A') score1 += DRAW;
        else if(line[2] == 'X' && line[0] == 'B') score1 += LOSS;
        else if(line[2] == 'X' && line[0] == 'C') score1 += WIN;

        // PAPER vs ROCK, PAPER, SCICCORS
        else if(line[2] == 'Y' && line[0] == 'A') score1 += WIN;
        else if(line[2] == 'Y' && line[0] == 'B') score1 += DRAW;
        else if(line[2] == 'Y' && line[0] == 'C') score1 += LOSS;

        // SCICCORS vs ROCK, PAPER, SCICCORS
        else if(line[2] == 'Z' && line[0] == 'A') score1 += LOSS;
        else if(line[2] == 'Z' && line[0] == 'B') score1 += WIN;
        else if(line[2] == 'Z' && line[0] == 'C') score1 += DRAW;

        //Score 2
        //LOOSE
        if(line[2] == 'X' && line[0] == 'A') score2 += LOSS + SCICCORS;
        else if(line[2] == 'X' && line[0] == 'B') score2 += LOSS + ROCK;
        else if(line[2] == 'X' && line[0] == 'C') score2 += LOSS + PAPER;

        else if(line[2] == 'Y' && line[0] == 'A') score2 += DRAW + ROCK;
        else if(line[2] == 'Y' && line[0] == 'B') score2 += DRAW + PAPER;
        else if(line[2] == 'Y' && line[0] == 'C') score2 += DRAW + SCICCORS;

        else if(line[2] == 'Z' && line[0] == 'A') score2 += WIN + PAPER;
        else if(line[2] == 'Z' && line[0] == 'B') score2 += WIN + SCICCORS;
        else if(line[2] == 'Z' && line[0] == 'C') score2 += WIN + ROCK;
    }

    printf("Answer 1: %ld", score1);
    printf("Answer 2: %ld", score2);

    fclose(fp);
    if (line)
        free(line);
    
    return 0;
}