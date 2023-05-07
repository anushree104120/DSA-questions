//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
         string temp="";
        temp+=str[0];
        for(int i=1;i<str.length();i++){
            if(str[i]<temp[i-1])temp+=str[i];\
            else if(str[i]==temp[i-1] and i!=1)temp+=str[i];
            else break;
        }
        string t = temp;
        reverse(t.begin(),t.end());
        temp+=t;
        return temp;
    
    
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends