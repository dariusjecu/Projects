#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
    int x,max=-99999;
    ifstream f("/home/sdav/parallel-computing/Sorted/array.txt");
    while(!f.eof())
    {
        f>>x;
        if(x>max)
            max=x;
    }
    
    cout<<max<<endl;
    return 0;
}
