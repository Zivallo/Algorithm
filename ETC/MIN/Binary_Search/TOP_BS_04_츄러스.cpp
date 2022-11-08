#include <iostream>
#include <queue>
using namespace std;

int N, K;
int len[11000];
priority_queue<int> q;

int bs(int s, int e) {
	int maxVal = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		int sum = 0;
		for (int j = 0; j < N; j++) {
			sum += len[j] / mid;
		}
		if (sum >= K) {
			maxVal = mid;
			s = mid + 1;
		}
		else e = mid - 1;
	}
	return maxVal;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> len[i];
	int ans = bs(1, 21e8);
	cout << ans;
	return 0;
}