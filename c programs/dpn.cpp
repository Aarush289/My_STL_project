#include<bits/stdc++.h>
using namespace std;
#define debug 1
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        int min=abs(arr[0]);
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                if(min>(-1*arr[i])){min=(-1*arr[i]);}
            }
            else{
                if(min>arr[i]){min=arr[i];}
            }
        }
        int min2;
        if(n>1){
            sort(arr,arr+n);
            int h=0;
            while(abs(arr[h])!=min){h++;}
            if(arr[n-1]<0){min2=(abs(arr[n-2])+min+1);}
            else{
                if(arr[0]>0){min2=arr[1];}
                else{
                    if(n==2){min2=(abs(arr[0])+arr[1]-min);}
                    else{
                        if(h==0){min2=arr[1];}
                        else{
                            if(h==(n-1)){min2=abs(arr[h-1])+min+1;}
                            else{
                                int min3,min4;
                                min3=arr[h+1];
                                min4=abs(arr[h-1])+min+1;
                                if(min3>min4){min2=min4;}
                                else{min2=min3;}
                            }
                        }
                    }
                }
            }
        }

        if(n==1){printf("1\n");}
        else{
            if(debug){printf("%d %d\n",min,min2);}
            int j=min2;
            while(j>0){
                 int flag=0;
                 int rem;
                if(arr[0]<0){rem =(arr[0]%j)+j;}
                else{rem=arr[0]%j;}
                for(int i=1;i<n;i++){
                      if(arr[i]<0){if(((arr[i]%j)+j)!=rem){flag=1;break;}}  
                      else{if(arr[i]%j!=rem){flag=1;break;}}
                }
                if(flag==0){break;}
                j--;
            }
            if(j==0){j++;}
            int num=arr[n-1]-j;
            int index=n-2;
            while( index>=0 && num==arr[index]){
                index--;
                num-=j;
            }
            int count=0;
            for(int i=0;i<n;i++){
                    count+=((arr[n-1]-arr[i])/j);
            }
            count+=((arr[n-1]-num)/j);
            if(debug){printf("%d\n",j);}
            printf("%d\n",count);

        }
    }
}