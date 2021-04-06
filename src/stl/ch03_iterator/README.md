# 迭代器（iterator）

迭代器是可以指向一定范围内元素的一种泛型数据（可以为任意类型），迭代器具有遍历、操作元素的能力。

可以将迭代器理解为指针的总称。

迭代器可以分为：输入、输出、前向、双向、随机读取、连续迭代器（contiguous C++17），通过 iterator_traits 每个迭代器表征特性。

迭代器具有如下特性：复制构造(X a, X b(a))，赋值初始化(=),析构性，交换性，数值类特性(如 value_type,difference_type,reference......),反引用（*it),自增。

迭代器是重要的，因为所有的STL操作是基于迭代器的，迭代器允许以不显示声明(collction-agnostic)的方式遍历顺序元素。迭代器可以用于创建构造器（generator)。

为了有效利用迭代器，迭代器的特性必须定义，包含：difference_type 表示两个迭代器差值的类型；value_type 反引用迭代器得到这个类型，同时禁止对输出迭代器使用；pointer，reference,iterator_category。

## input iterators

Input iterator add a few small requirements on top of a base iterator.It can read from the pointed-to element.Input iterator 仅仅适用于单通道算法（single pass algo），一旦自增，之前值的所有拷贝都可能无效，例子：steam iterator 从键盘输入得到字符，迭代器自增，原来的输入的字符已经不见了，不要去访问了。

## output iterators

output iterators can used in a sequential output operations,where each element pointed by the iterator is written a value only once, and then the iterator is incremented.

Algorithm requireing output iterators should be single-pass output algorithm.

* each iterator's position is deferenced, once at most. lvalue derefenceable.Must be a class or pointer type.

* equality and inequality may not be defined for output iterators(Not required or not guaranteed to be there)

## forward iterators

FI Can be used to acess the sequeue of elements in a range in the direction that goes from its begining towards its end.There is a key difference from input iterators that input iterators are only single-pass guarantedd,FI must be multi-pass guarantedd.If a FI satisfies the requirements for an output iterator,it is mutable forward iterator.(如果没有自增操作，则永远指向某个元素)

FI satisfies the input iterators, but don't need to statisfy the output iterators.

## bidirectional iterators

与FI相比，可以执行自减操作。 

## Random-access iterators

Random-access iterators can be used to acess elements at an arbitrary offset position（任意偏移位置），与指向的元素相关联，但是提供指针一样的功能（functionality）。功能上是最复杂的迭代器种类。

符合双向迭代器的特性，常数时间消耗的任意数量的偏移，

## auxiliary iterator functions

The iterator library offers some special functions that can be used universally, regardless of the type of iterator they are used on:next,prev,advance,distance

The library also provides special functions to access the iterators defined in containers: begin,end,rbegin,rend.They also are available with a c prefix for const.

## iterator adapters(适配器)

适配器接收（take in）迭代器，并且改变它的部分行为。例如，reverse_iterator 接收双向迭代器使其逆向运行；move_iterator 接收任意类型的input iterator反引用使其产生右值引用（如同 std::move 的使用）。

iterator header defines serveral special iterators for developers to use.例如：insert_iterator, front_insert_iterator, back_insert_iterator, ostream_iterator, istream_iterator, istreambuf_iterator, ostreambuf_iterator.