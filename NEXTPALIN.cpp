#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool allNines(vector<int> nums){
    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i]!=9)
            return false;
    }
    return true;
}

void generatePalindrome(vector<int> &nums){
    //cout<<nums.size()<<endl;
    int n = nums.size();
    if(allNines(nums)){
        nums.clear();
        nums.push_back(1);
        for(int i = 0 ; i < n-1 ; i++){
            nums.push_back(0);
        }
        nums.push_back(1);
        return ;
    }

    int mid = n / 2;
    //cout<<mid<<endl;
    bool leftSmall = false;
    int i = mid-1;
    //cout<<i<<endl;
    int j = (n%2) ? mid+1 : mid;
    //cout<<j<<endl;
    while(i>=0 && nums[i]==nums[j]){
        i--;
        j++;
    }
    //cout<<"I = "<<i<<" J = "<<j<<endl;
    if(i < 0 || (nums[i] < nums[j]))
    {
        leftSmall = true;
        //cout<<"LeftSmall "<<endl;
    }
    //cout<<leftSmall;

    while(i >= 0){
        nums[j] = nums[i];
        i--;
        j++;
    }

    if(leftSmall){
        //cout<<"In Left Small"<<endl;
        int carry = 1;
        int  i = mid - 1;
        if(n%2 == 1){
            nums[mid] += carry;
            carry = nums[mid]/10;
            nums[mid]%=10;
            j = mid + 1;
        }
        else{
            j = mid;
        }

        while(i >= 0){
            nums[i]+=carry;
            carry = nums[i]/10;
            nums[i] = nums[i]%10;
            nums[j++] = nums[i--];
        }
    }
}



int main(){
    int test;
    cin>>test;
    while(test--){
        string n;
        cin>>n;
        //cout<<"String = "<<n<<endl;
        vector<int> nums;
        for(int i = 0 ; i < n.size() ; i++){
            nums.push_back(n[i]-'0');
        }
        //reverse(nums.begin(),nums.end());
        generatePalindrome(nums);
        int i = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            cout<<nums[i];
        }
        cout<<endl;
    }
}
