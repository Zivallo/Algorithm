#include <iostream>
#include<queue>
using namespace std;
struct Node {
	int idx;
	int cnt;
};
int start, target, used[200000];
queue<Node> q;

int main() {
	cin >> start >> target;
	q.push({ start,0 });
	used[start] = 1;

	while (!q.empty()) {
		int nowx = q.front().idx;
		int cnt = q.front().cnt;
		q.pop();
		if (nowx == target) {
			cout << cnt;
			break;
		}

		int nx1 = nowx / 2;
		int nx2 = nowx * 2;
		int nx3 = nowx + 1;
		int nx4 = nowx - 1;
		int ncnt = cnt + 1;
		if (nx1 >= 0 && nx1 <= 100000) {
			if (used[nx1] == 0) {
				used[nx1] = 1;
				q.push({ nx1 , ncnt });
			}
		}
		if (nx2 >= 0 && nx2 <= 100000) {
			if (used[nx2] == 0) {
				used[nx2] = 1;
				q.push({ nx2 , ncnt });
			}
		}
		if (nx3 >= 0 && nx3 <= 100000) {
			if (used[nx3] == 0) {
				used[nx3] = 1;
				q.push({ nx3 , ncnt });
			}
		}
		if (nx4 >= 0 && nx4 <= 100000) {
			if (used[nx4] == 0) {
				used[nx4] = 1;
				q.push({ nx4 , ncnt });
			}
		}
	}


	return 0;
}