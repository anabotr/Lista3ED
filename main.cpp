#include "Player.hpp"
#include "Matchmaking.hpp"

#include <iostream>
using namespace std;

int main(){
    Player lala(1, "Larissa", 1000, 1);
    Player ana(2,"Ana", 1000, 2); 
    Player dani(3, "Dani", 600, 3); 
    Player pedro(4, "Ped", 110, 4); 

    Matchmaking cs;
    Matchmaking tt; 
    
    cs.insert(lala); 
    cs.insert(ana); 
    cs.insert(dani);
    cs.insert(pedro);
    
    cs.sortByScoreInsertion(); 
    cs.printWaitingPlayers(); 

    int n2;
    int n3;  
    int n4;  
    Player* g2;
    Player* g3;
    Player* g4; 

    g4 = cs.getWaitingPlayers(&n4); 
    cout << "Jogadores em espera: " << n4 << endl;
    delete[] g4;  

    g3 = cs.formGroup(3, 0, &n3);
    cs.printWaitingPlayers(); 
    cout << "Grupo com 3:" << g3 << endl;
    delete[] g3;  
    
    g2= cs.formGroup(2, 400, &n2);
    cs.printWaitingPlayers(); 
    cout << "Grupo com 2:" << g2 << endl;
    delete[] g2; 

    cout << "TT" << endl; 

    tt.insert(lala); 
    tt.insert(ana); 
    tt.insert(dani);
    tt.insert(pedro); 

    tt.printWaitingPlayers(); 
    tt.sortByScoreMerge(); 
    tt.printWaitingPlayers(); 

    int m3; 
    int m2;  
    int m4;
    int m5; 
    Player* h2;
    Player* h3;
    Player* h4;
    Player* h5;

    h5 = tt.getWaitingPlayers(&m5); 
    cout << "Jogadores em espera: " << n4 << endl; 
    delete[] h5; 

    h3 = tt.formGroup(3, 10, &m3);
    tt.printWaitingPlayers(); 
    cout << "Grupo com 3:" << h3 << endl;
    delete[] h3; 
    
    h4= tt.formGroup(4, 1000, &m4);
    tt.printWaitingPlayers(); 
    cout << "Grupo com 4:" << h4 << endl;  
    delete[] h4; 

    h2= tt.formGroup(2, 10, &m2);
    tt.printWaitingPlayers(); 
    cout << "Grupo com 2:" << h2 << endl;    
    delete[] h2;   
}
