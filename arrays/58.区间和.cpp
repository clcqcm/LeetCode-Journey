给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
前缀和法
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a,b,n,res;
    cin>>n;
    vector<int> arr(n);
    vector<int> sums(n+1);
    sums[0]=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sums[i+1]=arr[i]+sums[i];
    }
    while(cin>>a>>b){
        if(a<0||a>b){
            cout<<"error!input again!";
        }
        else{
            res=sums[b+1]-sums[a];
            cout<<res;
        }
        cout<<"\n";
    }
    return 0;
}