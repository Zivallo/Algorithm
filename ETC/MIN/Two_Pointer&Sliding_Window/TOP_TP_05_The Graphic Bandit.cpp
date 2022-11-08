#include <iostream>
using namespace std;

long long N, M, P;
long long house[110000];

int init(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) sum += house[i];
	return sum;
}

int main() {
	cin >> N >> M >> P;
	int cnt = 0;
	for (int i = 0; i < N; i++) cin >> house[i];
	long long start = init(M);
	if (N == M) {
		if (start < P) cnt++;
		cout << cnt;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (start < P) cnt++;

		if (i == N) break;

		start += house[(M + i) % N];
		start -= house[i % N];
	}
	cout << cnt;
	return 0;
}