//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
           vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='W'){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        int x[]={-1,1,0,0};
        int y[]={0,0,-1,1};
        while(q.size()){
            auto temp = q.front();
            q.pop();
            int i=temp.first;
            int j=temp.second;
            for(int k=0;k<4;k++){
                int newi=i+x[k];
                int newj=j+y[k];
                if(newi>=0 and newi<n and newj<m and newj>=0 and
                c[newi][newj]!='N' and ans[newi][newj]==-1){
                    ans[newi][newj]=ans[i][j]+1;
                    q.push({newi,newj});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='N' or c[i][j]=='.')ans[i][j]=0;
                else if(ans[i][j]!=-1)ans[i][j]*=2;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends