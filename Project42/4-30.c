////119小乐乐与字符串
////如ABC的子序列就有 A B C AB AC ABC
//#include<stdio.h>
//int main()
//{
//	char str[100] = { 0 };
//	scanf("%s", &str);
//	char* p = str;
//	long long int c = 0, ch = 0, chn = 0;
//	while (*p)
//	{
//		if (*p == 'C')
//		{
//			c++;
//		}
//		else if (*p == 'H')
//		{
//			ch += c;
//		}
//		else if (*p == 'N')
//		{
//			chn += ch;
//		}
//		p++;
//	}
//	printf("%ld",chn);
//	return 0;
//}
////小乐乐与二段数
//#include<stdio.h>
//int main()
//{
//
//	return 0;
//}
//超级圣诞树
//#include <stdio.h>
//
//int main()
//{
//
//	int i, j;
//	int k, h, n, z, s, m;
//	int rowbegin, rowend, rankbegin, rankend;
//
//	scanf("%d", &n);
//
//		int X = 3 * (1 << n - 1);
//	int Y = 5 * (1 << n - 1) + (1 << n - 1) - 1;
//
//	char b[10][10];//定义一个刚好可以存放图形的二维数组
//
//
//	for (i = 0; i < 10; i++)//将数组初始化，全为空格
//	{
//		for (j = 0; j < 10; j++)
//		{
//
//			b[i][j] = ' ';
//
//
//		}
//
//	}
//	for (i = 0; i < 3; i++)//将输入为 1 时的图形存放到数组内
//	{
//		for (j = 0; j < 5; j++)
//		{
//			if ((i == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0) || i == j)
//			{
//				b[i][j] = '*';
//			}
//			else
//			{
//				b[i][j] = ' ';
//			}
//
//		}
//
//	}
//
//	for (h = 0, z = 0, k = 0, s = 0, m = 0; s < n + n - 1; h++, z++, s++, k = 0)//控制循环的次数
//	{
//
//		if (z > 1)
//		{
//			z = 0;
//			h--;
//			k = h;
//			m = k;
//		}
//
//		rowbegin = (k > 0) * 3 * (1 << k - 1);//控制行的开始数值
//		rowend = 3 * (1 << m);//控制行的结束数值
//
//		rankbegin = (h > 0) * (5 * (1 << (h - 1)) + (1 << (h - 1))) - ((k > 0) << k - 1) * (3); //控制列的开始数值
//		rankend = 5 * (1 << h) + (1 << h) - 1 - ((k > 0) << k - 1) * (3);//控制列的结束数值
//
//		for (i = rowbegin; i < rowend; i++)
//		{
//			for (j = rankbegin; j < rankend; j++)
//			{
//				b[i][j] = b[i - rowbegin][j - rankbegin];
//			}
//		}
//	}
//
//
//	for (i = X - 1; i >= 0; i--)//输出树叶
//	{
//		for (j = Y - 1; j >= 0; j--)
//		{
//			printf("%c", b[i][j]);
//
//		}
//
//		putchar('\n');
//	}
//
//	for (i = 0; i < n; i++)//输出树干
//	{
//		for (j = 0; j < Y; j++)
//		{
//			printf("%c", b[X - 1][j]);
//		}
//
//		putchar('\n');
//	}
//
//	return 0;
//}
//'超级圣诞树(1-5)大于5时出现溢出
#include<stdio.h>
int main()
{
    int i, j;
    int k, h, n, z, s, m;
    int rowbegin, rowend, rankbegin, rankend;
    scanf("%d", &n);  //输入数值
    int X = 3 * (1 << n - 1);
    int Y = 5 * (1 << n - 1) + (1 << n - 1) - 1;
    char b[1000][1000] = { 0 };   //定义一个刚好可以存放图形的二维数组
    for (i = 0; i < X; i++)   //将数组初始化，全为空格
    {
        for (j = 0; j < Y; j++)
        {
            b[i][j] = ' ';
        }
    }
    for (i = 0; i < 3; i++)   //将输入为 1 时的图形存放到数组内
    {
        for (j = 0; j < 5; j++)
        {
            if ((i == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0) || i == j)
            {
                b[i][j] = '*';
            }
            else
            {
                b[i][j] = ' ';
            }
        }
    }
    for (h = 0, z = 0, k = 0, s = 0, m = 0; s < n + n - 1; h++, z++, s++, k = 0) //控制循环的次数
    {
        if (z > 1)
        {
            z = 0;
            h--;
            k = h;
            m = k;
        }
        rowbegin = (k > 0) * 3 * (1 << k - 1);  //控制行的开始数值
        rowend = 3 * (1 << m);     //控制行的结束数值
        rankbegin = (h > 0) * (5 * (1 << (h - 1)) + (1 << (h - 1))) - ((k > 0) << k - 1) * (3); //控制列的开始数值
        rankend = 5 * (1 << h) + (1 << h) - 1 - ((k > 0) << k - 1) * (3);     //控制列的结束数值
        for (i = rowbegin; i < rowend; i++)
        {
            for (j = rankbegin; j < rankend; j++)
            {
                b[i][j] = b[i - rowbegin][j - rankbegin];
            }
        }
    }
    for (i = X - 1; i >= 0; i--)    //输出树叶
    {
        for (j = Y - 1; j >= 0; j--)
        {
            printf("%c", b[i][j]);
        }
    putchar('\n');
    }

    for (i = 0; i < n; i++)    //输出树干
    {
        for (j = 0; j < Y; j++)
        {
            printf("%c", b[X - 1][j]);
        }
        putchar('\n');
    }
    return 0;
}