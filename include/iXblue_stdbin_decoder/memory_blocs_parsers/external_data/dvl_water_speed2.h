#pragma once

#include "iXblue_stdbin_decoder/data_models/external_data/dvl_water_speed.h"
#include "iXblue_stdbin_decoder/memory_block_parser.h"

namespace StdBinDecoder
{
namespace Parser
{
class DvlWaterSpeed2 : public MemoryBlockParser
{
public:
    DvlWaterSpeed2() : MemoryBlockParser(22, 33) {}
    void parse(boost::asio::mutable_buffer& buffer,
               Data::BinaryNav& outBinaryNav) override
    {
        Data::DvlWaterSpeed res;
        buffer >> res.validityTime_100us >> res.dvl_id >> res.xv1_waterspeed_ms >>
            res.xv2_waterspeed_ms >> res.xv3_waterspeed_ms >> res.dvl_speedofsound_ms >>
            res.xv1_stddev_ms >> res.xv2_stddev_ms >> res.xv3_stddev_ms;
        outBinaryNav.dvlWaterSpeed2 = res;
    }
};
} // namespace Parser
} // namespace StdBinDecoder