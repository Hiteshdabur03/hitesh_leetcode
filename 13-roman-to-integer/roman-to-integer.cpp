class Solution {
public:
    #define I 1
    #define V 5
    #define X 10
    #define L 50
    #define C 100
    #define D 500
    #define M 1000

int romanToInt(string s) {
    int sum = 0;
    int arr[20];
    for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                arr[i] = I;
            }if (s[i] == 'V') {
                arr[i] = V;
            }if (s[i] == 'X') {
                arr[i] = X;
            }if (s[i] == 'L') {
                arr[i] = L;
            }if (s[i] == 'C') {
                arr[i] = C;
            }if (s[i] == 'D') {
                arr[i] = D;
            }if (s[i] == 'M') {
                arr[i] = M;
            }
    }
    for (int i = 0; i < s.size(); i++) {
        if (arr[i] == arr[i+1]) {
            sum += arr[i];
        }
        else if((s.size() - i) > 1) {
            if (arr[i] > arr[i + 1] && arr[i + 2] > arr[i + 1]) {
                sum += arr[i] - arr[i + 1];
                i++;
            }
            else if (arr[i] > arr[i + 1] && arr[i + 2] <= arr[i + 1]) {
                sum += arr[i] + arr[i + 1];
                i++;
            }
            else if (arr[i] < arr[i + 1]) {
                sum += arr[i + 1] - arr[i];
                i++;
            }
       }
       else {
           if (arr[i] > arr[i + 1]) {
               sum += arr[i] + arr[i + 1];
           }
           else if (arr[i] < arr[i + 1]) {
               sum += arr[i+1] - arr[i];
           }
       }
    }
    return sum;
};
};