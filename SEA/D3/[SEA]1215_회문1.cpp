#include <iostream>
#include <string>
using namespace std;
int N;
string m[8];

bool checky(int y, int x) {
	for (int i = 0; i < N / 2; i++) {
		if (m[y][x + i] != m[y][x + N - i - 1])return false;
	}
	return true;
}
bool checkx(int y, int x) {
	for (int i = 0; i < N / 2; i++) {
		if (m[y + i][x] != m[y + N - i - 1][x])return false;
	}
	return true;
}
void solve() {
	for (int t = 1; t <= 10; t++) {
		cin >> N; int r = 0;
		for (int i = 0; i < 8; i++)cin >> m[i];
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x <= 8 - N; x++) {
				if (checky(y, x))r++;
				if (checkx(x, y))r++;
			}
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