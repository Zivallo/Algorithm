#include <iostream>
using namespace std;
int T, N, R;
int food[1100000];

int init(int n, int dat[220], int food[]) {
	for (int i = 0; i < n; i++) {
		dat[food[i]]++;
		if (dat[food[i]] > 2) return 0;
	}
	return 1;
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int dat[220] = { 0 };
		cin >> N >> R;
		for (int i = 0; i < N; i++) cin >> food[i];
		if (init(2 * R + 1, dat, food)) {
			int flag = 0;
			for (int i = 0; i < N; i++) {
				dat[food[i % N]]--;
				dat[food[((2 * R + 1) + i) % N]]++;
				if (dat[food[((2 * R + 1) + i) % N]] > 2) {
					cout << "#" << t << " NO\n";
					flag = 1;
					break;
				}
			}
			if (!flag) cout << "#" << t << " YES\n";
		}
		else cout << "#" << t << " NO\n";
	}
	return 0;
}