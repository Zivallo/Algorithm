#include <iostream>
using namespace std;

long long N, a[100010];
long long B, result;

void input() {
	cin >> N >> B;
	for (int i = 0; i < N; i++) cin >> a[i];
}
long long getCost(long long half) {
	long long cost = 0, cha = 0;
	for (int i = 0; i < N; i++) {
		cha = half - a[i];
		if (cha < 0) continue;
		if (cha > B) return B + 1;
		cost += cha * cha;
		if (cost > B) return B + 1;
	}
	return cost;
}
void solve() {
	input();
	long long l = 1, r = 2000000000;
	long long half = 0, cost = 0;
	while (l <= r) {
		half = (l + r) / 2;
		cost = getCost(half);
		if (cost == B) {
			result = half;
			break;
		}
		if (cost > B) {
			r = half - 1;
		}
		else {
			l = half + 1;
			result = half;
		}
	}
	cout << result << "\n";
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}