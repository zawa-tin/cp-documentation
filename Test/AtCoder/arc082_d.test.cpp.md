---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Monoid/MonoidConcept.hpp
    title: Src/Algebra/Monoid/MonoidConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Algebra/Semigroup/SemigroupConcept.hpp
    title: Src/Algebra/Semigroup/SemigroupConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/LazySegmentTree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
    title: Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
  - icon: ':heavy_check_mark:'
    path: Src/Sequence/CompressedSequence.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: Src/Template/TypeAlias.hpp
    title: "\u6A19\u6E96\u30C7\u30FC\u30BF\u578B\u306E\u30A8\u30A4\u30EA\u30A2\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/arc082/submissions/75030785
    - https://atcoder.jp/contests/arc082/tasks/arc082_d
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"Test/AtCoder/arc082_d.test.cpp\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/arc082/tasks/arc082_d\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Regular Contest 082 F - Sandlgass\n * https://atcoder.jp/contests/arc082/submissions/75030785\n\
    \ */\n\n#line 2 \"Src/Sequence/CompressedSequence.hpp\"\n\n#line 2 \"Src/Template/TypeAlias.hpp\"\
    \n\n#include <cstdint>\n#include <cstddef>\n\nnamespace zawa {\n\nusing i16 =\
    \ std::int16_t;\nusing i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing i128\
    \ = __int128_t;\n\nusing u8 = std::uint8_t;\nusing u16 = std::uint16_t;\nusing\
    \ u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    \n} // namespace zawa\n#line 4 \"Src/Sequence/CompressedSequence.hpp\"\n\n#include\
    \ <vector>\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include\
    \ <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nclass CompressedSequence\
    \ {\npublic:\n\n    static constexpr u32 NotFound = std::numeric_limits<u32>::max();\n\
    \n    CompressedSequence() = default;\n\n    template <class InputIterator>\n\
    \    CompressedSequence(InputIterator first, InputIterator last) : comped_(first,\
    \ last), f_{} {\n        std::sort(comped_.begin(), comped_.end());\n        comped_.erase(std::unique(comped_.begin(),\
    \ comped_.end()), comped_.end());\n        comped_.shrink_to_fit();\n        f_.reserve(std::distance(first,\
    \ last));\n        for (auto it{first} ; it != last ; it++) {\n            f_.emplace_back(std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), *it)));\n        }\n    }\n\
    \n    CompressedSequence(const std::vector<T>& A) : CompressedSequence(A.begin(),\
    \ A.end()) {}\n\n    inline usize size() const noexcept {\n        return comped_.size();\n\
    \    }\n\n    u32 operator[](const T& v) const {\n        return std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n    }\n\n    u32 upper_bound(const\
    \ T& v) const {\n        return std::distance(comped_.begin(), std::upper_bound(comped_.begin(),\
    \ comped_.end(), v));\n    }\n\n    u32 find(const T& v) const {\n        u32\
    \ i = std::distance(comped_.begin(), std::lower_bound(comped_.begin(), comped_.end(),\
    \ v));\n        return i == comped_.size() or comped_[i] != v ? NotFound : i;\n\
    \    }\n\n    bool contains(const T& v) const {\n        u32 i = std::distance(comped_.begin(),\
    \ std::lower_bound(comped_.begin(), comped_.end(), v));\n        return i < comped_.size()\
    \ and comped_[i] == v;\n    }\n\n    u32 at(const T& v) const {\n        u32 res\
    \ = find(v);\n        assert(res != NotFound);\n        return res;\n    }\n\n\
    \    inline u32 map(u32 i) const noexcept {\n        assert(i < f_.size());\n\
    \        return f_[i];\n    }\n\n    inline T inverse(u32 i) const noexcept {\n\
    \        assert(i < size());\n        return comped_[i];\n    }\n\n    inline\
    \ std::vector<T> comped() const noexcept {\n        return comped_;\n    }\n\n\
    private:\n\n    std::vector<T> comped_;\n\n    std::vector<u32> f_;\n\n};\n\n\
    } // namespace zawa\n#line 2 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\n#line 2 \"Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp\"\n\n#line\
    \ 2 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 2 \"Src/Algebra/Semigroup/SemigroupConcept.hpp\"\
    \n\n#include <concepts>\n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate\
    \ <class T>\nconcept Semigroup = requires {\n    typename T::Element;\n    { T::operation(std::declval<typename\
    \ T::Element>(), std::declval<typename T::Element>()) } -> std::same_as<typename\
    \ T::Element>;\n};\n\n} // namespace concepts\n\n} // namespace zawa\n#line 4\
    \ \"Src/Algebra/Monoid/MonoidConcept.hpp\"\n\n#line 6 \"Src/Algebra/Monoid/MonoidConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept Identitiable\
    \ = requires {\n    typename T::Element;\n    { T::identity() } -> std::same_as<typename\
    \ T::Element>;\n};\n\ntemplate <class T>\nconcept Monoid = Semigroup<T> and Identitiable<T>;\n\
    \n} // namespace\n\n} // namespace zawa\n#line 4 \"Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp\"\
    \n\nnamespace zawa {\n\nnamespace concepts {\n\ntemplate <class T>\nconcept MonoidWithAction\
    \ = requires {\n    requires Monoid<typename T::ValueMonoid>;\n    requires Monoid<typename\
    \ T::OperatorMonoid>;\n    { T::mapping(\n            std::declval<typename T::ValueMonoid::Element>(),\n\
    \            std::declval<typename T::OperatorMonoid::Element>()\n           \
    \ ) } -> std::same_as<typename T::ValueMonoid::Element>; \n};\n\n} // namespace\
    \ concepts\n\n} // namespace zawa\n#line 5 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\n#line 7 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n#include <bit>\n\
    #line 9 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\n#include <ranges>\n\
    #include <tuple>\n#line 12 \"Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <concepts::MonoidWithAction S>\nclass LazySegmentTree\
    \ {\npublic:\n\n    using VM = S::ValueMonoid;\n\n    using V = typename VM::Element;\n\
    \n    using OM = S::OperatorMonoid;\n\n    using O = typename OM::Element;\n\n\
    \    LazySegmentTree() = default;\n\n    explicit LazySegmentTree(usize n) \n\
    \        : m_n{n}, m_sz{1u << (std::bit_width(n))}, m_dat(m_sz << 1, VM::identity()),\
    \ m_lazy(m_sz << 1, OM::identity()) {}\n\n    explicit LazySegmentTree(const std::vector<V>&\
    \ a)\n        : m_n{a.size()}, m_sz{1u << (std::bit_width(a.size()))}, m_dat(m_sz\
    \ << 1, VM::identity()), m_lazy(m_sz << 1, OM::identity()) {\n        std::ranges::copy(a,\
    \ m_dat.begin() + inner_size());\n        for (usize i = inner_size() ; --i ;\
    \ ) recalc(i);\n    }\n\n    [[nodiscard]] inline usize size() const noexcept\
    \ {\n        return m_n;\n    }\n\n    [[nodiscard]] V operator[](usize i) {\n\
    \        assert(i < size());\n        return get(i, 1, 0, inner_size());\n   \
    \ }\n\n    [[nodiscard]] V get(usize i) {\n        return (*this)[i];\n    }\n\
    \n    [[nodiscard]] V product(usize l, usize r) {\n        assert(l <= r and r\
    \ <= size());\n        return product(l, r, 1, 0, inner_size());\n    }\n\n  \
    \  void operation(usize l, usize r, const O& o) {\n        assert(l <= r and r\
    \ <= size());\n        return operation(l, r, o, 1, 0, inner_size());\n    }\n\
    \n    void assign(usize i, const V& v) {\n        assert(i < size());\n      \
    \  assign(i, v, 1, 0, inner_size());\n    }\n\n    void operation(usize i, const\
    \ O& o) {\n        assert(i < size());\n        operation(i, o, 1, 0, inner_size());\n\
    \    }\n\nprivate:\n\n    using NodeInfo = std::tuple<usize, usize, usize>;\n\n\
    public:\n\n    template <class F>\n    requires std::predicate<F, V>\n    usize\
    \ maxRight(usize l, F f) {\n        assert(l <= size());\n        if (!f(VM::identity()))\
    \ return l;\n        if (l == size()) return size();\n        std::vector<NodeInfo>\
    \ ranges;\n        partition_range(l, size(), ranges, 1, 0, inner_size());\n \
    \       V prod = VM::identity();\n        for (auto [nd, nl, nr] : ranges) {\n\
    \            if (!f(VM::operation(prod, m_dat[nd]))) {\n                return\
    \ maxRight(f, prod, nd, nl, nr);\n            }\n            else {\n        \
    \        prod = VM::operation(prod, m_dat[nd]);\n            }\n        }\n  \
    \      return size();\n    }\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    usize minLeft(usize r, F f) {\n        assert(r <= size());\n      \
    \  if (!f(VM::identity())) return r;\n        if (!r) return 0;\n        std::vector<NodeInfo>\
    \ ranges;\n        partition_range(0, r, ranges, 1, 0, inner_size());\n      \
    \  V prod = VM::identity();\n        for (auto [nd, nl, nr] : ranges | std::views::reverse)\
    \ {\n            if (!f(VM::operation(m_dat[nd], prod))) {\n                return\
    \ minLeft(f, prod, nd, nl, nr);\n            }\n            else {\n         \
    \       prod = VM::operation(m_dat[nd],prod);\n            }\n        }\n    \
    \    return 0;\n    }\n\nprivate:\n\n    usize m_n{}, m_sz{};\n\n    std::vector<V>\
    \ m_dat;\n\n    std::vector<O> m_lazy;\n\n    inline usize inner_size() const\
    \ noexcept {\n        return m_sz;\n    }\n    \n    void recalc(usize nd) {\n\
    \        // assert(nd < inner_size());\n        m_dat[nd] = VM::operation(m_dat[nd\
    \ << 1 | 0], m_dat[nd << 1 | 1]);\n    }\n\n    void propagate(usize nd) {\n \
    \       // assert(nd < inner_size());\n        for (usize ch : {nd << 1 | 0, nd\
    \ << 1 | 1}) {\n            m_dat[ch] = S::mapping(m_dat[ch], m_lazy[nd]);\n \
    \           m_lazy[ch] = OM::operation(m_lazy[ch], m_lazy[nd]);\n        }\n \
    \       m_lazy[nd] = OM::identity();\n    }\n\n    V product(usize ql, usize qr,\
    \ usize nd, usize nl, usize nr) {\n        if (qr <= nl or nr <= ql) return VM::identity();\n\
    \        if (ql <= nl and nr <= qr) return m_dat[nd];\n        propagate(nd);\n\
    \        const usize m = (nl + nr) >> 1;\n        return VM::operation(\n    \
    \            product(ql, qr, nd << 1 | 0, nl, m),\n                product(ql,\
    \ qr, nd << 1 | 1, m, nr)\n                );\n    }\n\n    V get(usize i, usize\
    \ nd, usize nl, usize nr) {\n        if (nd >= inner_size()) return m_dat[nd];\n\
    \        propagate(nd);\n        const usize m = (nl + nr) >> 1;\n        return\
    \ i < m ? get(i, nd << 1 | 0, nl, m) : get(i, nd << 1 | 1, m, nr);\n    }\n\n\
    \    void operation(usize ql, usize qr, const O& o, usize nd, usize nl, usize\
    \ nr) {\n        if (qr <= nl or nr <= ql) return;\n        if (ql <= nl and nr\
    \ <= qr) {\n            m_dat[nd] = S::mapping(m_dat[nd], o);\n            m_lazy[nd]\
    \ = OM::operation(m_lazy[nd], o);\n            return;\n        }\n        propagate(nd);\n\
    \        const usize m = (nl + nr) >> 1;\n        operation(ql, qr, o, nd << 1\
    \ | 0, nl, m);\n        operation(ql, qr, o, nd << 1 | 1, m, nr);\n        recalc(nd);\n\
    \    }\n\n    void operation(usize i, const O& o, usize nd, usize nl, usize nr)\
    \ {\n        if (nl == i and i + 1 == nr) {\n            m_dat[nd] = S::mapping(m_dat[nd],\
    \ o);\n            return;\n        }\n        propagate(nd); \n        const\
    \ usize m = (nl + nr) >> 1;\n        i < m ? operation(i, o, nd << 1 | 0, nl,\
    \ m) : operation(i, o, nd << 1 | 1, m, nr);\n        recalc(nd);\n    }\n\n  \
    \  void assign(usize i, const V& v, usize nd, usize nl, usize nr) {\n        if\
    \ (nl == i and i + 1 == nr) {\n            m_dat[nd] = v;\n            return;\n\
    \        }\n        propagate(nd); \n        const usize m = (nl + nr) >> 1;\n\
    \        i < m ? assign(i, v, nd << 1 | 0, nl, m) : assign(i, v, nd << 1 | 1,\
    \ m, nr);\n        recalc(nd);\n    }\n\n    void partition_range(usize ql, usize\
    \ qr, std::vector<NodeInfo>& res, usize nd, usize nl, usize nr) {\n        if\
    \ (qr <= nl or nr <= ql) return;\n        if (ql <= nl and nr <= qr) {\n     \
    \       res.emplace_back(nd, nl, nr);\n            return;\n        }\n      \
    \  propagate(nd);\n        const usize m = (nl + nr) >> 1;\n        partition_range(ql,\
    \ qr, res, nd << 1 | 0, nl, m);\n        partition_range(ql, qr, res, nd << 1\
    \ | 1, m, nr);\n    }\n\n    template <class F>\n    requires std::predicate<F,\
    \ V>\n    usize maxRight(F f, const V& prod, usize nd, usize nl, usize nr) {\n\
    \        if (nd >= inner_size()) return nl;\n        propagate(nd);\n        const\
    \ usize m = (nl + nr) >> 1, lch = nd << 1 | 0, rch = nd << 1 | 1;\n        return\
    \ f(VM::operation(prod, m_dat[lch])) ? \n            maxRight(f, VM::operation(prod,\
    \ m_dat[lch]), rch, m, nr) : maxRight(f, prod, lch, nl, m);\n    }\n\n    template\
    \ <class F>\n    requires std::predicate<F, V>\n    usize minLeft(F f, const V&\
    \ prod, usize nd, usize nl, usize nr) {\n        if (nd >= inner_size()) return\
    \ nr;\n        propagate(nd);\n        const usize m = (nl + nr) >> 1, lch = nd\
    \ << 1 | 0, rch = nd << 1 | 1;\n        return f(VM::operation(m_dat[rch], prod))\
    \ ? \n            minLeft(f, VM::operation(m_dat[rch], prod), lch, nl, m) : minLeft(f,\
    \ prod, rch, m, nr);\n    }\n};\n\n} // namespace zawa\n#line 11 \"Test/AtCoder/arc082_d.test.cpp\"\
    \nusing namespace zawa;\n#line 13 \"Test/AtCoder/arc082_d.test.cpp\"\n#include\
    \ <iostream>\n#line 15 \"Test/AtCoder/arc082_d.test.cpp\"\n#include <variant>\n\
    #line 19 \"Test/AtCoder/arc082_d.test.cpp\"\nusing namespace std;\nstruct VM {\n\
    \   using Element = pair<long long,long long>;\n   static Element identity() {\n\
    \       return {-(long long)2e9,(long long)2e9};\n   }\n   static Element operation(Element\
    \ L, Element R) {\n       L.first = max(L.first,R.first);\n       L.second = min(L.second,R.second);\n\
    \       return L;\n   }\n};\nusing Assign = long long;\nusing Add = tuple<long\
    \ long,bool,long long>;\nusing Item = variant<Assign,Add>;\nAdd normalize(Add\
    \ v) {\n    if (!get<1>(v)) {\n        get<0>(v) += get<2>(v);\n        get<2>(v)\
    \ = 0;\n    }\n    return v;\n}\nstruct OM {\n    using Element = Item;\n    static\
    \ Element identity() {\n        return tuple{0LL,false,0LL};\n    }\n    static\
    \ Element operation(Element L, Element R) {\n        if (holds_alternative<Assign>(R))\n\
    \            return R;\n        if (holds_alternative<Assign>(L)) {\n        \
    \    long long v = get<Assign>(L);\n            auto [p,m,s] = get<Add>(R);\n\
    \            v += p;\n            if (m)\n                v *= -1;\n         \
    \   v += s;\n            return v;\n        }\n        auto [l1,m1,r1] = normalize(get<Add>(L));\n\
    \        auto [l2,m2,r2] = normalize(get<Add>(R));\n        if (!m1) {\n     \
    \       l1 += l2;\n            m1 = m2;\n            r1 = r2;\n            return\
    \ Add{l1,m1,r1};\n        }\n        if (!m2) {\n            r1 += l2;\n     \
    \       return Add{l1,m1,r1};\n        }\n        return Add{l1-r1-l2+r2,false,0LL};\n\
    \    }\n};\nstruct ACT {\n    using ValueMonoid = VM;\n    using OperatorMonoid\
    \ = OM;\n    static ValueMonoid::Element mapping(ValueMonoid::Element v, OperatorMonoid::Element\
    \ o) {\n        if (holds_alternative<Add>(o)) {\n            auto [l,m,r] = get<Add>(o);\n\
    \            v.first += l;\n            v.second += l;\n            if (m) {\n\
    \                v.first *= -1;\n                v.second *= -1;\n           \
    \ }\n            v.first += r;\n            v.second += r;\n            if (v.first\
    \ < v.second)\n                swap(v.first,v.second);\n            return v;\n\
    \        }\n        else\n            return {get<Assign>(o),get<Assign>(o)};\n\
    \    }\n};\nint main() {\n#ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n\
    \    ios::sync_with_stdio(0);\n    int X,K;\n    cin >> X >> K;\n    vector<int>\
    \ R(K);\n    for (auto& x : R)\n        cin >> x;\n    int Q;\n    cin >> Q;\n\
    \    vector<int> T(Q);\n    vector<long long> A(Q);\n    for (int i = 0 ; i <\
    \ Q ; i++)\n        cin >> T[i] >> A[i];\n    CompressedSequence<long long> comp{A};\n\
    \    const int n = ssize(comp);\n    LazySegmentTree<ACT> seg([&]() {\n      \
    \          vector<pair<long long,long long>> res(n);\n                for (int\
    \ i = 0 ; i < n ; i++)\n                    res[i] = {comp.inverse(i),comp.inverse(i)};\n\
    \                return res;\n            }());\n    vector<tuple<int,int,int>>\
    \ event;\n    event.reserve(K+Q);\n    for (int i = 0 ; i < K ; i++)\n       \
    \ event.push_back({R[i],0,i});\n    for (int i = 0 ; i < Q ; i++)\n        event.push_back({T[i],1,i});\n\
    \    ranges::sort(event);\n    bool sign = 0;\n    vector<long long> ans(Q);\n\
    \    int last_upd = 0;\n    for (auto [time,type,idx] : event) {\n        if (type\
    \ == 0) {\n            if (!sign) { // \u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\n\
    \                auto it = seg.maxRight(0,[&](const VM::Element& v) { return v.first\
    \ <= time - last_upd; });\n                seg.operation(0,it,Assign{0LL});\n\
    \                seg.operation(it,n,Add{-(time-last_upd),false,0LL});\n      \
    \      }\n            else { // \u6E1B\u5C11\n                auto it = seg.minLeft(n,[&](const\
    \ VM::Element& v) { return v.first <= time - last_upd; });\n                seg.operation(it,n,Assign{0LL});\n\
    \                seg.operation(0,it,Add{-(time-last_upd),false,0LL});\n      \
    \      }\n            seg.operation(0,n,Add{0LL,true,X});\n            last_upd\
    \ = time;\n            sign = !sign;\n            // for (int i = 0 ; i < n ;\
    \ i++)\n            //     cout << seg[i] << (i + 1 == n ? '\\n' : ' ');\n   \
    \     }\n        else if (type == 1) {\n            long long up = seg[comp.at(A[idx])].first;\n\
    \            // assert(0 <= up and up <= X);\n            up = max(0LL,up-(time-last_upd));\n\
    \            if (sign)\n                ans[idx] = X - up;\n            else\n\
    \                ans[idx] = up;\n        }\n        else\n            assert(0);\n\
    \    }\n    for (long long a : ans)\n        cout << a << '\\n';\n#else\n    cout\
    \ << \"Hello World\\n\";\n#endif\n}\n"
  code: "// #define PROBLEM \"https://atcoder.jp/contests/arc082/tasks/arc082_d\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n/*\n * AtCoder Regular Contest 082 F - Sandlgass\n * https://atcoder.jp/contests/arc082/submissions/75030785\n\
    \ */\n\n#include \"../../Src/Sequence/CompressedSequence.hpp\"\n#include \"../../Src/DataStructure/SegmentTree/LazySegmentTree.hpp\"\
    \nusing namespace zawa;\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\
    #include <variant>\n#include <tuple>\n#include <iterator>\n#include <ranges>\n\
    using namespace std;\nstruct VM {\n   using Element = pair<long long,long long>;\n\
    \   static Element identity() {\n       return {-(long long)2e9,(long long)2e9};\n\
    \   }\n   static Element operation(Element L, Element R) {\n       L.first = max(L.first,R.first);\n\
    \       L.second = min(L.second,R.second);\n       return L;\n   }\n};\nusing\
    \ Assign = long long;\nusing Add = tuple<long long,bool,long long>;\nusing Item\
    \ = variant<Assign,Add>;\nAdd normalize(Add v) {\n    if (!get<1>(v)) {\n    \
    \    get<0>(v) += get<2>(v);\n        get<2>(v) = 0;\n    }\n    return v;\n}\n\
    struct OM {\n    using Element = Item;\n    static Element identity() {\n    \
    \    return tuple{0LL,false,0LL};\n    }\n    static Element operation(Element\
    \ L, Element R) {\n        if (holds_alternative<Assign>(R))\n            return\
    \ R;\n        if (holds_alternative<Assign>(L)) {\n            long long v = get<Assign>(L);\n\
    \            auto [p,m,s] = get<Add>(R);\n            v += p;\n            if\
    \ (m)\n                v *= -1;\n            v += s;\n            return v;\n\
    \        }\n        auto [l1,m1,r1] = normalize(get<Add>(L));\n        auto [l2,m2,r2]\
    \ = normalize(get<Add>(R));\n        if (!m1) {\n            l1 += l2;\n     \
    \       m1 = m2;\n            r1 = r2;\n            return Add{l1,m1,r1};\n  \
    \      }\n        if (!m2) {\n            r1 += l2;\n            return Add{l1,m1,r1};\n\
    \        }\n        return Add{l1-r1-l2+r2,false,0LL};\n    }\n};\nstruct ACT\
    \ {\n    using ValueMonoid = VM;\n    using OperatorMonoid = OM;\n    static ValueMonoid::Element\
    \ mapping(ValueMonoid::Element v, OperatorMonoid::Element o) {\n        if (holds_alternative<Add>(o))\
    \ {\n            auto [l,m,r] = get<Add>(o);\n            v.first += l;\n    \
    \        v.second += l;\n            if (m) {\n                v.first *= -1;\n\
    \                v.second *= -1;\n            }\n            v.first += r;\n \
    \           v.second += r;\n            if (v.first < v.second)\n            \
    \    swap(v.first,v.second);\n            return v;\n        }\n        else\n\
    \            return {get<Assign>(o),get<Assign>(o)};\n    }\n};\nint main() {\n\
    #ifdef ATCODER\n    cin.tie(0);\n    cout.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    int X,K;\n    cin >> X >> K;\n    vector<int> R(K);\n    for (auto& x : R)\n\
    \        cin >> x;\n    int Q;\n    cin >> Q;\n    vector<int> T(Q);\n    vector<long\
    \ long> A(Q);\n    for (int i = 0 ; i < Q ; i++)\n        cin >> T[i] >> A[i];\n\
    \    CompressedSequence<long long> comp{A};\n    const int n = ssize(comp);\n\
    \    LazySegmentTree<ACT> seg([&]() {\n                vector<pair<long long,long\
    \ long>> res(n);\n                for (int i = 0 ; i < n ; i++)\n            \
    \        res[i] = {comp.inverse(i),comp.inverse(i)};\n                return res;\n\
    \            }());\n    vector<tuple<int,int,int>> event;\n    event.reserve(K+Q);\n\
    \    for (int i = 0 ; i < K ; i++)\n        event.push_back({R[i],0,i});\n   \
    \ for (int i = 0 ; i < Q ; i++)\n        event.push_back({T[i],1,i});\n    ranges::sort(event);\n\
    \    bool sign = 0;\n    vector<long long> ans(Q);\n    int last_upd = 0;\n  \
    \  for (auto [time,type,idx] : event) {\n        if (type == 0) {\n          \
    \  if (!sign) { // \u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\n                auto\
    \ it = seg.maxRight(0,[&](const VM::Element& v) { return v.first <= time - last_upd;\
    \ });\n                seg.operation(0,it,Assign{0LL});\n                seg.operation(it,n,Add{-(time-last_upd),false,0LL});\n\
    \            }\n            else { // \u6E1B\u5C11\n                auto it =\
    \ seg.minLeft(n,[&](const VM::Element& v) { return v.first <= time - last_upd;\
    \ });\n                seg.operation(it,n,Assign{0LL});\n                seg.operation(0,it,Add{-(time-last_upd),false,0LL});\n\
    \            }\n            seg.operation(0,n,Add{0LL,true,X});\n            last_upd\
    \ = time;\n            sign = !sign;\n            // for (int i = 0 ; i < n ;\
    \ i++)\n            //     cout << seg[i] << (i + 1 == n ? '\\n' : ' ');\n   \
    \     }\n        else if (type == 1) {\n            long long up = seg[comp.at(A[idx])].first;\n\
    \            // assert(0 <= up and up <= X);\n            up = max(0LL,up-(time-last_upd));\n\
    \            if (sign)\n                ans[idx] = X - up;\n            else\n\
    \                ans[idx] = up;\n        }\n        else\n            assert(0);\n\
    \    }\n    for (long long a : ans)\n        cout << a << '\\n';\n#else\n    cout\
    \ << \"Hello World\\n\";\n#endif\n}\n"
  dependsOn:
  - Src/Sequence/CompressedSequence.hpp
  - Src/Template/TypeAlias.hpp
  - Src/DataStructure/SegmentTree/LazySegmentTree.hpp
  - Src/DataStructure/SegmentTree/SegmentTreeConcept.hpp
  - Src/Algebra/Monoid/MonoidConcept.hpp
  - Src/Algebra/Semigroup/SemigroupConcept.hpp
  isVerificationFile: true
  path: Test/AtCoder/arc082_d.test.cpp
  requiredBy: []
  timestamp: '2026-04-18 17:26:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/AtCoder/arc082_d.test.cpp
layout: document
redirect_from:
- /verify/Test/AtCoder/arc082_d.test.cpp
- /verify/Test/AtCoder/arc082_d.test.cpp.html
title: Test/AtCoder/arc082_d.test.cpp
---
