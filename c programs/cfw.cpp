#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
      int n,k;
      scanf("%d%d",&n,&k);
      char str[n+1];
      scanf("%s",str);
     int group=1;
     int count0=0;
     for(int i=0;i<n;i++){
        if(str[i]=='0'){count0++;}
     }
     int count1=(n-count0);
     int ans=0;
     int i=0;
     int pre=0;
     int flag=0;
      int coun0=0;
      if(k!=0){
      if(str[0]=='1'){ i++;while(str[i]!='1'){i++;coun0++;if(str[i]==0){flag=1;break;}} group++;count0-=coun0; pre++;count1--;ans+=(count1-count0)*(pre);}
      else{while(str[i]!='1'){i++;coun0++;if(str[i]==0){flag=1;break;}} group++; count0-=coun0;pre++;ans+=(count1-count0);}
      }
     while(ans<k){
        group++;
        pre++;
        while(str[i]!='1'){i++;coun0++;if(str[i]==0){break;}}
        if(i==0){i++;while(str[i]!='1'){i++;coun0++;if(str[i]==0){break;}}}
        count1--;
        count0-=coun0;
        ans+=(count1-count0);
        if(str[i]==0){flag=1;break;}
        i++;
        coun0=0;
        //printf("%d\n",ans);//
     }
     if(flag==1){printf("-1\n");}
     else{printf("%d\n",group);}
   }
}