#include <iostream>
using namespace std;
int T, N; 
long long list[110];

void mk() {
	list[1] = 1, list[2] = 1, list[3] = 1, list[4] = 2, list[5] = 2; list[6] = 3;
	for (int i = 7; i <= 100; i++) {
		list[i] = list[i - 1] + list[i - 5];
	}
}
void solve() {
	mk();
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; cout << "#" << t << " " << list[N] << "\n";
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