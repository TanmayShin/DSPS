#include <iostream>
using namespace std;

#define MAX 10

class Deque {
private:
    int deque[MAX];
    int front;
    int rear;

public:
    Deque() 
    {
        front = -1;
        rear = -1;
    }

    void insertFront(int ele) 
    {
        
        if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) 
        {
            cout << "Deque is full" << endl;
            return;
        }

      
        if (front == -1) 
        {
            front = rear = 0;
        } 
        else if (front == 0) 
        {
            front = MAX - 1;  
        } 
        else 
        {
            front--;
        }

        deque[front] = ele;
    }

    void insertRear(int ele) 
    {
     
        if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) 
        {
            cout << "Deque is full" << endl;
            return;
        }

        
        if (rear == -1) 
        {
            front = rear = 0;
        } 
        else if (rear == MAX - 1) 
        {
            rear = 0;  
        } 
        else 
        {
            rear++;
        }

        deque[rear] = ele;
    }

    void deleteFront() 
    {
        
        if (front == -1) 
        {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Element deleted from front is " << deque[front] << endl;

      
        if (front == rear) 
        {
            front = rear = -1;  
        } 
        else if (front == MAX - 1) 
        {
            front = 0;  
        } 
        else 
        {
            front++;
        }
    }

    void deleteRear() 
    {
        
        if (rear == -1) 
        {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Element deleted from rear is " << deque[rear] << endl;

        
        if (front == rear) 
        {
            front = rear = -1;  
        } 
        else if (rear == 0) 
        {
            rear = MAX - 1;  
        } 
        else 
        {
            rear--;
        }
    }

    void display() 
    {
        
        if (front == -1) 
        {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Deque elements are: ";

        if (front <= rear) 
        {
          
            for (int i = front; i <= rear; i++) 
            {
                cout << deque[i] << " ";
            }
        } 
        else 
        {
           
            for (int i = front; i < MAX; i++) 
            {
                cout << deque[i] << " ";
            }
            for (int i = 0; i <= rear; i++) 
            {
                cout << deque[i] << " ";
            }
        }

        cout << endl;
    }
};

int main() 
{
    Deque dq;
    int ch, ele;
    do 
    {
        cout << "\n1. Insert element at front\n2. Insert element at rear\n3. Delete element from front\n4. Delete element from rear\n5. Display deque elements\n0. Exit\nChoose: ";
        cin >> ch;
        switch (ch) 
        {
            case 1:
                cout << "Enter the element: ";
                cin >> ele;
                dq.insertFront(ele);
                break;
            case 2:
                cout << "Enter the element: ";
                cin >> ele;
                dq.insertRear(ele);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                dq.display();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Wrong choice" << endl;
        }
    } while (ch != 0);
    return 0;
}
