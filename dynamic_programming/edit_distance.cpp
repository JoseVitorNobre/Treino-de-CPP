#include <iostream>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  int dp[2][5001];
  for(int i = 1; i <= s2.size(); i++) {
    dp[0][i] = i;
  }

  int aux = 1, last = 0;
  for(int i = 1; i <= s1.size(); i++) {
    dp[aux][0] = i;
    for(int j = 1; j <= s2.size(); j++) {
      dp[aux][j] = min(dp[last][j-1] + (s1[i-1] != s2[j-1]), min(dp[last][j], dp[aux][j-1]) + 1);
    }
    swap(aux, last);
  }
  cout << dp[last][s2.size()];
  return 0;
}