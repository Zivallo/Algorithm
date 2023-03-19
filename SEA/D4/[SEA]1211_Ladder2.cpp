#include <iostream>
#include <vector>
using namespace std;
int N;
int m[110][110];
vector<int> s;

int getLen(int sx) {
	int ret = 1, x = sx, y = 0, dir = 0;
	while (y < 99) {
		if (dir != 1 && x - 1 >= 0){
			if (m[y][x - 1] == 1) {
				x--;
				ret++;
				dir = 2;
				continue;
			}
		}
		if (dir != 2 && x + 1 < 100) {
			if (m[y][x + 1] == 1) {
				x++;
				ret++;
				dir = 1;
				continue;
			}
		}
		if (m[y + 1][x] == 1) { dir = 0; y++; ret++; }
	}
	return ret;
}
int search() {
	int ret = 0, mini = 21e8;
	for (int i = 0; i < s.size(); i++) {
		int len = getLen(s[i]);
		if (mini > len) {
			mini = len;
			ret = s[i];
		}
	}
	return ret;
}
void solve() {
	for (int t = 1; t <= 10; t++) {
		cin >> N; s = vector<int>();
		for (int y = 0; y < 100; y++)for (int x = 0; x < 100; x++) {
			cin >> m[y][x];
			if (y == 0)if (m[y][x] == 1)s.push_back(x);
		}
		cout << "#" << t << " " << search() << "\n";
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