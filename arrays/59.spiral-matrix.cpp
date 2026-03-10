class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l=0,r=n-1,t=0,b=n-1;
        vector<vector<int>> matrix(n, vector<int>(n));
        int num=1;
        while(num<=n*n){
            for(int i=l;i<=r;i++){
                matrix[t][i]=num;
                num++;
            }
            t++;
            for(int i=t;i<=b;i++){
                matrix[i][r]=num;
                num++;
            }
            r--;
            for(int i=r;i>=l;i--){
                matrix[b][i]=num;
                num++;
            }
            b--;
            for(int i=b;i>=t;i--){
                matrix[i][l]=num;
                num++;
            }
            l++;
        }
        return matrix;
    }
};