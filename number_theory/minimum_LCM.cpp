#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int res = 1;
        for(ll j = 2; j * j <= n; j++){
            if(n % j == 0){
                res = n / j;
                break;
            }
        }
        cout << res << " " << n - res << endl;
    }
    return 0;
}