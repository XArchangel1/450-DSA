class LRUCache {
public:
    class Node{
        public:
        int key = 0;
        int val = 0;
        Node *next = NULL;
        Node *prev = NULL;
        Node(int _key,int _val)
        {
            key = _key;
            val = _val;
        }
    };
    
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node *> m;
    
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode)
    {
        Node *temp = head->next;
        temp->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
    }
    
    void deleteNode(Node *delNode)
    {
        delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }
    
    int get(int key) 
    {
       if(m.find(key) != m.end())
        {
            Node *resNode = m[key];
            int res = resNode->val;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;
           return res;
       }
        
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(m.find(key) != m.end())
        {
            Node *existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        
        if(m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(key,value));
        m[key] = head->next;
    }
};