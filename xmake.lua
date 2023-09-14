set_project("LeetCode")

set_version("1.0.0")

set_languages("cxx17")

target("main")
    set_kind("binary")
    add_includedirs("LeetCode")
    add_files("LeetCode/leetcode-main.cpp")