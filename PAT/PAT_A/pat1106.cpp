/*
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N-1, and the root supplier's ID is 0); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:

Ki ID[1] ID[2] ... ID[Ki]

where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. Kj being 0 means that the j-th member is a retailer. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the number of retailers that sell at the lowest price. There must be one space between the two numbers. It is guaranteed that the all the prices will not exceed 1010.

Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
Sample Output:
1.8362 2

*/

#include <vector>
#include <queue>
#include <stdio.h>
#include <math.h>

using namespace std;

const int max_n = 100000;
vector<int> G[max_n];

pair<int,int> bfs()
{
    queue<int> que;
    que.push(0);
    que.push(-1);
    int l = 0, cnt = 0;
    while (!que.empty()) {
        int p = que.front();
        que.pop();
        if (p < 0) {
            if (cnt) return make_pair(l, cnt);
            if (!que.empty()) {
                l++;
                que.push(-1);
            }
        }
        else {
            if (G[p].size() == 0) cnt++;
            for (auto i:G[p]) que.push(i);
        }
    }
}

int main()
{
    int m;
    double p, r;
    scanf("%d %lf %lf", &m, &p, &r);
    for (int i=0; i<m; ++i) {
        int a;
        scanf("%d", &a);
        for (int j=0; j<a; ++j) {
            int b;
            scanf("%d", &b);
            G[i].push_back(b);
        }
    }
    auto x = bfs();
    printf("%.4f %d\n", pow((100+r)/100,x.first)*p, x.second);
    return 0;

}