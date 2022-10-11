#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Node { int y, x; int arrow; bool death; };
vector<Node> enemy;
vector<pair<int, int>> archer;
int N, M, D, result;
void input() {
	cin >> N >> M >> D;
	for (int y = 0; y < N; y++)for (int x = 0; x < M; x++) {
		int val;
		cin >> val;
		if (val == 1) enemy.push_back({ y, x, 0, false });
	}
}
void shoot(int y,int x,int sec) {
	int taridx = 0, tarX = M + 1, miniDist = D + 1;
	int flag = 0;
	for (int i = 0; i < enemy.size(); i++) {
		if (enemy[i].death == true) continue;
		int ny = enemy[i].y + 1 * sec;
		int dist = abs(y - ny) + abs(x - enemy[i].x);
		if (dist <= D && dist <= miniDist) {
			if (dist == miniDist && tarX <= enemy[i].x) continue;
			tarX = enemy[i].x;
			taridx = i; miniDist = dist; flag = 1;			
		}
	}
	if (flag) enemy[taridx].arrow++;
}
int setMap(int sec) {
	for (int i = 0; i < enemy.size(); i++) {
		if (enemy[i].death == true) continue;
		int ny = enemy[i].y + 1 * sec;
		if (ny >= N) enemy[i].death = true;
		if (enemy[i].arrow) enemy[i].death = true;
	}
	for (int i = 0; i < enemy.size(); i++) if (enemy[i].death == false) return 1;
	return 0;
}
int cntDeathEnemy() {
	int cnt = 0;
	for (int i = 0; i < enemy.size(); i++) if (enemy[i].arrow) cnt++;
	return cnt;
}
void simulation() {
	int status = 1;
	int sec = 0;
	while (status) {
		for (int i = 0; i < archer.size(); i++) {
			shoot(archer[i].first, archer[i].second, sec);
		}
		sec++;
		status = setMap(sec);
		if (!status) result = max(result, cntDeathEnemy());
	}
}
void initEnemy() {
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i].arrow = 0;
		enemy[i].death = false;
	}
}
void setArcher(int lev,int start) {
	if (lev == 3) {
		initEnemy();
		simulation();
		return;
	}
	for (int i = start; i < M; i++) {
		archer.push_back({ N,i });
		setArcher(lev + 1, i + 1);
		archer.pop_back();
	}
}
void solve() {
	input();
	setArcher(0, 0);
	cout << result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}