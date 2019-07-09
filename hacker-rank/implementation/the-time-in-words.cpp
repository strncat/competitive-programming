//
//  Hacker Rank
//  Taum and B'day
//
//  Created by Fatima B on 12/31/15.
//  Copyright © 2015 Fatima B. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::unordered_map<int,std::string> hours;
    std::unordered_map<int,std::string> minutes;
    minutes[1] = "one minute";
    minutes[2] = "two minutes";
    minutes[3] = "three minutes";
    minutes[4] = "four minutes";
    minutes[5] = "five minutes";
    minutes[6] = "six minutes";
    minutes[7] = "seven minutes";
    minutes[8] = "eight minutes";
    minutes[9] = "nine minutes";
    minutes[10] = "ten minutes";
    minutes[11] = "eleven minutes";
    minutes[12] = "twelve minutes";
    minutes[13] = "thirteen minutes";
    minutes[14] = "fourteen minutes";
    minutes[15] = "quarter";
    minutes[16] = "sixteen minutes";
    minutes[17] = "seventeen minutes";
    minutes[18] = "eighteen minutes";
    minutes[19] = "nineteen minutes";
    minutes[20] = "twenty minutes";
    minutes[21] = "twenty one minutes";
    minutes[22] = "twenty two minutes";
    minutes[23] = "twenty three minutes";
    minutes[24] = "twenty four minutes";
    minutes[25] = "twenty five minutes";
    minutes[26] = "twenty six minutes";
    minutes[27] = "twenty seven minutes";
    minutes[28] = "twenty eight minutes";
    minutes[29] = "twenty nine minutes";
    minutes[30] = "half";

    hours[1] = "one"; hours[2] = "two";
    hours[3] = "three"; hours[4] = "four";
    hours[5] = "five"; hours[6] = "six";
    hours[7] = "seven"; hours[8] = "eight";
    hours[9] = "nine"; hours[10] = "ten";
    hours[11] = "eleven"; hours[12] = "twelve";

    int h, m;
    scanf("%d %d", &h, &m);

    if (m == 0) {
        std::cout << hours[h] << " o' clock" << std::endl;
    } else if (m <= 30) {
        std::cout << minutes[m] << " past " << hours[h] << std::endl;
    } else {
        std::cout << minutes[60-m] << " to " << hours[h+1] << std::endl;
    }

    return 0;
}
