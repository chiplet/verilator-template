#pragma once

#include <cstdint>
#include <memory>


template<typename MODULE>
class TestBench
{
    public:
        TestBench();

        void Tick();
        uint64_t GetTicks() const { return tickcount_; }
        std::shared_ptr<MODULE> GetModule() { return module_; }

    private:
        std::shared_ptr<MODULE> module_;    // verilog module under test
        uint64_t tickcount_;
};


template<typename MODULE>
TestBench<MODULE>::TestBench() : tickcount_(0)
{
    module_ = std::make_shared<MODULE>();
}

template<typename MODULE>
void TestBench<MODULE>::Tick()
{
    tickcount_++;
    module_->eval();
    // rising clock edge
    module_->i_clk = 1;
    module_->eval();
    // falling clock edge
    module_->i_clk = 0;
    module_->eval();
}
