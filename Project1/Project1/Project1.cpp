#include <mutex>

//反转链表
//struct ListNode
//{
//	int val;
//	ListNode* next;
//	ListNode(int x)
//	{
//		val = x;
//		next = nullptr;
//	}
//};
//ListNode* reverseList(ListNode* head) {
//	ListNode* pre = nullptr;
//	ListNode* current = head;
//	while (current)
//	{
//		ListNode* next = current->next;
//		current->next = pre;
//		pre = current;
//		current = next;
//	}
//	return pre;
//}


//确保线程安全的单例模式
class Singleton
{
public:
	Singleton() {};
	static Singleton* instance;
	static std::mutex mtx;

private:
	static Singleton* getInstance()
	{
		std::lock_guard<std::mutex> lock(mtx);
		if (instance == nullptr)
		{
			instance = new Singleton();
		}
		return instance;
	}
};

