#include <iostream>
#include <vector>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        /*
        构造函数初始化，上面这个是特殊写法
        
        ListNode(int x) {
            val = x;
            next = NULL;
        }
        */
        ListNode(int x): val(x), next(NULL) {}
};

ListNode* createLinkedList(vector<int> arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;

    for (int i = 1; i < arr.size(); ++i) {
        // new 实例化对象创建除了 head 以外的节点，然后会返回这个对象的指针，然后 cur 的 next 指针指向这个新建的节点
        cur->next = new ListNode(arr[i]);

        // cur 指针移动到下一个节点，确保下次循环的时候正常执行
        cur = cur->next;
    }

    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);

    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
    return 0;
}