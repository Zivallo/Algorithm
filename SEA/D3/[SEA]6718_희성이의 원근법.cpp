#include <iostream>
using namespace std;
long long T, d;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> d;
		cout << "#" << t << " ";
		if (d < 100)cout << "0";
		else if (d < 1000)cout << "1";
		else if (d < 10000)cout << "2";
		else if (d < 100000)cout << "3";
		else if (d < 1000000)cout << "4";
		else cout << "5";
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}