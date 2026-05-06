#include <iostream>
using namespace std;

#include "Matchmaking.hpp" 
#include "Player.hpp"

Matchmaking::Matchmaking(){}
Matchmaking::~Matchmaking(){}

bool Matchmaking::insert(Player player){
    this->players[this->size] = player; 
    this->size += 1; 
}

bool Matchmaking::removePlayer(int id){
    for(int i = 0; i < this->size+1; i++){
        if(this->players[i].getId() == id){
            int temp = i;
            for (int j = i+1; j < this->size+1; j++){
                this->players[temp] = this->players[j];
                temp++; 
            }
            return true; 
        }
        return false; 
    }
}

void Matchmaking::sortByScoreInsertion(){
    if (this->size == 0){
        return; 
    }
    for(int i = 1; i<this->size; i++){
        int j = i-1; 
        Player curr = this->players[j]; 
        while (j>=0 && this->players[i].getScore() >= curr.getScore()){
            this->players[j+1] = this->players[j]; 
            j = j-1; 
        }
        this->players[j+1] = curr; 
    }
}
void Matchmaking::sortByScoreMerge(){}

Player* Matchmaking::formGroup(int groupSize, int delta, int* n){}

Player* Matchmaking::getWaitingPlayers(int* n){
    // Podemos retornar uma cópia do array mas ele é muito grande ent acho que para gastar menos memória assim é melhor mas aumenta a complexidade 
    if (this->size == 0){
        *n = 0; 
        return nullptr; 
    }
    Player arr[this->size];
    for (int i =0; i<this->size; i++){
        arr[i] = this->players[i]; 
    } 
    *n = this->size; 
    return arr; 
}

void Matchmaking::printWaitingPlayers(){
    if (this->size == 0){
        cout << "(empty)" << endl; 
    }
    for(int i = 0; i < this->size+1; i++){
        cout << "[" << this->players[i].getId() << " | " << this->players[i].getName()  << " | " << this->players[i].getScore()  << " | " << this->players[i].getTimestamp() << "]" << endl; 
    }
}