#include<iostream>
#include<string>
using namespace std;

int N;

void dfs(string s, int left, int right) {
	if (s.size() == N) {
		cout << s << endl;
		return;
	}

	if (left < N / 2) {
		dfs(s + "(", left + 1, right);
	}

	if (right < left) {
		dfs(s + ")", left, right + 1);
	}
}

int main() {
	cin >> N;

	if (N % 2 == 1) {
		return 0;
	}

	dfs("", 0, 0);

	return 0;
}
