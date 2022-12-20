#include<iostream>
using namespace std;
int T, N, arr[30];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; for (int i = 0; i < N; i++)cin >> arr[i];
		int r = 0;
		for (int i = 1; i < N - 1; i++) {
			if (arr[i - 1] < arr[i] && arr[i] < arr[i + 1])r++;
			if (arr[i - 1] > arr[i] && arr[i] > arr[i + 1])r++;
		}
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