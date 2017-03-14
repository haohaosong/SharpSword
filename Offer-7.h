#pragma once

/*
* author:haohaosong
* date:2017/3/14
* note:������-7 ����ջʵ��һ�����У���������ʵ��һ��ջ
*/

//����ջʵ��һ������
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
    stack<T> sin;//���е�ջ  
    stack<T> sout;//���е�ջ  
};  

//��������ʵ��һ��ջ  
template<typename T>  
class StackBTQ  
{  
public:  
    void Push(const T& x)  
    {  
        //��ջ��Ԫ��ֱ��push��qin����  
        qin.push(x);  
    }  
  
    void Pop()  
    {  
        assert(!qin.empty() || !qout.empty());  
        //qin����Ϊ��  
        if (qin.empty())  
        {  
            while (qout.size() > 1)  
            {  
                qin.push(qout.front());  
                qout.pop();  
            }  
            qout.pop();  
        }  
        else//qin���в�Ϊ��  
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
        //qin����Ϊ��  
        if (qin.empty())  
        {  
            while (qout.size() > 1)  
            {  
                qin.push(qout.front());  
                qout.pop();  
            }  
            return qout.front();  
        }  
        else//qin���в�Ϊ��  
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