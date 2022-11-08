#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int idx=0;
    int used[250010]={0};
    
    if(ingredient[0]==1) {idx++;used[1]=1;}
    for(int i=1;i<ingredient.size();i++){
        if(ingredient[i]!=1 && idx==0) continue;
        if(used[idx]!=0 &&(used[idx]+1)==ingredient[i]) used[idx]++;
        else{
            if((used[idx]+1)==4 && ingredient[i]==1){
                used[idx]=0;
                answer++;
                idx--;
            }
            else {
                if(ingredient[i]==1) {idx++;used[idx]=1;}
                else {
                    if(used[idx]+1==ingredient[i]) used[idx]++;
                    else {idx=0;used[0]=0;}
                }
            }
        }
    }
    
    return answer;
}
