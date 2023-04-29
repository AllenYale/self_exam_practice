#include <iostream>

using namespace std;

// 定义链表节点结构体
struct Node {
    string data; // 节点数据
    Node* next; // 指向下一个节点的指针
};

// 定义单链表类
class LinkedList {
private:
    Node* head; // 头节点指针
public:
    LinkedList() { // 构造函数，初始化头节点
        head = new Node;
        head -> next = NULL;
    }

    ~LinkedList() { // 析构函数，释放链表空间
        Node* p = head;
        while (p) {
            Node* q = p -> next;
            delete p;
            p = q;
        }
    }

    void Insert(string s) { // 插入操作
        Node* p = head;
        while (p -> next && p -> next -> data != s) { // 遍历链表，查找是否已存在该数据
            p = p -> next;
        }
        if (p -> next == NULL) { // 若不存在则插入
            Node* newNode = new Node; // 新建节点
            newNode -> data = s;
            newNode -> next = p -> next;
            p -> next = newNode;
            cout << "插入成功" << endl;
        } else { // 已存在则不插入
            cout << "该数据已存在，插入失败" << endl;
        }
    }

    void Delete(string s) { // 删除操作
        Node* p = head;
        while (p -> next && p -> next -> data != s) { // 遍历链表，查找是否存在该数据
            p = p -> next;
        }
        if (p -> next) { // 若存在该节点，则删除
            Node* q = p -> next;
            p -> next = q -> next;
            delete q;
            cout << "删除成功" << endl;
        } else { // 否则提示删除失败
            cout << "该数据不存在，删除失败" << endl;
        }
    }

    void PrintList() { // 打印链表
        Node* p = head -> next;
        while (p) {
            cout << p -> data << " ";
            p = p -> next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list1; // 新建一个链表
    list1.Insert("hello"); // 插入数据
    list1.Insert("world");
    list1.Insert("hello"); // 重复插入同一数据
    list1.PrintList(); // 打印链表
    list1.Delete("world"); // 删除数据
    list1.Delete("world"); // 尝试删除不存在的数据
    list1.PrintList(); // 打印链表

    return 0;
}

/*
该程序中，Node 结构体定义了单链表中的节点结构，LinkedList 类包含了单链表的操作函数和头节点指针，Insert 函数和 Delete 函数分别实现了插入和删除操作，PrintList 函数用于打印当前链表。在 main 函数中，我们可以调用这些函数进行单链表的操作。
*/ 

