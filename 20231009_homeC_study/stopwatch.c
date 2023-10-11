/*

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main() {
    int isRunning = 0; 
    int hours = 0, minutes = 0, seconds = 0, millisecond = 0;

    while (1) { // while문에서 (1)을 줘서 무한반복문으로 들어간다 
        system("cls"); // 화면 지우기 (Windows에서의 명령)
        system("color 0c");
       

        if (isRunning) {  //첫번째 if문에서 초단위는 00:00:01씩 증가한다. 
            millisecond++;
            if (millisecond == 100) {
                millisecond = 0;
                seconds++;
                if (seconds == 60) { // 두번째 if문에서 초단위가 60이되면 0이되고 분단위가 1씩 증가하게 적었다.
                    seconds = 0;
                    minutes++;
                    if (minutes == 60) {  //세번째 if문에서는  분단위가 60이 되면 0으로 되고 시간단위가 1씩 증가한다.
                        minutes = 0;
                        hours++;
                        if (hours == 24) {
                            hours = 0;
                        }
                        
                    }

                }

            }

        }
        printf("\t ===========testClock==============\n\n");
        printf("스톱워치: %02d:%02d:%02d:%03d \n", hours, minutes, seconds, millisecond);
        printf("1. 시작/일시정지  2. 타임리셋  3. 종료\n");           
        printf("\t ===========testClock==============\n\n");

        if (_kbhit()) {
            char key = _getch();
            if (key == '1') {
                isRunning = !isRunning; // 시작/일시정지 하기 
            }
            else if (key == '2') {
                // 타임리셋하기 시간 = 분 = 초 단위를 0으로 만들기
                hours = minutes = seconds = millisecond = 0;
            }
            else if (key == '3') {
                break; // 브레이크 걸어서 while 반복문 종료하기  이건 자바에서 스위치문처럼 생각하면 된다.
            }
            else
            {
                printf("잘못된 키보드를 누르셨습니다.!\n");
            }
        }

        Sleep(10); // #include <windows.h>을 써서 윈도우 운영체제 명령어를 가져온다. 1초 대기
                     //Sleep() 함수: 프로그램을 지정된 시간  Sleep(1000)은 1초 동안 대기
    }

    return 0;
}

*/
