#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> first;
    vector<int> second;
    int n, m , k;
    cin>>n>>m>>k;
    for(int i = 0 ; i < n ; i++){
        int a;
        cin>>a;
        first.push_back(a);
    }
    for(int i = 0 ; i < m ; i++){
        int a;
        cin>>a;
        second.push_back(a);
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m  ; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(first[i-1] == second[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    int q = min(m,n);
    cout<<min(q , dp[n][m]+k);
    return 0;
}
