/*
    C++ 是一种静态类型的(使用静态类型的编程语言是在编译时执行类型检查，而不是运行是执行类型检查)、编译型的、通用的、大小写铭感的、不规则的语言，支持过程化编程，面向对象编程和泛型编程。
    C++ 被认为是一种中级语言，因为它结合了高级语言的特性和低级语言的特性。
    C++ 是 C 语言的超集，任何合法的C程序都可以认为是合法的C++程序，支持面向对象编程。
*/

/*
    泛型编程
    泛型编程是一种编程范式，旨在通过编写与类型无关的代码来提高代码的重用性和灵活性。
    
    C++ 通过模板（Templates）支持泛型编程，允许程序员编写与类型无关的函数和类。

    例如:

        template <typename T>
        T add(T a, T b) {
            return a + b;
        }
        这里的T是“占位符类型”，调用add函数时，可以传入任何支持加法操作的类型，如int、float、double等。

        add(3,5);         // 调用时T被推断为int
        add(2.5,4.5);     // 调用时T被推断为double
        add(std::string("Hello, "), std::string("World!"));     // 调用时T被推断为std::string
*/


// gcc C语言编译器
// g++ 本质是gcc的一部分，但默认把代码按C++编译
// gdb 调试器 debuger
/* cmake 跨平台构建系统生成器。
   它本身不编译，它生成编译系统。
   写一个 CMakeLists.txt，CMake 根据设置的项目结构，自动生成 Makefile、Ninja 配置、VS 工程等
*/

// clang C/C++/Objective-C编译器
/*
    现代化
    clang 是 LLVM 的一部分，架构跟清晰，模块化更强，错误提示更友好。
    工具链更“工程化”
    C++标准更新更快
    它可以作为 gcc 的替代品，或者作为 g++ 的替代品。
    它的 C++ 编译器是 clang++，C 编译器是 clang
*/

// 单行注释
/*
   多行注释
   也可以用 // 逐行注释
*/


#include <iostream>

// C++ 命名空间
// std 是 C++ 标准库的命名空间
// using namespace std;

int main() {

    // 表示std中的cout对象
    // 如果使用了 using namespace std; 则可以直接使用 cout
    std::cout << "Hello, World!" << std::endl;
    return 0;
}