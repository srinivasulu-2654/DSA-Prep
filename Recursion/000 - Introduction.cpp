/*
  -> A function that calls itself is known as recursive function and phenomenon of calling the same function 
     again and again from itslef only called as Recursion
  -> Check here pass by value and pass by reference
  Pass by Value:
  
      #include <iostream>
    using namespace std;
    
    void fun(int x) {
        if (x == 0) return;
    
        cout << x << " ";
        fun(x - 1);
    }
    
    int main() {
        int n = 3;
        fun(n);
    }
    
  Pass by reference:
    
      #include <iostream>
    using namespace std;
    
    void fun(int &x) {
        if (x == 0) return;
    
        cout << x << " ";
        x--;           // modifies original variable
        fun(x);
    }
    
    int main() {
        int n = 3;
        fun(n);
    
        cout << "\nFinal n: " << n;
    }

    Pass by value → each call independent
    Pass by reference → all calls share same data

  
*/
