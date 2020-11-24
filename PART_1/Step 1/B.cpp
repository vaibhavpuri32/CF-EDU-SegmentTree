#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
ll t[400200];
void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
        t[v] = a[tl];
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
    
}
void update(ll v, ll tl, ll tr, ll pos, ll val)
{
    if (tl == tr)
        t[v] = val;
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(2 * v, tl, tm, pos, val);
        }
        else
        {
            update(2 * v + 1, tm + 1, tr, pos, val);
        }
        t[v] = min(t[2 * v],t[2 * v + 1]);
    }
}

ll MinSeg(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
    {
        return inf;
    }
    if (tl == l && r == tr)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return (min(MinSeg(2 * v, tl, tm, l, min(r, tm)), MinSeg(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)));
}
int main()
{
    ll i, j, n, m;
    cin >> n >> m;
    ll a[n + 5];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(a, 1, 0, n - 1);
    while (m--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            update(1, 0, n - 1, y, z);
        }
        else
        {
            z--;
            cout << MinSeg(1, 0, n - 1, y, z) << "\n";
        }

        /*for(i=1; i<=9; i++)
          cout<<t[i]<<" "; 
          cout<<"\n"*/
    }

    return (0);
}
