
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>  //시간관련 함수를 포함하는 헤더
#include <windows.h> //Sleep 함수를 포함하는 헤더

void printTime(struct tm* t1);										 //시간을 출력하는 함수 선언
void arrIn(char* clockDigits, int digit, int beginNumber);		//배열에 배열을 넣어주는 함수 선언
int main()
{
	time_t curr;
	struct tm* curTime;

	int isRunning = 0; // 스탑워치 실행 여부를 나타내는 변수
	DWORD startTime = 0; // 스탑워치 시작 시간을 저장하는 변수
	DWORD elapsedTime = 0; // 경과 시간을 저장하는 변수

	do
	{
		time(&curr); //현재타임
		curTime = localtime(&curr);

		// 시, 분, 초를 0으로 설정
		curTime->tm_hour = 0;
		curTime->tm_min = 0;
		curTime->tm_sec = 0;

		DWORD elapsedMilliseconds = GetTickCount() - startTime + elapsedTime; // 경과 시간을 밀리초 단위로 계산
		DWORD elapsedSeconds = elapsedMilliseconds / 1000; // 초 단위로 변환

		curTime->tm_hour = elapsedSeconds / 3600; // 시 계산 (3600초가 1시간)
		curTime->tm_min = (elapsedSeconds % 3600) / 60; // 분 계산 (60초가 1분)
		curTime->tm_sec = elapsedSeconds % 60; // 초 계산

		printf("디지털시계 입니다. 종료를 원하시면 CTRL + C 를 입력하세요.\n\n");

		printTime(curTime);

		// 스탑워치 메뉴 표시
		printf("\n");
		printf("1. 시작/일시정지  2. 리셋  3. 종료\n");

		// 사용자 입력 처리
		if (_kbhit()) // 키 입력 확인
		{
			char key = _getch(); // 키 입력 받기
			switch (key)
			{
			case '1': // 시작/일시정지 스위치 (키보드 1 키)
				if (isRunning)
				{
					isRunning = 0;
					elapsedTime += GetTickCount() - startTime; // 경과 시간 업데이트
				}
				else
				{
					isRunning = 1;
					startTime = GetTickCount(); // 시작 시간 기록
				}
				break;
			case '2': // 리셋 스위치 (키보드 2 키)
				isRunning = 0;
				elapsedTime = 0;
				break;
			case '3': // 종료 스위치 (키보드 3 키)
				return 0; // 프로그램 종료
			}
		}

		Sleep(100);
		system("cls");

	} while (1);

	return 0;
}

void printTime(struct tm* t1)					//시간 출력함수 정의
{

	char clockDigits[5][33] = { 0, };				//가로 33칸, 세로 5줄 짜리 시계표시를 만들 배열

	arrIn(clockDigits, (t1->tm_hour / 10), 0);			//시간 10의 자리
	arrIn(clockDigits, (t1->tm_hour % 10), 5);		//시간 1의 자리
	arrIn(clockDigits, (t1->tm_min / 10), 12);			//분 10의 자리
	arrIn(clockDigits, (t1->tm_min % 10), 17);		//분 1의 자리
	arrIn(clockDigits, (t1->tm_sec / 10), 24);			//시간 10의 자리
	arrIn(clockDigits, (t1->tm_sec % 10), 29);		//시간 1의 자리


	//디지털 시계 형식으로 배열 clockDigits를 출력함
	for (int i = 0; i < 5; i++)				//배열의 세로길이 만큼 반복
	{
		for (int j = 0; j < 33; j++)		//배열의 가로 길이 만큼 반복
		{
			if (clockDigits[i][j] == 1)		//배열의 요소가 1이면 저장되어 있으면 색칠된 사각형 출력
			{
				printf("■");
			}
			else if ((i == 1 || i == 3) && (j == 10 || j == 22))
			{
				printf("■");					// 시,분,초를 구별하는 ":" 출력
			}
			else
			{
				printf("  ");					//위의 두가지에 아무것도 해당하지 않으면 두칸짜리 공백출력
			}
		}
		printf("\n");							//배열의 가로 한줄이 끝나면 줄바꿈
	}
}


//출력할 배열에 각 시분초에 해당하는 숫자 형태를 입력해 주는 함수 정의
//입력받을 매개변수는 디지털시계배열, 나타낼 숫자, 숫자의 가로 위치
void arrIn(char clockDigits[][33], int digit, int beginNumber)
{
	char numDigits[10][5][4] =  //디지털로 표시해줄 3차원 배열 [0][][] -> 0, [1][][] ->1 ...
	{
		{	//0을 표시
		{1,1,1,1},
		{1,0,0,1},
		{1,0,0,1},
		{1,0,0,1},
		{1,1,1,1}
		},
		{	//1을 표시
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1}
		},
		{	//2를 표시
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1}
		},
		{	//3을 표시
		{1,1,1,1},
		{0,0,0,1},
		{0,1,1,1},
		{0,0,0,1},
		{1,1,1,1}
		},
		{	//4를 표시
		{1,0,0,1},
		{1,0,0,1},
		{1,1,1,1},
		{0,0,0,1},
		{0,0,0,1}
		},
		{	//5을 표시
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1}
		},
		{	//6을 표시
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1}
		},
		{	//7을 표시
		{1,1,1,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1}
		},
		{	//8을 표시
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1}
		},
		{	//9를 표시
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
2023-10-11 깃에다 올려보기
*/