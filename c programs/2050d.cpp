#include<bits/stdc++.h>
using namespace std;
#define debug 0
void take(int arr[] , int n){
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
}
void take(char str[]){
    scanf("%s",str);
}
bool prime(int n){
    if(n==2){return 1;}
    int flag=0;
    for(int i=2;i<n;i++){
        if(n%i==0){flag=1;break;}
    }
    return (flag==0) ;
}

long long int calculate(long long int m ){
    long long result = 1;
    long long int base=2;
    while (m > 0) {
        if (m % 2 == 1)  // If exp is odd, multiply result with base
            result *= base;
            result %=(1000000007);
        base *= base;
        base%=(1000000007);// Square the base
        m /= 2; // Reduce exponent by half
    }
    return result%(1000000007);
}
int main(){
    int cases;
    cin >> cases ;
    while(cases--){
        int n,m;
        cin >> n >> m;
        char str[n][m+1];
        for(int i=0;i<n;i++){
            take(str[i]);
        }
        int flag=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(str[i][j] =='1'){
                    int flag1=0,flag2=0;
                    for(int k=0;k<j;k++){
                        if(str[i][k]=='0'){flag1=1;break;}
                    }
                    for(int k=0;k<i;k++){
                        if(str[k][j]=='0'){flag2=1;break;}
                    }
                    if(flag1*flag2==1){flag=1;}
                }
            }
        }
        if(flag==1){cout << "No" << endl;}
        else{cout << "Yes" << endl;}
    }
}