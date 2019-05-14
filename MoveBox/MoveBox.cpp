//1:定义一个8行8列的推箱子
 #include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

//打印地图
/*2:游戏5个元素
2.1 : 空地       0表示空地
2.2 : 人物       5表示人物
2.3 : 目的地    3表示目的地
2.4 : 墙          1表示墙
2.5 : 箱子       4表示箱子
在简单关卡下,只考虑:
1:人的面前是空地
******************************
2:人的前面是箱子,箱子的前面是目的地
********************************/
int map[8][8] = {
	{ 0, 0, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 1, 3, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 1, 1, 1, 1 },
	{ 1, 1, 1, 4, 0, 4, 3, 1 },
	{ 1, 3, 0, 4, 5, 1, 1, 1 },
	{ 1, 1, 1, 1, 4, 1, 0, 0 },
	{ 0, 0, 0, 1, 3, 1, 0, 0 },
	{ 0, 0, 0, 1, 1, 1, 0, 0 }
};

void DrawMap(){
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++){
			switch (map[i][j])
			{
			case 0:cout << "  "; break;
			case 1:cout << "■"; break;
			case 3:cout << "●"; break;
			case 4:cout << "☆"; break;
			case 5:cout << "♂"; break;
			case 7:cout << "★"; break;//4+3箱子+目的地
			case 8:cout << "♂"; break; //5+3人+目的地
				
			}
		}
		cout << endl;
	}
}


void PlayGame()
{	
	//获取到当前人的下标
	int row, col;  //人的行和列   时刻都能够确定人的下标
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[i][j] == 5 || map[i][j] == 8)
			{
				row = i;
				col = j;
			}
		}
	}
	cout << row << col;

	/*按键处理 :动的地方----->人--->找人
	怎么动:数组操作
	1:需要按键:上下左右
	2:根据不同方位的按键做不同的处理
	*/
	char input;
	input = _getch();   //变量接受键盘输入
	//getchar()显示回文  按下enter键接受完成  getch()不显示回文,按下马上接受
	switch (input)
	{
	case 'w':  //上
	case 'W':
	case 72:
		if (map[row - 1][col] == 0 || map[row - 1][col] ==3)  //如果人的前面是空地
		{
			map[row][col] -= 5;
			map[row - 1][col] += 5;
		}
		else if (map[row - 1][col] == 4 || map[row -1][col] == 7)  //如果人的前面是箱子,箱子后面是目的地
		{
			if (map[row - 2][col] == 0 || map[row - 2][col] == 3) //箱子前面是空地
			{
				map[row - 2][col] += 4;
				map[row - 1][col] += 1;
				map[row][col] -= 5;
			}
	
		}
		break;
	case 's':  //下
	case 'S':
	case 80: 
		if (map[row + 1][col] == 0 || map[row - 1][col] == 3)  //如果人的前面是空地
		{
			map[row][col] -= 5;
			map[row + 1][col] += 5;
		}
		else if (map[row + 1][col] == 4 || map[row + 1][col] == 7)  //如果人的前面是箱子,箱子后面是目的地
		{
			if (map[row + 2][col] == 0 || map[row + 2][col] == 3) //箱子前面是空地
			{
				map[row + 2][col] += 4;
				map[row + 1][col] += 1;
				map[row][col] -= 5;
			}

		}
		break;
	case 'a':  //左
	case 'A':
	case 75:
		if (map[row][col - 1] == 0 || map[row][col - 1] == 3)  //如果人的前面是空地
		{
			map[row][col] -= 5;
			map[row][col - 1] += 5;
		}
		else if (map[row][col - 1] == 4 || map[row][col - 1] == 7)  //如果人的前面是箱子,箱子后面是目的地
		{
			if (map[row][col - 2] == 0 || map[row][col - 2] == 3) //箱子前面是空地
			{
				map[row][col - 2] += 4;
				map[row][col - 1] += 1;
				map[row][col] -= 5;
			}

		}
		break;
	case 'd':  //右
	case 'D':
	case 77:
		if (map[row][col + 1] == 0 || map[row][col + 1] == 3)  //如果人的前面是空地
		{
			map[row][col] -= 5;
			map[row][col + 1] += 5;
		}
		else if (map[row][col + 1] == 4 || map[row][col + 1] == 7)  //如果人的前面是箱子,箱子后面是目的地
		{
			if (map[row][col + 2] == 0 || map[row][col + 2] == 3) //箱子前面是空地
			{
				map[row][col + 2] += 4;
				map[row][col + 1] += 1;
				map[row][col] -= 5;
			}

		}
		break;
	}

}

int main(){
	//设置标题
	SetConsoleTitle("推箱子");
	//设置窗口的大小
	system("mode con cols=26 lines=12");
	while (1)
	{
		system("CLS");
		DrawMap();
		PlayGame();
	}
	//system("pause");
	return 0;

}