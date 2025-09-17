#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int n;
        scanf("%d",&n);
        char str[101];
        //getchar();//
        scanf("%s",str);
        int m=strlen(str);
        if(debug){printf("%d\n",m);}
        if(m%2==1){printf("NO\n");}
        else{
            int count1=0;
            int flag=0;
            int count=0;
            for(int i=0;i<m;i++){
                if(str[i]=='('){count++;}
            }
            count=(m/2)-count;
            if(debug){printf("%d\n",count);}
            for(int i=0;i<m;i++){
                if(count1<0){flag=1;break;}
                if(str[i]=='('){count1++;}
                if(str[i]==')'){count1--;}
                if(str[i]=='?'){
                    if(count>0){count--;count1++;}
                    else{count1--;}
                }
            }
            if(flag==0){printf("YES\n");}
            else{printf("NO\n");}
        }
        
    }
}