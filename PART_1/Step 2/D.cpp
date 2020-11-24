#include <bits/stdc++.h>
using namespace std;
#define ll long long int
pair<ll, ll> t[4000005];
void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v].first = a[tl];
        t[v].second = tr;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v].first = max(t[2 * v].first, t[2 * v + 1].first);
        t[v].second = tr;
    }
}

void update(ll v, ll tl, ll tr, ll pos, ll val)
{
    if (tl == tr)
    {
        t[v].first = val;
        t[v].second = tr;
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
        t[v].first = max(t[2 * v].first, t[2 * v + 1].first);
        t[v].second = tr;
    }
}
ll ans = -1;
void get(ll v, ll tl, ll tr, ll val, ll pos)
{
    if (ans != -1)
        return;
    if (tl == tr)
    {
        ans = tl;
        return;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (t[2 * v].first >= val && t[2 * v].second >= pos)
        {
            get(2 * v, tl, tm, val, pos);
            if (ans != -1)
                return;
        }
        if (t[2 * v + 1].first >= val && t[2 * v + 1].second >= pos)
        {
            get(2 * v + 1, tm + 1, tr, val, pos);
            if (ans != -1)
                return;
        }
    }
}

int main()
{
    ll i, n, m;
    cin >> n >> m;
    ll a[n + 5];
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

            get(1, 0, n - 1, y, z);
            if (t[1].first < y)
                cout << "-1\n";
            else
                cout << ans << "\n";
            ans = -1;
        }
    }

    return (0);
}