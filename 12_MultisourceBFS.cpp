/*
given "n" points on a plane (xi, yi)
For each point, find the nearest point with integer co-ordinates, that is not among the given "n" points.

#০১ : যাদের এডজাসেন্ট এ, এমন একটা সেল আছে যেটা ঐ সেটের অন্তর্ভুক্ত না, তাদের আনসার ১ দূরত্বে পাব।
#০২ : পরের ইটারেশন এ এইবার যাদের জন্য আনসার পাইছি, তাদের এডজাসেন্ট গুলার জন্য আনসার বের করবো।
    -> (xi, yi) এর জন্য যে আনসার হবে
    -> (xj, yj) যদি এডজাসেন্ট হয় (xi, yi) এর, তাহলে (xj, yj) এর জন্য আনসার (xi, yi) এর আনসার ই হবে।

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main()
{
    int n;
    cin >> n;
    vector<pll> a(n);
    for (auto &[x, y] : a)
        cin >> x >> y;
    set<pll> set(a.begin(), a.end());
    map<pll, pll> ans;
    queue<pll> q;

    for (auto [x, y] : a)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (!set.count({nx, ny}))
            {
                // #০১ : যাদের এডজাসেন্ট এ, এমন একটা সেল আছে যেটা ঐ সেটের অন্তর্ভুক্ত না, তাদের জন্য আনসার বের করতেছি।
                ans[{x, y}] = {nx, ny};
                q.push({x, y}); // -------------> Multi-Source
                break;
            }
        }
    }
    // #০২ : পরের ইটারেশন এ এইবার যাদের জন্য আনসার পাইছি, তাদের এডজাসেন্ট গুলার জন্য আনসার বের করবো।
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (set.count({nx, ny}) and !ans.count({nx, ny}))
            {
                ans[{nx, ny}] = ans[{x, y}];
                q.push({nx, ny});
            }
        }
    }

    for (auto p : a)
    {
        cout << ans[p].first << " " << ans[p].second << endl;
    }
}