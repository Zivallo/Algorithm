#include <iostream>
#include <string>
using namespace std;

string bridge[2], cdt;
int used[140], cnt;

void DFS(int now, int lev, int which) {
	if (lev == cdt.size()) {
		cnt++;
		return;
	}
	for (int i = now; i < bridge[which].size(); i++) {
		int next = i;
		if (bridge[which][next] != cdt[lev]) continue;
		if (used[next] == 1) continue;
		used[next] = 1;
		DFS(next, lev + 1, (which + 1) % 2);
		used[next] = 0;
	}
}

int main() {
	cin >> cdt;
	cin >> bridge[0];
	cin >> bridge[1];
	DFS(0, 0, 0);
	DFS(0, 0, 1);
	cout << cnt;
	return 0;
}