#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int T, M, C, I, pm, pc, pi, cnt1;
unsigned char sm[100100], sc[5000], si[5000];
int garo[100100];

void init() {
	memset(garo, 0, sizeof(garo));
	memset(sm, 0, sizeof(sm));
	pm = 0; pc = 0; pi = 0; cnt1 = 0;
}
pair<int, pair<int, int>> simulation() {
	pc = 0; int cnt = 0, mini = 0;
	while (1) {
		if (cnt == 50000000) {
			mini = pc;
		}
		if (cnt >= 100000000) {
			return { 0,{mini,garo[mini]} };
		}
		if (sc[pc] == '+') sm[pm] = (sm[pm] + 1 > 255 ? 0 : sm[pm] + 1);
		else if (sc[pc] == '-') sm[pm] = (sm[pm] + 1 < 0 ? 255 : sm[pm] - 1);
		else if (sc[pc] == '<') pm = (pm - 1 < 0 ? M - 1 : pm - 1);
		else if (sc[pc] == '>') pm = (pm + 1 >= M ? 0 : pm + 1);
		else if (sc[pc] == '[' && sm[pm] == 0) pc = garo[pc];
		else if (sc[pc] == ']' && sm[pm] != 0) pc = garo[pc];
		if (sc[pc] == ',') {
			if (pi == I) sm[pm] = 255;
			else {
				sm[pm] = si[pi];
				pi++;
			}
		}
		++cnt;
		if (cnt > 50000000) if (mini > pc)mini = pc;
		pc++;
		if (pc == C) break;
	}
	return { 1,{1,1} };
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> M >> C >> I;
		init();
		stack<int> s;
		for (int i = 0; i < C; i++) {
			cin >> sc[i];
			if (sc[i] == '[') s.push(i);
			if (sc[i] == ']') {
				garo[i] = s.top();
				garo[s.top()] = i;
				s.pop();
			}
		}
		for (int i = 0; i < I; i++)cin >> si[i];
		pair<int, pair<int, int>> r = simulation();
		if (r.first == 0) cout << "Loops " << r.second.first << " " << r.second.second << "\n";
		else cout << "Terminates\n";
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