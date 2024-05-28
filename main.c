#include "Lan_Party_Graph_header.h"

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Invalid data");
        exit(1);
    }

    char *input = argv[1];
    char *output_1 = argv[2];
    char *output_2 = argv[3];

    printf("Input file : %s\n", input);
    printf("Output file 1: %s\n", output_1);
    printf("Output file 2: %s\n", output_2);

    //task 1
    QueueMatch *theMatches = createTheQueue(input);
    QueueMatch *theContestHistory = CreateQueue();
    Graph *theContest = generateTheGraph(theMatches, output_1, theContestHistory);

    //task 2
    calculateThePrestige(theContest, theContestHistory);
    showThePrestige(theContestHistory, output_2);
    deleteQueue(theContestHistory); //eliberare memorie graf
    for (int i = 0; i < theContest->V; i++) {
        free(theContest->a[i]);
    }
    free(theContest->a);
    free(theContest);

}