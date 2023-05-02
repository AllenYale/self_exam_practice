#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;

//定义划分函数，用于将待排序数组划分成两部分，一部分小于pivot，一部分大于pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; //以最右侧元素作为中轴元素
    int i = low - 1; //i用于记录当前小于pivot的元素的最后一个所在的位置

    for (int j = low; j <= high - 1; j++) //遍历整个区间，除了最右侧的pivot元素
    {
        if (arr[j] < pivot) //如果当前元素小于pivot，就把它放到前面的一部分中去
        {
            i++;
            swap(arr[i], arr[j]); //交换位置，保证当前元素之前的所有元素都比pivot小
        }
    }
    swap(arr[i + 1], arr[high]); //经过上述操作，i+1的位置就是pivot最终停留的位置，我们把它交换到正确的位置上
    return (i + 1); //返回pivot的位置
}

//定义快速排序函数
void quickSort(int arr[], int low, int high)
{
    if (low < high) //只有当区间长度大于等于2时才需要排序
    {
        int pi = partition(arr, low, high); //获得pivot的位置
        quickSort(arr, low, pi - 1); //对左半部分进行递归排序
        quickSort(arr, pi + 1, high); //对右半部分进行递归排序
    }
}


void bubbleSort(int arr[], int n) //定义冒泡排序函数
{
    for (int i = 0; i < n - 1; i++) //外层循环控制比较轮数，共进行n-1轮
    {
        for (int j = 0; j < n - i - 1; j++) //内层循环控制每轮中比较次数，因为每轮比较后最大的数会放在最后，所以随着轮数增加，比较范围逐渐缩小
        {
            if (arr[j] > arr[j + 1]) //如果前一个数比后一个数大，则交换两个数的位置
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // int arr[] = { 10, 7, 8, 9, 1, 5 };
    const int n = 10000;
    int arr[n];

    // 生成随机数组
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    // int n = sizeof(arr) / sizeof(arr[0]);
     // cout << "after quick sorting: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

     // 计时开始
    auto start = chrono::high_resolution_clock::now();


    // quickSort(arr, 0, n - 1);//Sorting time: 969 microseconds.

    bubbleSort(arr,n);//Sorting time: 166137 microseconds.

   
     // 计时结束
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // 输出排序时间
    cout << "Sorting time: " << duration.count() << " microseconds." << endl;
    return 0;
}
