#include <iostream>

class LinkedListNode{
public:
    LinkedListNode(int val = 0):val_(val), next_(nullptr)
    {}
    ~LinkedListNode(){}
private:
    friend class LinkedList;
    int val_;
    LinkedListNode* next_;
};

class LinkedList{
public:
    //初始化链表
    LinkedList():head_(new LinkedListNode){}
    //插入节点
    //按索引到的结点插入
    void insertByIndex(LinkedListNode* p, LinkedListNode* inserted){
        inserted->next_ = p->next_;
        p->next_ = inserted;
    }
    //尾插法
    void insertTail(int val){
        LinkedListNode* find = head_;
        while(find->next_) find = find->next_;
        find->next_ = new LinkedListNode(val);
    }
    //头插法
    void insertHead(int val){
        insertByIndex(head_, new LinkedListNode(val));
    }
    //删除结点,传入要删除结点的前一个结点
    void eraseNode(LinkedListNode* prev){
        LinkedListNode* erased = prev->next_;
        prev->next_ = erased->next_;
        erased->~LinkedListNode();
    }

    //按值查找结点
    LinkedListNode* find(int val){
        LinkedListNode* find = head_->next_;
        while(find != nullptr){
            if(find->val_ == val) return find;
            find = find->next_;
        }
        return find;
    }
    //按索引查找
    LinkedListNode* access(int index){
        if(index < 0) return nullptr;
        LinkedListNode* find = head_;
        while(index-- != 0){
            find = find->next_;
            if(find == nullptr) break;
        }
        return find;
    }

    void print(){
        LinkedListNode* print = head_->next_;
        while(print != nullptr){
            if(print->next_ != nullptr)
                std::cout << print->val_ << "->";
            else
                std::cout << print->val_;
            print = print->next_;
        }
        std::cout << '\n';
    }
private:
    LinkedListNode* head_;
};