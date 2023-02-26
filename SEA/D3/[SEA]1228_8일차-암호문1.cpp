#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> pass;

void ins() {
	int x, y, s;
	cin >> x >> y;
	for (int i = 0; i < y; i++) {
		cin >> s;
		pass.insert(pass.begin() + x + i, s);
	}
}
void solve() {
	for (int t = 1; t <= 10; t++) {
		cin >> N; pass = vector<int>();
		for (int i = 0; i < N; i++) {
			int tmp; cin >> tmp;
			pass.push_back(tmp);
		}
		cin >> M; for (int i = 0; i < M; i++) {
			char cmd; cin >> cmd;
			if (cmd == 'I')ins();
		}cout << "#" << t << " ";
		for (int i = 0; i < 10; i++)cout << pass[i] << " ";
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