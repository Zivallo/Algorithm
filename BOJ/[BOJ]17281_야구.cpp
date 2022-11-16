#include <iostream>
#include <queue>
using namespace std;
int taja[60][20], order[20], used[20], N;
int score, result;
queue<int> rue;
void simulation() {
	score = 0;
	int tajaIdx = 0;
	for (int t = 0; t < N; t++) {
		int outCnt = 0;
		rue = queue<int>();
		for (int i = 0; i < 3; i++) rue.push(0);
		while (outCnt < 3) {
			int val = taja[t][order[tajaIdx]];
			if (val == 0) {
				outCnt++;
				tajaIdx = (tajaIdx + 1) % 9;
				continue;
			}
			rue.push(val);
			if (rue.front() != 0) score++;
			rue.pop();
			for (int i = 0; i < val - 1; i++) {
				rue.push(0);
				if (rue.front() != 0) score++;
				rue.pop();
			}
			tajaIdx = (tajaIdx + 1) % 9;
		}
	}
	if (result < score) result = score;
}
void setTaja(int lev) {
	if (lev == 9) {
		simulation();
		return;
	}
	if (lev == 3) {
		order[lev] = 0;
		setTaja(lev + 1);
		return;
	}
	for (int i = 1; i < 9; i++) {
		if (used[i] == 1)continue;
		used[i] = 1;
		order[lev] = i;
		setTaja(lev + 1);
		used[i] = 0;
	}
}
void solve() {
	cin >> N;
	for (int t = 0; t < N; t++) for (int i = 0; i < 9; i++)cin >> taja[t][i];
	result = 0;
	setTaja(0);
	cout << result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}