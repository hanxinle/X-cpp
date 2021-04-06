# Algorithm

在头文件<algorithm> 中，counting、searching、sorting、partitioning and transforming ...

All algorithm operate on range [first,last), ref: https://en.cppreference.com/w/cpp/algorithm.

cpp17 add execution policies for algorithm，包括顺序执行，并行执行等，在<execution>中定义，编译器支持不完全，仅作了解，to compare what compilers can do can use Compiler Ecplorer ：https://godbolt.org

## Sequence Algorithm

算法根据是否会对原始数据进行修改分为两种，一般能够明显区分，不确定的时候，在调用算法前对原始数据进行copy操作。

for_each 两者皆可，equal binary predicates，两个操作数。

move 操作，transform the owner of items,当不能用copy的时候，如线程等情况，可用 move.

示例，unique_ptr 不能被 copy，用move。
