//
//  Angry Professor
//
//

#include <iostream>

void tests() {
}

int main() {
    tests();
    int cases, n, k, s, before, after;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &n, &k);
        before = 0;
        after = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &s);
            if (s <= 0) { before++; } else { after++; }
        }
        if (before < k) { printf("YES\n"); } else { printf("NO\n"); }
    }
    return 0;
}
