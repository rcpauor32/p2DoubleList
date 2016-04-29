#ifndef __P2DOUBLELIST_H__
#define	__P2DOUBLELIST_H__

typedef unsigned int uint;

template<class T>

class DoubleList {
	struct node {
	public:
		mutable T data;
		node* next = nullptr;
		node* prev = nullptr;

	public:
		node(){}
		node(const T& data) : data(data) {}

	};

public:
	DoubleList() {
		iterator = root;
	}
	virtual ~DoubleList(){}
private:
	node* root;
	node* iterator;

public:
	// Push_Front ---
	void Push_Front(const T& data) {
		node* newnode = new node(data);
		newnode->next = root;
		root->prev = newnode;
		root = newnode;
	}

	// Push_Back ---
	void Push_Back(const T& data) {
		node* newnode = new node(data);
		if (root == nullptr)
			root = newnode;
		else {
			node* last = end();
			last->next = newnode;
			newnode->prev = last;
		}
	}

	// First ---
	node* first() {
		return root;
	}

	// End ---
	node* end() {
		while (iterator->next != nullptr) {
			iterator = iterator->next;
		}
		return iterator;
	}

	// Empty ---
	bool Empty() {
		return root == nullptr;
	}

	// Size ---
	const uint size() const {
		if (root = nullptr)
			return 0;
		
		uint size = 1;
		while (iterator->next != nullptr) {
			iterator = iterator->next;
			size++;
		}
		return size;

	}
};

#endif