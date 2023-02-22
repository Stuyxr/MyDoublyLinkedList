# 项目介绍

一个简单的带有迭代器的双向列表。

涉及内容：

1. 双向列表的实现
2. 移动语义的理解
3. 重载运算符的实现
4. 迭代器的原理

# 写的过程写出来的bug

1. `Node* next, prev;`写在一行`prev`不会是指针类型

2. 模板的使用，只有最外边的class带`template <typename T>`，内部的不需要

3. 重载运算符`<<`，使得其可以被输出流输出。该函数不是类成员函数，是友元函数或者普通函数。写法不太熟练。

   ```c++
   friend ostream& operator<<(ostream& os, const Person& p) {}
   ```

4. 构建迭代器，重载`it++`和`++it`是不一样的。

   前缀形式的重载：`MyIterator& operator++(){}`，返回左值

   后缀形式的重载：`const MyIterator operator++(int) {}`，返回右值

   构造`begin()`, `end()`

# Output

```
------Test easy functions of MyList------
size of list: 4
Jane 25; stuyxr 23; John 30; stuzkb 22; 
stuyxr 23; John 30; stuzkb 22; 

------Test use rvalue of Person to construct Node------
p1: John 30;, p2: 1;

------Test copy constructor------
show copy list:
stuyxr 23; John 30; stuzkb 22; 
show list:
stuyxr 23; John 30; stuzkb 22; 

------Test move constructor------
show move list:
stuyxr 23; John 30; stuzkb 22; 
show list:


------Test iterator------
stuyxr 23;
John 30;
stuzkb 22;
```



