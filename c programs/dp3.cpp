#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        char str[1000000];
        scanf("%s",str);
        int n=strlen(str)-1;
        int countb=0;
        int countB=0;
        vector<char> vec;
        while(n>=0){
            if(str[n]=='B'){countB++;}
            if(str[n]=='b'){countb++;}
            if(str[n]!='B' && str[n]!='b'){
                if(str[n]>='a' && str[n]<='z'){if(countb==0){vec.insert(vec.begin(),str[n]);}
                                                else{countb--;}}
                else{if(countB==0){vec.insert(vec.begin(),str[n]);}else{countB--;}}
            }
            n--;
        }
        for(int i=0;i<vec.size();i++){
            printf("%c",vec[i]);
        }
        printf("\n");
    }
}