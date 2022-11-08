#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, int> reportCnt;
    unordered_map<string, vector<string>> singo;

    for (int i = 0; i < report.size(); i++) {
        int ret = report[i].find(' ', 0);
        string name1 = report[i].substr(0, ret);
        string name2 = report[i].substr(ret + 1, report[i].length() - ret - 1);
        int flag = 1;
        for (int j = 0; j < singo[name1].size(); j++) {
            if (singo[name1][j] == name2) {
                flag = 0;
                break;
            }
        }
        if(flag) singo[name1].push_back(name2);
        if (reportCnt.count(name2)==0) {
            reportCnt[name2]=0;
        }
        if (flag) reportCnt[name2]++;
    }

    for (int i = 0; i < id_list.size(); i++) {
        int cnt = 0;
        for (auto it = singo[id_list[i]].begin(); it != singo[id_list[i]].end(); it++) {
            if (reportCnt[*it] >= k) cnt++;
        }
        answer.push_back(cnt);
    }

    return answer;
}
