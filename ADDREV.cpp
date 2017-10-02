#include<bits/stdc++.h>
using namespace std;

int reverseNumber(int n){
    while(n!=0 && n%10 == 0){
        n = n / 10;
    }
    int rev = 0;
    while(n!=0){
        int digit = n % 10;
        rev = (10 * rev) + digit;
        n = n / 10;
    }
    return rev;
}

int main()
{
    int test;
    cin>>test;
    while(test--){
        int a ;
        int b;
        cin>>a;
        cin>>b;
        int aRev = reverseNumber(a);
        int bRev = reverseNumber(b);
        int sum = aRev + bRev;
        cout<<reverseNumber(sum)<<endl;
    }
    return 0;
}
