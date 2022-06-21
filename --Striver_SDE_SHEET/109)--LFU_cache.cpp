struct Node {
    int key, val, freq;
    Node *prev, *next;
    Node() : prev(nullptr), next(nullptr){};
};


struct DoubleLinkedList {
    int currentSize;
    Node *head, *tail;
    
    DoubleLinkedList() : currentSize(0), head(new Node()), tail(new Node()) {
        head->next = tail;
        tail->prev = head;
    }
    
    ~DoubleLinkedList() {
        Node *curr = head;
        while (curr != nullptr) {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    void append(Node *node) {
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        node->prev->next = node;
        ++currentSize;
    }
    
    void pop(Node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = nullptr;
        node->prev = nullptr;
        --currentSize;
    }
    
    Node *last() {
        Node *node = tail->prev;
        pop(node);
        return node;
    }
};

class LFUCache {
public:
    LFUCache(int capacity) : Cap(capacity), Mfreq(0) {
    }
    
    ~LFUCache() {
        for (pair<int, DoubleLinkedList*> p: Lists) {
            delete p.second;
        }
    }
    
    int get(int key) {
        if(Nodes.count(key) == 1) {
            promote(key);
            return Nodes[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (!Cap) return;
        
        if (Nodes.count(key) == 1) {
            promote(key);
            Nodes[key]->val = value;
        } 
        else {
            if (Nodes.size() == Cap) {
                evict();
            }
            insert(key, value);
        }
    }
    
private:
    int Cap, Mfreq;
    unordered_map<int, DoubleLinkedList*> Lists;
    unordered_map<int, Node*> Nodes; 
    
    void insert(int key, int value) {
        Mfreq = 1;
        Node *node = new Node();
        node->key = key;
        node->val = value;
        node->freq = Mfreq;
        Nodes[key] = node;
        addToList(Mfreq, node);
    }
    
    void addToList(int freq, Node *node) {
        if (Lists.count(freq) == 0) {
            Lists[freq] = new DoubleLinkedList();
        }
        Lists[freq]->append(node);
    }
    
    void evict() {
        Node *node = Lists[Mfreq]->last();
        Nodes.erase(node->key);
        delete node;
        removeIfEmpty(Mfreq);
    }
    
    void removeIfEmpty(int freq) {
        if (Lists[Mfreq]->currentSize == 0) {
            DoubleLinkedList *del = Lists[Mfreq];
            delete del;
            Lists.erase(Mfreq);
            if (freq == Mfreq)
                ++Mfreq;
        }
    }
    
    void promote(int key) {
        Node *node = Nodes[key];
        int freq = node->freq++;
        Lists[freq]->pop(node);
        removeIfEmpty(freq);
        addToList(freq+1, node);
    }
};