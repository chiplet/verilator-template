#pragma once

#include <cstdint>
#include <memory>
#include "verilated.h"
#include "verilated_vcd_c.h"


template<typename MODULE>
class TestBench
{
    public:
        TestBench();
        virtual ~TestBench() {}

        virtual void Tick();
        virtual void Reset();
        virtual void Eval() { module_->eval(); }
        virtual bool Done() const { return Verilated::gotFinish(); }
        virtual uint64_t GetTicks() const { return tickcount_; }
        virtual void OpenTrace(const char* vcdname);
        virtual void CloseTrace();
        std::unique_ptr<MODULE>& GetModule() { return module_; }

    private:
        std::unique_ptr<MODULE> module_;        // verilog module under test
        std::unique_ptr<VerilatedVcdC> trace_;  // VCD trace
        uint64_t tickcount_;
};


template<typename MODULE>
TestBench<MODULE>::TestBench() : tickcount_(0)
{
    module_ = std::make_unique<MODULE>();
    Verilated::traceEverOn(true);
}

template<typename MODULE>
void TestBench<MODULE>::Tick()
{
    tickcount_++;
    module_->eval();
    // rising clock edge
    if (trace_) trace_->dump((vluint64_t)(10*tickcount_-2));
    module_->i_clk = 1;
    module_->eval();
    if (trace_) trace_->dump((vluint64_t)(10*tickcount_));
    // falling clock edge
    module_->i_clk = 0;
    module_->eval();
    if (trace_)
    {
        trace_->dump((vluint64_t)(10*tickcount_+5));
        trace_->flush();
    }
}

template<typename MODULE>
void TestBench<MODULE>::Reset()
{
    module_->i_reset = 1;
    Tick();
    module_->i_reset= 0;
}

template<typename MODULE>
void TestBench<MODULE>::OpenTrace(const char* vcdname)
{
    if (!trace_)
    {
        trace_ = std::make_unique<VerilatedVcdC>();
        module_->trace(trace_.get(), 99); // TODO: handle potential nullptr return from trace_.get()
        trace_->open(vcdname);
    }
}

template<typename MODULE>
void TestBench<MODULE>::CloseTrace()
{
    if (trace_)
    {
        trace_->close();
    }
}
