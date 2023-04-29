#include <iostream>
#include <string>

using namespace std;

// 定义链表节点结构体
struct ListNode {
    string val;        // 数据域为字符串类型
    ListNode *next;    // 指向下一个节点的指针
    ListNode(string x) : val(x), next(NULL) {}    // 节点构造函数
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

    // 链表插入节点
    void insertNode(string str) {
        // 如果链表中已经有该字符串，则不插入
        if (find(str)) {
            cout << "The string already exists in the linked list." << endl;
            return;
        }
        // 创建新节点，并将其插入到链表尾部
        ListNode *newNode = new ListNode(str);
        ListNode *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }

    // 链表删除节点
    void deleteNode(string str) {
        ListNode *p = head;
        ListNode *prev = NULL;
        while (p != NULL) {
            if (p->val == str) {    // 找到要删除的节点
                prev->next = p->next;
                delete p;    // 释放节点空间
                return;
            }
            prev = p;
            p = p->next;
        }
        cout << "The string does not exist in the linked list." << endl;
    }

    // 查找链表中是否存在某个字符串
    bool find(string str) {
        ListNode *p = head->next;
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
    list.insertNode("hello");
    list.insertNode("world");
    list.insertNode("c++");
    list.traverse();    // 输出链表内容：hello world c++
    list.deleteNode("world");
    list.traverse();    // 输出链表内容：hello c++
    list.deleteNode("python");    // 输出：The string does not exist in the linked list.
    return 0;
}

