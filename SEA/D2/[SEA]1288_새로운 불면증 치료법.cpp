#include <iostream>
using namespace std;
int T;
long long N;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; long long r = 1, tmp = N;
		int u[11] = { 0 }, c = 0;
		while (1)
		{
			tmp = N * r;
			while (tmp > 0)
			{
				if (u[tmp % 10] == 0)
				{
					c++;
					u[tmp % 10] = 1;
				}
				tmp /= 10;
			}
			if (c >= 10)break;
			r++;
		}
		cout << "#" << t << " " << r * N << "\n";
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