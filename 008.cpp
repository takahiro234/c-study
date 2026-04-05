#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    const long long MOD = 1000000007;

    int N;
    string S;
    cin >> N >> S;

    string T = "atcoder";
    vector<long long> dp(8, 0);

    dp[0] = 1;

    for (char c : S) {
        for (int j = 6; j >= 0; j--) {
            if (c == T[j]) {
                dp[j + 1] += dp[j];
                dp[j + 1] %= MOD;
            }
        }
    }

    cout << dp[7] << endl;
    return 0;
}
