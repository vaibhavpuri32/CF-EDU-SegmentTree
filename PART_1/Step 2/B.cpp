#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
ll t[4000006];

void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
        t[v] = a[tl];
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void update(ll v, ll tl, ll tr, ll pos)
{
    if (tl == tr)
        t[v] = 1 - t[v];
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(2 * v, tl, tm, pos);
        }
        else
        {
            update(2 * v + 1, tm + 1, tr, pos);
        }
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll get(ll v, ll tl, ll tr, ll k)
{
    if (tl == tr)
    {
        return tl;
    }
    ll tm = (tl + tr) / 2;
    if (k <= t[2 * v])
    {
        return get(2 * v, tl, tm, k);
    }
    else
    {
        return get(2 * v + 1, tm + 1, tr, k - t[2 * v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, n, m;
    cin >> n >> m;
    ll a[n + 8];
    for (i = 0; i < n; i++)
        cin >> a[i];
    build(a, 1, 0, n - 1);
    while (m--)
    {
        ll x, y, z;
        cin >> x >> y;
        if (x == 1)
        {
            update(1, 0, n - 1, y);
        }
        else
        {
            ll ans = get(1, 0, n - 1, y+1);
            cout << ans << "\n";
        }
    }
    return (0);
}