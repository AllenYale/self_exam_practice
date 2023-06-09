#include <iostream>
#include <string>

using namespace std;

//定义 链表节点 结构体，默认public属性。
//单链表，每个节点都包括两部分内容：数据域和指向下一个节点的指针
struct ListNode {
    string val;        // 数据域为字符串类型
    ListNode *next;    // 指向下一个节点的指针
    ListNode(string x) : val(x), next(NULL) {}    // 节点构造函数，将x传入val，该节点的 next 指针初始化为 NULL。
};

//定义 链表 结构体，默认private属性
//链表结构体中有链表头指针和操作链表方法
class LinkedList {
private:
    ListNode *head;    // 链表头指针

public:
    // 链表初始化
    LinkedList() {
        head = new ListNode("");    // 初始化头节点，数据域为空字符串
    }

    ~LinkedList() {        // 析构函数，程序结束时等释放链表空间
    ListNode* p = head;
        while (p) {
            ListNode* q = p -> next;
            delete p;
            p = q;
        }
        head = NULL;  // 将头指针置为空指针，避免悬空指针的问题
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
        while (p->next != NULL) {// 1st insert p->next == NULL ; 2nd insert 开始 逐个往后找node
            p = p->next;
        }
        p->next = newNode;// 1st insert head->next=newNode; 2nd insert 开始 让最后一个node next 指向 newNode
    }

    // 链表删除节点
    void deleteNode(string str) {
        ListNode *p = head;
        ListNode *prev = NULL;
        //从head开始找，逐个往后找node，只要没到最后一个node，进入循环；到最后一个node.next = NULL，找不到要删除节点The string does not exist in the linked list.
        while (p != NULL) { 
            if (p->val == str) {    // p->val == str 是否找到要删除的节点，如果找不是要删除的节点往后找
	            if (p->val=="") {
					cout << "Can't delete the head node" << endl;	//不允许删除head节点
					return;
				}     
                prev->next = p->next;   // p->val == str true，p是要删除的节点，p删除后，p的next赋值为prev的next
                delete p;    // 释放要删除的p节点空间
                return;
            }
            prev = p;   // p不是要删除的节点，假设（p是要删除的节点的前一个节点pre）prev = p （当前节点）
            p = p->next;    // p为继续往后找的next节点
        }
        cout << "The string does not exist in the linked list." << endl;
    }

    // 查找链表中是否存在某个字符串
    bool find(string str) {
        ListNode *p = head->next;   // 从head的next node开始找，逐个往后找node
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
            cout << p->val << "\t";
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
    ////遍历链表
    list.traverse();    // 输出链表内容：Hello World C C++ I love Data Structure
    list.insertNode("I love Data Structure");   //The string already exists in the linked list.
    ////删除链表
    list.deleteNode("World");
    ////删除成功
    list.traverse();    // 输出链表内容：Hello C C++ I love Data Structure
    ////删除失败
    list.deleteNode("doesn't_exist_node");    // 输出：The string does not exist in the linked list.
    return 0;
}
