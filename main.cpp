#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int groupDiffLength,maxHeight;
int groupCnt,maxn=1e9,minn=-1e9;
int main(){
    int n=1;
    while(cin>>a[n]){
        maxn=max(maxn,a[n]),minn=min(minn,a[n]);
        n++;
    }
    cin>>groupDiffLength;
    groupCnt=(maxn-minn)/groupDiffLength;
    vector<char,vector<char>>imageRes;
    int memoryImage[n+5];
    for(int i=1;i<=n;i++){
        int j=1,tmp=minn;
        while(a[j]<tmp){
            tmp+=groupDiffLength*j;
            j++;
        }
        memoryImage[tmp]++;
    }
    for(int i=1;i<=groupCnt;i++)
        maxHeight=max(maxHeight,memoryImage[i]);
    for(int i=1;i<=groupCnt;i++){
        for(int j=1;j<=memoryImage[i];j++)
            imageRes[i][j]='*';
    }
    for(int i=1;i<=groupCnt;i++)
        for(int k=maxHeight;k>=1;k--)
            cout<<imageRes[i][k];
    cout<<endl;
    for(int i=1;i<=groupCnt;i++)cout<<'-';
    cout<<endl;
    for(int i=1;i<=groupCnt;i++)cout<<i;
}
