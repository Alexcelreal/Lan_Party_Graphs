# LanParty_Graphs - Tema 2 in cadrul disciplinei "Proiectarea Algoritmilor"

Acest proiect are ca scop implementarea notiunilor dobandite in urma laboratorului si cursului de Proiectarea Algoritmilor.

## Cuprins

1. [Descriere](#descriere)
2. [Structura Proiectului](#structura-proiectului)
3. [Taskuri realizate](#taskuri-realizate)
   - [Task 1](#task-1)
     - [Functii Utilizate T1](#functii-utilizate-1)
   - [Task 2](#task-2)
     - [Functii Utilizate T2](#functii-utilizate-2)
4. [Cerinte de sistem](#cerinte-de-sistem)
5. [Utilizare](#utilizare)

## Descriere

- Programul creat implementeaza o simulare a unui turneu de gayming (Lan Party), unde echipele sunt eliminate progresiv, in functie de scor. Va exista un unic castigator.
- In urma meciurilor disputate se va realiza graful turneului. 
- In functie de graful rezultat se va calcula prestigiul fiecarie echipe.
- Fisierele `.c` contin functiile utilizate, iar fisierele `.h` (headerele) contin antetele functiilor, bibliotecide utilizate si structurile de date necesare programului.

## Structura proiectului
```
├── CMakeLists.txt
├── Input
│   ├── test1.in
│   ├── ...
├── Lan_Party_Graph_header.h
├── Makefile
├── Queue.c
├── README.md
├── RezultateGraf
│   ├── test1.out
│   ├── ...
├── RezultateScor
│   ├── test1.out
│   ├── ...
├── clasament
├── cmake-build-debug
├── createTheGraph.c
├── main.c
├── readFromFile.c
└── thePrestige.c
```
## Taskuri Realizate

### Task 1:
    Fisiere: readFromFile.c / createTheGraph.c
- Citirea din fisierul Input/testn.in a datelor si adaugarea acestora intr-o coada de echipe;
- Desfasurarea meciurilor intre echipe, utilizand o coada de castigatori si una de pierzatori, pana la aflarea invingatorului;
- Crearea matricei de adiacenta a grafului rezultat in urma meciurilor disputate;

### Functii Utilizate 1:
    QueueMatch *createTheQueue(char *input)
- Citeste datele din fisierul de intrare si le adauga intr-o coada de meciuri;
- Returneaza pointer catre coada de meciuri creata;


    char *strtrim(char *string)
- Stergerea spatiilor goale de la inceputul si finalul fiecarui string;
- Stergere "\n";

    
    void TheTable(QueueMatch *Matches, QueueMatch *win, QueueMatch *contestHistory, Graph *theContest)
- Se extrag cate 2 echipe din coada de meciuri, pana cand aceasta este goala, iar acestea sunt redistribuite in functie de penctaj catre coada `win` sau `contestHistory`;
- Se actualizeaza matricea de adiacenta a grafului `theContest` pe baza rezultatelor meciurilor;

  
    void RestoreData(QueueMatch *win, QueueMatch **Matches)
- Muta datele din coada castigatoare in coada de meciuri principala;


    Graph *generateTheGraph(QueueMatch *Matches, char *output_1, QueueMatch *contestHistory)
- Genereaza graful competitiei pe baza rezultatelor obtinute la apelul functiilor descrise anterior;
- Scrie matricea de adiacenta a grafului intr-un fisier de iesire;
- Returneaza pointer la structura `Graph` generata;

### Task 2:
- Calcularea prestigiului fiecarei echipe;
- Afisarea prestigiului echipei si numele acesteia intr-un fisier de iesire;

#### Functii Utilizate 2:
    float theCalculation(int nrVictory)
- Calculeaza prestigiul unei echipe in functie de numarul de victorii;
- Returneaza un `float` reprezentand prestigiul calculat;


    void calculateThePrestige(Graph *theContest, QueueMatch *contestHistory)
- Calculeaza si atribuie prestigiul fiecarei echipe din coada `contestHistory`, generata la taskul anterior;
- Numara numarul de victorii pentru fiecare echipa in functie de matricea de adiacenta a grafului;

    
    void showThePrestige(QueueMatch *contestHistory, char *output_2)
- Afiseaza prestigiul si numele echipei in fisierul de iesire specificat;


## Cerinte de sistem:
- Sistem de operare: Linux, macOS, Windows
- Compilator: GCC
- CMake: Versiunea 3.10 sau mai noua
- Spatiu pe Disc: Minimum 100MB
- Memorie RAM: Minimum 512 MB

## Utilizare:
- Functia `main` din acest program gestioneaza fluxul principal de executie al programului LanParty_Graphs;
- Aplicatia citeste informatiile din fisierul testn.in, unde n este numarul testului;
- Taskul 2 este dependent de taskul 1;
- Pentru a compila programul se va scrie in terminal comanda `make build`;
- Pentru a rula programul se va scrie in terminal comanda `make run` (doar pentru un test specificat);
- Pentru a rula testul dorit se vor face modificari in urmatoarea linie de cod din Makefile: `./clasament Input/testn.in r1.out r2.out`, unde n reprezinta numarul testului;
- Pentru a rula checkerul se va scrie in terminal comanda `.\checker.sh`;
- Pentru a vizualiza rezultatul se acceseaza fisierele r1.out si r2.out;
- Pentru a sterge fisierul executabil si fisierele r1.out si r2.out se va scrie in terminal comanda `make clean`;
