#pragma once

#include <string>
#include <iostream>

namespace zawa {

namespace internal {

std::string yes{"Yes"};
std::string no{"No"};

} // namespace internal

void YesNo(bool answer) {
    std::cout << (answer ? internal::yes : internal::no) << std::endl;
}

void SetYes(const std::string& yes) {
    internal::yes = yes;
}

void SetNo(const std::string& no) {
    internal::no = no;
}

void SetAtCoderYesNo() {
    SetYes("Yes");
    SetNo("No");
}

void SetCodeforcesYesNo() {
    SetYes("YES");
    SetNo("NO");
}

} // namespace zawa
