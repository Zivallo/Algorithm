#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
	int s, e;
	int sec;
};
int N;
Node arr[1000];
int room[1000];

bool cmp(Node t, Node v) {
	if (t.sec != v.sec) return t.sec < v.sec;
	return t.s < v.s;
}

int isPossible(int s, int e) {
	for (int i = s; i < e; i++) {
		if (room[i] == 1) return 0;
	}
	return 1;
}
void setRes(int s, int e) {
	for (int i = s; i < e; i++) {
		room[i] = 1;
	}
}

int main() {
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].s >> arr[i].e;
		arr[i].sec = arr[i].e - arr[i].s;
	}
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++) {
		if (isPossible(arr[i].s, arr[i].e)) {
			setRes(arr[i].s, arr[i].e);
			ans++;
		}
	}
	cout << ans;
	return 0;
}