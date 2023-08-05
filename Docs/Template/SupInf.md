---
title: sup inf変数
documentation_of: //Src/Template/SupInf.hpp
---

## 概要

適当な初期値として利用できる`sup`と`inf`を提供します。

#### ライブラリの使い方

```cpp
i32 supi;
i32 infi;
i64 supl;
i64 infl;

void SetSupi(i32)
void SetInfi(i32)
void SetSupl(i64)
void SetInfl(i64)
```

それぞれ`i32`型と`i64`型で`sup`と`inf`を提供します。予め`Set...`でこれらの値を各自設定することを想定しています。
- デフォルトでは、 $2^{30} - 1$ と $2^{62} - 1$ となっています。
