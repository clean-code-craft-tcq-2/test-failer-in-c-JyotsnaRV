#include <stdio.h>
#include <assert.h>
void testNumberColorPairCode(int colorNum, int majorColorCode, int minorColorCode);

typedef struct{
    int givenInputNum;
    int givenColorCombo[25];
    int actualColorCobo[25];
}ColorComboCheck;
ColorComboCheck ColorComboVar_St;

int colorCodeCombo;
ColorComboCheck printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
            /* update the test related checks and value for further checks using below mentioned function */
            testNumberColorPairCode(i*5+j,i,j);
        }
    }
    ColorComboVar_St.givenInputNum = i * j;
    return ColorComboVar_St;
}

void testNumberColorPairCode(int colorNum, int majorColorCode, int minorColorCode)
{
    int expectedColorCombo, combo;
    /* refer the explanation mentioned at the bottom of this file  */
    if((colorNum) < 5)
    {
        colorCodeCombo = -1;
    }
    else if(((colorNum)%5) == 0)
    {
        colorCodeCombo += 5; 
    }
    else
    {
        /* do nothing */
    }
    /* calculate the correct color code pair number with provide major and minor inputs */
    combo = majorColorCode*10;
    /* based on line 19 where array index is used wrongly as i for both major and minor index the next line is commented for negative test case */
//    combo += minorColorCode;
(void)minorColorCode;
    combo += majorColorCode;
    /* calculate the correct pair number */
    expectedColorCombo = (colorNum+1) + colorCodeCombo;
    printf("actual color code \n pair number = %d \tcolor combo = %d\n",colorNum+1, expectedColorCombo);
    ColorComboVar_St.givenColorCombo[colorNum] = combo;
    ColorComboVar_St.actualColorCobo[colorNum] = expectedColorCombo;
//    assert(ColorComboVar_St.givenColorCombo[colorNum] == ColorComboVar_St.actualColorCobo[colorNum]);
}

int main() {
    int checkComboNumber = 20; /* input anything between 0 - 24 */
    ColorComboCheck result_St = printColorMap();
    /* First assert will pass */
    assert(result_St.givenInputNum == 25);
    /* negative test case where combination will not match with the pair number*/
//    printf(" pair number = %d \t input combination = %d \t expected combination = %d\n",checkComboNumber, result_St.givenColorCombo[checkComboNumber],result_St.actualColorCobo[checkComboNumber]);
    assert(result_St.givenColorCombo[checkComboNumber] == result_St.actualColorCobo[checkComboNumber]);
    printf("All is well (maybe!)\n");
    return 0;
}

/* Reference serial number of color combos for testNumberColorPairCode function
n => 0 to 24

if n<5, combo = n-1
0   00
1   01
2   02
3   03
4   04

combo += 5
5   10
6   11
7   12
8   13
9   14

combo += 5
10  20
11  21
12  22
13  23
14  24

combo += 5
15  30
16  31
17  32
18  33
19  34

combo += 5
20  40
21  41
22  42
23  43
24  44

*/
