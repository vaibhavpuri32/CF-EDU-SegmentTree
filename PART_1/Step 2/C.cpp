#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
ll t[4000005];
void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = max(t[2 * v], t[2 * v + 1]);
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
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}

ll get(ll v, ll tl, ll tr, ll val)
{

    if (tl == tr)
        return tl;
    else
    {
        ll tm = (tl + tr) / 2;
        if (t[2 * v] >= val)
            return get(2 * v, tl, tm, val);
        else
            return get(2 * v + 1, tm + 1, tr, val);
    }
}

int main()
{
    ll i, n, m;
    cin >> n >> m;
    ll a[n + 5];
    ll Max = -inf;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        Max = max(Max, a[i]);
    }

    build(a, 1, 0, n - 1);
    while (m--)
    {
        ll x, y, z;
        cin >> x;
        if (x == 1)
        {
            cin >> y >> z;
            update(1, 0, n - 1, y, z);
        }
        else
        {
            cin >> y;
            if (y > t[1])
                cout << "-1\n";
            else
                cout << get(1, 0, n - 1, y) << "\n";
        }
    
    }

    return 0;
}