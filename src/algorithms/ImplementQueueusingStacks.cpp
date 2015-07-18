class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> temp;
        while (!q.empty()) {
            temp.push(q.top());
            q.pop();
        }
        q.push(x);
        while (!temp.empty()) {
            q.push(temp.top());
            temp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        q.pop();
    }

    // Get the front element.
    int peek(void) {
        return q.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return q.empty();
    }
private:
    stack<int> q;
};
