#include <iostream>

using namespace std;
int mod = 1e9 + 7;
int tamanho = 1e6;
long long exponential(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  int somaTotal = (n * (n + 1)) / 2;
  if (somaTotal % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }

  long long dp[tamanho];
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = somaTotal / 2; j >= 0; j--) {
      if(j >= i){
        dp[j] += dp[j - i];
        if(dp[j] >= mod) dp[j] -= mod;
      }
    }
  }
  cout << (dp[somaTotal / 2] * exponential(2, mod - 2)) % mod << endl;
  
  return 0;
}