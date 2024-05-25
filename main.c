#include "Lan_Party_Graph_header.h"

int main(int argc, char *argv[]){

    if(argc!=4){
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
    QueueMatch *theMatches= createTheQueue(input);
    generateTheGraph(theMatches,output_1);
}