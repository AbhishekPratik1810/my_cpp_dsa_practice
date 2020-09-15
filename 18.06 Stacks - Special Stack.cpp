//https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}

int currMin;

int _stack :: getMin()
{
   if(s.empty())
    return -1;
   else
    return currMin;
}


int _stack ::pop()
{
   if(s.empty())
    return -1;

   int toReturn;

   if(s.top()>=currMin)
        toReturn = s.top();
   else{
        toReturn = currMin;
        currMin =  (2*currMin-s.top());
   }
   s.pop();

   return toReturn;
}

void _stack::push(int x)
{
   if(s.empty()){
       currMin = x;
       s.push(x);
       return;
   }
   if(x>=currMin)
    s.push(x);

   else{
       s.push(2*x-currMin);
       currMin = x;
   }
}
