#include <bits/stdc++.h>
using namespace std;
class SGTree
{
    vector<int> seg, lazy;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r)
    {

        // update if any updates are remaining
        // as the node will stay fresh and updated
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];
            // propragate downward
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        // no overlap
        // l r low high or low high l r
        if (r < low || high < l)
            return 0;

        // complete overlap
        if (low >= l && high <= r)
            return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
    void update(int ind, int low, int high, int l, int r, int val)
    {
        // update the prev remaing update
        // and propragate downwards
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];
            // propragate downward
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // no overlap
        if (high < l || r < low)
        {
            return;
        }
        // complete overlap
        // l low high r
        if (low >= l && high <= r)
        {
            seg[ind] += (high - low + 1) * val;
            // if a leaf noe, it will have children
            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        // last case has to be no overlap case
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};
