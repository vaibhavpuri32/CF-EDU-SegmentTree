#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
pair<ll, ll> t[4000005];

pair<ll, ll> merge(pair<ll, ll> &a, pair<ll, ll> &b)
{
    pair<ll, ll> temp;
    if (a.first == b.first)
    {
        temp.first = a.first;
        temp.second = a.second + b.second;
    }
    else if (a.first < b.first)
    {
        temp = a;
    }
    else
    {
        temp = b;
    }
    return temp;
}

void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v].first = a[tl];
        t[v].second = 1;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);

        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

void update(ll v, ll tl, ll tr, ll pos, ll val)
{
    if (tl == tr)
    
    {
        t[v].first = val;
        t[v].second = 1;
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
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

pair<ll, ll> get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return {inf, 0};
    if (tl > r || tr < l)
        return {inf, 0};
    if (tl >= l && tr <= r)
        return t[v];
    ll tm = (tl + tr) / 2;
    pair<ll, ll> a = get(2 * v, tl, tm, l, r);
    pair<ll, ll> b = get(2 * v + 1, tm + 1, tr, l, r);
    pair<ll, ll> ans = merge(a, b);
    return ans;
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
        cin >> x >> y >> z;
        if (x == 1)
        {
            update(1, 0, n - 1, y, z);
        }
        else
        {
            z--;
            cout << get(1, 0, n - 1, y, z).first << "  " << get(1, 0, n - 1, y, z).second << "\n";
        }
    }
    return (0);
}