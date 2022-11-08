#include <iostream>
#include <vector>
using namespace std;
int N, M, used[110], parents[110];
vector<int> know[110];

int findP(int tar) {
	if (tar == parents[tar]) return tar;
	return parents[tar] = findP(parents[tar]);
}
void uni(int a, int b) {
	int PA = findP(a);
	int PB = findP(b);
	if (PA == PB)return;
	parents[PB] = PA;
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			used[i] = 0;
			parents[i] = i;
		}
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			if (a < b) uni(a, b);
			else uni(b, a);
		}		
		int result = 0;
		for (int i = 1; i <= N; i++) {
			if (used[findP(i)] == 1) continue;
			used[findP(i)] = 1;
			result++;
		}
		cout << "#" << t << " " << result << "\n";
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