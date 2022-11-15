#include <queue>
using namespace std;
int T, N, sy, sx, ty, tx, map[20][20], dp[20][20];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };
struct Node { int y, x, sec; };
void input() {
    cin >> N;
    for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) {
        cin >> map[y][x];
        dp[y][x] = 21e8;
    }
    cin >> sy >> sx >> ty >> tx;
}
void solve() {
    cin >> T; for (int t = 1; t <= T; t++) {
        input();
        queue<Node> q;
        q.push({ sy,sx,0 });
        dp[sy][sx] = 0;
        while (!q.empty()) {
            Node now = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = now.y + drY[i];
                int nx = now.x + drX[i];
                int nsec = nsec = now.sec + 1;
                if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
                if (map[ny][nx] == 1)continue;
                if (dp[ny][nx] <= nsec) continue;
                dp[ny][nx] = nsec;
                q.push({ ny,nx,nsec });
            }
        }
        if (dp[ty][tx] == 21e8) dp[ty][tx] = -1;
        cout << "#" << t << " " << dp[ty][tx] << "\n";
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