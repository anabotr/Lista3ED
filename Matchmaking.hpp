#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP

#include "Player.hpp"
#include <iostream>
using namespace std;


class Matchmaking {

private:
    static const int MAX_PLAYERS = 10000;
    Player players[MAX_PLAYERS];
    int size = 0;

public:

    Matchmaking();
    ~Matchmaking();

    bool insert(Player player);
    bool removePlayer(int id);

    void sortByScoreInsertion();
    void sortByScoreMerge();

    Player* formGroup(int groupSize, int delta, int* n);

    Player* getWaitingPlayers(int* n);

    void printWaitingPlayers();

    Player* merge(Player arr1[], int n, Player arr2[], int m); 
    Player* mergeSort(Player arr[], int n); 

    // Outros métodos auxiliares, se necessário
};

#endif