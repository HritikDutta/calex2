// Custom stack implementation

template <typename T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node* next;

        Node(T value)
        : data(value), next(nullptr) {}
    }* head;

public:
    Stack()
    : head(nullptr) {}

    void push(T data)
    {
        Node* newNode = new Node(data);

        newNode->next = head;
        head = newNode;
    }

    T& top()
    {
        return head->data;
    }

    void pop()
    {
        if (!head)
            return;
        
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int size()
    {
        int count = 0;
        Node* temp = head;

        while (temp)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    bool empty()
    {
        return head == nullptr;
    }

    void clear()
    {
        while (!empty())
            pop();
    }

    ~Stack()
    {
        clear();
    }
};