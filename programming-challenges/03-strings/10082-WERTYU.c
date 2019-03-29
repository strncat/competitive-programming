#include <stdio.h>

int main() {
    
    char a;
    
    while(scanf("%c",&a) == 1)
    {
        switch (a) {
            case '1':
                printf("`");
                break;
            case  '2':
                printf ("1");
                break;
            case  '3':
                printf("2");
                break;
            case  '4':
                printf("3");
                break;
            case '5':
                printf("4");
                break;
            case '6':
                printf("5");
                break;
            case '7':
                printf("6");
                break;
            case '8':
                printf("7");
                break;
            case '9':
                printf("8");
                break;
            case '0':
                printf("9");
                break;
            case '-':
                printf("0");
                break;
            case '=':
                printf("-");
                break;
            case 'W':
                printf("Q");
                break;
            case 'E':
                printf("W");
                break;
            case 'R':
                printf("E");
                break;
            case 'T':
                printf("R");
                break;
            case 'Y':
                printf("T");
                break;
            case 'U':
                printf("Y");
                break;
            case 'I':
                printf("U");
                break;
            case 'O':
                printf("I");
                break;
            case 'P':
                printf("O");
                break;
            case '[':
                printf("P");
                break;
            case ']':
                printf("[");
                break;
            case '\\':
                printf("]");
                break;
            case 'S':
                printf("A");
                break;
            case 'D':
                printf("S");
                break;
            case 'F':
                printf("D");
                break;
            case 'G':
                printf("F");
                break;
            case 'H':
                printf("G");
                break;
            case 'J':
                printf("H");
                break;
            case 'K':
                printf("J");
                break;
            case 'L':
                printf("K");
                break;
            case ';':
                printf("L");
                break;
            case '\'':
                printf(";");
                break;
            case 'X':
                printf("Z");
                break;
            case 'C':
                printf("X");
                break;
            case 'V':
                printf("C");
                break;
            case 'B':
                printf("V");
                break;
            case 'N':
                printf("B");
                break;
            case 'M':
                printf("N");
                break;
            case ',':
                printf("M");
                break;
            case '.':
                printf(",");
                break;
            case '/':
                printf(".");
                break;
            case ' ':
                printf(" ");
                break;
            case '\n':
                printf("\n");
                break;
                
        }
    }
    return 0;
}

