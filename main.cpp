#include "Player.hpp"
#include "Matchmaking.hpp"

#include <iostream>
using namespace std;

int main(){
    Player lala(1, "Larissa", 1000, 1);
    Player ana(2,"Ana", 1000, 2); 
    Player dani(3, "Dani", 600, 3); 
    Player pedro(4, "Ped", 110, 4); 
    Player ana3(5, "Anaa", 1000, 5); 

    Matchmaking cs;
    Matchmaking tt; 
    
    // Inserção de jogadores 
    cs.insert(lala); 
    cs.insert(ana); 
    cs.insert(dani);
    cs.insert(pedro);

    // Remoção de jogador 
    cs.removePlayer(4); 
    
    // Ordenação por inserção com empate de score 
    cs.sortByScoreInsertion(); 

    // Exibição de estado do sistema 
    cs.printWaitingPlayers(); 

    int n2;
    int n3;  
    int n4;  
    Player* g2;
    Player* g3;
    Player* g4; 

    // Recuperação dos dados 
    g4 = cs.getWaitingPlayers(&n4); 
    cout << "Jogadores em espera: " << n4 << endl;
    delete[] g4;  

    // Formação de grupo sem sucesso
    g3 = cs.formGroup(3, 0, &n3);

    // Exibição de estado do sistema 
    cs.printWaitingPlayers(); 
    cout << "Grupo com 3:" << g3 << endl;
    delete[] g3;  
    
    // Formação bem-sucedida de grupo 
    g2= cs.formGroup(2, 400, &n2);

    // Exibição de estado do sistema 
    cs.printWaitingPlayers(); 
    cout << "Grupo com 2: " << g2 << endl;
    delete[] g2; 

    cout << "TT" << endl; 

    // Inserção de jogadores 
    tt.insert(lala); 
    tt.insert(ana); 
    tt.insert(dani);
    tt.insert(pedro); 
    tt.insert(ana3); 

    // Remoção de jogador 
    tt.removePlayer(2); 

    // Ordenação por Merge com empate de score 
    tt.sortByScoreMerge(); 

    // Exibição de estado do sistema 
    tt.printWaitingPlayers(); 

    int m3; 
    int m2;  
    int m4;
    int m5; 
    Player* h2;
    Player* h3;
    Player* h4;
    Player* h5;

    // Recuperação dos dados 
    h5 = tt.getWaitingPlayers(&m5); 
    cout << "Jogadores em espera: " << n4 << endl; 
    delete[] h5; 

    // Formação de grupo sem sucesso
    h3 = tt.formGroup(3, 10, &m3);

    // Exibição de estado do sistema 
    tt.printWaitingPlayers(); 
    cout << "Grupo com 3: " << h3 << endl;
    delete[] h3; 
    
    // Formação de grupo bem-sucedida
    h4= tt.formGroup(4, 1000, &m4);

    // Exibição de estado do sistema 
    tt.printWaitingPlayers(); 
    cout << "Grupo com 4: " << h4 << endl;  
    delete[] h4; 

    // Formação de grupo sem sucesso
    h2= tt.formGroup(2, 10, &m2);

    // Exibição de estado do sistema 
    tt.printWaitingPlayers(); 
    cout << "Grupo com 2: " << h2 << endl;    
    delete[] h2;  
}
