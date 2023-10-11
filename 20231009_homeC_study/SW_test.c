
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>  //�ð����� �Լ��� �����ϴ� ���
#include <windows.h> //Sleep �Լ��� �����ϴ� ���

void printTime(struct tm* t1);										 //�ð��� ����ϴ� �Լ� ����
void arrIn(char* clockDigits, int digit, int beginNumber);		//�迭�� �迭�� �־��ִ� �Լ� ����
int main()
{
	time_t curr;
	struct tm* curTime;

	int isRunning = 0; // ��ž��ġ ���� ���θ� ��Ÿ���� ����
	DWORD startTime = 0; // ��ž��ġ ���� �ð��� �����ϴ� ����
	DWORD elapsedTime = 0; // ��� �ð��� �����ϴ� ����

	do
	{
		time(&curr); //����Ÿ��
		curTime = localtime(&curr);

		// ��, ��, �ʸ� 0���� ����
		curTime->tm_hour = 0;
		curTime->tm_min = 0;
		curTime->tm_sec = 0;

		DWORD elapsedMilliseconds = GetTickCount() - startTime + elapsedTime; // ��� �ð��� �и��� ������ ���
		DWORD elapsedSeconds = elapsedMilliseconds / 1000; // �� ������ ��ȯ

		curTime->tm_hour = elapsedSeconds / 3600; // �� ��� (3600�ʰ� 1�ð�)
		curTime->tm_min = (elapsedSeconds % 3600) / 60; // �� ��� (60�ʰ� 1��)
		curTime->tm_sec = elapsedSeconds % 60; // �� ���

		printf("�����нð� �Դϴ�. ���Ḧ ���Ͻø� CTRL + C �� �Է��ϼ���.\n\n");

		printTime(curTime);

		// ��ž��ġ �޴� ǥ��
		printf("\n");
		printf("1. ����/�Ͻ�����  2. ����  3. ����\n");

		// ����� �Է� ó��
		if (_kbhit()) // Ű �Է� Ȯ��
		{
			char key = _getch(); // Ű �Է� �ޱ�
			switch (key)
			{
			case '1': // ����/�Ͻ����� ����ġ (Ű���� 1 Ű)
				if (isRunning)
				{
					isRunning = 0;
					elapsedTime += GetTickCount() - startTime; // ��� �ð� ������Ʈ
				}
				else
				{
					isRunning = 1;
					startTime = GetTickCount(); // ���� �ð� ���
				}
				break;
			case '2': // ���� ����ġ (Ű���� 2 Ű)
				isRunning = 0;
				elapsedTime = 0;
				break;
			case '3': // ���� ����ġ (Ű���� 3 Ű)
				return 0; // ���α׷� ����
			}
		}

		Sleep(100);
		system("cls");

	} while (1);

	return 0;
}

void printTime(struct tm* t1)					//�ð� ����Լ� ����
{

	char clockDigits[5][33] = { 0, };				//���� 33ĭ, ���� 5�� ¥�� �ð�ǥ�ø� ���� �迭

	arrIn(clockDigits, (t1->tm_hour / 10), 0);			//�ð� 10�� �ڸ�
	arrIn(clockDigits, (t1->tm_hour % 10), 5);		//�ð� 1�� �ڸ�
	arrIn(clockDigits, (t1->tm_min / 10), 12);			//�� 10�� �ڸ�
	arrIn(clockDigits, (t1->tm_min % 10), 17);		//�� 1�� �ڸ�
	arrIn(clockDigits, (t1->tm_sec / 10), 24);			//�ð� 10�� �ڸ�
	arrIn(clockDigits, (t1->tm_sec % 10), 29);		//�ð� 1�� �ڸ�


	//������ �ð� �������� �迭 clockDigits�� �����
	for (int i = 0; i < 5; i++)				//�迭�� ���α��� ��ŭ �ݺ�
	{
		for (int j = 0; j < 33; j++)		//�迭�� ���� ���� ��ŭ �ݺ�
		{
			if (clockDigits[i][j] == 1)		//�迭�� ��Ұ� 1�̸� ����Ǿ� ������ ��ĥ�� �簢�� ���
			{
				printf("��");
			}
			else if ((i == 1 || i == 3) && (j == 10 || j == 22))
			{
				printf("��");					// ��,��,�ʸ� �����ϴ� ":" ���
			}
			else
			{
				printf("  ");					//���� �ΰ����� �ƹ��͵� �ش����� ������ ��ĭ¥�� �������
			}
		}
		printf("\n");							//�迭�� ���� ������ ������ �ٹٲ�
	}
}


//����� �迭�� �� �ú��ʿ� �ش��ϴ� ���� ���¸� �Է��� �ִ� �Լ� ����
//�Է¹��� �Ű������� �����нð�迭, ��Ÿ�� ����, ������ ���� ��ġ
void arrIn(char clockDigits[][33], int digit, int beginNumber)
{
	char numDigits[10][5][4] =  //�����з� ǥ������ 3���� �迭 [0][][] -> 0, [1][][] ->1 ...
	{
		{	//0�� ǥ��
		{1,1,1,1},
		{1,0,0,1},
		{1,0,0,1},
		{1,0,0,1},
		{1,1,1,1}
		},
		{	//1�� ǥ��
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1}
		},
		{	//2�� ǥ��
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1}
		},
		{	//3�� ǥ��
		{1,1,1,1},
		{0,0,0,1},
		{0,1,1,1},
		{0,0,0,1},
		{1,1,1,1}
		},
		{	//4�� ǥ��
		{1,0,0,1},
		{1,0,0,1},
		{1,1,1,1},
		{0,0,0,1},
		{0,0,0,1}
		},
		{	//5�� ǥ��
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1}
		},
		{	//6�� ǥ��
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1}
		},
		{	//7�� ǥ��
		{1,1,1,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1}
		},
		{	//8�� ǥ��
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1}
		},
		{	//9�� ǥ��
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1}
		}
	};

	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = beginNumber; j < beginNumber + 4; j++)
		{
			clockDigits[i][j] = numDigits[digit][i][cnt];
			cnt++;
		}
		cnt = 0;
	}
}
/*
2023-10-11 �꿡�� �÷�����
*/