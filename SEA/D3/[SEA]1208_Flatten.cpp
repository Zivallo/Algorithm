#include <iostream>
using namespace std;
int D, block[110];

void solve() {
	block[101] = 21e8;
	for (int t = 1; t <= 10; t++) {
		cin >> D; for (int i = 0; i < 100; i++)cin >> block[i];
		for (int i = 0; i < D; i++) {
			int mai = 100, mii = 101;
			for (int j = 0; j < 100; j++) {
				if (block[j] > block[mai])mai = j;
				if (block[j] < block[mii])mii = j;
			}
			block[mai]--;
			block[mii]++;
		}int mar = 0, mir = 21e8;
		for (int i = 0; i < 100; i++) {
			if (block[i] > mar)mar = block[i];
			if (block[i] < mir)mir = block[i];
		}
		cout << "#" << t << " " << mar - mir << "\n";
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