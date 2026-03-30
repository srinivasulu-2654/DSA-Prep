class myQueue {

  public:
  
    int *arr;
    int size;
    int front;
    int rear;
  
    myQueue(int n) {
        // Define Data Structures
        arr = new int[n];
        size = n;
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front == -1 || front > rear;
    }

    bool isFull() {
        // check if the queue is full
        return rear + 1 == size;
    }

    void enqueue(int x) {
        
        if(rear == size - 1) return;
       
      if(front == -1) front = 0;
      rear++;
      arr[rear] = x;
    }

    void dequeue() {
        if(isEmpty()) return;

        if(front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        
    }

    int getFront() {
        if(isEmpty()) return -1;
    return arr[front];
    }

    int getRear() {
        if(isEmpty()) return -1;
    return arr[rear];
    }
};
