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
void del() {
	int x, y;
	cin >> x >> y;
	for (int i = 0; i < y; i++) {
		pass.erase(pass.begin() + x);
	}
}
void add() {
	int y, s; cin >> y;
	for (int i = 0; i < y; i++) {
		cin >> s; pass.push_back(s);
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
			if (cmd == 'D')del();
			if (cmd == 'A')add();
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