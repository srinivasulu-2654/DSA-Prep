class myStack {
    queue<int> q;

  public:
    
    void push(int x) {
       
       int sz = q.size();
       q.push(x);
       for(int i=0;i<sz;i++)
       {
           q.push(q.front());
           q.pop();
       }
    }

    void pop() {
        // Removes an element from the top of the stack
        if(q.empty()) return;
        q.pop();
    }

    int top() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(q.empty()) return -1;
        return q.front();
    }

    int size() {
        // Returns the current size of the stack
        return q.size();
    }
};
