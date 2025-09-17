#include<bits/stdc++.h>
using namespace std;
# define debug 0
int main() {
    char str1[200001];
    char str2[200001];
    scanf("%s",str1);
    scanf("%s",str2);
    map<char,int> mp1;
      int arr1[26]={0};
    int arr2[26]={0};
    for(int i=(strlen(str1)-1);i>0;i--){
        mp1[str1[i]]=i;
    }
    map<char,int> mp2;

    for(int i=0;i<(strlen(str2)-1);i++){
        mp2[str2[i]]=((strlen(str2))-i);
    }
        int flag=0;
        for(int i=0;i<26;i++){
            if(arr1[i]!=0 &&arr2[i]!=0){flag=1;break;}
        }
        
        int min=strlen(str1)+strlen(str2);
        int j=0;
        if(flag==0){printf("-1\n");}
        else{
                for(int i=1;i<strlen(str1);i++){
                    if(arr2[str1[i]-'a']==0){continue;}
                    int in=mp1[str1[i]]+mp2[str2[i]];
                    if(in<min){min=in;j=i;}
                }
                for(int i=0;i<=j;i++){
                        printf("%c",str1[i]);
                }
                int k=strlen(str2)-2;
                while(str2[k]!=str1[j]){
                    printf("%c",str2[k]);
                }
                printf("\n");
        }

}