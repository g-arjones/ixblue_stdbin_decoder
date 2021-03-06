#pragma once

#include "iXblue_stdbin_decoder/data_models/navigation_data/realtime_heave_surge_sway.h"
#include "iXblue_stdbin_decoder/memory_block_parser.h"

namespace StdBinDecoder
{
namespace Parser
{
class RealTimeHeaveSurgeSway : public MemoryBlockParser
{
public:
    RealTimeHeaveSurgeSway() : MemoryBlockParser(2, 16) {}
    void parse(boost::asio::mutable_buffer& buffer,
               Data::BinaryNav& outBinaryNav) override
    {
        Data::RealTimeHeaveSurgeSway res;
        buffer >> res.rt_heave_withoutBdL >> res.rt_heave_atBdL >> res.rt_surge_atBdL >>
            res.rt_sway_atBdL;
        outBinaryNav.rtHeaveSurgeSway = res;
    }
};
} // namespace Parser
} // namespace StdBinDecoder