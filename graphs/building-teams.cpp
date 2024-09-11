#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll maxn = 1e5 + 5;
ll a[2 * maxn], b[maxn];

void init() {
    for (ll i = 1; i < 2 * maxn; i++) {
        a[i] = i;
    }
}

ll find(ll x) {
    if (a[x] == x) return x;
    ll temp = find(a[x]);
    a[x] = temp;
    return temp;
}

int main() {
    ll n, m;
    init();

    cin >> n >> m;
    
    for (ll i = 0; i < m; i++) {
        ll ax, bx, aa, bb;
        cin >> ax >> bx;  

        aa = find(ax);
        bb = find(bx);

        if (aa == bb) {
            cout << "IMPOSSIBLE\n";  
            return 0;
        }

        a[find(ax + n)] = bb;
        a[aa] = find(bx + n);
    }

    for (ll i = 1; i <= n; i++) {
        ll temp = find(i);
        if (temp > n)
            cout << "1 ";
        else
            cout << "2 ";
    }

    cout << "\n";
    return 0;
}
