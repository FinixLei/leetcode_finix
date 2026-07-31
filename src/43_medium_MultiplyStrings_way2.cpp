class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        const int size1 = num1.size();
        const int size2 = num2.size();
        const int max_size = size1 + size2;

        int array[size2][max_size];
        for (int i=0; i<size2; i++) {
            memset((char*)(&array[i][0]), 0, max_size*sizeof(int));
        }

        for (int i=size2-1; i>=0; i--) {
            int go = 0;
            int curr_j = 0;
            for (int j=size1-1; j>=0; j--) {
                int tmp = (num2[i] - '0') * (num1[j] - '0');
                int d = tmp + go;
                if (d > 9) {
                    d  = (tmp + go) % 10;
                    go = (tmp + go) / 10;
                }
                else {
                    go = 0;  // recover go 
                }
                
                // "max_size - (size1 - j)" is the col offset
                // "-(size2 - i - 1)" is the offset for row
                curr_j = max_size - (size1-j) - (size2-i-1);  // curr_j = i+j+1
                array[size2-i-1][curr_j] = d;  // row is size2-i-1
            }
            array[size2-i-1][curr_j-1] = go;  // regardless go > 0 or not
        }
        
        int result[max_size];
        memset(result, 0, max_size);

        int go = 0;
        for (int j=max_size-1; j>=0; j--) {
            int sum = 0;
            for (int i=0; i<size2; i++) {
                sum += array[i][j];
            }
            sum += go;
            if (sum <= 9) {
                result[j] = sum;
                go = 0;
            }
            else {
                result[j] = sum % 10;
                go = (sum-result[j]) / 10;
            }
        }

        int start = 0;
        while (start<max_size && result[start] == 0) {
            start ++;
        }

        string s = "";
        for (int i=start; i<max_size; i++) {
            s.push_back((char)(result[i] + '0'));
        }
        return s;
    }
};
