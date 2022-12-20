#include <iostream>
#include <queue>
using namespace std;
struct Node { int y, x, sec, f; };
int T, N, M, m[12][12], d[3][12][12];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void input() {
    cin >> N >> M;
    for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) {
        cin >> m[y][x]; d[0][y][x] = 21e8; d[1][y][x] = 21e8;
    }
}
bool c(int y, int x) {
    int f1 = 0, f2 = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
        if (i < 2) {
            if (m[ny][nx] != 1) f1 = 1;
        }
        else {
            if (m[ny][nx] != 1) f2 = 1;
        }
    }
    if (f1 && f2) return false;
    else return true;
}
void solve() {
    cin >> T; for (int t = 1; t <= T; t++) {
        input();
        queue<Node> q;
        q.push({ 0,0,0,0 });
        d[0][0][0] = 0;
        while (!q.empty()) {
            Node now = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = now.y + dy[i];
                int nx = now.x + dx[i];
                int ns = 0;
                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if (m[ny][nx] != 1 && m[now.y][now.x] != 1) continue;
                if (m[ny][nx] == 0 && now.f == 1) continue;
                if (m[ny][nx] != 1) if (!c(ny, nx)) continue;
                if (m[ny][nx] == 0) ns = now.sec + (M - now.sec % M);
                if (m[ny][nx] == 1) ns = now.sec + 1;
                if (m[ny][nx] > 1) ns = now.sec + (m[ny][nx] - now.sec % m[ny][nx]);
                if (ns >= d[now.f][ny][nx])continue;
                d[now.f][ny][nx] = ns;
                if (m[ny][nx] == 0)q.push({ ny,nx,ns,1 });
                else q.push({ ny,nx,ns,now.f });
            }
        }
        cout << "#" << t << " " << (d[0][N - 1][N - 1] > d[1][N - 1][N - 1] ? d[1][N - 1][N - 1] : d[0][N - 1][N - 1]) << "\n";
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