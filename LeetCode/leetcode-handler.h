/* This file is generated by extension [LeetCode C++ Debugger], you can delete it if you want. */

#ifndef LEETCODE_HANDLER
#define LEETCODE_HANDLER

#include "2848.points-that-intersect-with-cars.cpp"
#include "leetcode-io.h"

namespace lc {

class Handler {
public:
    static std::string GetClassName() { return "Solution"; } 
    Handler(const json::Json& in) {
        solution_ = new Solution();
    }
    ~Handler() { delete solution_; }
    json::Json Handle(const json::Json& in, const std::string& fname) { return json::Create<json::JNull>(); }
    void Handle(io::SI& in, io::MO& out) {
        vector<vector<int>> nums;
        in >> nums;
        #ifdef LAZY_INTERACTION
        in.Input(LAZY_INTERACTION);
        #endif
        out << solution_->numberOfPoints(nums) << std::endl;
    }
    
private:
    Solution* solution_;
};

} // namespace lc

#endif // LEETCODE_HANDLER