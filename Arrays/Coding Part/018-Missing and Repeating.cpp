Approach - 1:

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here

    long long n = a.size();

    // 1. do (sum of array el's - sum of first n natural num's) => S - Sn = x - y
    // 2. do same like that only but now squares

    long long Sn = (n*(n+1))/2;
    long long S2n = (n*(n+1)*(2*n+1)) / 6;
    long long S1 = 0,S2 = 0;

    for(int i=0;i<n;i++){
        S1 += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    long long val1 = S1 - Sn; // x - y
    long long  val2 = S2 - S2n;
    val2 = val2/val1; // x+y

    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x,(int)y};

}

Approach 2 :

Must see please it would be like Bitwise operators of XOR
