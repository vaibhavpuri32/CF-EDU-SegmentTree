#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll t[40000005];
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
    ll i, n;
    cin >> n;
    n = 2 * n;

    ll a[n + 5], b[n + 5];

    map<ll, vector<ll>> m;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = 0;
    }

    build(b, 1, 0, n - 1);

    for (i = 0; i < n; i++)
    {
        m[a[i]].push_back(i);
    }
    ll ans[n + 19];
    for (i = 0; i < n; i++)
    {
        if (m[a[i]][0] == i)
        {
            ans[a[i]] = sum(1, 0, n - 1, m[a[i]][0], m[a[i]][1]);
            update(1, 0, n - 1, m[a[i]][1], 1);
        }
        else if (m[a[i]][1] == i)
        {
            update(1, 0, n - 1, m[a[i]][1], 0);
        }
    }

    for (i = 0; i < n + 2; i++)
        b[i] = 0;
    build(b, 1, 0, n - 1);
    m.clear();
    reverse(a, a + n);

    for (i = 0; i < n; i++)
    {
        m[a[i]].push_back(i);
    }

    for (i = 0; i < n; i++)
    {
        if (m[a[i]][0] == i)
        {
            ans[a[i]] = ans[a[i]] + sum(1, 0, n - 1, m[a[i]][0], m[a[i]][1]);
            update(1, 0, n - 1, m[a[i]][1], 1);
        }
        else if (m[a[i]][1] == i)
        {
            update(1, 0, n - 1, m[a[i]][1], 0);
        }
    }

    for (i = 1; i <= n / 2; i++)
        cout << ans[i] << " ";

    return (0);
}