#include <iostream>
using namespace std;

int N, M;
int arr[110000];
int acc[110000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        acc[i] = acc[i - 1] + arr[i];
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << acc[b] - acc[a - 1] << '\n';
    }

    return 0;
}