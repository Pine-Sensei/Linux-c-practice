#include <stdio.h>
#define LEN 4
/*由于这个序列已经从小到大排好序了，
每次取中间的元素和待查找的元素比较，
如果中间的元素比待查找的元素小，
就说明“如果待查找的元素存在，
一定位于序列的后半部分”，
这样可以把搜索范围缩小到后半部分，
然后再次使用这种算法迭代。
这种“每次将搜索范围缩小一半”的思想称为折半查找（Binary Search）。
思考一下，这个算法的时间复杂度是多少？*/
int a[LEN] = {1, 2, 3, 4};

int binarysearch(int number)
{
    int start = 0, end = LEN - 1, mid;
    while (start <= end)
    {
        mid = (end + start)/2;
        if (a[mid] == number)
		    return mid;
	    else
            if (a[mid] > number)
                start = mid + 1;    
	        else
                end = mid - 1; 
    }
    return -1;
}

int main()
{
    printf("%d\n", binarysearch(2));
}