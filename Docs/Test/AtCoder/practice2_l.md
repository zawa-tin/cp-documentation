---
title: ALPC-L Lazy Segment Tree
documentation_of: "//Test/Manual/practice2_l.test.cpp"
---

以下の様にデータを持つ

```cpp
struct {
    long long zero; // 区間に含まれる0の数
    long long one; // 区間に含まれる1の数
    long long inv; // 区間転倒数
};
```

単位元は`{ 0, 0, 0 }`、区間をマージする時は、invに前のoneと後ろのzeroの積を足せば良い

区間のflipは「元々の転倒数 + flip後の転倒数 = 0の数と1の数の積」を利用する
