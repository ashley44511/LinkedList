#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

template<typename T> class LinkedList {

private:


public:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };

//number of nodes
    unsigned int _countNodes;
//node pointer to head
    Node* _head;
//node pointer to tail
    Node* _tail;

//Behaviors
    void PrintForward() const;
    void PrintReverse() const;
    void PrintForwardRecursive(const Node* node) const;
    void PrintReverseRecursive(const Node* node) const;

//Accessors
    unsigned int NodeCount() const;
    void FindAll(vector<Node*>& outData, const T& value) const;
    const Node* Find(const T& data) const;
    const Node* Find(const T& data);
    const Node* GetNode(unsigned int index) const;
    Node* GetNode(unsigned int index);
    Node* Head();
    const Node* Head() const;
    Node* Tail();
    const Node* Tail() const;

//Insertion
    void AddHead(const T& data);
    void AddTail(const T& data);
    void AddNodesHead(const T* data, unsigned int count);
    void AddNodesTail(const T* data, unsigned int count);
    void InsertAfter(Node* node, const T& data);
    void InsertBefore(Node* node, const T& data);
    void InsertAt(const T& data, unsigned int index);

//Removal
    bool RemoveHead();
    bool RemoveTail();
    unsigned int Remove(const T&data);
    bool RemoveAt(unsigned int index);
    void Clear();

//Operators
    const T& operator[](unsigned int index) const;
    T& operator[](unsigned int index);
    bool operator==(const LinkedList<T>& rhs) const;
    LinkedList<T>& operator=(const LinkedList<T>& rhs);

//Construction/Destruction
//default constructor
    LinkedList();
//parameterized constructor
    LinkedList(const LinkedList<T>& list);
//destructor
    ~LinkedList();
};


//DEFINITIONS

//Behaviors
//iterate through all nodes and print out values one at a time
template<typename T> void LinkedList<T>::PrintForward() const {
    Node* currentNode = _head;
    for(int i = 0; i < _countNodes; i++) {
        //node(i) starting with head
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
    }
}

template<typename T> void LinkedList<T>::PrintReverse() const {
    Node* currentNode = _tail;
    for(int i = 0; i < _countNodes; i++) {
        //node(i) starting with tail
        cout << currentNode->data << endl;
        currentNode = currentNode->prev;
    }
}

//From starting node, RECURSIVELY visit each node that follows,
//in forward order, and print their values
//@param Node* node is a pointer to a node, the starting node
template<typename T> void LinkedList<T>::PrintForwardRecursive(const LinkedList::Node* node) const {

}

//in backward order
//@param Node* is a pointer to a node, the starting node
template<typename T> void LinkedList<T>::PrintReverseRecursive(const LinkedList::Node* node) const {

}


//Accessors
//how many nodes stored in list
template<typename T> unsigned int LinkedList<T>::NodeCount() const {
    return _countNodes;
}
//Find all nodes which match parameter value, store a pointer to
//that node in the passed in vector (output parameter)
//@param outData is output parameter to store pointers to nodes with specifed value
//@param value is a data value that we are looking for in list
template<typename T> void LinkedList<T>::FindAll(vector<LinkedList<T>::Node*>& outData, const T& value) const {
    Node* currentNode;
    bool found = false;
    for(int i = 0; i < _countNodes; i++) {
        currentNode = const_cast<Node*>(GetNode(i));
        if (currentNode->data == value) {
            outData.push_back(currentNode);
            //found = true;
        }
    }
    /*
    if (found == false) {
        return nullptr;
    } else {
        return outData;
    }
     */
}
//find first node with data value matching data param
//@param data is a data value that may be stored in list
template<typename T> const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {
    //return pointer to that node if found
    //return nullptr if no node found
    Node* currentNode;
    bool found = false;
    for(int i = 0; i < _countNodes; i++) {
        currentNode = const_cast<Node*>(GetNode(i));
        if (currentNode->data == data) {
            return currentNode;
            found = true;
            break;
        }
    }
    if (found == false) {
        return nullptr;
    }
}

template<typename T> const typename LinkedList<T>::Node* LinkedList<T>::Find(const T &data) const {
    return nullptr;
}
//given index, return pointer to the node at that index
//throw out_of_range exception if the index is out of range
template<typename T> const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
    Node* currentNode = _head;
    for(int i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }
    return currentNode;
}

template<typename T> typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
    Node* currentNode = _head;
    for(int i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }
    return currentNode;
}

template<typename T> typename LinkedList<T>::Node* LinkedList<T>::Head() {
    return _head;
}

template<typename T> const typename LinkedList<T>::Node* LinkedList<T>::Head() const {
    return _head;
}

template<typename T> typename LinkedList<T>::Node* LinkedList<T>::Tail() {
    return _tail;
}

template<typename T> const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
    return _tail;
}


//Insertion

template<typename T> void LinkedList<T>::AddHead(const T &data) {
    Node* temp = new Node;
    temp->data = data;
    temp->prev = nullptr;
    temp->next = _head;
    if (_countNodes == 0) {
        _tail = temp;
    } else {
        _head->prev = temp;
    }
    _head = temp;
    _countNodes += 1;
}

template<typename T> void LinkedList<T>::AddTail(const T &data) {
    Node* temp = new Node;
    temp->data = data;
    temp->prev = _tail;
    temp->next = nullptr;
    if (_countNodes == 0) {
        _head = temp;
    } else {
        _tail->next = temp;
    }
    _tail = temp;
    _countNodes += 1;
}

template<typename T> void LinkedList<T>::AddNodesHead(const T *data, unsigned int count) {
    for(int i = 0; i < count; i++) {
        AddHead(data[i]);
    }
}

template<typename T> void LinkedList<T>::AddNodesTail(const T *data, unsigned int count) {
    for(int i = 0; i < count; i++) {
        AddTail(data[i]);
    }
}

template<typename T> void LinkedList<T>::InsertAfter(LinkedList::Node *node, const T &data) {

}

template<typename T> void LinkedList<T>::InsertBefore(LinkedList::Node *node, const T &data) {

}

template<typename T> void LinkedList<T>::InsertAt(const T &data, unsigned int index) {

}


//Removal

template<typename T> bool LinkedList<T>::RemoveHead() {
    return false;
}

template<typename T> bool LinkedList<T>::RemoveTail() {
    return false;
}

template<typename T> unsigned int LinkedList<T>::Remove(const T &data) {
    return 0;
}

template<typename T> bool LinkedList<T>::RemoveAt(unsigned int index) {
    return false;
}

template<typename T> void LinkedList<T>::Clear() {

}


//Operators

template<typename T> const T &LinkedList<T>::operator[](unsigned int index) const {
    try {
        if (index > _countNodes) {
            throw out_of_range("This index is out of range.");
        } else {
            return GetNode(index);
        }
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }
}

template<typename T> T &LinkedList<T>::operator[](unsigned int index) {
    try {
        if (index > _countNodes) {
            throw out_of_range("This index is out of range.");
        } else {
            return GetNode(index);
        }
    }
    catch (out_of_range& e) {
        cout << e.what() << endl;
    }
}
//equality
template<typename T> bool LinkedList<T>::operator==(const LinkedList<T> &rhs) const {
    return false;
}
//copy assignment operator
template<typename T> LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    _head = rhs._head;
    _tail = rhs._tail;
    _countNodes = rhs._countNodes;

    return *this;
}


//Construction/Destruction

template<typename T> LinkedList<T>::LinkedList() {
    //cout << "constructor" << endl;
    /*
      cout << "newHead" << endl;
      Node* newHead = new Node;
      newHead->_next = nullptr;
      newHead->_previous = nullptr;
      _head = newHead;
      //delete newHead;
      cout << "newTail" << endl;
      Node* newTail = new Node;
      newTail->_next = nullptr;
      newTail->_previous = nullptr;
      _tail = newTail;
      _countNodes = 0;
    */
    _head = nullptr;
    _tail = nullptr;
    _countNodes = 0;
}

template<typename T> LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    _head = list._head;
    _tail = list._tail;
    _countNodes = list._countNodes;
}

template<typename T> LinkedList<T>::~LinkedList() {
    //cout << "destructor" << endl;
    Node* currentNode = _head;
    Node* delNode = _head;
    for(int i = 0; i < _countNodes; i++) {
        currentNode = currentNode->next;
        delete delNode;
        //cout << "deletedNode" << endl;
        delNode = currentNode;
    }
    delete delNode;

}