#pragma once

/*
* author:haohaosong
* date:2017/3/14
* note:面试题-7 两个栈实现一个队列，两个队列实现一个栈
*/

//两个栈实现一个队列
template<typename T>  
class QueueBTS  
{  
public:  
    void Push(const T& x)  
    {  
        sin.push(x);  
    }  
    void Pop()  
    {  
        assert(!sin.empty() || !sout.empty());  
        if (sout.empty())  
        {  
            while (!sin.empty())  
            {  
                sout.push(sin.top());  
                sin.pop();  
            }  
        }  
        sout.pop();  
    }  
  
    const T& Front()  
    {  
        assert(!sin.empty() || !sout.empty());  
        if (sout.empty())  
        {  
            while (!sin.empty())  
            {  
                sout.push(sin.top());  
                sin.pop();  
            }  
        }  
        return sout.top();  
    }  
protected:  
    stack<T> sin;//入列的栈  
    stack<T> sout;//出列的栈  
};  

//两个队列实现一个栈  
template<typename T>  
class StackBTQ  
{  
public:  
    void Push(const T& x)  
    {  
        //入栈的元素直接push到qin里面  
        qin.push(x);  
    }  
  
    void Pop()  
    {  
        assert(!qin.empty() || !qout.empty());  
        //qin队列为空  
        if (qin.empty())  
        {  
            while (qout.size() > 1)  
            {  
                qin.push(qout.front());  
                qout.pop();  
            }  
            qout.pop();  
        }  
        else//qin队列不为空  
        {  
            while (qin.size() > 1)  
            {  
                qout.push(qin.front());  
                qin.pop();  
            }  
            qin.pop();  
        }  
    }  
  
    T Top()  
    {  
        assert(!qin.empty() || !qout.empty());  
        //qin队列为空  
        if (qin.empty())  
        {  
            while (qout.size() > 1)  
            {  
                qin.push(qout.front());  
                qout.pop();  
            }  
            return qout.front();  
        }  
        else//qin队列不为空  
        {  
            while (qin.size() > 1)  
            {  
                qout.push(qin.front());  
                qin.pop();  
            }  
            return qin.front();  
        }  
    }  
protected:  
    queue<T> qin;  
    queue<T> qout;  
};  