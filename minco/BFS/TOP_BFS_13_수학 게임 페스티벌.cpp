#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Node {
	int pass;
	string path;
};
int N, A, B, used[10000];
queue<Node> q;

void init() {
	while (!q.empty()) q.pop();
	for (int i = 0; i < 10000; i++) used[i] = 0;
}
void D(int nowPass, string nowPath) {
	int nextPass = nowPass * 2;
	if (nextPass > 9999) nextPass = nextPass % 10000;
	if (used[nextPass] == 1) return;
	used[nextPass] = 1;
	string nextPath = nowPath + 'D';
	q.push({ nextPass,nextPath });
}
void S(int nowPass, string nowPath) {
	int nextPass = nowPass - 1;
	if (nextPass < 0) nextPass = 9999;
	if (used[nextPass] == 1) return;
	used[nextPass] = 1;
	string nextPath = nowPath + 'S';
	q.push({ nextPass,nextPath });
}
void L(int nowPass, string nowPath) {
	int nextPass = nowPass / 1000 + (nowPass % 1000) * 10;
	if (used[nextPass] == 1) return;
	used[nextPass] = 1;
	string nextPath = nowPath + 'L';
	q.push({ nextPass,nextPath });
}
void R(int nowPass, string nowPath) {
	int nextPass = nowPass / 10 + (nowPass % 10) * 1000;
	if (used[nextPass] == 1) return;
	used[nextPass] = 1;
	string nextPath = nowPath + 'R';
	q.push({ nextPass,nextPath });
}
string getPath() {
	while(!q.empty()) {
		int nowPass = q.front().pass;
		string nowPath = q.front().path;
		q.pop();

		if (nowPass == B) return nowPath;

		for (int i = 0; i < 4; i++) {
			if (i == 0) D(nowPass, nowPath);
			if (i == 1) S(nowPass, nowPath);
			if (i == 2) L(nowPass, nowPath);
			if (i == 3) R(nowPass, nowPath);
		}		
	}
	return "None";
}

int main() {
	cin >> N;
	for (int t = 0; t < N; t++) {
		init();
		cin >> A >> B;
		used[A] = 1;
		q.push({ A,"" });
		string ans = getPath();
		cout << ans << '\n';
	}
	return 0;
}