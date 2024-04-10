#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{ // **** IMPORTANT :: Use only one of the function for a object either union_by_rank or union_by_size().
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0); // work for both 1 base and zero bassed index
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int ultimate_parent(int node)
    { // if two elements are in the same component their ult_parent will be same
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = ultimate_parent(parent[node]);
    }
    void union_by_rank(int u, int v)
    {
        int ultp_u = ultimate_parent(u);
        int ultp_v = ultimate_parent(v);
        if (ultp_u == ultp_v)
            return;
        if (rank[ultp_u] < rank[ultp_v])
        {
            parent[ultp_u] = ultp_v;
        }
        else if (rank[ultp_u] > rank[ultp_v])
        {
            parent[ultp_v] = ultp_u;
        }
        else
        {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
    void union_by_size(int u, int v)
    {
        int ultp_u = ultimate_parent(u);
        int ultp_v = ultimate_parent(v);
        if (ultp_u == ultp_v)
            return;
        if (size[ultp_u] < size[ultp_v])
        {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        }
        else
        {
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
    }
};

int32_t main()
{

    int n;
    cin >> n;
    DisjointSet s1(n);
    return 0;
}