#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
pair<ll, ll> t[4000005];
void add(ll v, ll tl, ll tr, ll l, ll r, ll val)
{
    if (l > r || tl > tr)
        return;
    if (tl >= l && tr <= r)
    {
        t[v].second = t[v].second + val;
        t[v].first = t[v].first + val;
        return;
    }
    ll tm = (tl + tr) / 2;

    add(2 * v, tl, tm, l, min(tm, r), val);
    add(2 * v + 1, tm + 1, tr, max(tm + 1, l), r, val);
    t[v].second = min(t[2 * v].second, t[2 * v + 1].second) + t[v].first;
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return inf;
    if (l == tl && r == tr)
        return t[v].second;
    ll tm = (tl + tr) / 2;
    auto t1 = get(2 * v, tl, tm, l, min(tm, r));
    auto t2 = get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    return min(t1, t2) + t[v].first;
}

int main()
{
    ll i, n, m;
    cin >> n >> m;
    while (m--)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll l, r, v;
            cin >> l >> r >> v;
            r--;
            add(1, 0, n - 1, l, r, v);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            r--;
            cout << get(1, 0, n - 1, l, r) << "\n";
        }
    }

    return (0);
}
