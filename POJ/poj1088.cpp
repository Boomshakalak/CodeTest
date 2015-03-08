/*
Description

Michaelϲ����ѩ���Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б�����ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael��֪����һ����������׻��¡�������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�������һ������ 
 1  2  3  4 5

16 17 18 19 6

15 24 25 20 7

14 23 22 21 8

13 12 11 10 9

һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�һ���ɻ��еĻ���Ϊ24-17-16-1����Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ����
Input

����ĵ�һ�б�ʾ���������R������C(1 <= R,C <= 100)��������R�У�ÿ����C������������߶�h��0<=h<=10000��
Output

��������ĳ��ȡ�
Sample Input

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
Sample Output

25
*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int	max_n = 105;
int			h[max_n][max_n];
int			r, c;
int			dat[max_n][max_n];

int dp(int x, int y) {
	if (dat[x][y] > 0)
		return dat[x][y];
	int ans = 1;
	if (x > 0 && h[x][y] > h[x-1][y])
		ans = max(dp(x-1, y)+1, ans);
	if (x < r-1 && h[x][y] > h[x+1][y])
		ans = max(dp(x+1, y)+1, ans);
	if (y > 0 && h[x][y] > h[x][y-1])
		ans = max(dp(x, y-1)+1, ans);
	if (y < c-1 && h[x][y] > h[x][y+1])
		ans = max(dp(x, y+1)+1, ans);
	dat[x][y] = ans;
	return ans;
}
int main()
{
	scanf("%d%d", &r, &c);
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			scanf("%d", &h[i][j]);
	int ans = 0;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			ans = max(ans, dp(i, j));
	printf("%d\n", ans);
	return 0;
}