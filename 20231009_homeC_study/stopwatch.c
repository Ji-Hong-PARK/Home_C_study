/*

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main() {
    int isRunning = 0; 
    int hours = 0, minutes = 0, seconds = 0, millisecond = 0;

    while (1) { // while������ (1)�� �༭ ���ѹݺ������� ���� 
        system("cls"); // ȭ�� ����� (Windows������ ���)
        system("color 0c");
       

        if (isRunning) {  //ù��° if������ �ʴ����� 00:00:01�� �����Ѵ�. 
            millisecond++;
            if (millisecond == 100) {
                millisecond = 0;
                seconds++;
                if (seconds == 60) { // �ι�° if������ �ʴ����� 60�̵Ǹ� 0�̵ǰ� �д����� 1�� �����ϰ� ������.
                    seconds = 0;
                    minutes++;
                    if (minutes == 60) {  //����° if��������  �д����� 60�� �Ǹ� 0���� �ǰ� �ð������� 1�� �����Ѵ�.
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
        printf("�����ġ: %02d:%02d:%02d:%03d \n", hours, minutes, seconds, millisecond);
        printf("1. ����/�Ͻ�����  2. Ÿ�Ӹ���  3. ����\n");           
        printf("\t ===========testClock==============\n\n");

        if (_kbhit()) {
            char key = _getch();
            if (key == '1') {
                isRunning = !isRunning; // ����/�Ͻ����� �ϱ� 
            }
            else if (key == '2') {
                // Ÿ�Ӹ����ϱ� �ð� = �� = �� ������ 0���� �����
                hours = minutes = seconds = millisecond = 0;
            }
            else if (key == '3') {
                break; // �극��ũ �ɾ while �ݺ��� �����ϱ�  �̰� �ڹٿ��� ����ġ��ó�� �����ϸ� �ȴ�.
            }
            else
            {
                printf("�߸��� Ű���带 �����̽��ϴ�.!\n");
            }
        }

        Sleep(10); // #include <windows.h>�� �Ἥ ������ �ü�� ��ɾ �����´�. 1�� ���
                     //Sleep() �Լ�: ���α׷��� ������ �ð�  Sleep(1000)�� 1�� ���� ���
    }

    return 0;
}

*/
