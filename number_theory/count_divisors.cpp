#include <iostream>
using namespace std;

int count_divisors(int x) {
    int count = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            count += (i == x / i) ? 1 : 2;
        }
    }
    return count;
}

int main() {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        cout << count_divisors(x) << endl;
    }
    return 0;
}
