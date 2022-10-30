#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
ll t[400005];
bool marked[400005];

void push(int v) 
{
    if (marked[v]) {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val)
{
    if (l > r)
        return;
    if (l == tl && tr == r)
    {
        t[v] = new_val;
        marked[v] = true;
    }
    else
    {
        push(v);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), new_val);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, new_val);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
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
            update(1, 0, n - 1, l, r, v);
        }
        else
        {
            ll y;
            cin >> y;
            cout << get(1, 0, n - 1, y) << "\n";
        }
    }

    return (0);
}
