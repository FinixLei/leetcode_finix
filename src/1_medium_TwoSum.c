/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct _HashNode {
    int key;
    int val;  // index in the array
    struct _HashNode * next;
} HashNode;

static int HASH_TABLE_SIZE = 10000;

static inline int getHashTableIndex(int value) {
    return abs(value) % HASH_TABLE_SIZE;
}

// return the value's index in nums, otherwise return -1
int checkIfExistsInHashTable(HashNode** ht, int value) {
    int index = getHashTableIndex(value);
    if (ht[index] == NULL) return -1;

    HashNode * p = ht[index];
    while (p != NULL) {
        if (p->key == value) return p->val; 
        else p = p->next;
    }
    return -1;
}

void clearHashTable(HashNode ** ht) {
    int i = 0;
    HashNode * p = NULL;
    HashNode * n = NULL;

    if (ht == NULL) return;

    for (i=0; i<HASH_TABLE_SIZE; i++) {
        if (ht[i] == NULL) continue;
        p = ht[i];
        n = p->next;
        while (n != NULL) {
            free(p);
            p = n;
            n = n->next;
        }
        free(p);
    }
    free(ht);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashNode ** hashTable = (HashNode **) malloc (sizeof(HashNode *) * HASH_TABLE_SIZE);
    int i = 0;
    int hashIdx = -1;
    int rest = 0, restIdx = -1;
    int * res = (int *) malloc (sizeof(int) * 2);
    res[0] = -1;
    res[1] = -1;
    *returnSize = 0;

    for (i=0; i<HASH_TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    for (i=0; i<numsSize; i++) {
        hashIdx = getHashTableIndex(nums[i]);
        HashNode * p = (HashNode *) malloc (sizeof(HashNode));
        p->key = nums[i];
        p->val = i;
        p->next = NULL;

        if (hashTable[hashIdx] == NULL) hashTable[hashIdx] = p;
        else p->next = hashTable[hashIdx];
    }

    for (i=0; i<numsSize; i++) {
        rest = target - nums[i];
        restIdx = checkIfExistsInHashTable(hashTable, rest);
        if (restIdx >= 0 && restIdx != i) {
            res[0] = i;
            res[1] = restIdx;
            *returnSize = 2;
            break;
        }
    }
    
    clearHashTable(hashTable);
    if (*returnSize == 2) {
        return res;
    }
    free(res);
    return NULL;
}
