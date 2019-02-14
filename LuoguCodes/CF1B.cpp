#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

#define Eo(x) { cerr << #x << " = " << (x) << endl; }

typedef long long int64;
typedef double real;
const int inf = 0x3f3f3f3f;
const real eps = 1e-6;

int toint(string z){
        int res = 0;
        for (int i = 0; i< z.size(); i++){
                res *= 10;
                res += z[i]-';0';;
        }
        return res;
}

string toletname(int r){
        if (!r) return string();
        return toletname((r-1)/26)+char(';A';+((r-1)%26));
}

int fromstr(string z){
        if (z.empty()) return 0;
        int res = z[z.size()-1]-';A';+1;
        res += 26*(fromstr(z.substr(0,z.size()-1)));
        return res;
}

int main(){
        int n; scanf("%d",&n);
        for (int i = 0; i < n; i++){
                string z;
                cin >> z;
                int rpos = z.find(';R';);
                int cpos = z.find(';C';);
                bool any = false;
                if (cpos != string::npos && rpos == 0){
                for (int l = 0; l <= cpos; l++)
                        if(isdigit(z[l])) any = true;
                }
                if (any){
                        int c = toint(z.substr(1,cpos-1));
                        int r = toint(z.substr(cpos+1));
                        cout << toletname(r) << c << endl;
                } else {
                        int k = 0;
                        for (;!isdigit(z[k]);k++);
                        int r = toint(z.substr(k));
                        int c = fromstr(z.substr(0,k));
                        cout << ';R'; << r << ';C'; << c << endl;
                }
        }
        return 0;
}
