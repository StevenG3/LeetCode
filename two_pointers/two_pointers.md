# 双指针
## 快慢指针
### 链表
```C++
// 判断 head 和 head->next
if(head == nullptr || head->next == nullptr) return head;

// 将 slow 和 fast 都赋值为 head
ListNode* slow = head, * fast = head;
// 此处注意循环条件
while(fast->next && fast->next->next) {
	slow = slow->next;
	fast = fast->next->next;
}
```