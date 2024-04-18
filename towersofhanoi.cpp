#include<iostream>
#include<chrono>
#include<fstream>
#include<cstdlib>




using namespace std:: chrono;
using std::ofstream;
using namespace std;


void towerOfHanoi(int n, char from_rod, char to_rod,
                 char aux_rod)
{
   if (n == 0) {
       return;
   }
   towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
   towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}




void timecomp()
{

for(int i=3;i<=10000;i=i+1)
{

auto start=high_resolution_clock :: now();


for(int j=1;j<=10;j++)
{
    towerOfHanoi(i, 'A', 'C', 'B');
}


auto stop=high_resolution_clock :: now();

auto duration = duration_cast<microseconds>(stop - start)/10;
float dur=duration.count();

cout<<i<<" " << dur<<endl;

}

}




int main()
{

    timecomp();

return 0;
}
