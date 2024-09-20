#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long mod_exponentiation(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long a, b;
        cin >> a >> b;
        cout << mod_exponentiation(a, b, MOD) << endl;
    }
    return 0;
}
