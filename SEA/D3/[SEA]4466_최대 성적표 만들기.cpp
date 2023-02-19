#include <iostream>
#include <algorithm>
using namespace std;
int T, N, K;
int score[110];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++)cin >> score[i];
		sort(score, score + N, greater<int>());
		int r = 0;
		for (int i = 0; i < K; i++)r += score[i];
		cout << "#" << t << " " << r << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}