#include <iostream>
using namespace std;
int T;
int arr[11];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		int maxi = 0, mini = 21e8, sum = 0;
		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
			sum += arr[i];
			maxi = (maxi < arr[i] ? arr[i] : maxi);
			mini = (mini > arr[i] ? arr[i] : mini);
		}
		sum -= (maxi + mini);
		cout << "#" << t << " " << sum / 8 + ((sum * 10 / 8) % 10 > 4 ? 1 : 0) << "\n";
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