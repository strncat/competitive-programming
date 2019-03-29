//
//  main.cpp
//  uhunt
//
//  10258 - Contest Scoreboard
//  2017/03/20
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using std::string;
using std::vector;
using std::unordered_map;

typedef struct score_card {
    int penalty[10];
    int correct[10];
    score_card() {
        for (int i = 0; i < 10; i++) {
            penalty[i] = 0;
            correct[i] = 0;
        }
    }
} score_card;

typedef struct player {
    int id;
    int win;
    int time;
    player(int i, int w, int t) {
        id = i;
        win = w;
        time = t;
    }
} player;

int compare(const player& a, const player& b) {
    return (a.win > b.win ||
            (a.win == b.win && a.time < b.time) ||
            (a.win == b.win && a.time == b.time && a.id < b.id));
}

int main() {
    //freopen("sample.in", "r", stdin);

    int test_cases;
    scanf("%d\n", &test_cases);

    while (test_cases--) {

        unordered_map<int, score_card> m;
        char line[100];
        int id, problem, time;
        char result;

        while(fgets(line, 50, stdin)) {
            if (line[0] == '\n') {
                break;
            }

            sscanf(line, "%d %d %d %c", &id, &problem, &time, &result);
            m[id].correct[0] = 0;

            if (result == 'C') {
                if (!m[id].correct[problem]) { // if it wasn't already solved
                    m[id].correct[problem] = 1;
                    m[id].penalty[problem] += time;
                }
            } else if (result == 'I') {
                if (!m[id].correct[problem]) { // if it wasn't already solved
                    m[id].penalty[problem] += 20;
                }
            }
        }

        vector<player> players;
        for (auto i = m.begin(); i != m.end(); i++) {
            int total_penalty = 0;
            int total_correct = 0;
            for (int j = 0 ; j < 10; j++) {

                // clear the penalty if the problem wasn't solved
                if (i->second.correct[j] == 0) { i->second.penalty[j]=0; }

                total_correct += i->second.correct[j];
                total_penalty += i->second.penalty[j];
            }
            players.push_back(player(i->first, total_correct, total_penalty));
        }
 
        std::sort(players.begin(), players.end(), compare);

        for (int i = 0; i < players.size(); i++) {
            printf("%d %d %d\n", players[i].id, players[i].win, players[i].time);
        }
        if (test_cases) {
            printf("\n");
        }
    }
    return 0;
}
