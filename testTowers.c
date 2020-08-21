#include "towers.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void noNullArguments()
{
	{
	    int xCoords[] = {2,3};
	    int yCoords[] = {1,-1};
	    int heights[] = {4, 3};
	    int numTowers = 2;
	    int maxStars = -1;
	    int *tileCounts = splittingTowers(NULL, yCoords, heights, numTowers,&maxStars);

	    assert(!tileCounts);
	    assert(maxStars == -1);
	    //might need to free tileCounts
	    tileCounts = splittingTowers(xCoords, NULL, heights, numTowers, &maxStars);
	    assert(!tileCounts);
	    assert(maxStars == -1);
	    tileCounts = splittingTowers(xCoords, yCoords, NULL, numTowers, &maxStars);
	    assert(!tileCounts);
	    assert(maxStars == -1);
	    tileCounts = splittingTowers(xCoords, yCoords, NULL, numTowers, &maxStars);
	    assert(!tileCounts);
	    assert(maxStars == -1);
	    tileCounts = splittingTowers(xCoords, yCoords, heights, numTowers, NULL);
	    assert(!tileCounts);
	    assert(maxStars == -1);
	}
}

void noNegNumStones()
{
    {
        int xCoords[] = {2,3};
	    int yCoords[] = {1,-1};
	    int heights[] = {-4, 3};
	    int numTowers = 2;
	    int maxStars = -1;
	    int *tileCounts = splittingTowers(xCoords, yCoords, heights, numTowers,&maxStars);
        assert(!tileCounts);
    }

    {
        int xCoords[] = {2,3};
	    int yCoords[] = {1,-1};
	    int heights[] = {-4, -3};
	    int numTowers = 2;
	    int maxStars = -1;
	    int *tileCounts = splittingTowers(xCoords, yCoords, heights, numTowers,&maxStars);
        assert(!tileCounts);
    }
}

void testInitializeBoard()
{
    {
        /*
        int xCoords[] = {2,3,-2,-4};
	    int yCoords[] = {1,-1,-1,4};
	    int heights[] = {4, 3, 2, 1};
	    int numTowers = 4;
	    int maxStars = -1;
	    int *arr = splittingTowers(xCoords, yCoords, heights, numTowers,&maxStars);
        free(arr);
        */
    }
        
    {
        int xCoords[] = {1,2,1,0,1};
	    int yCoords[] = {1,1,2,1,0};
	    int heights[] = {11, 8, 5, 7, 3};
	    int numTowers = 5;
	    int maxStars = -1;
	    int *arr = splittingTowers(xCoords, yCoords, heights, numTowers,&maxStars);
        printf("maxStars = %d\n", maxStars);

        for(int i = 0; i < maxStars; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        free(arr);
    }
}

void testTowers(void)
{
    testInitializeBoard();
    //fprintf(stderr, "%s(): All test cases passed!\n", __FUNCTION__);
}

int main()
{
    testTowers();
}
