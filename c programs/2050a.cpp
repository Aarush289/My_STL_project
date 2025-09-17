#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        int low=0;
        int high=0;
        if(n==0){cout << "1" <<endl;cout << "0 " <<"0"<<endl; }
        else{
            int count=0;
            int count1=0;
            int temp=n;
            while(n>0){
                int num=sqrt(2*n);
                int i;
                for(i=num-1;i<=num+2;i++){
                    if(i*(i-1) >(2*n)){break;}
                }
                i--;
                if(debug){cout <<i<<endl;}
                n-=((i*(i-1))/2);
                count+=i;
                count1++;
            }
            count1--;
            cout << count-count1 <<endl;
            n=temp;
            int flag=0;
            while(n>0){
                int num=sqrt(2*n);
                int i;
                for(i=num-1;i<=num+2;i++){
                    if(i*(i-1) >2*n){break;}
                }
                i--;
                n-=((i*(i-1))/2);
                //if(debug){cout << n <<endl;}
                if(flag==0){for(int j=0;j<i;j++){
                    cout << low << " " << high <<endl;
                    low++;
                }}
                else{for(int j=0;j<i-1;j++){
                    cout << low << " " << high <<endl;
                    low++;
                }}
                
                low--;
                num=sqrt(2*n);
                for(i=num-1;i<=num+2;i++){
                    if(i*(i-1) >2*n){break;}
                }
                i--;
                n-=((i*(i-1))/2);
               // if(debug){cout << n <<endl;}
                high++;
                for(int j=0;j<i-1;j++){
                    
                    cout << low << " " << high <<endl;
                    high++;
                }
                high--;
                low++;
                flag=1;
            }
        }
    }
}