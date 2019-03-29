//
//  10033 - Interpreter
//  100days
//
//  Created by FB on 9/22/17.
//  Copyright © 2017 FB. All rights reserved.
//

#include <iostream>

int find_total_instructions(int *ram, int *registers, int nram, int nregisters) {
    // go through instructions stored in RAM, starting at ram address = 0
    // • 100 means halt
    // • 2dn means set register d to n (between 0 and 9)
    // • 3dn means add n to register d
    // • 4dn means multiply register d by n
    // • 5ds means set register d to the value of register s
    // • 6ds means add the value of register s to register d
    // • 7ds means multiply register d by the value of register s
    // • 8da means set register d to the value in RAM whose address is in register a
    // • 9sa means set the value in RAM whose address is in register a to the value of register s
    // • 0ds means goto the location in register d unless register s contains 0

    int total = 0;
    int address = 0;

    while (1) {
        int first = (ram[address] % 100) / 10;
        int second = ram[address] % 10;
        int command = ram[address] / 100;
        total++;
        address++;

        switch (command) {
            case 0:
                if (registers[second] != 0) { address = registers[first]; }
                break;
            case 1:
                return total;
                break;
            case 2:
                registers[first] = second;
                break;
            case 3:
                registers[first] = (registers[first] + second) % 1000;
                break;
            case 4:
                registers[first] = (registers[first] * second) % 1000;
                break;
            case 5:
                registers[first] = registers[second];
                break;
            case 6:
                registers[first] = (registers[first] + registers[second]) % 1000;
                break;
            case 7:
                registers[first] = (registers[first] * registers[second]) % 1000;
                break;
            case 8:
                registers[first] = ram[registers[second]];
                break;
            case 9:
                ram[registers[second]] = registers[first];
                break;
            default:
                break;
        }
    }
    return total;
}

int main(int argc, const char * argv[]) {
    //freopen("example.in" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    // 10 registers (0-9) (holds 3 digits 0-999)
    // 1000 words of RAM

    int test_cases;
    scanf("%d", &test_cases);

    std::string s;
    getchar();
    getchar();

    for (int test = 0; test < test_cases; test++) {

        int n = 0;
        int ram[1000] = {0};
        int registers[10] = {0};

        while (1) {
            std::getline(std::cin, s);
            if (s.length() == 0) { break; }
            ram[n++] = atoi(s.c_str());
        }
        int t = find_total_instructions(ram, registers, n, 10);
        if (test < test_cases-1) {
            std::cout << t << std::endl << std::endl;
        } else {
            std::cout << t << std::endl;
        }
    }
    return 0;
}
