#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_fair(ll n) {
    for (char c : to_string(n)) {
        int digit = c - '0';
        if (digit != 0 && n % digit != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ll t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        while (!is_fair(n)) {
            n++;
        }
        cout << n << "\n";
    }

    return 0;
}
