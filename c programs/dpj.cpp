#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    for(int p=0;p<cases;p++){
        int n,k;
        scanf("%d%d",&n,&k);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
      
        std::vector<std::vector<int>> vec(k);
        for(int i=0;i<n;i++){
            int l = arr[i]%k;
            vec[l].push_back(i);
        }
        for(int j=0;j<vec[0].size();j++){
            printf("%d ",vec[0][j]+1);
        }
        for(int i=k-1;i>0;i--){
            for(int j=0;j<vec[i].size();j++){
                printf("%d ",vec[i][j]+1);
            }
        }
        printf("\n");
    }
}