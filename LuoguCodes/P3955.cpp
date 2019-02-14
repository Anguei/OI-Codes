#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath> 
using namespace std;
int n,q,code[1010];
bool vi[1010];
struct reader{
    int length;
    int need;
    bool check;
    int ans;
    int mod;
}r[1010];
int mypow(int a, int b) {
    int ret = 1;
    while (b > 0) {
        ret *= 10;
        b /= 10;
    }
    return ret;
}
int main(){
    //freopen("librarian.in","r",stdin);
    //freopen("librarian.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>code[i];
    }
    sort(code+1,code+n+1);
    for(int i=1;i<=q;++i){
        cin>>r[i].length>>r[i].need;
    }
    for(int i=1;i<=q;++i){
        r[i].mod=pow(10,r[i].length);
        //cout<<r[i].mod<<endl;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=q;++j){
            if(r[j].check) continue;
            int m=code[i]%r[j].mod;
            if(m==r[j].need){
                r[j].check=true;
                r[j].ans=code[i];
                vi[i]=true;
            }
            else{
                r[j].ans=-1;
            }
        }
    }
    for(int i=1;i<=q;++i){
        cout<<r[i].ans<<endl;
    }
    return 0;
}
