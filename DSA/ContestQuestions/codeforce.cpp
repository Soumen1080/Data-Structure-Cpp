#include <iostream>
#include <vector>
#include <map>

// Sets up fast input/output
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

// Solves a single test case
void solve() {
    int n;
    long long k;
    std::cin >> n >> k;

    // A map to store the frequency of remainders.
    // Key: remainder (val % k), Value: count
    std::map<int, int> remainder_counts;

    // Process the first multiset S, incrementing the counts.
    for (int i = 0; i < n; ++i) {
        int s_val;
        std::cin >> s_val;
        remainder_counts[s_val % k]++;
    }

    // Process the second multiset T, decrementing the counts.
    for (int i = 0; i < n; ++i) {
        int t_val;
        std::cin >> t_val;
        remainder_counts[t_val % k]--;
    }

    // Check if all counts balanced out to zero.
    bool possible = true;
    for (auto const& pair : remainder_counts) {
        // If any remainder has a non-zero count, the multisets of remainders
        // were not identical.
        if (pair.second != 0) {
            possible = false;
            break;
        }
    }

    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    setup_io();
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}