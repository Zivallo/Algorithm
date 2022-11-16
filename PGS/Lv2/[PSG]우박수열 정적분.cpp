#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> area;
    int xk = k;
    double tmp = 0.0;
    area.push_back(tmp);
    while(k > 1){
        if(k%2==0) k=(k/2);
        else k=((k*3)+1);
        
        tmp += (double(k+xk)/2);
        area.push_back(tmp);
        
        xk = k;
    }
    for(int i=0;i<ranges.size();i++){
        int a= ranges[i][0];
        int b = area.size()+ranges[i][1]-1;
        if(a > b) answer.push_back(-1.0);
        else if(a == b) answer.push_back(0.0);
        else answer.push_back(area[b]-area[a]);
    }
    return answer;
}