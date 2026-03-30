/* 
    -> here we have to use 2 stacks
    -> s1 and  s2
    -> for push:
        Steps:
        -> s1->s2;
        -> x -> s1;
        -> s2 -> s1

    -> so here queue follows FIFO and stack follows LIFO right
    -> so that's why we are doing this thing

*/


class myQueue {
    
    stack<int>st1;
    stack<int>st2;

  public:
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        // Implement enqueue operation
        
        int s1 = st1.size();
        for(int i=0;i<s1;i++)
        {
            st2.push(st1.top());
            st1.pop();
        }
        
        st1.push(x);
        
        int s2 = st2.size();
        for(int i=0;i<s2;i++)
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    void dequeue() {
        // Implement dequeue operation
        
        if(st1.empty()) return;
        return st1.pop();
    }

    int front() {
        // Implement front operation
        
        if(st1.empty()) return -1;
        return st1.top();
    }

    int size() {
        // Implement size operation
        return st1.size();
    }
};
