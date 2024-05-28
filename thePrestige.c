//
// Created by Alexandru Mihalache on 25.05.2024.
//
#include "Lan_Party_Graph_header.h"

#define NR_ROUNDS 6

float theCalculation(int nrVictory) { //realizare calcul prestigiu
    float q = 0.15;
    int nrRounds = NR_ROUNDS;
    float result = (q * pow(2 - q, nrVictory));
    float result2 = pow(2, nrRounds) + pow((2 - q), nrRounds) * (q - 1);
    return result / result2;
}

void calculateThePrestige(Graph *theContest, QueueMatch *contestHistory) {
    QueueNode *nodeCpy = contestHistory->Front;
    while (nodeCpy != NULL) {
        int victory = 0;
        for (int i = 0; i < TEAMS_NUMBER; i++) {
            if (theContest->a[i][nodeCpy->data->pozition] == 1)
                victory++;
        }
        nodeCpy->data->teamPrestige = theCalculation(victory); //atribuire prestigiu echipa
        nodeCpy = nodeCpy->next;
    }
}

void showThePrestige(QueueMatch *contestHistory, char *output_2) { //afisare echipa si prestigiul acesteia
    FILE *myfile = fopen(output_2, "wt");
    if (myfile == NULL) {
        perror("Can't open this file");
        exit(1);
    }
    QueueNode *nodeCpy = contestHistory->Front;
    while (nodeCpy != NULL) {
        fprintf(myfile, "%.4f %s\n", nodeCpy->data->teamPrestige, nodeCpy->data->teamName);
        nodeCpy = nodeCpy->next;
    }
    fclose(myfile);
    deleteQueue(contestHistory);
}