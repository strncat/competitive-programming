#include <iostream>
#include <unordered_map>
    
using namespace std;

int main() {

    int test_cases;
    unordered_map<unsigned long long, bool> fibonacci;
    unsigned long long x;
    
    fibonacci.emplace(0, true);
    fibonacci.emplace(1, true);
    
    long long int term = 0, first = 0, second = 1;
    
    while (term <= 10000000000) {
        term = first + second;
        fibonacci.emplace(term, true);
        first = second;
        second = term;
    }
    
    cin >> test_cases;
    
    while (test_cases--) {
        cin >> x;
        
        std::unordered_map<unsigned long long, bool>::const_iterator iterator;
        
        iterator = fibonacci.find(x);
        
        if ( iterator != fibonacci.end() ) {
            cout << "IsFibo" << endl;
        } else {
            cout << "IsNotFibo" << endl;
        }
    }
    return 0;
}
