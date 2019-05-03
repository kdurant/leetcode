#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

int search(int* nums, int numsSize, int target){
	int left = 0;
	int right = numsSize - 1;

	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(nums[mid] == target)
			return mid;
		else if(nums[mid] < target)
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return - 1;
}

int main()
{
	int A[] = {-1,0,3,5,9,12};
	printf("%d\n", search(A, sizeof(A)/4, 9));

}