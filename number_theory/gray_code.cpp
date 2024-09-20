#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

vector<string> gray_code(int n) {
    vector<string> result;
    for (int i = 0; i < (1 << n); i++) 
        result.push_back(bitset<16>(i ^ (i >> 1)).to_string().substr(16 - n));
    return result;
}

int main() {
    int n;
    cin >> n;
    for (const auto& code : gray_code(n))
        cout << code << endl;
    return 0;
}
