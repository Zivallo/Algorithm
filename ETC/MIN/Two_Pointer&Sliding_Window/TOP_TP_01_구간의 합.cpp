#include <iostream>
using namespace std;

long long A[11000], N, M, cnt;

long long getSum(int n) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i];
	}
	return sum;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int j = 1; j < N; j++) {
		long long start = getSum(j);
		for (int i = 0; i <= N - j; i++) {
			if (start == M) cnt++;

			if (i == N - j) break;

			start += A[j + i];
			start -= A[i];
		}
	}
	cout << cnt << '\n';
	return 0;
}