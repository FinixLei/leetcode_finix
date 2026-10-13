/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void * a, const void * b) {
    return *(const int *)a - *(const int *)b;
}

typedef struct _Node {
    int a;
    int b; 
    int c;
    struct _Node * next;
} Node;

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** res = NULL;
    int i = 0, j = 0, k = 0;
    int tmp = 0;
    int count = 0;
    Node * head = NULL;

    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);

    for (i=0; i<numsSize-2; i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i-1]) continue;

        j = i + 1;
        k = numsSize - 1;

        while (j < k) {
            tmp = nums[j] + nums[k];
            if (tmp < -nums[i]) {
                j++;
            }
            else if (tmp > -nums[i]) {
                k--;
            }
            else {
                Node * p = (Node *) malloc (sizeof(Node));
                p->a = nums[i];
                p->b = nums[j];
                p->c = nums[k];
                p->next = head;
                head = p;

                count ++;
                while (j<k && nums[j]==nums[j+1]) j++;
                while (j<k && nums[k-1]==nums[k]) k--;
                j++;
                k--;
            }
        }
    }
    res = (int **) malloc (sizeof(int*) * count);
    for (i=0; i<count; i++) {
        res[i] = (int *) malloc (sizeof(int) * 3);
        res[i][0] = head->a;
        res[i][1] = head->b;
        res[i][2] = head->c;
        head = head->next;
    }

    *returnSize = count;

    if (count > 0) {
        *returnColumnSizes = (int *) malloc (sizeof(int) * count);
        for (i=0; i<count; i++) {
            (*returnColumnSizes)[i] = 3;
        }
        return res;
    }
    // count = 0
    returnColumnSizes = NULL;
    return res;    
}
