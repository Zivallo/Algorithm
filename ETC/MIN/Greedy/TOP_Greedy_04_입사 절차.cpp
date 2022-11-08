#include <iostream>
#include <queue>
using namespace std;

struct Node {
	long long ct;
	long long in;
};
int N, cnt = 1, ans;
bool operator< (Node v, Node t) {
	return t.ct < v.ct;
}
priority_queue<Node> pq;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long ct, in;
		cin >> ct >> in;
		pq.push({ ct,in });
	}
	Node xNow = pq.top();
	pq.pop();
	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (now.in > xNow.in) {
			continue;
		}
		xNow = now;
		cnt++;
	}
	cout << cnt;
	return 0;
}