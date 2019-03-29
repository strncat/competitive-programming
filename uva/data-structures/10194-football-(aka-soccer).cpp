//
//  main.cpp
//  uhunt
//
//  10194 - Football (aka Soccer)
//  2017/03/20
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <string.h>

using std::string;
using std::vector;
using std::unordered_map;

typedef struct team {
    string name;
    int points;
    int games;
    int wins;
    int loses;
    int ties;
    int goals_scored;
    int goals_against;
    team() {
        points = 0;
        games = wins = loses = ties = 0;
        goals_scored = goals_against = 0;
    }
} score_card;

int compare(const team& a, const team& b) {
    return (a.points > b.points ||
            // more wins
            (a.points == b.points && a.wins > b.wins) ||
            // goals diff
            (a.points == b.points && a.wins == b.wins
             && a.goals_scored-a.goals_against > b.goals_scored-b.goals_against) ||
            // goals scored
            (a.points == b.points && a.wins == b.wins
             && a.goals_scored-a.goals_against == b.goals_scored-b.goals_against
             && a.goals_scored > b.goals_scored) ||
            // fewer games
            (a.points == b.points && a.wins == b.wins
             && a.goals_scored-a.goals_against == b.goals_scored-b.goals_against
             && a.goals_scored == b.goals_scored && a.games < b.games) ||
            // name
            (a.points == b.points && a.wins == b.wins
             && a.goals_scored-a.goals_against == b.goals_scored-b.goals_against
             && a.goals_scored == b.goals_scored && a.games == b.games
             && strcasecmp(a.name.c_str(), b.name.c_str()) < 0)
            );
}

int main() {
    //freopen("sample.in", "r", stdin);

    int test_cases;
    scanf("%d\n", &test_cases);

    while (test_cases--) {

        unordered_map<string, team> m;
        int nteams, games;
        string line, name, tournament;

        std::getline(std::cin, tournament);

        scanf("%d\n", &nteams);
        for (int i = 0; i < nteams; i++) {
            std::getline(std::cin, name);
            m[name].name = name;
        }

        scanf("%d\n", &games);
        for (int i = 0; i < games; i++) {
            std::getline(std::cin, line);

            // Team A#3@1#Team B
            int index = 0;
            string aname, bname, ascore, bscore;
            while (line[index] != '#') {
                aname += line[index++];
            }
            index++;
            while (line[index] != '@') {
                ascore += line[index++];
            }
            index++;
            while (line[index] != '#') {
                bscore += line[index++];
            }
            index++;
            while (index < line.size()) {
                bname += line[index++];
            }

            int agoals, bgoals;
            if (ascore.length() == 1) {
                agoals = ascore[0]-'0';
            } else {
                agoals = ((ascore[0]-'0')*10) + ascore[1]-'0';
            }
            m[aname].goals_scored += agoals;
            m[bname].goals_against += agoals;

            if (bscore.length() == 1) {
                bgoals = bscore[0]-'0';
            } else {
                bgoals = ((bscore[0]-'0')*10) + bscore[1]-'0';
            }
            m[bname].goals_scored += bgoals;
            m[aname].goals_against += bgoals;

            m[bname].games++;
            m[aname].games++;

            if (agoals > bgoals) {
                m[aname].wins++;
                m[bname].loses++;
                m[aname].points += 3;
            } else if (agoals < bgoals) {
                m[bname].wins++;
                m[aname].loses++;
                m[bname].points += 3;
            } else { // tie;
                m[bname].ties++;
                m[aname].ties++;
                m[aname].points += 1;
                m[bname].points += 1;
            }
        }


        vector<team> teams;
        for (auto i = m.begin(); i != m.end(); i++) {
            //
            teams.push_back(i->second);
        }
 
        std::sort(teams.begin(), teams.end(), compare);

        std::cout << tournament << std::endl;
        for (int i = 0; i < teams.size(); i++) {
            // 1) Brazil 6p, 3g (2-0-1), 3gd (6-3)
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1, teams[i].name.c_str(), teams[i].points,
                   teams[i].games, teams[i].wins, teams[i].ties, teams[i].loses,
                   teams[i].goals_scored-teams[i].goals_against, teams[i].goals_scored, teams[i].goals_against);
        }

        if (test_cases) {
            printf("\n");
        }
    }
    return 0;
}
