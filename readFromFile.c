//
// Created by Alexandru Mihalache on 25.05.2024.
//
#include "Lan_Party_Graph_header.h"

#define DIM 25

char *strtrim(char *str) {
    char *end;
    while (isspace((unsigned char) *str)) { //stergere spatii inceput
        str++;
    }
    if (*str == '\0') {
        return str;
    }
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char) *end)) { //stergere spatii final
        end--;
    }
    *(end + 1) = '\0';
    return str;
}

QueueMatch *createTheQueue(char *input){
    FILE *readFile=fopen(input,"rt");
    if(readFile==NULL){
        perror("Can't open this file");
        exit(1);
    }
    int teamsNumber=TEAMS_NUMBER;
    char *name=(char*)malloc(DIM *sizeof(char));
    if(name==NULL){
        printf("Not enough memory");
        exit(1);
    }
    QueueMatch *theMatches= CreateQueue();
    int pozition=0;
    while(teamsNumber!=0){
        Team *theTeam=(Team*)malloc(sizeof(Team));
        if(theTeam==NULL){
            printf("Not enough memory");
            free(name);
            fclose(readFile);
            exit(1);
        }
        fscanf(readFile,"%f",&theTeam->teamScore);
        fscanf(readFile," ");
        fscanf(readFile,"%[^\n]",name);
        theTeam->teamName=strdup(strtrim(name));
        theTeam->pozition=pozition;
        enQueue(theMatches,theTeam);
        teamsNumber--;
        pozition++;
    }
    free(name);
    fclose(readFile);
    return theMatches;
}