// #include <stdio.h>
// #include <math.h>
// #define FRAME_WIDTH 16
// #define WINDOW_WIDTH 4

// int SumOfDifference(int f[FRAME_WIDTH][FRAME_WIDTH], int w[WINDOW_WIDTH][WINDOW_WIDTH], int windowRow, int windowCol, int frameStartRow, int frameStartCol){
//     int sumOfDiff = 0;

//     for(int i = 0; i <  windowRow; ++i){//moves through rows
//         for(int j = 0; j < windowCol; ++j){//moves through cols
//             sumOfDiff += abs(w[i][j] - f[i + frameStartRow][j + frameStartCol]);
//         }
//     }
//     //printf("%d\n", sumOfDiff);
//     return sumOfDiff;
// }

// void everything(/*int* x, int* y,*/int* corrdArray, int *frame, int *window, int aSize[4]){
//     int tempDiff, minDiff;
//     int row = 0, col = 0;
//     int windowRow = aSize[2];
//     int windowCol = aSize[3];
//     int frameRow = aSize[0];
//     int frameCol = aSize[1];
//     //printf("%d, %d\n", x, y);
//     minDiff = SumOfDifference(frame, window, windowRow, windowCol, row, col);

//     for (int i = 0; i < (frameRow / 2) - (windowCol / 2); ++i) {
//         ++row;
//         //printf("%d, %d\n", x, y);
//         tempDiff = SumOfDifference(frame, window, windowRow, windowCol, row, col);
//         if(tempDiff < minDiff){
//             corrdArray[0] = col;
//             corrdArray[1] = row;
//             minDiff = tempDiff;
//         }
//         while (row > 0) {  //moves diag left
//             --row;
//             ++col;
//             //printf("%d, %d\n", x, y);
//             tempDiff = SumOfDifference(frame, window, windowRow, windowCol, row, col);
//             if(tempDiff < minDiff){
//                 corrdArray[0] = col;
//                 corrdArray[1] = row;
//                 minDiff = tempDiff;
//             }
//         }
//         ++col;
//         //printf("%d, %d\n", x, y);
//         tempDiff = SumOfDifference(frame, window, windowRow, windowCol, row, col);
//         if(tempDiff < minDiff){
//             corrdArray[0] = col;
//             corrdArray[1] = row;
//             minDiff = tempDiff;
//         }
//         while (col > 0) { // moves up diag
//             ++row;
//             --col;
//             //printf("%d, %d\n", x, y);
//             tempDiff = SumOfDifference(frame, window, windowRow, windowCol, row, col);
//             if(tempDiff < minDiff){
//                 corrdArray[0] = col;
//                 corrdArray[1] = row;
//                 minDiff = tempDiff;
//             }
//         }
//     }
//     //printf("\nHALF\n\n");
//     --row;
//     for (int i = 0; i < (frameRow / 2) - (windowRow / 2); ++i) {
//         ++row; 
//         //printf("%d, %d\n", x, y);
//         tempDiff = SumOfDifference(frame, window, windowRow, windowCol, row, col);
//         if(tempDiff < minDiff){
//             corrdArray[0] = col;
//             corrdArray[1] = row;
//             minDiff = tempDiff;
//         }
//         while (row < frameRow - windowRow) {
//             ++row;
//             --col;
//             //printf("%d, %d\n", x, y);
//             tempDiff = SumOfDifference(frame, window, windowRow, windowCol, row, col);
//             if(tempDiff < minDiff){
//                 corrdArray[0] = col;
//                 corrdArray[1] = row;
//                 minDiff = tempDiff;
//             }
//         }
//         ++col;
//         //printf("%d, %d\n", x, y);
//         tempDiff = SumOfDifference(frame, window, windowRow, windowCol, row, col);
//         if(tempDiff < minDiff){
//             corrdArray[0] = col;
//             corrdArray[1] = row;
//             minDiff = tempDiff;
//         }
//         while (col < frameCol - windowCol) {
//             --row;
//             ++col;
//             //printf("%d, %d\n", x, y);
//             tempDiff = SumOfDifference(frame, window, windowRow, windowCol, row, col);
//             if(tempDiff < minDiff){
//                 corrdArray[0] = col;
//                 corrdArray[1] = row;
//                 minDiff = tempDiff;
//             }
//         }

//     }
//     ++row;
//     //printf("%d, %d\n", x, y);
//     tempDiff = SumOfDifference(frame, window, windowRow, windowCol, row, col);
//     if(tempDiff < minDiff){
//         corrdArray[0] = col;
//         corrdArray[1] = row;
//         minDiff = tempDiff;
//     }
//     //printf("%d :%d %d", minDiff, row, col);
// }

// // main function -
// // where the execution of program begins
// int main()
// {
//     int frame[FRAME_WIDTH][FRAME_WIDTH] = {
//                             {0,   1,   2,   3,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0},//0
//                             {1,   2,   3,   4,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15},//1
//                             {2,   3,  32,   1,   2,   3,  12,  14,  16,  18,  20,  22,  24,  26,  28,  30},//2
//                             {3,   4,   1,   2,   3,   4,  18,  21,  24,  27,  30,  33,  36,  39,  42,  45},//3
//                             {0,   4,   2,   3,   4,   5,  24,  28,  32,  36,  40,  44,  48,  52,  56,  60},//4
//                             {0,   5,   3,   4,   5,   6,  30,  35,  40,  45,  50,  55,  60,  65,  70,  75},//5
//                             {0,   6,  12,  18,  24,  30,  36,  42,  48,  54,  60,  66,  72,  78,  84,  90},//6
//                             {0,   7,  14,  21,  28,  35,  42,  49,  56,  63,  70,  77,  84,  91,  98, 105},//7
//                             {0,   8,  16,  24,  32,  40,  48,  56,  64,  72,  80,  88,  96, 104, 112, 120},//8
//                             {0,   9,  18,  27,  36,  45,  54,  63,  72,  81,  90,  99, 108, 117, 126, 135},//9
//                             {0,  10,  20,  30,  40,  50,  60,  70,  80,  90, 100, 110, 120, 130, 140, 150},//10
//                             {0,  11,  22,  33,  44,  55,  66,  77,  88,  99, 110, 121, 132, 143, 154, 165},//11
//                             {0,  12,  24,  36,  48,  60,  72,  84,  96, 108, 120, 132,   0,   1,   2,   3},//12
//                             {0,  13,  26,  39,  52,  65,  78,  91, 104, 117, 130, 143,   1,   2,   3,   4},//13
//                             {0,  14,  28,  42,  56,  70,  84,  98, 112, 126, 140, 154,   2,   3,   4,   5},//14
//                             {0,  15,  30,  45,  60,  75,  90, 105, 120, 135, 150, 165,   3,   4,   5,   6} //15
//                         };

//     int window[WINDOW_WIDTH][WINDOW_WIDTH] = {
//                             {0,   1,   2,   3},
//                             {1,   2,   3,   4},
//                             {2,   3,   4,   5},
//                             {3,   4,   5,   6}
//                        };

//     int frame2[FRAME_WIDTH][FRAME_WIDTH] = {
//                                             {9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 6, 7, 7, 7},//0
//                                             {9, 7, 7, 7, 7, 5, 6, 7, 8, 9, 10, 11, 6, 7, 7, 7},//1
//                                             {9, 7, 7, 7, 7, 3, 12, 14, 16, 18, 20, 6, 6, 7, 7, 7},//2
//                                             {9, 7, 7, 7, 7, 4, 18, 21, 24, 27, 30, 33, 6, 7, 7, 7},//3
//                                             {0, 7, 7, 7, 7, 5, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60},//4
//                                             {0, 5, 3, 4, 5, 6, 30, 35, 40, 45, 50, 55, 60, 65, 70,  75},//5
//                                             {0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90},//6
//                                             {0, 4, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105},//7
//                                             {0,   8,  16,  24,  32,  40,  48,  56,  64,  72,  80,  88,  96, 104, 112, 120},//8
//                                             {0,   9,  18,  27,  36,  45,  54,  63,  72,  81,  90,  99, 108, 117, 126, 135},//9
//                                             {0,  10,  20,  30,  40,  50,  60,  70,  80,  90, 100, 110, 120, 130, 140, 150},//10
//                                             {0,  11,  22,  33,  44,  55,  66,  77,  88,  99, 110, 121, 132, 143, 154, 165},//11
//                                             {9, 9, 9, 9, 48, 60, 72, 84, 96, 108, 120, 132, 0, 1, 2, 3},//12
//                                             {9, 9, 9, 9, 52, 65, 78, 91, 104, 114, 130, 143, 1, 2, 3, 4},//13
//                                             {9, 9, 9, 9, 56, 70, 84, 98, 112, 126, 140, 154, 2, 3, 4, 5},//14
//                                             {9, 9, 9, 9, 60, 75, 90, 105, 120, 135, 150, 165, 3, 4, 5, 6} //15
//                                            };
    
//     int window2 [WINDOW_WIDTH][WINDOW_WIDTH] = {
//                                                 {7,7,7,7},
//                                                 {7,7,7,7},
//                                                 {7,7,7,7},
//                                                 {7,7,7,7}
//                                                };

//     int frame3[FRAME_WIDTH][FRAME_WIDTH] = {
//                                             {7, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//0
//                                             {7, 8, 8, 8, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},//1
//                                             {7, 8, 8, 8, 2, 8, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30},//2
//                                             {7, 8, 8, 8, 8, 8, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45},//3
//                                             {0, 4, 8, 8, 8, 8, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60},//4
//                                             {0, 5, 8, 8, 8, 8, 30, 35, 40, 45, 50, 55, 60, 65, 70,  75},//5
//                                             {0, 6, 8, 8, 8, 8, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90},//6
//                                             {0, 4, 8, 8, 8, 8, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105},//7
//                                             {0, 1, 8, 8, 8, 8, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120},//8
//                                             {0, 1, 8, 8, 8, 8, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135},//9
//                                             {0, 10, 8, 8, 8, 8, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150},//10
//                                             {0,  11,  22,  33,  44,  55,  66,  77,  88,  99, 110, 121, 132, 143, 154, 165},//11
//                                             {9, 9, 9, 9, 48, 60, 72, 84, 96, 108, 120, 132, 0, 1, 2, 3},//12
//                                             {9, 9, 9, 9, 52, 65, 78, 91, 104, 114, 130, 143, 1, 2, 3, 4},//13
//                                             {9, 9, 9, 9, 56, 70, 84, 98, 112, 126, 140, 154, 2, 3, 4, 5},//14
//                                             {9, 9, 9, 9, 60, 75, 90, 105, 120, 135, 150, 165, 3, 4, 5, 6} //15
//                                            };
        
//         int window3 [8][4] = {
//                                 {8, 8, 8, 8},
//                                 {8, 8, 8, 8},
//                                 {8, 8, 8, 8},
//                                 {8, 8, 8, 8},
//                                 {8, 8, 8, 8},
//                                 {8, 8, 8, 8},
//                                 {8, 8, 8, 8},
//                                 {8, 8, 8, 8}
//                              };

//     int x;
//     int y;
//     int coord[] = {-1,-1};
//     int asize[] = {16,16,4,4};

//     everything(/*&y, &x,*/&coord, frame2, window2, asize);

//     //printf("%d %d", x, y);
//     printf("< %d , %d >", coord[0], coord[1]);
    
//     return 0;
// }





///START OF MY NEW CODE////

#include <stdio.h>
#include <math.h>
#define FRAME_WIDTH 16
#define WINDOW_WIDTH 4

int SumOfDifference(int* f, int* w, int* aSize, int frameStartIndex){
    int sumOfDiff = 0;
    for(int i = 0; i <  aSize[2] * aSize[3]; ++i) {
        sumOfDiff += abs(w[i] - f[i + frameStartIndex]);
        if((i & (aSize[3] - 1)) == (aSize[3] - 1)){
            frameStartIndex += aSize[1] - aSize[3];
        }
    }

    return sumOfDiff;
}

void everything(int* corrdArray, int *frame, int *window, int aSize[4]){
    int tempDiff, minDiff;
    int row = 0, col = 0;
    int windowSize = aSize[2];
    int frameSize = aSize[0] * aSize[1];
    minDiff = SumOfDifference(frame, window, aSize, 0);
    //printf("%d, %d\n", row, col);
    for (int i = 0; i < (aSize[0] / 2) - (aSize[3] / 2); ++i) {
        ++row;
        //printf("%d, %d\n", row, col);
        tempDiff = SumOfDifference(frame, window, aSize, row * aSize[1] + col);
        if(tempDiff < minDiff){
            corrdArray[0] = col;
            corrdArray[1] = row;
            minDiff = tempDiff;
        }
        while (row > 0) {  //moves diag left
            --row;
            ++col;
            //printf("%d, %d\n", row, col);
            tempDiff = SumOfDifference(frame, window, aSize, row * aSize[1] + col);
            if(tempDiff < minDiff){
                corrdArray[0] = col;
                corrdArray[1] = row;
                minDiff = tempDiff;
            }
        }
        ++col;
        tempDiff = SumOfDifference(frame, window, aSize, row * aSize[1] + col);
        if(tempDiff < minDiff){
            corrdArray[0] = col;
            corrdArray[1] = row;
            minDiff = tempDiff;
        }
        while (col > 0) { // moves up diag
            ++row;
            --col;
            //printf("%d, %d\n", row, col);
            tempDiff = SumOfDifference(frame, window, aSize, row * aSize[1] + col);
            if(tempDiff < minDiff){
                corrdArray[0] = col;
                corrdArray[1] = row;
                minDiff = tempDiff;
            }
        }
    }
    //printf("\nHALF\n\n");
    --row;
    for (int i = 0; i < (aSize[0] / 2) - (aSize[2] / 2); ++i) {
        ++row; 
        //printf("%d, %d\n", row, col);
        tempDiff = SumOfDifference(frame, window, aSize, row * aSize[1] + col);
        if(tempDiff < minDiff){
            corrdArray[0] = col;
            corrdArray[1] = row;
            minDiff = tempDiff;
        }
        while (row < aSize[0] - aSize[2]) {
            ++row;
            --col;
            //printf("%d, %d\n", row, col);
            tempDiff = SumOfDifference(frame, window, aSize, row * aSize[1] + col);
            if(tempDiff < minDiff){
                corrdArray[0] = col;
                corrdArray[1] = row;
                minDiff = tempDiff;
            }
        }
        ++col;
        //printf("%d, %d\n", row, col);
        tempDiff = SumOfDifference(frame, window, aSize, row * aSize[1] + col);
        if(tempDiff < minDiff){
            corrdArray[0] = col;
            corrdArray[1] = row;
            minDiff = tempDiff;
        }
        while (col < aSize[1] - aSize[3]) {
            --row;
            ++col;
            //printf("%d, %d\n", row, col);
            tempDiff = SumOfDifference(frame, window, aSize, row * aSize[1] + col);
            if(tempDiff < minDiff){
                corrdArray[0] = col;
                corrdArray[1] = row;
                minDiff = tempDiff;
            }
        }
    }
    ++row;
    //printf("%d, %d\n", row, col);
    tempDiff = SumOfDifference(frame, window, aSize, row * aSize[1] + col);
    if(tempDiff < minDiff){
        corrdArray[0] = col;
        corrdArray[1] = row;
        minDiff = tempDiff;
    }
}

int main() {
    int frame[FRAME_WIDTH * FRAME_WIDTH] = {
                            0,   1,   2,   3,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,//0
                            1,   2,   3,   4,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,//1
                            2,   3,  32,   1,   2,   3,  12,  14,  16,  18,  20,  22,  24,  26,  28,  30,//2
                            3,   4,   1,   2,   3,   4,  18,  21,  24,  27,  30,  33,  36,  39,  42,  45,//3
                            0,   4,   2,   3,   4,   5,  24,  28,  32,  36,  40,  44,  48,  52,  56,  60,//4
                            0,   5,   3,   4,   5,   6,  30,  35,  40,  45,  50,  55,  60,  65,  70,  75,//5
                            0,   6,  12,  18,  24,  30,  36,  42,  48,  54,  60,  66,  72,  78,  84,  90,//6
                            0,   7,  14,  21,  28,  35,  42,  49,  56,  63,  70,  77,  84,  91,  98, 105,//7
                            0,   8,  16,  24,  32,  40,  48,  56,  64,  72,  80,  88,  96, 104, 112, 120,//8
                            0,   9,  18,  27,  36,  45,  54,  63,  72,  81,  90,  99, 108, 117, 126, 135,//9
                            0,  10,  20,  30,  40,  50,  60,  70,  80,  90, 100, 110, 120, 130, 140, 150,//10
                            0,  11,  22,  33,  44,  55,  66,  77,  88,  99, 110, 121, 132, 143, 154, 165,//11
                            0,  12,  24,  36,  48,  60,  72,  84,  96, 108, 120, 132,   0,   1,   2,   3,//12
                            0,  13,  26,  39,  52,  65,  78,  91, 104, 117, 130, 143,   1,   2,   3,   4,//13
                            0,  14,  28,  42,  56,  70,  84,  98, 112, 126, 140, 154,   2,   3,   4,   5,//14
                            0,  15,  30,  45,  60,  75,  90, 105, 120, 135, 150, 165,   3,   4,   5,   6 //15
                        };
    
    int window[WINDOW_WIDTH * WINDOW_WIDTH] = {
                            0,   1,   2,   3,
                            1,   2,   3,   4,
                            2,   3,   4,   5,
                            3,   4,   5,   6
                       };

    int frame2[FRAME_WIDTH * FRAME_WIDTH] = {
        9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 6, 7, 7, 7,
        9, 7, 7, 7, 7, 5, 6, 7, 8, 9, 10, 11, 6, 7, 7, 7,
        9, 7, 7, 7, 7, 3, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30,
        9, 7, 7, 7, 7, 4, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45,
        0, 7, 7, 7, 7, 5, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60,
        0, 5, 3, 4, 5, 6, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75,
        0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90,
        0, 4, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105,
        0, 1, 8, 8, 8, 8, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120,
        0, 1, 8, 8, 8, 8, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135,
        0, 10, 8, 8, 8, 8, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150,
        0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143, 154, 165,
        9, 9, 9, 9, 48, 60, 72, 84, 96, 108, 120, 132, 0, 1, 2, 3,
        9, 9, 9, 9, 52, 65, 78, 91, 104, 114, 130, 143, 1, 2, 3, 4,
        9, 9, 9, 9, 56, 70, 84, 98, 112, 126, 140, 154, 2, 3, 4, 5,
        9, 9, 9, 9, 60, 75, 90, 105, 120, 135, 150, 165, 3, 4, 5, 6
    };

    int window2[WINDOW_WIDTH * WINDOW_WIDTH] = {
        7, 7, 7, 7,
        7, 7, 7, 7,
        7, 7, 7, 7,
        7, 7, 7, 7
    };
    int frame3[FRAME_WIDTH * FRAME_WIDTH] = {
                                            7, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//0
                                            7, 8, 8, 8, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,//1
                                            7, 8, 8, 8, 2, 8, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30,//2
                                            7, 8, 8, 8, 8, 8, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45,//3
                                            0, 4, 8, 8, 8, 8, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60,//4
                                            0, 5, 8, 8, 8, 8, 30, 35, 40, 45, 50, 55, 60, 65, 70,  75,//5
                                            0, 6, 8, 8, 8, 8, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90,//6
                                            0, 4, 8, 8, 8, 8, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105,//7
                                            0, 1, 8, 8, 8, 8, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120,//8
                                            0, 1, 8, 8, 8, 8, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135,//9
                                            0, 10, 8, 8, 8, 8, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150,//10
                                            0,  11,  22,  33,  44,  55,  66,  77,  88,  99, 110, 121, 132, 143, 154, 165,//11
                                            9, 9, 9, 9, 48, 60, 72, 84, 96, 108, 120, 132, 0, 1, 2, 3,//12
                                            9, 9, 9, 9, 52, 65, 78, 91, 104, 114, 130, 143, 1, 2, 3, 4,//13
                                            9, 9, 9, 9, 56, 70, 84, 98, 112, 126, 140, 154, 2, 3, 4, 5,//14
                                            9, 9, 9, 9, 60, 75, 90, 105, 120, 135, 150, 165, 3, 4, 5, 6 //15
                                           };
        
        int window3 [8 * 4] = {
                                8, 8, 8, 8,
                                8, 8, 8, 8,
                                8, 8, 8, 8,
                                8, 8, 8, 8,
                                8, 8, 8, 8,
                                8, 8, 8, 8,
                                8, 8, 8, 8,
                                8, 8, 8, 8
                             };
    int x;
    int y;
    int coord[] = {-1, -1};
    int asize[] = {16, 16, 4, 4};

    everything(coord, frame, window, asize);
    printf("<%d, %d>\n", coord[0], coord[1]);

    everything(coord, frame2, window2, asize);
    printf("<%d, %d>\n", coord[0], coord[1]);

    everything(coord, frame3, window3, asize);
    printf("<%d, %d>\n", coord[0], coord[1]);

    return 0;
}