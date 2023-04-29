#include <iostream>
#include <string>

using namespace std;

// ��������ڵ�ṹ��
struct ListNode {
    string val;        // ������Ϊ�ַ�������
    ListNode *next;    // ָ����һ���ڵ��ָ��
    ListNode(string x) : val(x), next(NULL) {}    // �ڵ㹹�캯��
};

// ��������ṹ��
class LinkedList {
private:
    ListNode *head;    // ����ͷָ��

public:
    // �����ʼ��
    LinkedList() {
        head = new ListNode("");    // ��ʼ��ͷ�ڵ㣬������Ϊ���ַ���
    }

    // �������ڵ�
    void insertNode(string str) {
        // ����������Ѿ��и��ַ������򲻲���
        if (find(str)) {
            cout << "The string already exists in the linked list." << endl;
            return;
        }
        // �����½ڵ㣬��������뵽����β��
        ListNode *newNode = new ListNode(str);
        ListNode *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }

    // ����ɾ���ڵ�
    void deleteNode(string str) {
        ListNode *p = head;
        ListNode *prev = NULL;
        while (p != NULL) {
            if (p->val == str) {    // �ҵ�Ҫɾ���Ľڵ�
                prev->next = p->next;
                delete p;    // �ͷŽڵ�ռ�
                return;
            }
            prev = p;
            p = p->next;
        }
        cout << "The string does not exist in the linked list." << endl;
    }

    // �����������Ƿ����ĳ���ַ���
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

    // ��������������нڵ��������
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
    list.traverse();    // ����������ݣ�hello world c++
    list.deleteNode("world");
    list.traverse();    // ����������ݣ�hello c++
    list.deleteNode("python");    // �����The string does not exist in the linked list.
    return 0;
}

