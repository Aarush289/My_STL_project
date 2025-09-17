# include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n,k;
        scanf("%d%d",&n,&k);
        int mem[n];
        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%d",&mem[i]);
            sum+=mem[i];
        }
        int num= (2*k)-sum;
        int count=0;
        int i=0;
        for(int i=0;i<n;i++){
            int n=mem[i]/2;
            if(mem[i]%2!=0){if(num>0){num--;count+=(2*n)+1;}
            else{count+=(mem[i]-1);}}
            else{count+=2*n;}
        }
        printf("%d\n",count);
    }
}