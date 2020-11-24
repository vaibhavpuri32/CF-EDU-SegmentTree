#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll t[4000005];
void build(ll b[], ll v, ll tl, ll tr)
{
    if (tl == tr)
        t[v] = b[tl];
    else
    {
        ll tm = (tl + tr) / 2;
        build(b, 2 * v, tl, tm);
        build(b, 2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v + 1] + t[2 * v];
    }
}

void update(ll v, ll tl, ll tr, ll pos, ll val)
{
    if (tl == tr)
    {
        t[v] = val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}
ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
    {
        return 0;
    }
    if (tl == l && tr == r)
        return t[v];
    ll tm = (tl + tr) / 2;
    return (sum(2 * v, tl, tm, l, min(tm, r)) + sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main()
{
    ll i, n, m;
    cin >> n >> m;
    ll a[n + 5];
    for (i = 0; i <= n + 2; i++)
        a[i] = 0;
    build(a, 1, 0, n);

    for (i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            a[x] = a[x] + z;
            update(1, 0, n, x, a[x]);
            a[y] = a[y] - z;
            update(1, 0, n, y, a[y]);
        }
        else
        {
            ll z;
            cin >> z;
            cout << sum(1, 0, n, 0, z) << "\n";
        }
    }

    return (0);
}