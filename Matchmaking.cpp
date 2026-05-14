#include <iostream>
using namespace std;

#include "Matchmaking.hpp" 
#include "Player.hpp"

Matchmaking::Matchmaking(){}
Matchmaking::~Matchmaking(){}

bool Matchmaking::insert(Player player){
    if (this->size == this->MAX_PLAYERS) return false;
    this->players[this->size] = player; 
    this->size += 1; 
    return true;
}

bool Matchmaking::removePlayer(int id){
    for(int i = 0; i < this->size; i++){
        if(this->players[i].getId() == id){
            int curr = i;
            if (i == this->size){
                this->size--;
                return true;
            }
            for (int j = i+1; j < this->size; j++){
                this->players[curr] = this->players[j];
                curr++; 
            }
            return true; 
        }
    }
    return false; 
}

void Matchmaking::sortByScoreInsertion(){
    if (this->size == 0){
        return; 
    }
    for(int i = 1; i<this->size; i++){
        int j = i-1; 
        Player curr = this->players[i]; 
        while (j>=0 && this->players[j].getScore() > curr.getScore()){
            this->players[j+1] = this->players[j]; 
            j = j-1; 
        }
        this->players[j+1] = curr; 
    }
}

Player* Matchmaking::merge(Player arr1[], int n, Player arr2[], int m) {
    Player* result = new Player[m + n];
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (arr1[i].getScore() <= arr2[j].getScore()) {
            result[i + j] = arr1[i];
            i++;
        } else {
            result[i + j] = arr2[j];
            j++;
        }
    }
    while (i < n) {
        result[i + j] = arr1[i];
        i++;
    }
    while (j < m) {
        result[i + j] = arr2[j];
        j++;
    }
    return result;
}

Player* Matchmaking::mergeSort(Player arr[], int n) {                  
    if (n == 1) {                                   
        Player* single = new Player[1];                  
        single[0] = arr[0];                         
        return single;                              
    }
    int mid = n / 2;                                
    Player* left = mergeSort(arr, mid);                
    Player* right = mergeSort(arr + mid, n - mid);   
    Player* sorted = merge(left, mid, right, n - mid);

    delete[] left;                                
    delete[] right;                                 
    return sorted;                                  
}

void Matchmaking::sortByScoreMerge(){
    Player* sorted = mergeSort(this->players, this->size);  
    for (int i = 0; i< this->size; i++){
        this->players[i] = sorted[i];
    }
}

Player* Matchmaking::formGroup(int groupSize, int delta, int* n){
    if (this->size < groupSize){
        n = 0;
        return nullptr;
    }
    for (int i = 0; i<this->size - groupSize + 1; i++){
        int j = i + groupSize - 1;
        int diff = this->players[j].getScore() - this->players[i].getScore();
        if (diff <= delta){
            Player* chosen = new Player[groupSize];
            for (int k = 0; k <groupSize; k++){
                chosen[k] = this->players[k+i];
            }
            *n = groupSize;

            for (int l = 0; l<groupSize; l++){
                removePlayer(chosen[l].getId());
            }
            
            return chosen;
        }
    }
    n = 0;
    return nullptr;
}

Player* Matchmaking::getWaitingPlayers(int* n){
    if (this->size == 0){
        *n = 0; 
        return nullptr; 
    }
    Player* arr = new Player[this->size];
    for (int i = 0; i<this->size; i++){
        arr[i] = this->players[i]; 
    } 
    *n = this->size; 
    return arr; 
}

void Matchmaking::printWaitingPlayers(){
    cout << "Waiting players: " << endl; 

    if (this->size == 0){
        cout << "(empty)" << endl; 
    }
    
    for(int i = 0; i < this->size; i++){
        cout << "[" << this->players[i].getId() << " | " << this->players[i].getName()  << " | " << this->players[i].getScore()  << " | " << this->players[i].getTimestamp() << "]" << endl; 
    }
}