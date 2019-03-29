//
//  main.cpp
//  uhunt
//
//  10142 - Australian Voting
//  2017/02/16
//
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <set>

int main() {
    //freopen("sample.in", "r", stdin);
    int t, n;
    scanf("%d", &t);
    while(t--) {
        // INPUT CRAP
        scanf("%d\n", &n);
        std::vector<std::string> candidates;
        std::vector<std::vector<int>> ballots;
        std::vector<int> indices;
        std::vector<bool> running;
        std::vector<int> count;
        std::string line;

        for (int i = 0; i < n; i++) {
            std::getline(std::cin, line);
            candidates.push_back(line);
            running.push_back(true);
            count.push_back(0);
        }

        getline(std::cin, line);
        while (line != "") {
            std::stringstream ss;
            ss << line;
            std::vector<int> ballot;

            int vote;
            for (int i = 0; i < n; i++) {
                ss >> vote;
                ballot.push_back(--vote);
            }

            ballots.push_back(ballot);
            indices.push_back(0);
            std::getline(std::cin, line);
        }

        // SOLUTION
        int num_votes = (int)ballots.size();
        int winner = -1;

        while (1) {
            // (1) count the votes
            std::fill(count.begin(), count.end(), 0);
            for (int i = 0; i < ballots.size(); i++) {
                if (indices[i] < ballots[i].size()) {
                    int candidate = ballots[i][indices[i]];
                    if (running[candidate]) {
                        count[candidate]++;
                    }
                }
            }

            // (2) maybe there is a majority right away
            for (int i = 0; i < candidates.size(); i++) {
                if (count[i] * 2 > ballots.size()) { // majority
                    winner = i;
                    break;
                }
                if (count[i] == 0) { // a candidate that didn't get any votes
                    running[i] = false; // drop them immediately
                }
            }

            if (winner != -1) { // majority found, quit
                break;
            }

            // (3) Find the lowest number of votes given. We don't count candidates who were given zero votes
            // Problem states: "all candidates tied for the lowest number of votes are eliminated"
            // They should at least have one vote
            int min = num_votes;
            int max = 0; // finding max so that we don't drop all candidates if they are all tied
            for (int i = 0; i < candidates.size(); i++) {
                if (running[i] == true && count[i] > 0 && count[i] < min) {
                    min = count[i];
                }
                if (running[i] == true && count[i] > 0 && count[i] > max) {
                    max = count[i];
                }
            }

            // (4) DROP IT
            if (min != max) {
                for (int i = 0; i < candidates.size(); i++) {
                    if (count[i] == min) {
                        running[i] = false;
                    }
                }
            }

            // (5) For each voter, move the current vote to the next running candidate
            bool new_vote = false;
            for (int i = 0; i < num_votes; i++) {
                while (indices[i] < ballots[i].size() && running[ballots[i][indices[i]]] == false) {
                    indices[i]++;
                    new_vote = true;
                }
            }

            if (!new_vote) { // we are stuck, no new votes ... tie situation
                break;
            }
        }

        // PRINT RESULTS
        if (winner != -1) {
            std::cout << candidates[winner] << std::endl;
        } else { // TIE
            for (int i = 0; i < candidates.size(); i++) {
                if (running[i] == true) {
                    std::cout << candidates[i] << std::endl;
                }
            }
        }
        if (t > 0) {
            std::cout << std::endl;
        }
    }
    return 0;
}
