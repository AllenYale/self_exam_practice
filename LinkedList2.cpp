#include <iostream>
#include <string>

using namespace std;

//// 定义链表节点结构体，单链表中，每个节点都包括两部分内容：数据域和指向下一个节点的指针
struct ListNode {
    string val;        // 数据域为字符串类型
    ListNode *next;    // 指向下一个节点的指针
    ListNode(string x) : val(x), next(NULL) {}    //// 节点构造函数，将x传入val，该节点的 next 指针初始化为 NULL。
};

// 定义链表结构体
class LinkedList {
private:
    ListNode *head;    // 链表头指针

public:
    // 链表初始化
    LinkedList() {
        head = new ListNode("");    // 初始化头节点，数据域为空字符串
    }

    ~LinkedList() {        //// 析构函数，程序结束时等释放链表空间
    ListNode* p = head;
        while (p) {
            ListNode* q = p -> next;
            delete p;
            p = q;
        }
    }

    // 链表插入节点
    void insertNode(string str) {
        // 如果链表中已经有该字符串，则不插入
        if (find(str)) {
            cout << "The string already exists in the linked list." << endl;
            return;
        }
        // 创建新节点，并将其插入到链表尾部
        ListNode *newNode = new ListNode(str);
        ListNode *p = head; //定义指针变量存放头节点
        while (p->next != NULL) {//// 1st insert p->next == null ; 2nd insert 开始 逐个往后找node
            p = p->next;
        }
        p->next = newNode;//// 1st insert head->next=newNode; 2nd insert 开始 让最后一个node next 有newNode
    }

    // 链表删除节点
    void deleteNode(string str) {
        ListNode *p = head;
        ListNode *prev = NULL;
        while (p != NULL) {         //// 从head开始找，逐个往后找node，只要没到最后一个node，进入循环；到最后一个node.next = null，找不到要删除节点The string does not exist in the linked list.
            if (p->val == str) {    //// 是否找到要删除的节点，如果找不是要删除的节点往后找，
                prev->next = p->next;
                delete p;    // 释放节点空间
                return;
            }
            prev = p;   ////（要删除的节点的pre）prev = p （当前节点）
            p = p->next;    //// 往后找next节点
        }
        cout << "The string does not exist in the linked list." << endl;
    }

    // 查找链表中是否存在某个字符串
    bool find(string str) {
        ListNode *p = head->next;   //// 从head的next node开始找，逐个往后找node
        while (p != NULL) {
            if (p->val == str) {
                return true;
            }
            p = p->next;
        }
        return false;
    }

    // 遍历链表，输出所有节点的数据域
    void traverse() {
        ListNode *p = head->next;
        while (p != NULL) {
            cout << p->val << " ";
            p = p->next;    
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    ////添加链表
    list.insertNode("Hello");
    list.insertNode("World");
    list.insertNode("C");
    list.insertNode("C++");
    list.insertNode("I love Data Structure");
    list.insertNode("I love Data Structure");   //The string already exists in the linked list.
    ////遍历链表
    list.traverse();    // 输出链表内容：Hello World C C++ I love Data Structure
    ////删除链表
    list.deleteNode("World");
    ////删除成功
    list.traverse();    // 输出链表内容：Hello C C++ I love Data Structure
    ////删除失败
    list.deleteNode("python or java");    // 输出：The string does not exist in the linked list.
    return 0;
}
/*

程序中使用了两个结构体，一个是 ListNode 结构体表示链表节点，包含一个字符串类型的数据域 val 和一个指向下一个节点的指针 next。另一个是 LinkedList 结构体表示链表本身，包含一个指向链表头的指针 head。

链表的初始化通过 LinkedList 的构造函数实现，创建一个头节点，并将 head 指向该头节点。

链表插入操作 insertNode 接收一个字符串作为参数，如果链表中已经存在该字符串，输出提示信息 The string already exists in the linked list. 并返回；否则创建一个新节点，将其插入到链表尾部。

链表删除操作 deleteNode 接收一个字符串作为参数，遍历链表查找要删除的节点，如果找到，删除该节点并释放其内存空间；如果未找到，输出提示信息 The string does not exist in the linked list.。

链表查找操作 find 接收一个字符串作为参数，遍历链表查找该字符串是否存在于链表中，如果找到，返回 true；否则返回 false。

链表遍历操作 traverse 遍历链表所有节点，并输出各个节点的数据域值。

在 main 函数中，首先创建一个 LinkedList 对象，然后依次调用 insertNode 插入三个字符串 "hello"、"world" 和 "c++"，随后调用 traverse 输出结果。接着调用 deleteNode 删除了字符串 "world"，再次调用 traverse 输出链表内容，可以看到该字符串已经被删除。最后调用 deleteNode 删除了不存在的字符串 "python"，输出相应提示信息。
*/
