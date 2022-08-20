#include <iostream>
using namespace std;

int T, N, W, maxi;
int line[110000], score[110000];

int getSum(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += line[i];
	}
	return sum;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		maxi = -21e8;
		cin >> N >> W;
		for (int i = 0; i < N; i++) cin >> line[i];
		int start = getSum(W);
		for (int i = 0; i <= N - W; i++) {
			if (start > maxi) {
				maxi = start;
				score[i] = start;
			}

			if (i == N - W) break;

			start += line[W + i];
			start -= line[i];
		}
		for (int i = 0; i < N; i++) {
			if (maxi == score[i]) {
				cout << "#" << t << " " << i << " " << i + W - 1 << " " << maxi << '\n';
				break;
			}
		}
	}
	return 0;
}