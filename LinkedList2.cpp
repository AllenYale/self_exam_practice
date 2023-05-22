#include <iostream>
#include <string>

using namespace std;

//���� ����ڵ� �ṹ�壬Ĭ��public���ԡ�
//������ÿ���ڵ㶼�������������ݣ��������ָ����һ���ڵ��ָ��
struct ListNode {
    string val;        // ������Ϊ�ַ�������
    ListNode *next;    // ָ����һ���ڵ��ָ��
    ListNode(string x) : val(x), next(NULL) {}    // �ڵ㹹�캯������x����val���ýڵ�� next ָ���ʼ��Ϊ NULL��
};

//���� ���� �ṹ�壬Ĭ��private����
//����ṹ����������ͷָ��Ͳ���������
class LinkedList {
private:
    ListNode *head;    // ����ͷָ��

public:
    // �����ʼ��
    LinkedList() {
        head = new ListNode("");    // ��ʼ��ͷ�ڵ㣬������Ϊ���ַ���
    }

    ~LinkedList() {        // �����������������ʱ���ͷ�����ռ�
    ListNode* p = head;
        while (p) {
            ListNode* q = p -> next;
            delete p;
            p = q;
        }
        head = NULL;  // ��ͷָ����Ϊ��ָ�룬��������ָ�������
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
        ListNode *p = head; //����ָ��������ͷ�ڵ�
        while (p->next != NULL) {// 1st insert p->next == NULL ; 2nd insert ��ʼ ���������node
            p = p->next;
        }
        p->next = newNode;// 1st insert head->next=newNode; 2nd insert ��ʼ �����һ��node next ָ�� newNode
    }

    // ����ɾ���ڵ�
    void deleteNode(string str) {
        ListNode *p = head;
        ListNode *prev = NULL;
        //��head��ʼ�ң����������node��ֻҪû�����һ��node������ѭ���������һ��node.next = NULL���Ҳ���Ҫɾ���ڵ�The string does not exist in the linked list.
        while (p != NULL) { 
            if (p->val == str) {    // p->val == str �Ƿ��ҵ�Ҫɾ���Ľڵ㣬����Ҳ���Ҫɾ���Ľڵ�������
	            if (p->val=="") {
					cout << "Can't delete the head node" << endl;	//������ɾ��head�ڵ�
					return;
				}     
                prev->next = p->next;   // p->val == str true��p��Ҫɾ���Ľڵ㣬pɾ����p��next��ֵΪprev��next
                delete p;    // �ͷ�Ҫɾ����p�ڵ�ռ�
                return;
            }
            prev = p;   // p����Ҫɾ���Ľڵ㣬���裨p��Ҫɾ���Ľڵ��ǰһ���ڵ�pre��prev = p ����ǰ�ڵ㣩
            p = p->next;    // pΪ���������ҵ�next�ڵ�
        }
        cout << "The string does not exist in the linked list." << endl;
    }

    // �����������Ƿ����ĳ���ַ���
    bool find(string str) {
        ListNode *p = head->next;   // ��head��next node��ʼ�ң����������node
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
            cout << p->val << "\t";
            p = p->next;    
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    ////�������
    list.insertNode("Hello");
    list.insertNode("World");
    list.insertNode("C");
    list.insertNode("C++");
    list.insertNode("I love Data Structure");
    ////��������
    list.traverse();    // ����������ݣ�Hello World C C++ I love Data Structure
    list.insertNode("I love Data Structure");   //The string already exists in the linked list.
    ////ɾ������
    list.deleteNode("World");
    ////ɾ���ɹ�
    list.traverse();    // ����������ݣ�Hello C C++ I love Data Structure
    ////ɾ��ʧ��
    list.deleteNode("doesn't_exist_node");    // �����The string does not exist in the linked list.
    return 0;
}
