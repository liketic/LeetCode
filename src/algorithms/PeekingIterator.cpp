// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    hasValue = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    if (this->hasValue) {
	        return this->last;
	    }
        this->last = Iterator::next();
        this->hasValue = true;
        return this->last;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (this->hasValue) {
	        this->hasValue = false;
	        return this->last;
	    }
	    return Iterator::next();
	}

	bool hasNext() const {
	    return hasValue ? true : Iterator::hasNext();
	}
private:
    int last;
    bool hasValue;
};
