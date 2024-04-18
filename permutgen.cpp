/*#include<iostream>
using namespace std;
void permute(char a[], int i, int n)
{
   int j;
   if (i == n)
     //cout << a << endl;
   else
   {
       for (j = i; j <= n; j++)
       {
          swap(a[i], a[j]);          
          permute(a, i+1, n);
          swap(a[i], a[j]);
       }
   }
} 

int main()
{
   char a[] = "ABCD";
   permute(a, 0, 3);
   getchar();
   return 0;
}*/




#include<iostream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

int *gen_input(int arr[], int k)
{
    for(int i = 0; i<k ; i++)
    {
        arr[i] = rand();
    }
    return arr;
}

void permutation_generator(int arr[], int k, int n)
{
    if(k==n-1)
    {
        for(int p=0; p<n; p++)
        {
            //cout << arr[p] << "\t";
        }
        //cout<< endl;
    }
    else
    {
        for(int i=k; i<n; i++)
        {
            swap(arr[i], arr[k]);
            permutation_generator(arr, k+1, n);
            swap(arr[i], arr[k]);
        }
    }
}

int main()
{
    int *arr = new int(100000);

    for(int i=3; i<=100; i= i+1)
    {
        arr = gen_input(arr, i);
        auto start = high_resolution_clock::now();
        for(int j = 1; j<=10; j++)
        {
            permutation_generator(arr , 0, i);
        }
        auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout << "Inputs = " << i << "\t Time = " << dur.count() << endl;
    }

    return 0;
}