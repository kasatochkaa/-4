#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    Queue<int> queue1;
    queue1.print();
    cout<<endl;
    queue1.push(15);
    queue1.push(23);
    queue1.push(23);
    queue1.push(23);
    queue1.push(23);
    queue1.push(23);
    queue1.push(23);
    queue1.push(23);
    queue1.push(23);
    queue1.push(23);
    queue1.push(23);
    queue1.push(23);
    queue1.push(1);
    queue1.print();
    cout<<endl<<queue1.top()<<endl;
    cout<<endl<<queue1.pop()<<endl;
    queue1.print();
    cout<<endl;
    Queue<int> queue2(queue1);
    queue2.print();
    queue2.pop();
    queue2.pop();
    queue2.pop();
    queue2.pop();
    queue2.pop();
    queue2.pop();
    cout<<endl;
    queue1.clear();
    queue1.print();
    cout<<endl;
    queue1 = queue2;
    queue1.print();
    return 0;
}
