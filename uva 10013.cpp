#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int c = 0;
void fun(int x,int y,int i)
{
    int sum = 0;
    if(c==0)
        sum = x+y;
    else
    {
        sum = x+y+c;
        if(i==0)
        {
            v.push_back(sum);
            return;
        }
        c = 0;
    }
    if(sum>=10)
    {
        int mod = sum%10;
        c = sum/10;
        v.push_back(mod);
    }
    else
        v.push_back(sum);
}

int main()
{
    int t,tt,x,y;
    cin >> t;
    vector<pair<int,int>>vec;
    for(int i=0;i<t;i++)
    {
        cin >> tt;
        for(int i=0;i<tt;i++)
        {
            cin >> x>> y;
            int sum = x+y;
            vec.push_back(make_pair(x,y));
        }
        for(int i=vec.size()-1;i>=0;i--)
            fun(vec[i].first,vec[i].second,i);
        for(int i=v.size()-1;i>=0;i--)
            cout << v[i];

        if(i!=t-1)
            cout << endl;

        cout << endl;
        vec.clear();
        v.clear();
        c = 0;
    }
}
