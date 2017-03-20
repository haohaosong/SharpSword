#pragma once

/*
* author:haohaosong
* date:2017/3/15
* note:ì³²¨ÄÇÆõÊýÁÐ
*/

long long Fib(size_t n)  
{  
    if (n <= 2)  
        return n - 1;  
  
    return Fib(n - 1) + Fib(n - 2);  
}  

long long FibNonR(size_t n)  
{  
    if (n <= 2)  
        return n - 1;  
  
    long long f1 = 0;  
    long long f2 = 1;  
    long long f = 0;  
    for (size_t i = 2; i < n; ++i)  
    {  
        f = f1 + f2;  
  
        f1 = f2;  
        f2 = f;  
    }  
  
    return f;  
}  