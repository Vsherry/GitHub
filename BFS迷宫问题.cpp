#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;

class Point
{
public:
	Point(int x = -1, int y = -1, int p_v = 0,bool f = false)
	{
		m_x = x;
		m_y = y;
		m_f = f;
		m_value = p_v;
	}
	Point(const Point& item)
	{
		m_x = item.m_x;
		m_y = item.m_y;
		m_f = item.m_f;
		m_value = item.m_value;
	}
	bool operator ==(const Point& item)
	{
		if (m_x == item.m_x && m_y == item.m_y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator !=(const Point& item)
	{
		if (*this == item)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	void operator =(const Point& item)
	{
		m_x = item.m_x;
		m_y = item.m_y;
		m_value = item.m_value;
	}
	void setFlag(bool temp)
	{
		m_f = temp;
	}
	void setValsue(int p_x, int p_y, int p_v)
	{
		m_x = p_x;
		m_y = p_y;
		m_value = p_v;
	}
protected:

public:
	int m_x;
	int m_y;
	int m_value;
	bool m_f;
};

void bfs(vector<vector<Point>>& chart, vector<Point>& route);

int main()
{
	int m;
	int n;
	while (cin >> m >> n)
	{
		vector<vector<Point>> chart(m,vector<Point>(n,Point(-1,-1)));
		vector<Point> route;
		int flag = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int temp = 0;
				cin >> temp;
				chart[i][j].setValsue(i, j, temp);
			}
		}
		bfs(chart, route);
		if (!route.empty())
		{
			for (int i = route.size() - 1; i >= 0; i--)
			{
				cout << "(" << route[i].m_x << "," << route[i].m_y << ")" << endl;
			}
		}
	}
	return 0;
}

void bfs(vector<vector<Point>>& chart, vector<Point>& route)
{
	int m = chart.size();
	int n = chart[0].size();
	Point startPoint = chart[0][0];
	Point endPoint = chart[m - 1][n - 1];
	//mark标记每一个节点的前驱节点，如果没有则为（-1，-1），如果有则表示已经被访问
	Point** mark = new Point*[m];
	for (int i = 0; i < m; i++)
	{
		mark[i] = new Point[n];
	}

	queue<Point> queuePoint;
	queuePoint.push(startPoint);
	mark[startPoint.m_x][startPoint.m_y] = startPoint;

	//当队列不为空时执行这样的操作
	while (!queuePoint.empty())
	{
		//首先将队列顶部元素取出来,并出队列
		Point pointFront = queuePoint.front();
		queuePoint.pop();

		//根据条件判断是否满足要求，将满足要求的点放入队列中
		//判断点是否被访问过，如果已经访问过则不做任何操作
		if (pointFront.m_x - 1 >= 0 && chart[pointFront.m_x - 1][pointFront.m_y].m_value == 0)  //向上遍历
		{
			if (mark[pointFront.m_x - 1][pointFront.m_y] == Point())
			{
				mark[pointFront.m_x - 1][pointFront.m_y] = pointFront;
				queuePoint.push(Point(pointFront.m_x - 1, pointFront.m_y));
				if (Point(pointFront.m_x - 1, pointFront.m_y) == endPoint)
				{
					break;
				}
			}
		}

		if (pointFront.m_y - 1 >= 0 && chart[pointFront.m_x][pointFront.m_y - 1].m_value == 0)  //向左访问
		{
			if (mark[pointFront.m_x][pointFront.m_y - 1] == Point())
			{
				mark[pointFront.m_x][pointFront.m_y - 1] = pointFront;
				queuePoint.push(Point(pointFront.m_x, pointFront.m_y - 1));
				if (Point(pointFront.m_x, pointFront.m_y - 1) == endPoint)
				{
					break;
				}
			}
		}

		if (pointFront.m_y + 1 < n && chart[pointFront.m_x][pointFront.m_y + 1].m_value == 0)  //向右访问
		{
			if (pointFront.m_x == 2 && pointFront.m_y == 2)
			{
				double l = 0;
			}
			if (mark[pointFront.m_x][pointFront.m_y + 1] == Point())
			{
				mark[pointFront.m_x][pointFront.m_y + 1] = pointFront;
				queuePoint.push(Point(pointFront.m_x, pointFront.m_y + 1));
				if (Point(pointFront.m_x, pointFront.m_y + 1) == endPoint)
				{
					break;
				}
			}
		}

		if (pointFront.m_x + 1 < m && chart[pointFront.m_x + 1][pointFront.m_y].m_value == 0)  //向下访问
		{
			if (mark[pointFront.m_x + 1][pointFront.m_y] == Point())
			{
				mark[pointFront.m_x + 1][pointFront.m_y] = pointFront;
				queuePoint.push(Point(pointFront.m_x + 1, pointFront.m_y));
				if (Point(pointFront.m_x + 1, pointFront.m_y) == endPoint)
				{
					break;
				}
			}
		}
	}
	//根据本前驱节点所在的二维数组得到最终的路径数据
	if (queuePoint.empty() == false)
	{
		int row = endPoint.m_x;
		int col = endPoint.m_y;
		int temp1 = 0;
		int temp2 = 0;
		route.push_back(endPoint);
		while (!(mark[row][col] == startPoint))
		{
			route.push_back(mark[row][col]);
			temp1 = mark[row][col].m_x;
			temp2 = mark[row][col].m_y;
			row = temp1;
			col = temp2;
		}
		route.push_back(startPoint);
	}
}
