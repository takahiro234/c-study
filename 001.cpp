#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, L, K;
	cin >> N >> L;
	vector<int> A(N);
	for (int i = 0; i < N; i++)cin >> A[i];
	cin >> K;
	auto can = [&](int x) {
		int cnt = 0;//何回切れたか
		int last = 0;//最後に切った位置
		for (int i = 0; i < N; i++) {
			if (A[i] - last >= x && L - A[i] >= x) {
				cnt++;
				last = A[i];
			}
		}
		return cnt >= K;
	};
	int left = 0;
	int right = L + 1;

	while (right - left > 1) {
		int mid = (left + right) / 2;
		if (can(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
		cout << left << endl;
		return 0;
}




