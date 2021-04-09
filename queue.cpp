#include <iostream>
using namespace std;

/* given structure of the queue class */
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

/* methods asked to be implemented */

//Function to push an element x in a queue.
void MyQueue :: push(int x) {
        this->rear++;
        this->arr[(this->rear)-1]=x;
        //cout << "rear" <<"[" << this->rear << "] = " << x << endl;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop() {
    if(this->rear==this->front) {
        return -1;
    }
    else {
        this->front++;
        return this->arr[this->front-1];
    }

}