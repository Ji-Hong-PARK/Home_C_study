


// scanf() �� ����ϴ� 1 -> ���͸� ��� �ľ� �ð� Ÿ���� �ö󰣴� ��ġ�����ؼ� ã�ƺ���



//#include <stdio.h>
//#include <windows.h>
//
//#define _CRT_SECURE_NO_WARNINGS  // scanf() �Լ� ����Ҷ� ���
//
//
//int main() {
//    int hours = 0, minutes = 0, seconds = 0;
//    int isRunning = 0; // �����ġ ���� ���� �÷���
//
//    while (1) {
//        system("cls"); // ȭ�� ����� (Windows������ ���)
//        printf("�����ġ: %02d:%02d:%02d\n", hours, minutes, seconds);
//        printf("1. ����/�Ͻ�����  2. ����  3. ����\n");
//
//        int choice;
//        if (scanf_s("%d", &choice) != 1) {
//            printf("�ùٸ� �Է��� �ƴմϴ�. �ٽ� �Է��ϼ���.\n");
//            fflush(stdin); // �Է� ���� ����
//            continue;
//        }
//
//        switch (choice) {
//        case 1:
//            isRunning = !isRunning; // ����/�Ͻ����� ���
//            break;
//        case 2:
//            hours = minutes = seconds = 0; // �����ġ ����
//            break;
//        case 3:
//            return 0; // ���α׷� ����
//        default:
//            printf("�ùٸ� ������ �ƴմϴ�. �ٽ� �����ϼ���.\n");
//        }
//
//        if (isRunning) {
//            Sleep(1000); // 1�� ���
//            seconds++;
//            if (seconds == 60) {
//                seconds = 0;
//                minutes++;
//                if (minutes == 60) {
//                    minutes = 0;
//                    hours++;
//                    if (hours == 24) {
//                        hours = 0; // 24�ð��� �Ѿ�� 0���� ����
//                    }
//                }
//            }
//        }
//    }
//
//    return 0;
//}


// 
// _kbhit() �Լ��� ��� - Ű���� �Է��� Ȯ���ϴ� �Լ��̸�, ����� �Է��� ������ �� �ַ� ��� 
// 
//#include <stdio.h>
//#include <conio.h>
//#include <windows.h>
//
//int main() {
//    int isRunning = 0; // �����ġ ���� ���� �÷���
//    int hours = 0, minutes = 0, seconds = 0;
//
//    while (1) {
//        system("cls"); // ȭ�� ����� (Windows������ ���)
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
//        printf("�����ġ: %02d:%02d:%02d\n", hours, minutes, seconds);
//        printf("1. ����/�Ͻ�����  2. ����\n");
//
//        if (_kbhit()) {
//            char key = _getch();
//            if (key == '1') {
//                isRunning = !isRunning; // ����/�Ͻ����� ���
//            }
//            else if (key == '2') {
//                break; // ���α׷� ����
//            }
//        }
//
//        Sleep(1000); // 1�� ���
//    }
//
//    return 0;
//}



//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
// ������ �߰��ϱ�


//#include <stdio.h>
//#include <conio.h>
//#include <windows.h>
//
//int main() {
//    int isRunning = 0; 
//    int hours = 0, minutes = 0, seconds = 0;
//
//    while (1) { // while������ (1)�� �༭ ���ѹݺ������� ���� 
//        system("cls"); // ȭ�� ����� (Windows������ ���)
//
//        if (isRunning) {  //ù��° if������ �ʴ����� 00:00:01�� �����Ѵ�. 
//            seconds++;
//            if (seconds == 60) { // �ι�° if������ �ʴ����� 60�̵Ǹ� 0�̵ǰ� �д����� 1�� �����ϰ� ������.
//                seconds = 0;
//                minutes++;
//                if (minutes == 60) {  //����° if��������  �д����� 60�� �Ǹ� 0���� �ǰ� �ð������� 1�� �����Ѵ�.
//                    minutes = 0;
//                    hours++;
//                }
//            }
//        }
//
//        printf("�����ġ: %02d:%02d:%02d\n", hours, minutes, seconds);  // %02d : %02d :%02d \n�� ���������� 00:00:00�� ǥ���ϱ� ���ؼ�
//        printf("1. ����/�Ͻ�����  2. Ÿ�Ӹ���  3. ����\n");              // 
//
//        if (_kbhit()) {
//            char key = _getch();
//            if (key == '1') {
//                isRunning = !isRunning; // ����/�Ͻ����� �ϱ� 
//            }
//            else if (key == '2') {
//                // Ÿ�Ӹ����ϱ� �ð� = �� = �� ������ 0���� �����
//                hours = minutes = seconds = 0;
//            }
//            else if (key == '3') {
//                break; // �극��ũ �ɾ while �ݺ��� �����ϱ�  �̰� �ڹٿ��� ����ġ��ó�� �����ϸ� �ȴ�.
//            }
//        }
//
//        Sleep(1000); // #include <windows.h>�� �Ἥ ������ �ü�� ��ɾ �����´�. 1�� ���
//                     //Sleep() �Լ�: ���α׷��� ������ �ð�  Sleep(1000)�� 1�� ���� ���
//    }
//
//    return 0;
//}


// 




