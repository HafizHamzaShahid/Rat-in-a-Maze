//Q1

#include<iostream>
#include"point.h"
#include<time.h>
#include"work.h"
#include"myconsole.h"
#include"mygraphics.h"
using namespace std;
//const int row = 7;
//const int col = 7;
void myBox1(int** arr, int i, int j, int X, int Y)
{
	//quee
	if (arr[i][j] % 2 == 0)
	{
		myRect(X, Y, X + 50, Y + 50, RGB(255, 255, 255), RGB(115, 145, 255));
		myRect(X + 20, Y + 20, X + 40, Y + 40, RGB(255, 255, 255), RGB(0, 0, 255));
		myDrawTextWithFont(X + 25, Y + 25, 10, "o", RGB(255, 255, 255), RGB(0, 0, 255));
	}
	if (arr[i][j] % 2 == 1)
	{
		myRect(X, Y, X + 50, Y + 50, RGB(255, 255, 255), RGB(250, 200, 155));
		myRect(X + 20, Y + 20, X + 40, Y + 40, RGB(255, 255, 255), RGB(0, 0, 255));
		myDrawTextWithFont(X + 25, Y + 25, 10, "o", RGB(255, 255, 255), RGB(0, 0, 255));
	}
}
void myBox(int** arr, int i, int j, int X, int Y)
{
	if (arr[i][j] == 1)
	{
		myRect(X, Y, X + 50, Y + 50, RGB(155,155,155), RGB(255, 0, 0));
	}
	if (arr[i][j] == -1)
	{
		myRect(X, Y, X + 50, Y + 50, RGB(155, 255, 155), RGB(255, 255, 255));
	}
	if (arr[i][j] == 0)
	{
		myRect(X, Y, X + 50, Y + 50, RGB(155, 255, 155), RGB(0, 255, 0));
	}
	if (arr[i][j] == 1050)
	{ 
		myRect(X, Y, X + 50, Y + 50, RGB(155, 255, 155), RGB(0, 200, 180));
		myRect(X + 20, Y + 20, X + 40, Y + 40, RGB(155, 255, 155), RGB(0, 0, 255));
		myDrawTextWithFont(X + 25, Y + 25, 10, "S", RGB(155, 255, 155), RGB(0, 0, 255));
	}
	if (arr[i][j] == 1100)
	{
		myRect(X, Y, X + 50, Y + 50, RGB(155, 255, 155), RGB(0, 0, 255));
		myRect(X+20, Y+20, X + 40, Y + 40, RGB(155, 255, 155), RGB(0, 0, 255));
		myDrawTextWithFont(X + 25, Y + 25, 10, "o", RGB(155, 255, 155), RGB(0, 0, 255));
	}
	
	if (arr[i][j] == 10)
	{
		myRect(X, Y, X + 50, Y + 50, RGB(155, 255, 155), RGB(199, 23, 255));
	}
}
void Menu()
{
	char str1[50] = { "RAT IN A MAZE" };
	myDrawTextWithFont(220, 160, 100, str1, RGB(255, 0, 0), RGB(255, 255, 255));
	Sleep(1000);
}

int main()
{
	Menu();
	Sleep(100);
	ClearScreen();


	int n, m;
	int** arr;
	
	myDrawTextWithFont(20, 50, 25, "Enter Size  : ", RGB(255, 0, 0), RGB(255, 255, 255));
	cout << endl<<endl<<endl<< "                  ";
	Sleep(100);
	cin >> n;

	arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;

		}
	}

	srand(time(0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = ((rand() % 2));
		}
		i++;

	}
	cout << endl << endl;
	myDrawTextWithFont(20, 100, 25, "Enter Starting Point : ", RGB(255, 0, 0), RGB(255, 255, 255));
	int s, t;
	cout << "                              ";
	cin >> s >> t;
	arr[s][t] = 1050;
	cout << endl << endl << endl;
	myDrawTextWithFont(20,150, 25, "Enter Ending Point : ", RGB(255, 0, 0), RGB(255, 255, 255));
	cout << "                                 ";
	int x, y;
	cin >> x >> y;
	arr[x][y] = 1100;

	//cout << "Grid Is \n";

	for (int i = 0, Y = 100; i < n; i++, Y += 51)
	{
		for (int j = 0, X = 100; j < n; j++, X += 51)
		{
			myBox(arr, i, j, X, Y);

		}
		cout << endl;
	}
	Sleep(100);

	//int i = s;
	//int j = t;

	////Stack base
	//Link_List<point>::Stack_Base sl;
	//point p(i, j);
	//int X = 100, Y = 100;
	//
	//for (int a = 0; a < n; a++, Y += 51)
	//{
	//	 X = 100;
	//	for (int b = 0; b < n; b++, X += 51)
	//	{
	//		if (a == s && b == t)
	//		{
	//			goto l;
	//		}
	//	}
	//}
 //   l:

	//while (arr[i][j] != 1100)
	//{
	//	Sleep(1000);

	//	if (j + 1 < n && arr[i][j + 1] != 1 && arr[i][j + 1] != -1 && arr[i][j + 1] != 1100)
	//	{
	//		j++;
	//		arr[i][j] = -1;
	//		p.set(i, j);
	//		sl.Push(p);
	//		X += 51;
	//		myBox(arr, i, j, X, Y);
	//		Sleep(200);

	//	}
	//	else if (j - 1 >= 0 && arr[i][j - 1] != 1 && arr[i][j - 1] != -1 && arr[i][j - 1] != 1100)
	//	{
	//		j--;
	//		arr[i][j] = -1;
	//		p.set(i, j);
	//		sl.Push(p);
	//		X -= 51;
	//		myBox(arr, i, j, X, Y);
	//		Sleep(200);
	//	}
	//	else if (i + 1 < n && arr[i + 1][j] != 1 && arr[i + 1][j] != -1 && arr[i + 1][j] != 1100)
	//	{
	//		
	//		i++;
	//		arr[i][j] = -1;
	//		p.set(i, j);
	//		sl.Push(p);
	//		Y += 51;
	//		myBox(arr, i, j, X, Y);
	//		Sleep(200);
	//	}
	//	else if (i - 1 >= 0 && arr[i - 1][j] != 1 && arr[i - 1][j] != -1 && arr[i - 1][j] != 1100)
	//	{
	//		
	//		i--;
	//		p.set(i, j);
	//		sl.Push(p);
	//		arr[i][j] = -1;
	//		Y -= 51;
	//		myBox(arr, i, j, X, Y);
	//		Sleep(200);
	//	}
	//	else if (arr[i][j] == 1100)
	//	{
	//		goto l4;
	//	}
	//	else 
	//	{
	//		arr[i][j] = 10;
	//		point p_1 = sl.pop();
	//		int w = p_1.getX();
	//		int v = p_1.getY();
	//		int A = 100;
	//		int B = 100;
	//		for (int a = 0; a < n; a++, A += 51)
	//		{
	//			int	B = 100;
	//			for (int B = 100, b = 0; b < n; b++, B += 51)
	//			{
	//				if (a == w && b == v)
	//				{
	//					myBox(arr, i, j, B, A);
	//					Sleep(200);
	//				}
	//			}
	//		}
	//		i = w;
	//		y = v;
	//	}
	//	
	//}
	//l4:
	//while (!sl.isEmpty())
	//{
	//	if (arr[i][j] != 1050)
	//	{
	//		point p_1 = sl.pop();
	//		int w = p_1.getX();
	//		int v = p_1.getY();
	//		int A = 100;
	//		int B = 100;
	//		for (int a = 0; a < n; a++, A += 51)
	//		{
	//			int	B = 100;
	//			for (int B = 100, b = 0; b < n; b++, B += 51)
	//			{
	//				if (a == w && b == v)
	//				{
	//					myBox(arr, i, j, B, A);
	//					Sleep(200);
	//				}
	//			}
	//		}
	//		i = w;
	//		y = v;
	//	}
	//}


	///Quee Base

	//Grid

    Sleep(2500);
	for (int i = 0, Y = 100; i < n; i++, Y += 51)
	{
		for (int j = 0, X = 800; j < n; j++, X += 51)
		{
			myBox(arr, i, j, X, Y);

		}
		cout << endl;
	}
	Sleep(1000);

	Link_List<point>::Quee_Base ql;
	

	int P = 800, Q = 100;
	
	for (int a = 0; a < n; a++, Q += 51)
	{
		P = 800;
		for (int b = 0; b < n; b++, P += 51)
		{
			if (a == s && b == t)
			{
				goto l6;
			}
		}
	}
	l6:
	int pq = 2;
	int i1 = s;
	int j1 = t;
	point p1(i1, j1);
	ql.Enquee(p1);
	while (arr[i1][j1] != 1100)
	{
	  
	    point p1 = ql.Dequee();
		i1 = p1.getX();
		j1 = p1.getY();
		Sleep(1000);
		
		if (j1 + 1 < n && arr[i1][j1 + 1] != 1 && arr[i1][j1 + 1] != 1050 && arr[i1][j1 + 1] != 1100)
		{
			j1++;
			arr[i1][j1] = pq;
			p1.set(i1, j1);
			ql.Enquee(p1);
			P += 51;
			myBox1(arr, i1, j1, P, Q);
			Sleep(200);

		}
		if (j1 - 1 >= 0 && arr[i1][j1 - 1] != 1 && arr[i1][j1 - 1] != 1050 && arr[i1][j1 - 1] != 1100)
		{
			j1--;
			arr[i1][j1] = pq;
			p1.set(i1, j1);
			ql.Enquee(p1);
			P -= 51;
			myBox1(arr, i1, j1, P, Q);
			Sleep(200);
		}
		if (i1 + 1 < n && arr[i1 + 1][j1] != 1 && arr[i1 + 1][j1] != 1050 && arr[i1 + 1][j1] != 1100)
		{
			i1++;
			arr[i1][j1] = pq;
			p1.set(i1, j1);
			ql.Enquee(p1);
			Q += 51;
			myBox1(arr, i1, j1, P, Q);
			Sleep(200);
		}
		if (i1 - 1 >= 0 && arr[i1 - 1][j1] != 1 && arr[i1 - 1][j1] != 1050 && arr[i1 - 1][j1] != 1100)
		{
			i1--;
			p1.set(i1, j1);
			ql.Enquee(p1);
			arr[i1][j1] = pq;
			Q -= 51;
			myBox1(arr, i1, j1, P, Q);
			Sleep(200);
		}

		 pq++;
	}

	int pq_1 = pq;
	int i2 = s;
	int j2 = t;

	while (arr[i2][j2] != 1050)
	{
		point p_2 = ql.Dequee();
		int i2 = p_2.getX();
		int j2 = p_2.getY();
		int A = 100;
		int B = 800;
		for (int a = 0; a < n; a++, A += 51)
		{
			int	B = 800;
			for (int B = 100, b = 0; b < n; b++, B += 51)
			{
				if (a == i2 && b == j2)
				{
					myBox(arr, i2, j2, B, A);
					Sleep(200);
				}
			}
		}

	}
	system("pause");
	return 0;
}