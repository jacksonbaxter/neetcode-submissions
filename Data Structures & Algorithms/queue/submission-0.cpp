class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) : value(value), next(nullptr), prev(nullptr) {}
};

class Deque {
private:
    Node* head;
    Node* tail;

public:
    Deque() {
        head = new Node(0);
        tail = new Node(0);

        head->next = tail;
        tail->prev = head;
    }

    bool isEmpty() {
        return head->next == tail;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        Node* prevNode = tail->prev;

        newNode->next = tail;
        newNode->prev = prevNode;

        prevNode->next = newNode;
        tail->prev = newNode;
    }

    void appendleft(int value) {
        Node* newNode = new Node(value);
        Node* nextNode = head->next;

        newNode->next = nextNode;
        newNode->prev = head;

        nextNode->prev = newNode;
        head->next = newNode;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        Node* targetNode = tail->prev;
        Node* prevNode = targetNode->prev;
        int value = targetNode->value;

        prevNode->next = tail;
        tail->prev = prevNode;

        delete targetNode;
        return value;
    }

    int popleft() {
        if (isEmpty()) {
            return -1;
        }
        Node* targetNode = head->next;
        Node* nextNode = targetNode->next;
        int value = targetNode->value;

        head->next = nextNode;
        nextNode->prev = head;

        delete targetNode;
        return value;
    }
};
