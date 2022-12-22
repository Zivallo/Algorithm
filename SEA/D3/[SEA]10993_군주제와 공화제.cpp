#include <iostream>
#include <string>
using namespace std;
struct Node { int x, y, s; };
int T, N;
string ans[1100];
Node info[1100];

void input() {
	cin >> N; 
	for (int i = 1; i <= N; i++)ans[i] = 'K';
	for (int i = 1; i <= N; i++) {
		int x, y, s;
		cin >> x >> y >> s;
		info[i] = { x,y,s };
	}
}
string parent(string num,string ans[1100]) {
	if (ans[stoi(num)] == "K" || ans[stoi(num)] == "D") return num;
	return ans[stoi(num)] = parent(ans[stoi(num)], ans);
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		input();
		for (int i = 1; i <= N; i++) {
			int cnt = 0;
			float maxi = 0;
			for (int j = 1; j <= N; j++) {
				if (i == j)continue;
				float space = (float)info[j].s / ((info[i].x - info[j].x) * (info[i].x - info[j].x) + (info[i].y - info[j].y) * (info[i].y - info[j].y));
				if (space <= info[i].s)continue;
				if (maxi == space) cnt++;
				if (maxi < space) {
					ans[i] = parent(to_string(j), ans);
					maxi = space;
					cnt = 1;
				}
			}
			if (cnt > 1)ans[i] = 'D';
		}
		cout << "#" << t << " ";
		for (int i = 1; i <= N; i++) {
			if (ans[i] == "K" || ans[i] == "D")cout << ans[i] << " ";
			else cout << parent(ans[i], ans) << " ";
		}
		cout << "\n";
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