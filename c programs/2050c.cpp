#include<bits/stdc++.h>
using namespace std;
#define debug 1
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        char str[100000];
        cin >> str ;
        int sum=0;
        int c2=0,c3=0;
        for(int i=0;i<strlen(str);i++){
            sum+=(str[i]-'0');
            sum%=9;
            if(str[i]=='2'){c2++;}
            if(str[i]=='3'){c3++;}
        }
       // if(debug){cout << sum << "\t" << c2 << "\t" <<  c3 <<endl;}; //
        vector <int> vec;
        for(int i=0;i<=c2;i++){
            if(i>8){break;}
            for(int j=0;j<=c3;j++){
                   if(j>2){break;} 
                   vec.push_back((2*i)+(6*j));
            }
        }
        sum=(9-sum)%9;
        int size=vec.size();
        int flag=0;
        for(int i=0;i<size;i++){
            if(vec[i]%9==sum){flag=1;break;}
        }
         /*for(int i=0;i<size;i++){
            printf("%d ",vec[i]);
         }
         printf("\t");*/
        if(sum==0){flag=1;}
        if(flag==1){cout << "YES\n";}
        else{ cout << "NO\n";}
    }
}