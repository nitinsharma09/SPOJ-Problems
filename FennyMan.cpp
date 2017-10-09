#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n!=0){
        long int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            ans += (i * i);
        }
        cout<<ans<<endl;
        cin>>n;
    }
    return 0;
}
