#include <map>
#include <vector>

using namespace std;

// rings has the 5 colours of the target: 'K', 'R', 'Y', 'G' or 'B'
// Returns the code to report, or 0 if the target is fake
char targetCode(const vector<char>& rings) {
    map<char, int> values = {{'K', -2}, {'R', -1}, {'Y', 0}, {'G', 1}, {'B', 2}};
    int total = 0;
    for (char color : rings)
        total += values[color];

    switch (total) {
        case 0: return 'F';
        case 1: return 'P';
        case 2: return 'C';
        case 3: return 'O';
        default: return 0;
    }
}
