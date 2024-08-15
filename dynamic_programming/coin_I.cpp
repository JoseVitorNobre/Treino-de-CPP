#include <iostream>
using namespace std;
int modulo = 1e9 + 7;
int X = 1e6;
#define INFINITE 1e9

int main() {
  int n, x;
  cin >> n >> x;
  int coins[101];
  for (int i = 0; i < n; i++) cin >> coins[i];
  
  int dp[X];
  dp[0] = 1;
  
  for(int i = 1; i <= x; i++) {
    long long sum = 0;
    for(int j = 0; j < n; j++) {
      if(i - coins[j] >= 0) {
        sum += dp[(i - coins[j])];
      }
    }
    dp[i] = sum % modulo;
  }

  cout << dp[x];
  return 0;
}