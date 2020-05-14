//
//  540 Team Queue
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>
#include <stack>
#include <unordered_map>

int main() {
    //freopen("in.txt" , "r" , stdin);

    int n, test = 1;
    while (scanf("%d", &n) && n != 0) {
        // this will map each member to its team id
        // for example team_ids[101] = 0 means that 101 is in team 0
        std::unordered_map<int,int> team_ids;

        // this will hold a queue for team team
        // so team_queues[0] is the queue for team 0
        std::unordered_map<int,std::queue<int>> team_queues;

        int m, u, team = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &m);
            team_queues[team] = std::queue<int>();
            for (int j = 0; j < m; j++) {
                scanf("%d", &u);
                team_ids[u] = team;
            }
            team++;
        }

        std::string s;
        // this will hold all queues together
        // for example, if main contains [0, 1]. this means that main has
        // team 0 at the front and team 1 at the end of the queue
        std::queue<int> main;

        printf("Scenario #%d\n", test++);

        while (std::cin >> s) {
            if (s == "STOP") {
                break;
            }
            int u;
            if (s == "ENQUEUE") {
                scanf("%d\n", &u);
                int team = team_ids[u];
                // this member is the first in their team to show up
                // so we enqueue their team in main
                if (team_queues[team].empty()) {
                    main.push(team);
                }
                team_queues[team].push(u);

            }
            if (s == "DEQUEUE") {
                int team = main.front();
                printf("%d\n", team_queues[team].front());
                team_queues[team].pop();
                // if the team queue becomes empty, we remove it from main
                // this means that there isn't anyone from the team in the line
                // holding a spot for their team
                if (team_queues[team].empty()) {
                    main.pop();
                }
            }
        }
        printf("\n");
    }

}
