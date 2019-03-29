//
//  main.cpp
//  uhunt
//
//  10191 - Longest Nap
//  2017/03/15
//  This solution assumes appointments can overlap ....
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::pair;

typedef struct slot {
    string time;
    int hours;
    int minutes;
    slot(string t) {
        time = t;
        hours = (t[0]-'0')*10 + t[1]-'0';
        minutes = (t[3]-'0')*10 + t[4]-'0';
    }
} slot;

bool compare(const pair<slot,slot>& a, const pair<slot,slot>& b) {
    return (a.first.hours < b.first.hours) ||
    (a.first.hours == b.first.hours && a.first.minutes < b.first.minutes);
}

int main() {
    //freopen("sample.in", "r", stdin);

    int n, t = 1;
    string line;
    char hs1[10], hs2[10];
    vector<pair<slot,slot>> a;

    while (scanf("%d\n", &n) != EOF) {
        a.clear();
        a.push_back(pair<slot,slot>(slot("10:00"), slot("10:00")));
        a.push_back(pair<slot,slot>(slot("18:00"), slot("18:00")));

        for (int i = 0; i < n; i++) {
            getline(std::cin, line); // '\r'
            sscanf(line.c_str(), "%s %s", hs1, hs2);

            a.push_back(pair<slot,slot>(slot(hs1),slot(hs2)));
        }

        std::sort(a.begin(), a.end(), compare);

        // merge overlapping intervals
        vector<pair<slot,slot>> merged;
        merged.push_back(a[0]);

        for (int i = 1; i < a.size(); i++) {
            int last = (int)merged.size()-1;

            if (a[i].first.hours < merged[last].second.hours ||
                (a[i].first.hours == merged[last].second.hours && a[i].first.minutes < merged[last].second.minutes)) {
                // merge
                if (a[i].second.hours > merged[last].second.hours ||
                    (a[i].second.hours == merged[last].second.hours && a[i].second.minutes > merged[last].second.minutes)) {
                    merged[last].second = a[i].second;
                } // else stay at merged[last].second
            } else {
                merged.push_back(a[i]);
            }
        }

        int hmax = 0, mmax = 0, max = 0, max_index = 0;
        for (int i = 0; i < merged.size()-1; i++) {
            int hdiff = merged[i+1].first.hours - merged[i].second.hours;
            int mdiff = merged[i+1].first.minutes - merged[i].second.minutes;

            if (mdiff < 0) {
                hdiff--;
                mdiff += 60;
            }
            int diff = mdiff + hdiff*60;

            if (diff > max) {
                max_index = i;
                max = diff;
                hmax = hdiff;
                mmax = mdiff;
            }
        }

        if (hmax > 0 && mmax >= 0) {
            printf("Day #%d: the longest nap starts at %s and will last for %d hours and %d minutes.\n",
                   t, merged[max_index].second.time.c_str(), hmax, mmax);
        } else if (mmax > 0) {
            printf("Day #%d: the longest nap starts at %s and will last for %d minutes.\n",
                   t, merged[max_index].second.time.c_str(), mmax);
        }
        t++;
    }
    return 0;
}
