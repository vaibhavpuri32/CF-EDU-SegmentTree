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
        t[v] = t[2 * v] + t[2 * v + 1];
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
        {
            update(2 * v, tl, tm, pos, val);
        }
        else
        {
            update(2 * v + 1, tm + 1, tr, pos, val);
        }
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
    ll c[n + 5], a[n + 5], b[n + 5], ans[n + 5];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        c[i] = a[i];
        b[i] = 0;
    }
    sort(c, c + n);

    build(b, 1, 0, n - 1);
    map<ll, ll> pos;

    for (i = 0; i < n; i++)
        pos[c[i]] = i;

    for (i = 0; i < n; i++)
    {
        if (a[i] == n)
        {
            ans[i] = 0;
        }
        else
        {
            ans[i] = sum(1, 0, n - 1, a[i], n - 1);
        }
        update(1, 0, n - 1, a[i] - 1, 1);
    }

    for (i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";

    return (0);
}