//1:����һ��8��8�е�������
 #include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

//��ӡ��ͼ
/*2:��Ϸ5��Ԫ��
2.1 : �յ�       0��ʾ�յ�
2.2 : ����       5��ʾ����
2.3 : Ŀ�ĵ�    3��ʾĿ�ĵ�
2.4 : ǽ          1��ʾǽ
2.5 : ����       4��ʾ����
�ڼ򵥹ؿ���,ֻ����:
1:�˵���ǰ�ǿյ�
******************************
2:�˵�ǰ��������,���ӵ�ǰ����Ŀ�ĵ�
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
			case 1:cout << "��"; break;
			case 3:cout << "��"; break;
			case 4:cout << "��"; break;
			case 5:cout << "��"; break;
			case 7:cout << "��"; break;//4+3����+Ŀ�ĵ�
			case 8:cout << "��"; break; //5+3��+Ŀ�ĵ�
				
			}
		}
		cout << endl;
	}
}


void PlayGame()
{	
	//��ȡ����ǰ�˵��±�
	int row, col;  //�˵��к���   ʱ�̶��ܹ�ȷ���˵��±�
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

	/*�������� :���ĵط�----->��--->����
	��ô��:�������
	1:��Ҫ����:��������
	2:���ݲ�ͬ��λ�İ�������ͬ�Ĵ���
	*/
	char input;
	input = _getch();   //�������ܼ�������
	//getchar()��ʾ����  ����enter���������  getch()����ʾ����,�������Ͻ���
	switch (input)
	{
	case 'w':  //��
	case 'W':
	case 72:
		if (map[row - 1][col] == 0 || map[row - 1][col] ==3)  //����˵�ǰ���ǿյ�
		{
			map[row][col] -= 5;
			map[row - 1][col] += 5;
		}
		else if (map[row - 1][col] == 4 || map[row -1][col] == 7)  //����˵�ǰ��������,���Ӻ�����Ŀ�ĵ�
		{
			if (map[row - 2][col] == 0 || map[row - 2][col] == 3) //����ǰ���ǿյ�
			{
				map[row - 2][col] += 4;
				map[row - 1][col] += 1;
				map[row][col] -= 5;
			}
	
		}
		break;
	case 's':  //��
	case 'S':
	case 80: 
		if (map[row + 1][col] == 0 || map[row - 1][col] == 3)  //����˵�ǰ���ǿյ�
		{
			map[row][col] -= 5;
			map[row + 1][col] += 5;
		}
		else if (map[row + 1][col] == 4 || map[row + 1][col] == 7)  //����˵�ǰ��������,���Ӻ�����Ŀ�ĵ�
		{
			if (map[row + 2][col] == 0 || map[row + 2][col] == 3) //����ǰ���ǿյ�
			{
				map[row + 2][col] += 4;
				map[row + 1][col] += 1;
				map[row][col] -= 5;
			}

		}
		break;
	case 'a':  //��
	case 'A':
	case 75:
		if (map[row][col - 1] == 0 || map[row][col - 1] == 3)  //����˵�ǰ���ǿյ�
		{
			map[row][col] -= 5;
			map[row][col - 1] += 5;
		}
		else if (map[row][col - 1] == 4 || map[row][col - 1] == 7)  //����˵�ǰ��������,���Ӻ�����Ŀ�ĵ�
		{
			if (map[row][col - 2] == 0 || map[row][col - 2] == 3) //����ǰ���ǿյ�
			{
				map[row][col - 2] += 4;
				map[row][col - 1] += 1;
				map[row][col] -= 5;
			}

		}
		break;
	case 'd':  //��
	case 'D':
	case 77:
		if (map[row][col + 1] == 0 || map[row][col + 1] == 3)  //����˵�ǰ���ǿյ�
		{
			map[row][col] -= 5;
			map[row][col + 1] += 5;
		}
		else if (map[row][col + 1] == 4 || map[row][col + 1] == 7)  //����˵�ǰ��������,���Ӻ�����Ŀ�ĵ�
		{
			if (map[row][col + 2] == 0 || map[row][col + 2] == 3) //����ǰ���ǿյ�
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
	//���ñ���
	SetConsoleTitle("������");
	//���ô��ڵĴ�С
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