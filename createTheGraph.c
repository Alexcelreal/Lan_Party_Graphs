//
// Created by Alexandru Mihalache on 25.05.2024.
//

#include "Lan_Party_Graph_header.h"

void showTheTable(QueueMatch *Matches, QueueMatch *win, QueueMatch *contestHistory, Graph *theContest){
    Team *T1=NULL;
    Team *T2=NULL;
    while(!isEmpty(Matches)){
        T1= deQueue(Matches);
        T2= deQueue(Matches);
        if(T1->teamScore>T2->teamScore){
            enQueue(win,T1);
            enQueue(contestHistory,T2);
            theContest->a[T2->pozition][T1->pozition]=1;
        }else if(T1->teamScore<T2->teamScore){
            enQueue(win,T2);
            enQueue(contestHistory,T1);
            theContest->a[T1->pozition][T2->pozition]=1;
        }else if(strcmp(T1->teamName,T2->teamName)>0){
            enQueue(win,T1);
            enQueue(contestHistory,T2);
            theContest->a[T2->pozition][T1->pozition]=1;
        }else{
            enQueue(win,T2);
            enQueue(contestHistory,T1);
            theContest->a[T1->pozition][T2->pozition]=1;
        }
        theContest->E+=1;
    }
    T1=NULL;
    T2=NULL;
    deleteQueue(Matches);
}

void RestoreData(QueueMatch *win, QueueMatch **Matches){
    Team *newTeam=NULL;
    QueueMatch *tempMatch= CreateQueue();
    while(!isEmpty(win)){
        newTeam= deQueue(win);
        enQueue(tempMatch,newTeam);
    }
    while(!isEmpty(tempMatch)){
        newTeam= deQueue(tempMatch);
        enQueue(*Matches,newTeam);
    }
    deleteQueue(tempMatch);
}

Graph *generateTheGraph(QueueMatch *Matches, char *output_1, QueueMatch *contestHistory){
    FILE *myfile=fopen(output_1,"wt");
    if(myfile==NULL){
        perror("Can't open this file");
        exit(1);
    }
    Graph *theContest=(Graph*)malloc(sizeof(Graph));
    if(theContest==NULL){
        printf("Not enough memory");
        exit(1);
    }
    theContest->V=TEAMS_NUMBER;
    theContest->E=0;
    theContest->a=(int**)malloc(theContest->V*sizeof(int*));
    for(int i=0;i<theContest->V;i++){
        theContest->a[i]=(int*)calloc(theContest->V,sizeof(int));
    }
    if(theContest->a==NULL){
        printf("Not enough memory");
        exit(1);
    }
    int cnt=1;
    int nrRounds=floor(log2(TEAMS_NUMBER));
    QueueMatch *win=CreateQueue();
    while(cnt<=nrRounds){
        showTheTable(Matches,win,contestHistory,theContest);
        RestoreData(win,&Matches);
        cnt++;
    }
    Team *theWinner= deQueue(Matches);
    enQueue(contestHistory,theWinner);
    deleteQueue(Matches);

    for(int i=0;i<TEAMS_NUMBER;i++){
        for(int j=0;j<TEAMS_NUMBER;j++){
            fprintf(myfile,"%d ",theContest->a[i][j]);
        }
        fprintf(myfile,"\n");
    }
    fclose(myfile);
    return theContest;
}
