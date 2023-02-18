#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
unordered_map<string, vector<pair<int, int>>> um;
unordered_map<string, int> um1;
int tim[55][20];
int N, M;
vector<string> s;

bool cmp(pair<int, int> t, pair<int, int> v) {
	return t.first < v.first;
}
void solve() {
	cin >> N >> M;
	string t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		s.push_back(t);
		um1[t] = i;
		tim[i][8] = 1;
		tim[i][18] = 1;
	}
	sort(s.begin(), s.end());
	// 사용시간 체크
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> t >> a >> b;
		for (int j = a; j < b; j++) {
			tim[um1[t]][j] = 1;
		}
	}
	// 비는 시간 체크
	for (int i = 0; i < N; i++) {
		int idx = 0;
		for (int j = 9; j < 18; j++) {
			if (tim[um1[s[i]]][j - 1] == 1 && tim[um1[s[i]]][j] == 0) {
				um[s[i]].push_back({ j,0 });
			}
			if (tim[um1[s[i]]][j] == 0 && tim[um1[s[i]]][j + 1] == 1) {
				um[s[i]][idx].second = j + 1;
				idx++;
			}
		}
	}
	// 출력
	for (int i = 0; i < N; i++) {
		cout << "Room " << s[i] << ":\n";
		if (um[s[i]].empty())cout << "Not available\n";
		else {
			cout << um[s[i]].size() << " available:\n";
			sort(um[s[i]].begin(), um[s[i]].end(), cmp);
			for (int j = 0; j < um[s[i]].size(); j++) {
				if (um[s[i]][j].first < 10)cout << "0" << um[s[i]][j].first;
				else cout << um[s[i]][j].first;
				cout << "-";
				if (um[s[i]][j].second < 10)cout << "0" << um[s[i]][j].second;
				else cout << um[s[i]][j].second << "\n";
			}
		}
		if (i != N - 1)cout << "-----\n";
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}