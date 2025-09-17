#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n;
        scanf("%d",&n);
        int arr[n];
        int answer[n];
        int min=0;
        int temp[n];
        int h=0;     
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            if(arr[i]<0){answer[i]=min-arr[i];temp[i]=answer[i];}
            else
            {
                answer[i]=min;
                temp[i]=answer[i];
                sort(temp,temp+(i+1));
                int flag=0;
                while(h<i+1){
                    if(temp[h]!=h){min=h;flag=1;break;}
                    h++;
                }
                if(flag==0){min=i+1;}
                }
               //printf("%d\n",min);//
                           }
            for(int i=0;i<n;i++){
                printf("%d ",answer[i]);
            }
            printf("\n");
        }
    }
