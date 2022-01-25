#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    int sizePassed;
    
    sizePassed = 37;
    printf("Checking Tshirt Size of %d\n",sizePassed);
    assert(size(sizePassed) == 'S');
    printf("All is well (maybe!)\n");
    
    sizePassed = 40;
    printf("Checking Tshirt Size of %d\n",sizePassed);
    assert(size(sizePassed) == 'M');
    printf("All is well (maybe!)\n");
    
    sizePassed = 43;
    printf("Checking Tshirt Size of %d\n",sizePassed);
    assert(size(sizePassed) == 'L');
    printf("All is well (maybe!)\n");
   
    /* Negative Testcases for uncovered inputs */
    sizePassed = 38;
    printf("Checking Tshirt Size of %d\n",sizePassed);
    assert(size(sizePassed) == 'M');
    printf("All is well (maybe!)\n");
   
    sizePassed = 42;
    printf("Checking Tshirt Size of %d\n",sizePassed);
    assert(size(sizePassed) == 'L');
    printf("All is well (maybe!)\n");
    
    return 0;
}
