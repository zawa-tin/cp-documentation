---
title: ioまわりの設定
documentation_of: //Src/Template/IOSetting.hpp
---

## ライブラリの使い方

```cpp
void SetFastIO()
```

入出力高速化のおまじないをします。


```cpp
void SetPrecision(u32 dig)
```

```cpp
std::cout << std::fixed << std::setprecision(dig)
```

をします。
