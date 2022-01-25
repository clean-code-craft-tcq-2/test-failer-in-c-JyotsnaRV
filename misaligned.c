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
            testNumberColorPairCode(i*5+j,i,j);
        }
    }
    ColorComboVar_St.givenInputNum = i * j;
    return ColorComboVar_St;
}

void testNumberColorPairCode(int colorNum, int majorColorCode, int minorColorCode)
{
    int expectedColorCombo, combo;
    if((colorNum+1) <= 5)
    {
        colorCodeCombo = -1;
    }
    else if((colorNum+1)%5 == 0)
    {
        colorCodeCombo += 5; 
    }
    else
    {
        /* do nothing */
    }
    /* calculate the correct color code pair number with provide major and minor inputs */
    combo = majorColorCode*10;
    combo += minorColorCode;
    /* calculate the correct pair number */
    expectedColorCombo = (colorNum+1) + colorCodeCombo;
    printf("actual color code \n pair number = %d \tcolor combo = %d\n",colorNum+1, expectedColorCombo);
    ColorComboVar_St.givenColorCombo[colorNum] = combo;
    ColorComboVar_St.actualColorCobo[colorNum] = expectedColorCombo;
//    assert(ColorComboVar_St.givenColorCombo[colorNum] == ColorComboVar_St.actualColorCobo[colorNum]);
}

int main() {
    int checkComboNumber = 20;
    ColorComboCheck result_St = printColorMap();
    /* First assert will pass */
    assert(result_St.givenInputNum == 25);
    /* negative test case */
    printf(" input combination = %d \t expected combination = %d\n",result_St.givenColorCombo[checkComboNumber],result_St.actualColorCobo[checkComboNumber]);
    assert(result_St.givenColorCombo[checkComboNumber] == result_St.actualColorCobo[checkComboNumber]);
    printf("All is well (maybe!)\n");
    return 0;
}
