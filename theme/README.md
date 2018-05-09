## Binary Search Tree

[ Binary Search Tree (C++ implementation) ](./BinarySearchTree.cpp)

实现的时候，果然遇到了一些问题。尤其是一个内存管理的问题，我在写析构函数的时候，
想也没想，就这样写了：

```cpp
~BinarySearchTree()
  {
    delete left;
    delete right;
  }
;
```

后来测试的时候出现访问越界的错误。找了很久才发觉，原来是 `delete` 一个节点的时候，
这个节点的有效的孩子节点也在析构函数里面被隐式地释放掉了。。解决方法就是
`delete` 任何一个节点的时候都要把它的孩子节点赋值成 `nullptr`，在 C++ 里面
`delete nullptr` 不会产生错误。

另外一个，由于删除节点可能会删除掉根节点，所以根节点也需要在堆上，`delete` 一个
指向栈上的变量的指针会出错。
