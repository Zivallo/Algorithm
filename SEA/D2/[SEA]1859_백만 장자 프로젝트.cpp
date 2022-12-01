#include <iostream>
using namespace std;
int T, N;
long long arr[1000010];
void solve() {
	arr[0] = 21e8;
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 1; i <= N; i++)cin >> arr[i];
		long long r = 0, cur = arr[N], sum = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (arr[i] >= cur) {
				cur = arr[i];
				r += sum;
				sum = 0;
			}
			else {
				sum += (cur - arr[i]);
			}
		}
		cout << "#" << t << " " << r << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}