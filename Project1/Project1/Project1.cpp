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


////确保线程安全的单例模式
//class Singleton
//{
//private://重点是构造必须为私有，保证外面不能直接new一个对象，要直接 Singleton::getInstance()获得instance，因为getInstance为静态
//	Singleton() {};
//	static Singleton* instance;//instance必须为静态
//	static std::mutex mtx;//保证单线程
//
//public:
//	static Singleton* getInstance()
//	{
//		std::lock_guard<std::mutex> lock(mtx);
//		if (instance == nullptr)
//		{
//			instance = new Singleton();
//		}
//		return instance;
//	}
//};
//



//
//#include <iostream>
//#include <memory> // 包含智能指针头文件
//#include <vector>
//using namespace std;
//
//// 测试类：用于观察构造和析构
//class MyClass {
//public:
//    MyClass(int id) : id_(id) {
//        cout << "MyClass(" << id_ << ") 构造" << endl;
//    }
//    ~MyClass() {
//        cout << "MyClass(" << id_ << ") 析构" << endl;
//    }
//    void print() {
//        cout << "MyClass id: " << id_ << endl;
//    }
//private:
//    int id_;
//};
//
//// 1. unique_ptr 基本用法（独占所有权）
//void test_unique_basic() {
//    cout << "\n--- 测试 unique_ptr 基本用法 ---" << endl;
//
//    // 创建 unique_ptr（推荐用 make_unique，C++14 起支持）
//    unique_ptr<MyClass> ptr1 = make_unique<MyClass>(1);
//    ptr1->print(); // 直接访问对象（类似裸指针）
//
//    // 错误：unique_ptr 不可拷贝（编译报错）
//    // unique_ptr<MyClass> ptr2 = ptr1; 
//
//    // 正确：通过移动语义转移所有权
//    unique_ptr<MyClass> ptr2 = move(ptr1);
//    if (ptr1 == nullptr) {
//        cout << "ptr1 已失去所有权（为空）" << endl;
//    }
//    ptr2->print();
//} // 函数结束时，ptr2 析构，自动释放 MyClass(1)
//
//
//// 2. unique_ptr 作为函数返回值（转移所有权）
//unique_ptr<MyClass> create_unique_obj(int id) {
//    return make_unique<MyClass>(id); // 返回时自动移动所有权
//}
//
//void test_unique_return() {
//    cout << "\n--- 测试 unique_ptr 作为返回值 ---" << endl;
//    auto ptr = create_unique_obj(2);
//    ptr->print();
//} // 函数结束，ptr 析构，释放 MyClass(2)
//
//
//// 3. unique_ptr 作为容器元素（只能移动插入）
//void test_unique_container() {
//    cout << "\n--- 测试 unique_ptr 作为容器元素 ---" << endl;
//    vector<unique_ptr<MyClass>> vec;
//
//    // 插入元素：必须用移动语义
//    vec.push_back(make_unique<MyClass>(3));
//    vec.push_back(move(create_unique_obj(4))); // 移动临时对象
//
//    // 遍历容器
//    for (const auto& ptr : vec) {
//        ptr->print();
//    }
//} // 容器销毁时，所有 unique_ptr 析构，释放 MyClass(3) 和 (4)
//
//int main() {
//    // 依次调用测试函数
//    test_unique_basic();
//    test_unique_return();
//    test_unique_container();
//    return 0;
//}


#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;
//vector<int> twoSum(vector<int>& nums, int target)
//{		
//	unordered_set<int> numSet;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (numSet.find(target - nums[i]) == numSet.end())
//		{
//			numSet.insert(nums[i]);
//		}
//		else
//		{
//			return { target - nums[i],nums[i] };
//			break;
//		}
//	}
//	return {};
//}
//int  main()
//{
//	vector<int> v;
//	v.push_back(2);
//	v.push_back(7);
//	v.push_back(11);
//	v.push_back(15);
//	vector<int> v2 = twoSum(v,13);
//	cout << v2[0] << "," << v2[1];
//	return 0;
//}
//string reverseWords(string s)
//{
//
//	string ans;
//	int left = 0;
//	int right = s.size() - 1;
//	while (left < right && s[left] == ' ')
//	{
//		left++;
//	}
//	while (left < right && s[right] == ' ')
//	{
//		right--;
//	}
//	while (left <= right)
//	{
//	
//		if (s[left] != ' ')
//		{
//			ans.push_back(s[left]);
//		}
//		else 
//		{
//			if (ans.back() != ' ') {
//				ans.push_back(' ');
//			}
//		}
//		left++;
//		
//	}
//	reverse(ans.begin(), ans.end());
//	int start = 0;
//	for (int i = 0; i <= ans.size(); i++)
//	{
//		if (i == ans.size() || ans[i] == ' ')
//		{
//			reverse(ans.begin() + start, ans.begin() + i);
//			start = i + 1;
//		}
//		
//	}
//	return ans;
//}
//int  main()
//{
//	string s = " hello      world ";
//	cout << "输出: "<< reverseWords(s) << endl; \
//}

//struct ListNode
//{
//	int val;
//	ListNode* next;
//	ListNode() :val(0), next(nullptr) {};
//	ListNode(int x) :val(x), next(nullptr) {};
//	ListNode(int x,ListNode* next) :val(x), next(next) {};
//
//};
//ListNode* reverseList(ListNode* head) {
//	ListNode* curPoint = nullptr;
//	ListNode* curr = head;
//	while (curr != nullptr)
//	{
//		ListNode* next = curr->next;
//		curr->next = curPoint;
//		curPoint = curr;
//		curr = next;
//	}
//	return curPoint;
//}
//void printList(ListNode* head) {
//	ListNode* cur = head;
//	while (cur != nullptr)
//	{
//		cout << cur->val << "->";
//		cur = cur->next;
//	}
//	cout << "nullptr" << endl;
//}
//int main()
//{
//	ListNode* node1 = new ListNode(1);  // 第一个节点（值1）
//	ListNode* node2 = new ListNode(2);  // 第二个节点（值2）
//	ListNode* node3 = new ListNode(3);  // 第三个节点（值3）
//	ListNode* node4 = new ListNode(4);  // 第四个节点（值4）
//	ListNode* node5 = new ListNode(5);  // 第五个节点（值5）
//	node1->next = node2;  
//	node2->next = node3;  
//	node3->next = node4;  
//	node4->next = node5;  
//	node5->next = nullptr; 
//	ListNode* ans = reverseList(node1);
//	printList(ans);
//	while (ans != nullptr)
//	{
//		ListNode* temp = ans;
//		ans = ans->next;
//		delete temp;
//	}
//}

