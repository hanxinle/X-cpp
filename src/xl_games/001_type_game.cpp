/*
 * 2022-07-13
 * CopyRight @ hanxinle
 */

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

const static int TOTALCNT = 5;
const static int DEST = 4;  // y 轴元素间隔
const static int XLEN = 80; // x 轴元素范围

// 提供一个辅助函数，将光标定位，在这个函数语句调用后调用 printf
// 可在光标后打印内容.
static void  GotoLocation(int x, int y) {
    COORD cd;
    cd.X = x;
    cd.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}

// 抽线字母、子弹属性，声明全局的字母集合
typedef struct {
    char ch;
    int x;
    int y;
    bool display;
    bool live;
} letter;

static letter letters[TOTALCNT];
static letter bullet;

// 初始化字母集合
static void InitLetters() {
    srand(time(NULL));
    for (int i = 0; i < TOTALCNT; i++) {
        letters[i].ch = rand() % 26 + 'A';
        letters[i].x = rand() % 80;
        letters[i].y = 1 - DEST * i;
        letters[i].display = false;
        letters[i].live = true;
    }
}

// 初始化字母集合元素的显示规则
static void SetDiplayLetters() {
    for (int i = 0; i < TOTALCNT; i++) {
        if (letters[i].y >= 25 || letters[i].y <= 0) {
            letters[i].display = false;
        }
        else {
            letters[i].display = true;
        }
    }
}
// 字母集合元素移动规则，y++ // 这里我第一版想错了，先不改，先这么高者
// 这里不应该写实际的移动规则，而是实际上的移动行为,要用到 GotoLocation 的
static void LettersMoving() {
    SetDiplayLetters();
    for (int i = 0; i < TOTALCNT; i++) {
        if (letters[i].live == true && letters[i].display == true) {
            GotoLocation(letters[i].x, letters[i].y);
            printf(" ");
            //letters[i].y++;
            GotoLocation(letters[i].x, letters[i].y+1);
            printf("%c", letters[i].ch);
        }

        if (letters[i].y <= 25)
            letters[i].y++;
    }
}

// 初始化子弹，全局使用唯一的子弹
void static InitBullet() {
    bullet.x = 100;
    bullet.y = 25;
    bullet.display = false;
    bullet.live = true;
}

// 忘了子弹的移动规则，先不设计它，看看会有什么影响.
// 后续补上，while 循环里写这么多代码不美观.
static void  BulletMoving() {
    if (bullet.display == true && bullet.live == true) {
        GotoLocation(bullet.x, bullet.y);
        printf(" ");
 
        GotoLocation(bullet.x, bullet.y-1);
        printf("%c", bullet.ch);
        bullet.y--;                // 不要忽略
    }
}

// 输赢的判断放在main 中执行，包括结果打印

int main() {
    unsigned int score = 0;
    InitLetters();

    // 结束条件，最后一个字母下落到底部.//这样判断挺智慧的.
    while (letters[TOTALCNT - 1].y < 25) {

        LettersMoving();

        if (_kbhit()) {
            bullet.ch = _getch();
            bullet.ch -= 32;
            for (int i = 0; i < TOTALCNT; i++) {
                InitBullet();
                bullet.display = true;
                // 字母相同则进入处理
                if (bullet.ch == letters[i].ch && letters[i].display == true) {
                    bullet.x = letters[i].x;
                    while (bullet.y > 0 ) {
                        LettersMoving();
                        BulletMoving();
                        // == 有时候命中不到，换成 <= 关系
                        if (bullet.y <= letters[i].y) {
                            bullet.display = false;
                            bullet.live = false;
                            letters[i].display = false;
                            letters[i].live = false;

                            GotoLocation(bullet.x, bullet.y);
                            printf(" ");

                            score++;
                            break;
                        }                       
                        Sleep(300);   // 子弹速度
                    }
                }
            }
        }
        Sleep(500);                   // 字母下降速度
    }
    printf("\n\n");
    printf("****************************************\n");
    printf("\n\n\tscore = %d\n\n", score);
    printf("****************************************\n");
    return 0;
}
