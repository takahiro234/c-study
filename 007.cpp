#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int>A(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A.begin(), A.end());

	int Q;
	cin >> Q;

	vector<long long> B(Q);

	for (int i = 0; i < Q; i++)
		cin >> B[i];

	for (int i = 0; i < Q; i++) {
		long long ans = 0;
		int idx = lower_bound(A.begin(), A.end(), B[i]) - A.begin();

		if (idx == 0) {
			ans = abs(A[0] - B[i]);
		}
		else if (idx == N) {
			ans = abs(A[N - 1] - B[i]);
		}
		else {
			ans= min(abs(A[idx] - B[i]), abs(A[idx - 1] - B[i]));
		}
		cout << ans << endl;
	}

}
