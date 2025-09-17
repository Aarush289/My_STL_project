#include<bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n,m;
        scanf("%d",&n);
        vector <int> v;
        scanf("%d",&m);
        v.push_back(m);
        int max1=m;
        int j1=0,j2=0;
        for(int i=1;i<n;i++){
            scanf("%d",&m);
            v.push_back(m);
            if(max1 < m){max1=m;j1=i;}
        }
        v.erase(v.begin()+j1);
        int max2=v[0];
         for(int i=1;i<n-1;i++){
            if(max2<v[i]){max2=v[i];j2=i;}
        }
        if(j2>=j1){j2++;}
        v.insert(v.begin()+j1,max1);
        for(int i=0;i<n;i++){
            if(i!=j1){printf("%d ",v[i]-max1);}
            else{printf("%d ",v[i]-max2);}
        }
        printf("\n");
    }

}