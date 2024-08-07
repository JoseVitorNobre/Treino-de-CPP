/* 
A - Minimizing Coins

Consider a money sistem consisting of N coins. Each coin has a positive integer value.
Your task is to produce a sum of money X using the available coins in such a way that the number of coins is minimal.

For example, if the coins are {1, 5, 7} and the desired sum is 11, an optimal solution is 5 + 5 + 1 which requires 3 coins

Input
The first input line has two integers N and X: the number of coins and the desired sum of money.
The second line has N integers C1, C2, ..., CN: the values of the coins.

Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.

Constraints
1 ≤ N ≤ 100
1 ≤ X ≤ 10^6
1 ≤ C1, C2, ..., CN ≤ 10^6
 */

#include <iostream>
using namespace std;

#define INFINITE 1e8
const long int constraint = 1e6;

int main() {
    int n, x;
    cin >> n >> x;
    int coins[constraint], dp[constraint];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    for(int i = 1; i <= x; i++) {
        dp[i] = INFINITE;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= x; j++) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    if (dp[x] == INFINITE) cout << -1;
    else cout << dp[x];
    return 0;
}