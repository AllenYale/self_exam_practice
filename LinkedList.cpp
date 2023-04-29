#include <iostream>

using namespace std;

// ��������ڵ�ṹ��
struct Node {
    string data; // �ڵ�����
    Node* next; // ָ����һ���ڵ��ָ��
};

// ���嵥������
class LinkedList {
private:
    Node* head; // ͷ�ڵ�ָ��
public:
    LinkedList() { // ���캯������ʼ��ͷ�ڵ�
        head = new Node;
        head -> next = NULL;
    }

    ~LinkedList() { // �����������ͷ�����ռ�
        Node* p = head;
        while (p) {
            Node* q = p -> next;
            delete p;
            p = q;
        }
    }

    void Insert(string s) { // �������
        Node* p = head;
        while (p -> next && p -> next -> data != s) { // �������������Ƿ��Ѵ��ڸ�����
            p = p -> next;
        }
        if (p -> next == NULL) { // �������������
            Node* newNode = new Node; // �½��ڵ�
            newNode -> data = s;
            newNode -> next = p -> next;
            p -> next = newNode;
            cout << "����ɹ�" << endl;
        } else { // �Ѵ����򲻲���
            cout << "�������Ѵ��ڣ�����ʧ��" << endl;
        }
    }

    void Delete(string s) { // ɾ������
        Node* p = head;
        while (p -> next && p -> next -> data != s) { // �������������Ƿ���ڸ�����
            p = p -> next;
        }
        if (p -> next) { // �����ڸýڵ㣬��ɾ��
            Node* q = p -> next;
            p -> next = q -> next;
            delete q;
            cout << "ɾ���ɹ�" << endl;
        } else { // ������ʾɾ��ʧ��
            cout << "�����ݲ����ڣ�ɾ��ʧ��" << endl;
        }
    }

    void PrintList() { // ��ӡ����
        Node* p = head -> next;
        while (p) {
            cout << p -> data << " ";
            p = p -> next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list1; // �½�һ������
    list1.Insert("hello"); // ��������
    list1.Insert("world");
    list1.Insert("hello"); // �ظ�����ͬһ����
    list1.PrintList(); // ��ӡ����
    list1.Delete("world"); // ɾ������
    list1.Delete("world"); // ����ɾ�������ڵ�����
    list1.PrintList(); // ��ӡ����

    return 0;
}

/*
�ó����У�Node �ṹ�嶨���˵������еĽڵ�ṹ��LinkedList ������˵�����Ĳ���������ͷ�ڵ�ָ�룬Insert ������ Delete �����ֱ�ʵ���˲����ɾ��������PrintList �������ڴ�ӡ��ǰ������ main �����У����ǿ��Ե�����Щ�������е�����Ĳ�����
*/ 

