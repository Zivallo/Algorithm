#include<iostream>
using namespace std;
using ll = long long;
ll K, P, N;

ll x(ll cnt) {
	if (cnt == 1)return P;
	ll ret = x(cnt / 2);
	ret = (ret * ret) % 1000000007;
	if (cnt % 2) ret = ret * P % 1000000007;
	return ret;
}
void solve() {
	cin >> K >> P >> N;
	cout << K * x(N * 10) % 1000000007 << "\n";
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}