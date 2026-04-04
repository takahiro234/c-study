#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int N, K;
	string S;
	cin >> N >> K >> S;

	vector<vector<int>>next_pos(N + 1, vector<int>(26, -1));

	for (int c = 0; c < 26; c++) {
		next_pos[N][c] = -1;
	}

	for (int i = N - 1; i >= 0; i--) {
		next_pos[i] = next_pos[i + 1];
		next_pos[i][S[i] - 'a'] = i;
	}
	string ans = "";
	int pos = 0;

	for (int i = 0; i < K; i++) {
		for (int c = 0; c < 26; c++) {
			int nxt = next_pos[pos][c];
			if (nxt == -1)continue;

			if (N - nxt >= K - i) {
				ans += char('a' + c);
				pos = nxt + 1;
				break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
