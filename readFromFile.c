//
// Created by Alexandru Mihalache on 25.05.2024.
//
#include "Lan_Party_Graph_header.h"

#define DIM 25

char *strtrim(char *string) {
    while (isspace(*string)) { //stergere spatii goale inceput
        string++;
    }
    if (*string == '\0') {
        return string;
    }
    char *end;
    end = string + strlen(string) - 1; //pozitionare ultim caracter ce nu este spatiu
    while (end > string && isspace(*end)) { //stergere spatii goale final
        end--;
    }
    *(end + 1) = '\0';
    return string;
}

QueueMatch *createTheQueue(char *input) {
    FILE *readFile = fopen(input, "rt");
    if (readFile == NULL) {
        perror("Can't open this file");
        exit(1);
    }
    int teamsNumber = TEAMS_NUMBER;
    char *name = (char *) malloc(DIM * sizeof(char));
    if (name == NULL) {
        printf("Not enough memory");
        exit(1);
    }
    QueueMatch *theMatches = CreateQueue();
    int pozition = 0;
    while (teamsNumber != 0) {
        Team *theTeam = (Team *) malloc(sizeof(Team));
        if (theTeam == NULL) {
            printf("Not enough memory");
            free(name);
            fclose(readFile);
            exit(1);
        }
        fscanf(readFile, "%f", &theTeam->teamScore); //citire scor echipa
        fscanf(readFile, " ");
        fscanf(readFile, "%[^\n]", name); //citire nume echipa (citire pana la \n)
        theTeam->teamName = strdup(strtrim(name));
        theTeam->pozition = pozition;
        theTeam->teamPrestige = 0;
        enQueue(theMatches, theTeam); //adaugare echipa in coada
        teamsNumber--;
        pozition++;
    }
    free(name);
    fclose(readFile);
    return theMatches;
}