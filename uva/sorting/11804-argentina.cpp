//
//  main.cpp
//  uhunt
//
//  11804 - Argentina
//  2017/02/07
//

#include <iostream>
#include <vector>
#include <algorithm> // sort

typedef struct Player {
    int attack;
    int defend;
    std::string name;
    Player(int a, int d, std::string n) {
        attack = a;
        defend = d;
        name = n;
    }
} Player;

std::vector<Player> players;

bool compare(const Player& a, const Player& b) {
    return (a.attack > b.attack) ||
    (a.attack == b.attack && a.defend < b.defend) ||
    (a.attack == b.attack && a.defend == b.defend && a.name < b.name);
}

int main() {
    //freopen("sample.in", "r", stdin);
    int test_cases, a, d;
    std::vector<Player> players;
    std::vector<std::string> attackers;
    std::vector<std::string> defenders;
    std::string s;

    scanf("%d", &test_cases);

    for (int t = 1; t <= test_cases; t++) {
        players.clear();
        attackers.clear();
        defenders.clear();
        for (int i = 0; i < 10; i++) {
            std::cin >> s >> a >> d;
            players.push_back(Player(a,d,s));
        }

        std::sort(players.begin(), players.end(), compare);
        for (int i = 0; i < 10; i++) {
            if (i < 5) {
                attackers.push_back(players[i].name);
            } else {
                defenders.push_back(players[i].name);
            }
            //std::cout << players[i].name << " " << players[i].attack << " " << players[i].defend << std::endl;
            std::sort(attackers.begin(), attackers.end());
            std::sort(defenders.begin(), defenders.end());
        }
        printf("Case %d:\n", t);
        printf("(");
        for (int i = 0; i < 4; i++) {
            std::cout << attackers[i] << ", ";
        }
        std::cout << attackers[4] << ")\n";
        printf("(");
        for (int i = 0; i < 4; i++) {
            std::cout << defenders[i] << ", ";
        }
        std::cout << defenders[4] << ")\n";

    }
    return 0;
}
