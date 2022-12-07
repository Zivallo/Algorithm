#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int l = 0, r = 1;
    int cnt_x = 1, cnt_y = 0;
    while (r <= s.length())
    {
        if (s[l] == s[r])cnt_x++;
        if (s[l] != s[r])cnt_y++;
        if (r == s.length())
        {
            answer++;
            break;
        }
        if (cnt_x == cnt_y)
        {
            answer++;
            cnt_x = 1;
            cnt_y = 0;
            l = r + 1;
            r++;
        }
        r++;
    }
    return answer;
}