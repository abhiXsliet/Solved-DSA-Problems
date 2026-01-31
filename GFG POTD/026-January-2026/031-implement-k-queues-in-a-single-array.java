// https://www.geeksforgeeks.org/problems/implement-k-queues-in-a-single-array/1/




class kQueues {

    int[] arr;     // stores elements
    int[] front;   // front of each queue
    int[] rear;    // rear of each queue
    int[] next;    // next index (queue links + free list)
    int free;      // head of free list
    int n, k;

    // Constructor
    kQueues(int n, int k) {
        this.n = n;
        this.k = k;

        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // initialize queues as empty
        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        // initialize free list
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        free = 0;
    }

    // enqueue x into i-th queue
    void enqueue(int x, int i) {
        if (isFull()) return;   // overflow protection

        int index = free;       // get free index
        free = next[index];     // update free list

        arr[index] = x;

        if (front[i] == -1) {
            front[i] = index;
        } else {
            next[rear[i]] = index;
        }

        next[index] = -1;
        rear[i] = index;
    }

    // dequeue from i-th queue
    int dequeue(int i) {
        if (isEmpty(i)) return -1;

        int index = front[i];
        front[i] = next[index];

        // add removed index to free list
        next[index] = free;
        free = index;

        return arr[index];
    }

    // check if i-th queue is empty
    boolean isEmpty(int i) {
        return front[i] == -1;
    }

    // check if array is full
    boolean isFull() {
        return free == -1;
    }
}