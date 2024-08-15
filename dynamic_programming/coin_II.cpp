#include <iostream>
#include <vector>
using namespace std;
int modulo = 1e9 + 7;

int main(){
  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for(int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  int dp[x+1] = {0};
  dp[0] = 1;

  for(auto coin : coins) {
    for(int i = 1; i <= x; ++i) {
      if(i - coin >= 0) {
        dp[i] += dp[i - coin];
        if(dp[i] >= modulo) dp[i] -= modulo;
      }
    }
  }
  cout << dp[x];
}