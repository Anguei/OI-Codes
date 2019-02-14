#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string s,atn="";int n;char ss[1001];
void Un()
{
    printf("Unsuccessful @");
    cout<<atn<<"attempt\n";
    cout<<n<<endl;
    int i,ii=s.find(';:';);
    for(i=0;i<ii;i++)
    putchar(s[i]);
    //while(1);
}
void Su()
{
    printf("Successful @");
    cout<<atn<<"attempt\n";
    //while(1);
}
void Go()
{
    printf("Unsuccessful @");
    cout<<atn<<"attempt\n";
    cout<<n<<endl;
    puts("Good Queue Shape");
    //while(1);
}
int main()
{
    int i,ii;
    while(getline(cin,s))
    {
        if(s=="")break;
        if(s=="\r")break;
        n++;
        if(s[s.size()-1]==';\r';)s[s.size()-1]='; ';;
        s=s+"   ";//cout<<s[s.size()-1]<<endl;
        if(atn=="")
        {
            i=s.find("@yyy loves ")+1;
            ii=s.find('; ';,i+10);
            //cout<<i<<'; ';<<ii<<endl;
            for(;i<=ii;ii--)
            ss[ii-i]=s[ii];
            atn=ss;
            //cout<<ss<<endl;
        }
        else
        {
            if(s.find(atn)==-1){Un();return 0;}
            i=s.find(atn);
            if(i<s.find(';:';)){Su();return 0;}
            for(i=ii=s.find(';@';)+1;i<s.size();i=ii=s.find(';@';,i))
            while(s[i]!='; ';){if(s[i]!=atn[i-ii]){Un();return 0;}i++;}
        }
    }
    Go();
    return 0;
}