#include <bits/stdc++.h>
using std::cout;
using std::vector;
using std::pair;
using std::string;
namespace dbg
{
    template<typename T>
    void print(vector<T> v)
    {
        for(int i = 0; i < v.size()-1; i++)
        {
            cout<<v[i]<<" ";
        }
        if(!v.empty())
        {
            cout<<v.back();
        }
    }
    template<typename T, typename U>
    void print(pair<T, U> p)
    {
        cout<<p.first<<" "<<p.second;
    }
    template<typename T>
    void print(T x)
    {
        cout<<x;
    }
    template<typename T>
    void covered(T x, pair<string, string> around)
    {
        cout<<around.first;
        print(x);
        cout<<around.second;
    }

    template<typename T>
    void box(T x)
    {
        covered(x, {"[", "]"});
    }

    template<typename T>
    void boxnl(T x)
    {
        box(x);
        cout<<"\n";
    }

    template<typename T>
    void curly(T x)
    {
        covered(x, {"{", "}"});
    }
    template<typename T>
    void curlynl(T x)
    {
        curly(x);
        cout<<"\n";
    }

    template<typename T>
    void round(T x)
    {
        covered(x, {"(", ")"});
    }
    template<typename T>
    void roundnl(T x)
    {
        round(x);
        cout<<"\n";
    }
}
