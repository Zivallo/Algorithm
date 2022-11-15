#include <iostream>
using namespace std;
int T, N, B;
int h[22], u[22], r, t;
void input() {
    r = 21e8, t = 0;;
    cin >> N >> B;
    for (int i = 0; i < N; i++) { cin >> h[i]; t += h[i]; }
}
void dfs(int l, int s, int n, int idx) {
    if (r == 0) return;
    if (s >= B || l == N) {
        r = (r > s - B ? s - B : r);
        return;
    }
    for (int i = idx; i < N; i++) {
        if (u[i] == 1) continue;
        if (s + n < B) continue;
        if (r == 0) return;
        u[i] = 1;
        dfs(l + 1, s + h[i], n - h[i], i + 1);
        u[i] = 0;
    }
}
void solve() {
    cin >> T; for (int tc = 1; tc <= T; tc++) {
        input();
        for (int i = 0; i < N; i++) {
            u[i] = 1;
            dfs(0, h[i], t - h[i], 0);
            u[i] = 0;
        }
        cout << "#" << tc << " " << r << "\n";
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