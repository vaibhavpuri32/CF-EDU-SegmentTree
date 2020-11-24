#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
ll t[4000005];
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

ll get(ll v, ll tl, ll tr, ll pos)
{
    if (tl == tr)
        return tl;
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= t[2 * v])
            return get(2 * v, tl, tm, pos);
        else
            return get(2 * v + 1, tm + 1, tr, pos - t[2 * v]);
    }
}
int main()
{
    ll i, n;
    cin >> n;
    ll a[n + 5], b[n + 5];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = 1;
    }
    build(b, 1, 0, n - 1);
    ll ans[n + 5];
    for (i = n - 1; i >= 0; i--)
    {
        ll pos = (i + 1 - a[i] - 1);
        ll k = get(1, 0, n - 1, pos + 1);
        ans[i] = k + 1;
        //cout << "k is " << k << "\n";
        update(1, 0, n - 1, k, 0);
    }

    for (i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout<<"\n";

    return (0);
}