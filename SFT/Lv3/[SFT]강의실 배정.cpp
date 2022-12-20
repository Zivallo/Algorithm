#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
struct info { long long s, e; };
vector<info>line;

bool cmp(info t, info v) {
	if (t.e != v.e)return t.e < v.e;
	else return t.s < v.s;
}
void solve() {
	cin >> N; int cnt = 0, end = 0;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		line.push_back({ s,e });
	}
	sort(line.begin(), line.end(), cmp);
	for (int i = 0; i < line.size(); i++) {
		if (end > line[i].s)continue;
		cnt++;
		end = line[i].e;
	}
	cout << cnt << "\n";
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}