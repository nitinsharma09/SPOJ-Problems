#include<bits/stdc++.h>
using namespace std;

int multiply(int x , vector<int> &result , int &res_size){
    int carry = 0;
    for(int i = 0 ; i < res_size ; i++){
        int prod = result[i] * x + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }

    while(carry){
        result[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

void factorial(int n){
    vector<int> result(500);
    result[0] = 1;
    int res_size = 1;
    for(int x = 2; x <= n ; x++){
        res_size = multiply(x , result , res_size);
    }
    for(int i = res_size-1 ; i >= 0 ; i--){
        cout<<result[i];
    }
    cout<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        factorial(n);
    }
    return 0;
}
