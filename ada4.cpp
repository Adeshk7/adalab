#include <iostream>
#include <vector>
#include <iomanip> // setprecision()
#include <cstdlib> // clock_t
using namespace std;

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> randomnumbers(vector<int> arr, int n)
{
    int N = 100; // This function will generate random numbers for n=50 it will generate 50 numbers
    for (int i = 0; i < n; i++)
    {
        arr.push_back(rand() % N);
    }

    return arr;
}

void merge(vector<int>& arr, int start, int end)
{
    int mid = (start + end) / 2;

    int firstlen = mid - start + 1;
    int secondlen = end - mid;

    vector<int> firstList(firstlen);
    vector<int> secondList(secondlen);

    int p = start;
    for (int i = 0; i < firstlen; i++)
    {
        firstList[i] = arr[p];
        p++;
    }

    for (int i = 0; i < secondlen; i++)
    {
        secondList[i] = arr[p];
        p++;
    }

    int start1 = 0;
    int start2 = 0;

    while (start1 < firstlen && start2 < secondlen)
    {
        if (firstList[start1] < secondList[start2])
        {
            arr[start++] = firstList[start1++];
        }
        else
        {
            arr[start++] = secondList[start2++];
        }
    }

    while (start1 < firstlen)
    {
        arr[start++] = firstList[start1++];
    }

    while (start2 < secondlen)
    {
        arr[start++] = secondList[start2++];
    }
}

void mergeSort(vector<int>& arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end);
    }
}

int main()
{
    vector<int> arr ={2,1,4,3,6,7,5}; // creating a dynamic array

   /* print(arr);

    mergeSort(arr,0,arr.size()-1);

    print(arr);*/

    for(int input_size=1000;input_size<50000;input_size = input_size +1000){


     // generating random numbers
    arr = randomnumbers(arr, input_size);

     // to calculate time if an algorithm runs 100 times for a specific input
    clock_t start, end;

    start = clock();

   for (int i = 0; i < 100; i++)
         mergeSort(arr,0,arr.size()-1);

     end = clock();

    // total time taken for running an algorithm 100 times for a specific input
    double time_taken = double(end - start) / CLOCKS_PER_SEC;

     //avearge time time_taken/100
     double average_time = time_taken / 100;

     cout << "\nAverage Time taken by for input size " << input_size << " is : " << fixed
       << time_taken << setprecision(5);
    cout << " sec " << endl;

     }

    return 0;
}
