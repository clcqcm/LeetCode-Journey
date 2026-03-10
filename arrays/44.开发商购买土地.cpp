1.蛮力法
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m,x=1,y=1,res=1e9,sum=0;
    cin>>n>>m;
    vector<int> rowSums(2),colSums(2);
    vector<vector<int>> block(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>block[i][j];
            sum+=block[i][j];
        }
    }
    while(y<=m-1){
        colSums[0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<y;j++){
                colSums[0]+=block[i][j];
            }
        }
        colSums[1]=sum-colSums[0];
        res=min(res,abs(colSums[0]-colSums[1]));
        y++;
    }
    while(x<=n-1){
        rowSums[0]=0;
        for(int i=0;i<x;i++){
            for(int j=0;j<m;j++){
                rowSums[0]+=block[i][j];
            }
        }
        rowSums[1]=sum-rowSums[0];
        res=min(res,abs(rowSums[0]-rowSums[1]));
        x++;
    }
    cout<<res;
    return 0;
}
2.二维数组的前缀和：sums[i+1][j+1]=sums[i][j+1]+sums[i+1][j]-sums[i][j]+x
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m,res=1e9;
    int rowSum[2],colSum[2];
    cin>>n>>m;
    vector<vector<int>> sums(n+1, vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            sums[i+1][j+1]=sums[i][j+1]+sums[i+1][j]-sums[i][j]+x;
        }
    }
    for(int i=1;i<n;i++){
        rowSum[0]=sums[i][m];
        rowSum[1]=sums[n][m]-rowSum[0];
        res=min(res,abs(rowSum[0]-rowSum[1]));
    }
    for(int i=1;i<m;i++){
        colSum[0]=sums[n][i];
        colSum[1]=sums[n][m]-colSum[0];
        res=min(res,abs(colSum[0]-colSum[1]));
    }
    cout<<res;
    return 0;
}