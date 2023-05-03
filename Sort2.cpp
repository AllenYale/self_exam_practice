#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;

void quickSort(int arr[], int left, int right)
{
    int i, j, t, temp;
    if (left > right)
        return;
    temp = arr[left]; //// temp中存的就是基准数，可任意取，取最左边的
    i = left;
    j = right;
    while (i != j)
    {   
        //// 先从右边开始找
        while (arr[j] >= temp && i < j)
            j--;
        //// 找左边的
        while (arr[i] <= temp && i < j) 
            i++;
        ////不满足上述2个while条件，交换两个数在数组中的位置
        if (i < j) 
        {
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    //// 最终将基准数归位，左边的都小于基准、右边的都大于基准数
    arr[left] = arr[i];
    arr[i] = temp;
    quickSort(arr, left, i - 1);  // 递归，继续处理左边的子序列
    quickSort(arr, i + 1, right); // 递归，继续处理右边的子序列
}

void bubbleSort(int arr[], int n) // 定义冒泡排序函数
{
    for (int i = 0; i < n - 1; i++) // 外层循环控制比较轮数，共进行n-1轮
    {
        for (int j = 0; j < n - i - 1; j++) // 内层循环控制每轮中比较次数，因为每轮比较后最大的数会放在最后，所以随着轮数增加，比较范围逐渐缩小
        {
            if (arr[j] > arr[j + 1]) // 如果前一个数比后一个数大，则交换两个数的位置
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//初始化n个elements的随机数组
int* randomArr(int n)
{
    int* arr = new int[n];

    // 生成随机数组
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

    return arr;
}

////初始化10000个elements的随机数组
const int n = 10000;

int main()
{
    int* arr1 = randomArr(n);

    // 计时开始
    auto start = chrono::high_resolution_clock::now();

    quickSort(arr1, 0, n - 1); ////quickSort Sorting time: 1890 microseconds.

    // 计时结束
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // 输出排序时间
    cout << "quickSorting time: " << duration.count() << " microseconds." << endl;

    int* arr2 = randomArr(n);
    // 计时开始
    auto start2 = chrono::high_resolution_clock::now();

    bubbleSort(arr2, n); ////bubbleSort Sorting time: 166137 microseconds.
                         // 计时结束
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
    // 输出排序时间
    cout << "bubbleSorting time: " << duration2.count() << " microseconds." << endl;

    return 0;
}

/*
快速排序
quicksort函数的参数包括了一个整型数组arr、一个左下标left和一个右下标right。
如果left > right,则直接返回，结束递归。
取arr[left]值为中间值，同时记录数组从下标left+1到下标right的范围内，比中间值小的数放在中间值左边，比中间值大的数放在中间值右边。这里使用了两个指针i和j。
当i < j时，一直循环找到第一个大于中间值的数以及第一个小于中间值的数，并交换两者位置。
重复步骤4，交换完之后，i和j在数组上移动，直到i >= j跳出循环。
将中间值与下标为i的元素进行交换。
对中间值左侧的数据和右侧的数据分别调用quicksort()函数进行递归排序。


冒泡排序
从第一个元素开始，依此比较其与相邻元素的大小。如果前一个元素大于后一个元素，则交换这两个元素。
依此比较完所有相邻元素，一轮下来之后，最后一个元素应该是整个序列中最大的元素。
重复1、2步骤，但将最后一个元素排除在比较范围之外（也就是说，下一轮比较时不再考虑最后一个元素）。
每一轮结束后，都会有一个元素被排到了正确的位置上。因此，只需要执行n-1轮比较即可。

*/
