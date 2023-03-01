#include <iostream>
using namespace std;
int T, tmp, r;

void solve() {
	for (int t = 1; t <= 10; t++) {
		cin >> T; int ys[101] = { 0 }, xs[101] = { 0 }, cs[2] = { 0 }, r = 0;
		for (int y = 0; y < 100; y++) {
			for (int x = 0; x < 100; x++) {
				cin >> tmp;
				r = (r > (ys[y] += tmp)) ? r : ys[y];
				r = (r > (xs[x] += tmp)) ? r : xs[x];
				if (x == y)r = (r > (cs[0] += tmp)) ? r : cs[0];
				if (99 - x == y)r = (r > (cs[1] += tmp)) ? r : cs[1];
			}
		}
		cout << "#" << T << " " << r << "\n";
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