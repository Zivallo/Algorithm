#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

struct Edge {
	int from, to, cost;
};
struct Node {
	int y, x, cost;
};
int T, X, Y, id;
int parent[110], used[55][55], coorId[55][55];
string map[55];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };

bool cmp(Edge t, Edge v) {
	return t.cost < v.cost;
}

queue<Node> q;
vector<Edge> list;

int Find(int now) {
	if (parent[now] == now) return now;
	return parent[now] = Find(parent[now]);
}

int Union(int A, int B) {
	int pA = Find(A);
	int pB = Find(B);
	if (pA == pB) return 0;
	parent[pB] = pA;
	return 1;
}

void setList(int sy, int sx) {
	int used1[55][55] = { 0, };
	q.push({ sy,sx,0 });
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + drY[i];
			int nx = now.x + drX[i];
			int nCost = now.cost + 1;
			if (ny < 0 || nx < 0 || ny >= Y || nx >= X) continue;
			if (used[ny][nx] == 1) continue;
			if (used1[ny][nx] == 1) continue;
			if (map[ny][nx] == '#') continue;
			used1[ny][nx] = 1;
			if (map[ny][nx] == 'A') {
				list.push_back({ coorId[sy][sx],coorId[ny][nx],nCost });
				continue;
			}
			if (map[ny][nx] == 'S') {
				list.push_back({ coorId[sy][sx],coorId[ny][nx],nCost });
				continue;
			}
			q.push({ ny,nx,nCost });
		}
	}
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		list.clear();
		id = 1;
		memset(used, 0, sizeof(used));
		memset(coorId, 0, sizeof(coorId));

		cin >> X >> Y;
		for (int y = 0; y < Y; y++) {
			cin >> map[y];
		}
		for (int y = 0; y < Y; y++) {
			for (int x = 0; x < X; x++) {
				if (map[y][x] == 'A') {
					coorId[y][x] = id;
					parent[id] = id;
					id++;
				}
				if (map[y][x] == 'S') {
					coorId[y][x] = id;
					parent[id] = id;
					id++;
				}
			}
		}
		for (int y = 0; y < Y; y++) {
			for (int x = 0; x < X; x++) {
				if (map[y][x] == 'A') {
					used[y][x] = 1;
					setList(y, x);
				}
				if (map[y][x] == 'S') {
					used[y][x] = 1;
					setList(y, x);
				}
			}
		}
		sort(list.begin(), list.end(), cmp);
		int result = 0, cnt = 0;
		for (int i = 0; i < list.size(); i++) {
			if (Union(list[i].from, list[i].to)) {
				result += list[i].cost;
			}
		}
		cout << result << '\n';
	}
	return 0;
}