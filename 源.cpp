#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<numeric>
#include<complex>
#include<cmath>
#include<string>
using namespace std;

//<iostream>输入输出的使用
void test_1() {
	//加快C++的输入速度
	// ios::sync_with_stdio(false)：
	// C++的 cin/cout 默认与C语言的 stdio 同步
	// 代价是之后不能随意混用C和C++的I/O函数（如 cin 和 printf），
	// 否则可能导致输出顺序错乱。
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	//cin 输入
	cin >> n;
	//cout 输出
	//endl 换行
	cout << n<<endl;

}
//<array>数组的使用
void test_2() {
	array<int, 5> myarray = { 1,2,3,4,5 };
	for (auto a : myarray) {
		cout << a << " ";
	}
	cout << endl;
	// 使用索引访问数组元素
	cout << "Element at index 2:" << myarray.at(2) << endl;
	cout << "Array size:" << myarray.size() << endl;
	cout << "first:" << myarray.front()<<endl;
	cout << "last:" << myarray.back() << endl;
	cout << "to:" << myarray.data()<< endl;

	myarray[3] = 10;
	for (auto a : myarray) {
		cout << a << " ";
	}
	cout << endl;
	fill(myarray.begin(), myarray.begin() + 3, 2);
	for (auto a : myarray) {
		cout << a << " ";
	}
	cout << endl;
}
//<vector>向量的使用
void test_3() {
	vector<int>myVector;
	myVector.push_back(10);
	int firstElement = myVector[0];
	size_t size = myVector.size();
	myVector.clear();
	std::vector<int> vec1;                  // 空的vector
	std::vector<int> vec2(5);               // 长度为5的vector，元素默认初始化
	std::vector<int> vec3(5, 10);           // 长度为5的vector，元素值为10
	std::vector<int> vec4 = { 1, 2, 3, 4 };   // 使用初始化列表初始化
	// 声明一个存储整数的 vector
	std::vector<int> numbers;

	// 添加元素
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);

	// 输出 vector 中的元素
	std::cout << "Vector contains: ";
	for (int i = 0; i < numbers.size(); ++i) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	// 添加更多元素
	numbers.push_back(40);
	numbers.push_back(50);

	// 再次输出 vector 中的元素
	std::cout << "After adding more elements, vector contains: ";
	for (int i = 0; i < numbers.size(); ++i) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	// 访问特定元素
	std::cout << "The first element is: " << numbers[0] << std::endl;

	// 清空 vector
	numbers.clear();

	// 检查 vector 是否为空
	if (numbers.empty()) {
		std::cout << "The vector is now empty." << std::endl;
	}
	vector<int>v;
	v.push_back(1);
	cout << v[0];
	v.pop_back();
	if (v.empty()) {
		cout << "The vector is now empty." << std::endl;
	}
	v.push_back(199);
	cout << v.at(0)<<endl;
	cout << v.front() << endl;
	cout << v.back() << endl;
	cout << "This is capacity:" << v.capacity() << endl;
	v.reserve(100);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	v.resize(19);
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	v.insert(v.begin(), 1);
	v.erase(v.begin()+1);
	for (int i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
}
//<deque>双端队列的使用
//deque 是 vector 的随机访问能力 + queue 的双端操作能力。
void test_4() {
	deque<int>myDeque1();
	deque<int>myDeque2(2);
	//deque(size_type n, const T& value)	
	// 创建一个包含 n 个值为 value 的 deque 容器。
	deque<int>myDeque3(3, 1);
	deque<int>myDeque4 = { 1,2,3,4,5,6 };
	deque<int>myDeque5 = myDeque2;
	deque<int> d{ 1, 2, 3 };

	// 重载 1：3 个 7
	d.assign(3, 7);                 // d = {7, 7, 7}
	for (int x : d) std::cout << x << ' ';
	cout << endl;
	// 重载 2：从其他容器范围复制
	list<int> src{ 10, 20, 30, 40 };
	d.assign(src.begin(), src.end()); // d = {10, 20, 30, 40}
	for (int x : d) std::cout << x << ' ';
	cout << endl;
	// 重载 3：初始化列表
	d.assign({ 5, 6, 7 });            // d = {5, 6, 7}

	for (int x : d) std::cout << x << ' '; // 5 6 7

}
//<list>双向链表的使用
void test_5() {
	// 创建一个整数类型的列表
	std::list<int> numbers;

	// 向列表中添加元素
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);

	// 访问并打印列表的第一个元素
	std::cout << "First element: " << numbers.front() << std::endl;

	// 访问并打印列表的最后一个元素
	std::cout << "Last element: " << numbers.back() << std::endl;

	// 遍历列表并打印所有元素
	std::cout << "List elements: ";
	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// 删除列表中的最后一个元素
	numbers.pop_back();

	// 再次遍历列表并打印所有元素
	std::cout << "List elements after removing the last element: ";
	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
//<forward_list>单向链表的使用
void test_6() {
	// 创建一个空的 forward_list
	std::forward_list<int> fl;

	// 在列表前端添加元素
	fl.push_front(10);
	fl.push_front(20);
	fl.push_front(30);

	// 遍历 forward_list 并输出元素
	for (auto it = fl.begin(); it != fl.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// 输出结果：30 20 10
}
//<stack>栈的使用
void test_7() {
	std::stack<int> s;

	// 向栈中添加元素
	s.push(10);
	s.push(20);
	s.push(30);

	// 打印栈顶元素
	std::cout << "Top element is: " << s.top() << std::endl; // 输出: Top element is: 30

	// 移除栈顶元素
	s.pop();
	std::cout << "After popping, top element is: " << s.top() << std::endl; // 输出: After popping, top element is: 20

	// 检查栈是否为空
	if (!s.empty()) {
		std::cout << "Stack is not empty." << std::endl; // 输出: Stack is not empty.
	}

	// 打印栈的大小
	std::cout << "Size of stack: " << s.size() << std::endl; // 输出: Size of stack: 2

	// 继续移除元素
	s.pop();
	s.pop();

	// 检查栈是否为空
	if (s.empty()) {
		std::cout << "Stack is empty." << std::endl; // 输出: Stack is empty.
	}

}
//<queue>队列的使用
void test_8() {
	queue<int>q;
	q.push(10);
	q.push(20);
	q.push(30);
	// 打印队列中的元素数量
	std::cout << "队列中的元素数量: " << q.size() << std::endl;

	// 打印队首元素
	std::cout << "队首元素: " << q.front() << std::endl;

	// 打印队尾元素
	std::cout << "队尾元素: " << q.back() << std::endl;

	// 移除队首元素
	q.pop();
	std::cout << "移除队首元素后，队首元素: " << q.front() << std::endl;

	// 再次打印队列中的元素数量
	std::cout << "队列中的元素数量: " << q.size() << std::endl;


}
//<priority_queue>优先队列的使用
void test_9() {
	// 声明一个整型优先队列
	priority_queue<int> pq;

	// 声明一个自定义类型的优先队列，需要提供比较函数
	struct compare {
		bool operator()(int a, int b) {
			return a > b; // 这里定义了最小堆
		}
	};
	priority_queue<int, vector<int>, compare> pq_min;
	//包含库<functional>可以写成priority_queue<int, vector<int>, greater<int>>
	// 向优先队列中添加元素
	pq.push(30);
	pq.push(10);
	pq.push(50);
	pq.push(20);

	// 输出队列中的元素
	std::cout << "队列中的元素：" << std::endl;
	while (!pq.empty()) {
		std::cout << pq.top() << std::endl;
		pq.pop();
	}
	// 向优先队列中添加元素
	pq_min.push(30);
	pq_min.push(10);
	pq_min.push(50);
	pq_min.push(20);

	// 输出队列中的元素
	std::cout << "最小堆中的元素：" << std::endl;
	while (!pq_min.empty()) {
		std::cout << pq_min.top() << std::endl;
		pq_min.pop();
	}
}
//<set>集合的使用
void test_10() {
	set<int>mySet;
	mySet.insert(10);
	mySet.insert(20);
	mySet.insert(30);
	mySet.insert(40);
	// 输出集合中的元素
	cout << "Set elements: ";
	for(int num: mySet) {
		cout << num << " ";
	}
	cout << endl;
	if(mySet.find(20) != mySet.end()) {
		cout << "20 is in the set." << endl;
	} else {
		cout << "20 is not in the set." << endl;
	}
	mySet.erase(20);
	cout << "After erasing 20, set elements: ";
	for(int num: mySet) {
		cout << num << " ";
	}
	cout << endl;
	if (mySet.empty()) {
		cout << "Set is empty." << endl;
	}
	else {
		cout << "Set is not empty." << endl;
	}
	// 输出集合的大小
	cout << "Set size: " << mySet.size() << endl;
}
//<unordered_set>无序集合的使用
void test_11() {
	unordered_set<int> uset;
	// 插入元素
	uset.insert(10);
	uset.insert(20);
	uset.insert(30);
	// 输出集合中的元素
	cout << "Unordered set elements: ";
	for(int num : uset) {
		cout << num << " ";
	}
	cout << endl;
	// 查找元素
	auto it = uset.find(20);
	if(it != uset.end()) {
		cout << "Found 20 in the unordered set." << endl;
	} else {
		cout << "20 not found in the unordered set." << endl;
	}
	// 删除元素
	uset.erase(20);
	cout << "After erasing 20, unordered set elements: ";
	for(int num : uset) {
		cout << num << " ";
	}
	cout << endl;
	// 检查集合大小和是否为空
	cout << "size: " << uset.size() << endl;
	cout << "empty: " << (uset.empty() ? "true" : "false") << endl;
	// 清空集合
	uset.clear();
	cout << "After clearing, unordered set size: " << uset.size() << endl;
	cout << "After clearing, unordered set empty: " << (uset.empty() ? "true" : "false") << endl;

}
//<map>映射的使用
void test_12() {
	map<string, int> employees;
	// 插入键值对
	employees["Alice"] = 30;
	employees["Bob"] = 25;
	employees["Charlie"] = 35;
	//遍历 map 并输出键值对
	for(auto const& pair : employees) {
		cout << pair.first << ": " << pair.second << endl;
	}
	auto it = employees.find("Bob");
	if(it != employees.end()) {
		cout << "Found Bob with age: " << it->second << endl;
	} else {
		cout << "Bob not found in the map." << endl;
	}
	employees.erase("Alice");
	cout << "After erasing Alice, map elements: " << endl;
	for (auto const& pair : employees) {
		cout << pair.first << ": " << pair.second << endl;
	}
	//greater<int>可以用来创建一个按值降序排列的 map
	map<int, string, greater<int>> scoreMap;//创建一个按键降序排列的 map
	map<int, string> scoreMap2;//创建一个按键升序排列的 map
	scoreMap[90] = "Alice";
	scoreMap[85] = "Bob";
	scoreMap[95] = "Charlie";
	//遍历 scoreMap 并输出键值对
	for(auto const& pair : scoreMap) {
		cout << pair.first << ": " << pair.second << endl;
	}
	scoreMap2[90] = "Alice";
	scoreMap2[85] = "Bob";
	scoreMap2[95] = "Charlie";
	//遍历 scoreMap2 并输出键值对
	for(auto const& pair : scoreMap2) {
		cout << pair.first << ": " << pair.second << endl;
	}

}
//<unordered_map>无序映射的使用
void test_13() {
	unordered_map<int, string>myMap;
	myMap[1] = "One";
	myMap[2] = "Two";
	myMap[3] = "Three";

	// 遍历 unordered_map 并输出键值对
	for(const auto& pair : myMap) {
		cout << pair.first << ": " << pair.second << endl;
	}
	//访问特定键的值
	cout << "Value for key 2: " << myMap[2] << endl;
	//delete a key-value pair
	myMap.erase(2);
	//再次遍历 unordered_map 并输出键值对
	for(const auto& pair : myMap) {
		cout << pair.first << ": " << pair.second << endl;
	}

}
//<algorithm>算法的使用
void test_14() {
	//排序算法
	// 使用 sort 算法对 vector 进行排序
	vector<int> vec = { 5, 2, 9, 1, 5, 6 };
	sort(vec.begin(), vec.end());
	for(int num : vec) {
		cout << num << " ";
	}
	cout << endl;
	//使用 partial_sort 算法对 vector 进行部分排序
	vector<int> vec2 = { 5, 2, 9, 1, 5, 6 };
	partial_sort(vec2.begin(), vec2.begin() + 3, vec2.end());
	for(int num : vec2) {
		cout << num << " ";
	}
	cout << endl;
	//使用stable_sort算法对vector进行稳定排序
	vector<int> vec3 = { 5, 2, 9, 1, 5, 6 };
	stable_sort(vec3.begin(), vec3.end());
	for(int num : vec3) {
		cout << num << " ";
	}
	cout << endl;
	//搜索算法
	//使用find算法在vector中查找元素
	vector<int> vec4 = { 5, 2, 9, 1, 5, 6 };
	auto it = find(vec4.begin(), vec4.end(), 5);
	if(it != vec4.end()) {
		cout << "Found: " << *it << endl;
	} else {
		cout << "Not found" << endl;
	}
	//使用binary_search算法在有序vector中查找元素
	vector<int> vec5 = { 1, 2, 3, 4, 5, 6 };
	sort(vec5.begin(), vec5.end());
	if(binary_search(vec5.begin(), vec5.end(), 4)) {
		cout << "Found 4" << endl;
	} else {
		cout << "Not found 4" << endl;
	}
	//使用find_if算法在vector中查找满足条件的元素
	vector<int> vec6 = { 5, 2, 9, 1, 5, 6 };
	auto it2 = find_if(vec6.begin(), vec6.end(), [](int x) { return x > 5; });
	if(it2 != vec6.end()) {
		cout << "Found: " << *it2 << endl;
	} else {
		cout << "Not found" << endl;
	}
	//复制算法
	//使用copy算法将一个vector的元素复制到另一个vector
	vector<int> vec7 = { 5, 2, 9, 1, 5, 6 };
	vector<int> vec8(6);
	copy(vec7.begin(), vec7.end(), vec8.begin());
	for(int num : vec8) {
		cout << num << " ";
	}
	cout << endl;
	//比较算法
	//使用equal算法比较两个vector是否相等
	vector<int> vec9 = { 5, 2, 9, 1, 5, 6 };
	vector<int> vec10 = { 5, 2, 9, 1, 5, 6 };
	if(equal(vec9.begin(), vec9.end(), vec10.begin())) {
		cout << "vec9 and vec10 are equal" << endl;
	} else {
		cout << "vec9 and vec10 are not equal" << endl;
	}
	//修改算法
	//使用reverse算法将vector的元素反转
	vector<int> vec11 = { 5, 2, 9, 1, 5, 6 };
	reverse(vec11.begin(), vec11.end());
	for(int num : vec11) {
		cout << num << " ";
	}
	cout << endl;
	//使用fill算法将vector的元素填充为指定值
	vector<int> vec12(6);
	fill(vec12.begin(), vec12.end(), 1);
	for(int num : vec12) {
		cout << num << " ";
	}
	cout << endl;
	//使用replace算法将vector中的指定值替换为另一个值
	vector<int> vec13 = { 5, 2, 9, 1, 5, 6 };
	replace(vec13.begin(), vec13.end(), 5, 10);
	for(int num : vec13) {
		cout << num << " ";
	}
	cout << endl;
	//排列算法
	//使用next_permutation算法生成下一个排列
	vector<int> vec14 = { 1, 2, 3 };
	do {
		for(int num : vec14) {
			cout << num << " ";
		}
		cout << endl;
	} while (next_permutation(vec14.begin(), vec14.end()));
	//使用prev_permutation算法生成上一个排列
	vector<int> vec15 = { 3, 2, 1 };
	do {
		for(int num : vec15) {
			cout << num << " ";
		}
		cout << endl;
	} while (prev_permutation(vec15.begin(), vec15.end()));
	//归并算法
	//使用merge算法将两个有序vector合并为一个有序vector
	vector<int> vec16 = { 1, 3, 5 };
	vector<int> vec17 = { 2, 4, 6 };
	vector<int> vec18(6);
	merge(vec16.begin(), vec16.end(), vec17.begin(), vec17.end(), vec18.begin());
	for(int num : vec18) {
		cout << num << " ";
	}
	cout << endl;
	//使用inplace_merge算法将一个vector的两个有序部分合并为一个有序部分
	vector<int> vec19 = { 1, 3, 5, 2, 4, 6 };
	inplace_merge(vec19.begin(), vec19.begin() + 3, vec19.end());
	for(int num : vec19) {
		cout << num << " ";
	}
	cout << endl;
	//集合算法
	//使用set_union算法求两个有序vector的并集
	vector<int> vec20 = { 1, 2, 3 };
	vector<int> vec21 = { 2, 3, 4 };
	vector<int> vec22(6);
	auto it3 = set_union(vec20.begin(), vec20.end(), vec21.begin(), vec21.end(), vec22.begin());
	vec22.resize(it3 - vec22.begin());
	for(int num : vec22) {
		cout << num << " ";
	}
	cout << endl;
	//使用set_intersection算法求两个有序vector的交集
	vector<int> vec23 = { 1, 2, 3 };
	vector<int> vec24 = { 2, 3, 4 };
	vector<int> vec25(6);
	auto it4 = set_intersection(vec23.begin(), vec23.end(), vec24.begin(), vec24.end(), vec25.begin());
	vec25.resize(it4 - vec25.begin());
	for(int num : vec25) {
		cout << num << " ";
	}
	cout << endl;
	//使用set_difference算法求两个有序vector的差集
	vector<int> vec26 = { 1, 2, 3 };
	vector<int> vec27 = { 2, 3, 4 };
	vector<int> vec28(6);
	auto it5 = set_difference(vec26.begin(), vec26.end(), vec27.begin(), vec27.end(), vec28.begin());
	vec28.resize(it5 - vec28.begin());
	for(int num : vec28) {
		cout << num << " ";
	}
	cout << endl;
	//其他算法
	//使用accumulate算法计算vector中所有元素的和（需要 <numeric> 库）
	vector<int> vec29 = { 1, 2, 3, 4, 5 };
	int sum = accumulate(vec29.begin(), vec29.end(), 0);
	cout << "Sum: " << sum << endl;
	//使用count算法计算vector中某个值的出现次数
	vector<int> vec30 = { 1, 2, 3, 2, 4, 2 };
	int count2 = count(vec30.begin(), vec30.end(), 2);
	cout << "Count of 2: " << count2 << endl;
	//使用for_each算法对vector中的每个元素执行指定操作
	vector<int> vec31 = { 1, 2, 3, 4, 5 };
	for_each(vec31.begin(), vec31.end(), [](int& n) { n *= 2; });
	for(int num : vec31) {
		cout << num << " ";
	}
	cout << endl;
	//使用min_element和max_element算法找到vector中的最小值和最大值
	vector<int> vec32 = { 5, 2, 9, 1, 5, 6 };
	auto minIt = min_element(vec32.begin(), vec32.end());
	auto maxIt = max_element(vec32.begin(), vec32.end());
	cout << "Min: " << *minIt << ", Max: " << *maxIt << endl;

}
//<numeric>数值算法的使用
void test_15() {
	//使用accumulate算法计算vector中所有元素的和（需要 <numeric> 库）
	vector<int> vec = { 1, 2, 3, 4, 5 };
	int sum = accumulate(vec.begin(), vec.end(), 0);
	cout << "Sum: " << sum << endl;
	//使用inner_product算法计算两个vector的内积
	vector<int> vec1 = { 1, 2, 3 };
	vector<int> vec2 = { 4, 5, 6 };
	int innerProd = inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0);
	cout << "Inner product: " << innerProd << endl;
	//使用partial_sum算法计算vector中元素的前缀和
	vector<int> vec3 = { 1, 2, 3, 4, 5 };
	vector<int> prefixSum(vec3.size());
	partial_sum(vec3.begin(), vec3.end(), prefixSum.begin());
	cout << "Prefix sum: ";
	for (int num : prefixSum) {
		cout << num << " ";
	}
	cout << endl;
	//使用adjacent_difference算法计算vector中相邻元素的差值
	vector<int> vec4 = { 1, 2, 3, 4, 5 };
	vector<int> adjDiff(vec4.size());
	adjacent_difference(vec4.begin(), vec4.end(), adjDiff.begin());
	cout << "Adjacent difference: ";
	for (int num : adjDiff) {
		cout << num << " ";
	}
	cout << endl;
	//使用gcd算法计算两个整数的最大公约数
	int a = 48, b = 18;
	int gcdValue = gcd(a, b);
	cout << "GCD of " << a << " and " << b << " is: " << gcdValue << endl;
	//使用lcm算法计算两个整数的最小公倍数
	int lcmValue = lcm(a, b);
	cout << "LCM of " << a << " and " << b << " is: " << lcmValue << endl;
	//使用iota算法生成一个递增的整数序列
	vector<int> vec5(5);
	iota(vec5.begin(), vec5.end(), 1); // 从 1 开始填充
	cout << "Iota sequence: ";
	for (int num : vec5) {
		cout << num << " ";
	}
	cout << endl;
}
//<complex>复数的使用
void test_16() {
	complex<double> c1(5.0, 3.0); // 创建一个复数 5 + 3i
	complex<double> c2(2.0, -4.0); // 创建一个复数 2 - 4i
	// 输出复数
	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	// 复数的加法
	complex<double> c3 = c1 + c2;
	cout << "c1 + c2: " << c3 << endl;
	// 复数的减法
	complex<double> c4 = c1 - c2;
	cout << "c1 - c2: " << c4 << endl;
	// 复数的乘法
	complex<double> c5 = c1 * c2;
	cout << "c1 * c2: " << c5 << endl;
	// 复数的除法
	complex<double> c6 = c1 / c2;
	cout << "c1 / c2: " << c6 << endl;
	//复数的共轭
	complex<double> c7 = conj(c1);
	cout << "Conjugate of c1: " << c7 << endl;
	//复数的模
	double magnitude = abs(c1);
	cout << "Magnitude of c1: " << magnitude << endl;
	//复数的幅角
	double angle = arg(c1);
	cout << "Angle of c1: " << angle << " radians" << endl;

}
//<cmath>数学函数的使用
void test_17() {
	//使用abs函数计算绝对值
	int a = -5;
	cout << "Absolute value of " << a << " is: " << abs(a) << endl;
	//使用fabsl函数计算浮点数的绝对值
	double b = -3.14;
	cout << "Absolute value of " << b << " is: " << fabs(b) << endl;
	//使用fmod函数计算浮点数的余数
	//fmod 的用途：最符合普通人的直觉。
	// 在周期性循环（如游戏循环、时间计算、数组索引循环）中极其常用。
	double c = 5.3, d = 2.0;
	cout << "fmod(" << c << ", " << d << ") = " << fmod(c, d) << endl;
	//使用remainder函数计算浮点数的余数
	//remainder 的用途：更符合数学上的对称性，通常用于高精度数学计算和 IEEE 754 浮点数标准。
	double e = 5.3, f = 2.0;
	cout << "remainder(" << e << ", " << f << ") = " << remainder(e, f) << endl;
	//使用fmax和fmin函数计算两个数的最大值和最小值
	double g = 3.5, h = 4.2;
	cout << "fmax(" << g << ", " << h << ") = " << fmax(g, h) << endl;
	cout << "fmin(" << g << ", " << h << ") = " << fmin(g, h) << endl;
	//使用hypot函数计算直角三角形的斜边长度
	double x = 3.0, y = 4.0;
	cout << "hypot(" << x << ", " << y << ") = " << hypot(x, y) << endl;
	//使用exp函数计算指数
	double i = 2.0;
	cout << "exp(" << i << ") = " << exp(i) << endl;
	//使用log函数计算自然对数
	double j = 7.38905609893065; // e^2
	cout << "log(" << j << ") = " << log(j) << endl;
	//使用log10函数计算以10为底的对数
	double k = 1000.0;
	cout << "log10(" << k << ") = " << log10(k) << endl;
	//使用pow函数计算幂
	double l = 2.0, m = 3.0;
	cout << "pow(" << l << ", " << m << ") = " << pow(l, m) << endl;
	//使用sqrt函数计算平方根
	double n = 16.0;
	cout << "sqrt(" << n << ") = " << sqrt(n) << endl;
	//使用cbrt函数计算立方根
	double o = 27.0;
	cout << "cbrt(" << o << ") = " << cbrt(o) << endl;
	// 三角函数
	std::cout << "sin(3.14159 / 2) = " << sin(3.14159 / 2) << std::endl;
	std::cout << "cos(3.14159) = " << cos(3.14159) << std::endl;
	// 取整函数
	std::cout << "ceil(2.3) = " << ceil(2.3) << std::endl;
	std::cout << "floor(2.3) = " << floor(2.3) << std::endl;
}
// <string>
void test_18() {
	std::string str = "Hello, World!";

	// size()
	std::cout << "Length: " << str.size() << std::endl;

	// empty()
	std::cout << "Is empty? " << (str.empty() ? "Yes" : "No") << std::endl;

	// operator[]
	std::cout << "First character: " << str[0] << std::endl;

	// at()
	std::cout << "Character at position 7: " << str.at(7) << std::endl;

	// substr()
	std::string sub = str.substr(7, 5);
	std::cout << "Substring from position 7 with length 5: " << sub << std::endl;

	// find()
	size_t pos = str.find("World");
	std::cout << "Position of 'World': " << pos << std::endl;

	// replace()
	str.replace(pos, 5, "C++");
	std::cout << "Modified string: " << str << std::endl;

	// append()
	str.append(" How are you?");
	std::cout << "Appended string: " << str << std::endl;

	// insert()
	str.insert(7, " Beautiful");
	std::cout << "String after insert: " << str << std::endl;

	// erase()
	str.erase(7, 10);
	std::cout << "String after erase: " << str << std::endl;

	// clear()
	str.clear();
	std::cout << "String after clear: " << (str.empty() ? "Empty" : "Not empty") << std::endl;

	// c_str()
	str = "Hello, C++!";
	const char* cstr = str.c_str();
	std::cout << "C-style string: " << cstr << std::endl;

	// compare()
	int cmp = str.compare("Hello, C++!");
	std::cout << "Comparison result: " << cmp << std::endl;

	// find_first_of()
	size_t pos_first_vowel = str.find_first_of("aeiou");
	std::cout << "First vowel at position: " << pos_first_vowel << std::endl;

	// find_last_of()
	size_t pos_last_vowel = str.find_last_of("aeiou");
	std::cout << "Last vowel at position: " << pos_last_vowel << std::endl;

	// find_first_not_of()
	size_t pos_first_non_vowel = str.find_first_not_of("aeiou");
	std::cout << "First non-vowel at position: " << pos_first_non_vowel << std::endl;

	// find_last_not_of()
	size_t pos_last_non_vowel = str.find_last_not_of("aeiou");
	std::cout << "Last non-vowel at position: " << pos_last_non_vowel << std::endl;

}
int main() {
	//<iostream>
	//test_1();
	//<array>
	//test_2();
	//<vector>
	//test_3();
	//<deque>
	//test_4();
	//<list>
	//test_5();
	//<forward_list>
	//test_6();
	//<stack>
	//test_7();
	//<queue>
	//test_8();
	//<priority_queue>
	//test_9();
	//<set>
	//test_10();
	//<unordered_set>
	//test_11();
	//<map>
	//test_12();
	//<unordered_map>
	//test_13();
	//<algorithm>
	//test_14();
	//<numeric>
	//test_15();
	//<complex>
	//test_16();
	//<cmath>
	//test_17();
	//<string>
	//test_18();
}