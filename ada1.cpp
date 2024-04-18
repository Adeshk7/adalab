
#include <iostream>
#include <time.h>
#include <vector>
#include <iomanip>
#include <cstdlib> 
using namespace std;

vector<int> randomnumbers(vector<int> arr, int n)
{
    int N=100;
    for (int i = 0; i < n; i++){
        arr.push_back(rand() % N);
    }

    return arr;
}

void print(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

void SelectionSort(vector<int> &arr)
{
    int min;
    for (int i = 0; i < arr.size(); i++)
    {
        min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            swap(arr[min], arr[i]);
        }
    }
}

int main()
{
    vector<int> arr;

    arr=randomnumbers(arr,100);
    print(arr);



    
    clock_t start, end;

    start = clock();

    for(int i=0;i<100;i++)
    SelectionSort(arr);

    end = clock();
    cout<<"\n-------------------------------"<<endl;
    cout<<"\n sorted array is :-"<<endl;
    print(arr);
    

	double timetaken = double(end - start)/CLOCKS_PER_SEC;
    double average_time=timetaken/100;
	cout << "\nAverage Time taken by program is : " << fixed 
		<< timetaken << setprecision(5);
	cout << " sec " << endl;
	
    return 0;
}