class MinStack {
public:
    void push(int x) {
        this->arr.push(x);
        if (this->minValueStack.empty() || x <= this->minValueStack.top()) {
            minValueStack.push(x);
        }
    }

    void pop() {
        int topValue = this->arr.top();
        if (topValue == this->minValueStack.top()) {
            minValueStack.pop();
        }
        this->arr.pop();
    }

    int top() {
        return this->arr.top();
    }

    int getMin() {
        return this->minValueStack.top();
    }
private:
    stack<int> arr;
    stack<int> minValueStack;
};
