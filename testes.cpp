#include <iostream>
#include <chrono>
#include <cmath>
#include "Matchmaking.hpp"
#include <random>

using namespace std;
using namespace std::chrono;

const int NUM_TAMS = 13;
const int NUM_EXECS = 100;

int sizes[NUM_TAMS] = {10, 100, 1000, 2000, 5000,10000,15000,20000,30000,40000,50000, 80000, 100000};

void generatePlayers(Player* players, int n) {
    static std::mt19937 rng(42); 
    std::uniform_int_distribution<int> dist(0, 4999);

    for (int i = 0; i < n; i++) {
        int id = i;
        string name = "Jogador" + to_string(i);
        int score = dist(rng);
        int timestamp = i;

        players[i] = Player(id, name, score, timestamp);
    }
}

void copyArray(Player* copia, Player* original, int n) {
    for (int i = 0; i < n; i++) {
        copia[i] = original[i];
    }
}

int main() {

    srand(42);

    cout << "N,Insertion(microsseg),Merge(microsseg)" << endl;

    for (int t = 0; t < NUM_TAMS; t++) {

        int N = sizes[t];

        Player* original = new Player[N];
        Player* working  = new Player[N];

        generatePlayers(original, N);

        long long total_insertion = 0;
        long long total_merge = 0;

        //warm-up para evitar erros de medição
        copyArray(working, original, N);
        Matchmaking warm_merge;
        for (int i = 0; i < N; i++) warm_merge.insert(working[i]);
        warm_merge.sortByScoreMerge();

        copyArray(working, original, N);
        Matchmaking warm_insert;
        for (int i = 0; i < N; i++) warm_insert.insert(working[i]);
        warm_insert.sortByScoreInsertion();

        for (int execucao = 0; execucao < NUM_EXECS; execucao++) {
            Matchmaking mm_insert;

            for (int i = 0; i < N; i++) {
                mm_insert.insert(original[i]);
            }

            auto inicio_insert = high_resolution_clock::now();
            mm_insert.sortByScoreInsertion();
            auto fim_insert = high_resolution_clock::now();

            total_insertion += duration_cast<microseconds>(fim_insert - inicio_insert).count();


            Matchmaking mm_merge;

            for (int i = 0; i < N; i++) {
                mm_merge.insert(original[i]);
            }

            auto inicio_merge = high_resolution_clock::now();
            mm_merge.sortByScoreMerge();
            auto fim_merge = high_resolution_clock::now();

            total_merge += duration_cast<microseconds>(fim_merge - inicio_merge).count();
        }
        
        long long n2 = (long long)N * N;
        double nlogn = N * log2(N);
        long long n_2 = N/2;

        cout << N << ","
             << (total_insertion / NUM_EXECS) << ","
             << (total_merge / NUM_EXECS) << endl;

        delete[] original;
        delete[] working;
    }

    return 0;
}