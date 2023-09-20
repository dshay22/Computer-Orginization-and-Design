#include <stdio.h>
#include <math.h>
#define FRAME_WIDTH 16
#define WINDOW_WIDTH 4

int SumOfDifference(int f[][16], int w[][4], int windowSize, int frameStartRow, int frameStartCol){
    int sumOfDiff = 0;

    for(int i = 0; i <  windowSize; ++i){//moves through rows
        for(int j = 0; j < windowSize; ++j){//moves through cols
            sumOfDiff += abs(w[i][j] - f[i + frameStartRow][j + frameStartCol]);
        }
    }
    return sumOfDiff;
}

// main function -
// where the execution of program begins
int main()
{
    int frame[16][16] = {
                            {0,   1,   2,   3,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},//0
                            {1,   2,   3,   4,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15},//1
                            {2,   3,  32,   1,   2,   3,  12,  14,  16,  18,  20,  22,  24,  26,  28,  30},//2
                            {3,   4,   1,   2,   3,   4,  18,  21,  24,  27,  30,  33,  36,  39,  42,  45},//3
                            {0,   4,   2,   3,   4,   5,  24,  28,  32,  36,  40,  44,  48,  52,  56,  60},//4
                            {0,   5,   3,   4,   5,   6,  30,  35,  40,  45,  50,  55,  60,  65,  70,  75},//5
                            {0,   6,  12,  18,  24,  30,  36,  42,  48,  54,  60,  66,  72,  78,  84,  90},//6
                            {0,   7,  14,  21,  28,  35,  42,  49,  56,  63,  70,  77,  84,  91,  98, 105},//7
                            {0,   8,  16,  24,  32,  40,  48,  56,  64,  72,  80,  88,  96, 104, 112, 120},//8
                            {0,   9,  18,  27,  36,  45,  54,  63,  72,  81,  90,  99, 108, 117, 126, 135},//9
                            {0,  10,  20,  30,  40,  50,  60,  70,  80,  90, 100, 110, 120, 130, 140, 150},//10
                            {0,  11,  22,  33,  44,  55,  66,  77,  88,  99, 110, 121, 132, 143, 154, 165},//11
                            {0,  12,  24,  36,  48,  60,  72,  84,  96, 108, 120, 132,   0,   1,   2,   3},//12
                            {0,  13,  26,  39,  52,  65,  78,  91, 104, 117, 130, 143,   1,   2,   3,   4},//13
                            {0,  14,  28,  42,  56,  70,  84,  98, 112, 126, 140, 154,   2,   3,   4,   5},//14
                            {0,  15,  30,  45,  60,  75,  90, 105, 120, 135, 150, 165,   3,   4,   5,   6} //15
                        };

    int window[4][4] = {
                            {0,   1,   2,   3},
                            {1,   2,   3,   4},
                            {2,   3,   4,   5},
                            {3,   4,   5,   6}
                       };

    int x = 0;
    int y = 0;
    printf("%d, %d\n", x, y);
    for (int i = 0; i < (FRAME_WIDTH / 2) - (WINDOW_WIDTH / 2); ++i) {
        ++x;
        printf("%d, %d\n", x, y);
        while (x > 0) {  //moves diag left
            --x;
            ++y;
            printf("%d, %d\n", x, y);
        }
        ++y;
        printf("%d, %d\n", x, y);
        while (y > 0) { // moves up diag
            ++x;
            --y;
            printf("%d, %d\n", x, y);
        }
    }
    printf("\nHALF\n\n");
    --x;
    for (int i = 0; i < (FRAME_WIDTH / 2) - (WINDOW_WIDTH / 2); ++i) {
        ++x; 
        printf("%d, %d\n", x, y);
        while (x != 12) {
            ++x;
            --y;
            printf("%d, %d\n", x, y);
        }
        ++y;
        printf("%d, %d\n", x, y);
        while (y != 12) {
            --x;
            ++y;
            printf("%d, %d\n", x, y);
        }

    }
    ++x;
    printf("%d, %d\n", x, y);
    return 0;
}