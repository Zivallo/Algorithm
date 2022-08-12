#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int st;
	int wait;
	int printNum;
	int idx;
};
struct PRINT {
	int num;
	int timee;
};

int N, M;
Node document[200001];
priority_queue<PRINT> print;
priority_queue<Node> pq;

bool operator< (Node v, Node t) {
	if (t.st != v.st) return t.st < v.st;
	if (t.wait != v.wait) return t.wait < v.wait;
	return t.idx < v.idx;
}
bool operator< (PRINT v, PRINT t) {
	if (t.timee != v.timee) return t.timee < v.timee;
	return t.num < v.num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int st, wait;
		cin >> st >> wait;
		document[i] = { st,wait,0,i };
		pq.push(document[i]);
	}
	for (int i = 1; i <= M; i++) {
		print.push({ i, 0 });
	}
	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		PRINT pt = print.top();
		print.pop();

		int ntime = 0;

		if (now.st >= pt.timee) ntime = now.st + now.wait;
		else ntime = pt.timee + now.wait;

		document[now.idx].printNum = pt.num;

		print.push({pt.num, ntime});
	}
	for (int i = 1; i <= N; i++) {
		cout << document[i].printNum << "\n";
	}
	return 0;
}