#include <iostream>
using namespace std;
unsigned long long T, N, Pd, Pg;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> Pd >> Pg;
		cout << "#" << t << " ";
		if (Pd != 100 && Pg == 100)cout << "Broken\n";
		else if (Pd != 0 && Pg == 0)cout << "Broken\n";
		else {
			int flag = 0;
			for (int i = 1; i <= N; i++)if (i * Pd % 100==0) { flag = 1; break; }
			if (flag)cout << "Possible\n";
			else cout << "Broken\n";
		}
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