#include<bits/stdc++.h>
#include <time.h>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

 


long double power(int m, int n) {
 
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        long double temp = power(m, n / 2);
        return temp * temp;
    } else {
        return m * power(m, n - 1);
    }
  

}


int main(){
     auto start = high_resolution_clock::now();

   cout<<" the answer is "<< power(2,1000)<<endl;
 auto stop = high_resolution_clock::now();

        auto dur = (duration_cast<nanoseconds>(stop - start))/10;

        cout <<  "\t Time = " << dur.count() << endl;
  
}