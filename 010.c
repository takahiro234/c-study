#include<stdio.h>
int main() {
	int N;
	scanf("%d", &N);

	int sum1[10001] = { 0 };
	int sum2[10001] = { 0 };

	for (int i = 1; i <= N; i++)
	{
		int c, p;
		scanf("%d %d", &c, &p);

		sum1[i] = sum1[i - 1];
		sum2[i] = sum2[i - 1];

		if (c == 1) {
			sum1[i] += p;
		}
		else {
			sum2[i] += p;
		}
	}

		int Q;
		scanf("%d", &Q);

		for (int i = 0; i < Q; i++)
		{
			int L, R;
			scanf("%d %d", &L, &R);

			int ans1 = sum1[R] - sum1[L - 1];
			int ans2 = sum2[R] - sum2[L - 1];

			printf("%d %d", ans1, ans2);

		}
		return 0;
}
