#include <stdio.h>
#include <assert.h>
void testNumberColorPairCode(int colorNum, int majorColorCode, int minorColorCode);

int colorCodeCombo;
int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
            testNumberColorPairCode(i*5+j,i,j);
        }
    }
    return i * j;
}

void testNumberColorPairCode(int colorNum, int majorColorCode, int minorColorCode)
{
    int expectedColorCombo;
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
    expectedColorCombo = (colorNum+1) + colorCodeCombo;
    printf("actual color code \n pair number = %d \tcolor combo = %d\n",colorNum+1, expectedColorCombo);
    assert((colorNum+1) == expectedColorCombo);
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
