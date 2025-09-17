#include<bits/stdc++.h>
#define debug 0
using namespace std;
#define siz 1000
int main(){
    int count=0;
    for(int i=0;i<siz; i++){
    vector<int> lis;
        int num=0;
        char c;
        while ((c = getchar()) != '\n' && c != EOF) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == ' ') {
                lis.push_back(num);
                num = 0;
            }
        }
        lis.push_back(num);
        int n=lis.size();
        if(debug){printf("%d\n",n);}
         int coun=0;
        for(int i=0;i<n;i++){
            int arr[n-1];
            int j=0;
            int flag=0;
            for(int k=0;k<n;k++){
                if(i!=k){arr[j]=lis[k]; j++;}
            }
                int diff =arr[1]-arr[0];
                if(diff==0){flag=1;}
                for(int j=1;j<(n-1);j++){
            if((arr[j]-arr[j-1]) >3 || (arr[j]-arr[j-1]) <-3 || ((arr[j]-arr[j-1])*(diff))<=0){flag=1;coun++;break;}
        }
        }
         if(coun!=(n)){count++;}
        
    //printf("%d\n",count);//
}
printf("%d\n",count);
}