


// scanf() 를 사용하니 1 -> 엔터를 계속 쳐야 시간 타임이 올라간다 고치기위해서 찾아보자



//#include <stdio.h>
//#include <windows.h>
//
//#define _CRT_SECURE_NO_WARNINGS  // scanf() 함수 사용할때 사용
//
//
//int main() {
//    int hours = 0, minutes = 0, seconds = 0;
//    int isRunning = 0; // 스톱워치 동작 여부 플래그
//
//    while (1) {
//        system("cls"); // 화면 지우기 (Windows에서의 명령)
//        printf("스톱워치: %02d:%02d:%02d\n", hours, minutes, seconds);
//        printf("1. 시작/일시정지  2. 리셋  3. 종료\n");
//
//        int choice;
//        if (scanf_s("%d", &choice) != 1) {
//            printf("올바른 입력이 아닙니다. 다시 입력하세요.\n");
//            fflush(stdin); // 입력 버퍼 비우기
//            continue;
//        }
//
//        switch (choice) {
//        case 1:
//            isRunning = !isRunning; // 시작/일시정지 토글
//            break;
//        case 2:
//            hours = minutes = seconds = 0; // 스톱워치 리셋
//            break;
//        case 3:
//            return 0; // 프로그램 종료
//        default:
//            printf("올바른 선택이 아닙니다. 다시 선택하세요.\n");
//        }
//
//        if (isRunning) {
//            Sleep(1000); // 1초 대기
//            seconds++;
//            if (seconds == 60) {
//                seconds = 0;
//                minutes++;
//                if (minutes == 60) {
//                    minutes = 0;
//                    hours++;
//                    if (hours == 24) {
//                        hours = 0; // 24시간을 넘어가면 0으로 리셋
//                    }
//                }
//            }
//        }
//    }
//
//    return 0;
//}


// 
// _kbhit() 함수를 사용 - 키보드 입력을 확인하는 함수이며, 사용자 입력을 감지할 때 주로 사용 
// 
//#include <stdio.h>
//#include <conio.h>
//#include <windows.h>
//
//int main() {
//    int isRunning = 0; // 스톱워치 동작 여부 플래그
//    int hours = 0, minutes = 0, seconds = 0;
//
//    while (1) {
//        system("cls"); // 화면 지우기 (Windows에서의 명령)
//
//        if (isRunning) {
//            seconds++;
//            if (seconds == 60) {
//                seconds = 0;
//                minutes++;
//                if (minutes == 60) {
//                    minutes = 0;
//                    hours++;
//                }
//            }
//        }
//
//        printf("스톱워치: %02d:%02d:%02d\n", hours, minutes, seconds);
//        printf("1. 시작/일시정지  2. 종료\n");
//
//        if (_kbhit()) {
//            char key = _getch();
//            if (key == '1') {
//                isRunning = !isRunning; // 시작/일시정지 토글
//            }
//            else if (key == '2') {
//                break; // 프로그램 종료
//            }
//        }
//
//        Sleep(1000); // 1초 대기
//    }
//
//    return 0;
//}



//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
// 리셋을 추가하기


//#include <stdio.h>
//#include <conio.h>
//#include <windows.h>
//
//int main() {
//    int isRunning = 0; 
//    int hours = 0, minutes = 0, seconds = 0;
//
//    while (1) { // while문에서 (1)을 줘서 무한반복문으로 들어간다 
//        system("cls"); // 화면 지우기 (Windows에서의 명령)
//
//        if (isRunning) {  //첫번째 if문에서 초단위는 00:00:01씩 증가한다. 
//            seconds++;
//            if (seconds == 60) { // 두번째 if문에서 초단위가 60이되면 0이되고 분단위가 1씩 증가하게 적었다.
//                seconds = 0;
//                minutes++;
//                if (minutes == 60) {  //세번째 if문에서는  분단위가 60이 되면 0으로 되고 시간단위가 1씩 증가한다.
//                    minutes = 0;
//                    hours++;
//                }
//            }
//        }
//
//        printf("스톱워치: %02d:%02d:%02d\n", hours, minutes, seconds);  // %02d : %02d :%02d \n을 적은이유는 00:00:00을 표현하기 위해서
//        printf("1. 시작/일시정지  2. 타임리셋  3. 종료\n");              // 
//
//        if (_kbhit()) {
//            char key = _getch();
//            if (key == '1') {
//                isRunning = !isRunning; // 시작/일시정지 하기 
//            }
//            else if (key == '2') {
//                // 타임리셋하기 시간 = 분 = 초 단위를 0으로 만들기
//                hours = minutes = seconds = 0;
//            }
//            else if (key == '3') {
//                break; // 브레이크 걸어서 while 반복문 종료하기  이건 자바에서 스위치문처럼 생각하면 된다.
//            }
//        }
//
//        Sleep(1000); // #include <windows.h>을 써서 윈도우 운영체제 명령어를 가져온다. 1초 대기
//                     //Sleep() 함수: 프로그램을 지정된 시간  Sleep(1000)은 1초 동안 대기
//    }
//
//    return 0;
//}


// 




