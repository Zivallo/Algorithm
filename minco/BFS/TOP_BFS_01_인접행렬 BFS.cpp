#include <iostream>
#include <queue>
using namespace std;

int main() {
	int cntNode;
	cin >> cntNode;
	int arr[100][100];
	for (int y = 0; y < cntNode; y++) {
		for (int x = 0; x < cntNode; x++) {
			cin >> arr[y][x];
		}
	}
	int used[100] = { 0, };

	queue<int> q;
	q.push(0);
	used[0] = 1;


	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int next = 0; next < cntNode; next++) {
			if (arr[now][next] == 0) continue;
			if (used[next] == 1) continue;
			used[next] = 1;
			q.push(next);
		}
	}
	return 0;
}