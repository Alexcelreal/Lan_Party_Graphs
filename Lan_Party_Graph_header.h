//
// Created by Alexandru Mihalache on 25.05.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define TEAMS_NUMBER 32

typedef struct Team{
    int pozition;
    char *teamName;
    float teamScore;
}Team;

typedef struct QueueNode{
    Team *data;
    struct QueueNode *next;
}QueueNode;

typedef struct QueueMatch{
    struct QueueNode *Front;
    struct QueueNode *Rear;
}QueueMatch;

typedef struct Graph{
    int V;
    int E;
    int **a;
}Graph;

//task 1
char *strtrim(char *str);
QueueMatch *createTheQueue(char *input);
QueueMatch *CreateQueue();
int isEmpty(QueueMatch *Matches);
void enQueue(QueueMatch *Matchs, Team *theTeam);
Team *deQueue(QueueMatch *Matchs);
void deleteQueue(QueueMatch *Match);
void showTheTable(QueueMatch *Matches, QueueMatch *win, QueueMatch *lost, Graph *theContest);
void RestoreDate(QueueMatch *win, QueueMatch *lost, QueueMatch **Matches);
void generateTheGraph(QueueMatch *Matches, char *output_2);

#ifndef TEMA_LAN_PARTY_GRAPHS_LAN_PARTY_GRAPH_HEADER_H
#define TEMA_LAN_PARTY_GRAPHS_LAN_PARTY_GRAPH_HEADER_H

#endif //TEMA_LAN_PARTY_GRAPHS_LAN_PARTY_GRAPH_HEADER_H
