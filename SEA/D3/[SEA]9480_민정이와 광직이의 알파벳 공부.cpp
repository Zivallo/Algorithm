#include <iostream>
#include <string>
using namespace std;
int T, N, r;

void dfs(int l, string* s, int* c, int cnt, int start) {
    if (start == N) return;
    for (int i = start; i < N; i++) {
        int cnt1 = 0;
        for (int j = 0; j < s[i].length(); j++) {
            if (c[s[i][j]] == 0)cnt1++;
            c[s[i][j]]++;
        }
        dfs(l + 1, s, c, cnt + cnt1, i + 1);
        for (int j = 0; j < s[i].length(); j++) c[s[i][j]]--;
        if (cnt + cnt1 >= 26) r++;
    }
}
void solve() {
    cin >> T; for (int t = 1; t <= T; t++) {
        r = 0; string s[15] = { "" }; int c[130] = { 0 };
        cin >> N;
        for (int i = 0; i < N; i++)cin >> s[i];
        dfs(0, s, c, 0, 0);
        cout << "#" << t << " " << r << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen_s(new FILE*, "input.txt", "r", stdin);
    solve();
    return 0;
}