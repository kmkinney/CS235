#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <math.h>
using namespace std;

int fibonacci(int n)
{
    if(n<2)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);

}



int recursive_better(int current, int prev, int n)
{
    if(n<=1)
        return current;
    return recursive_better(current +  prev, current, n-1);
}

int fib_better(int n)
{
    return recursive_better(1, 1, n);
}

int fib_iter(int n)
{
    if (n < 2)
        return 1;
    int n0 = 1;
    int n1 = 1;
    int res = 0;
    for(int i = 1;i < n; i++)
    {
        res = n0 + n1;
        n0 = n1;
        n1 = res;
    }
    return res;
}

int main()
{
    //Timing inefficient fibonacci
    clock_t oldtime, newtime;
    double seconds;
    int n, rval;

    //Iterative
    cout << "Enter an integer: ";
    cin >> n;
    cout << endl;
    oldtime = clock();
    rval = fib_iter(n);
    newtime = clock();
    seconds = (double)(newtime - oldtime) /CLOCKS_PER_SEC;
    cout << "Fib of " << n << " equals " << rval << endl;
    cout << "Took " << seconds << " seconds iteratively" << endl; 
    
    //Old recursive
    oldtime = clock();
    rval = fibonacci(n);
    newtime = clock();
    seconds = (double)(newtime - oldtime) /CLOCKS_PER_SEC;
    cout << "Fib of " << n << " equals " << rval << endl;
    cout << "Took " << seconds << " seconds recursively" << endl; 

    //New recursive
    oldtime = clock();
    rval = fib_better(n);
    newtime = clock();
    seconds = (double)(newtime - oldtime) /CLOCKS_PER_SEC;
    cout << "Fib of " << n << " equals " << rval << endl;
    cout << "Took " << seconds << " seconds recursively with better approach" << endl; 
    return 0;
}