#pragma once

#include "iXblue_stdbin_decoder/data_models/navigation_data/attitude_heading.h"
#include "iXblue_stdbin_decoder/memory_block_parser.h"

namespace StdBinDecoder
{
namespace Parser
{
class AttitudeHeading : public MemoryBlockParser
{
public:
    AttitudeHeading() : MemoryBlockParser(0, 12) {}
    void parse(boost::asio::mutable_buffer& buffer,
               Data::BinaryNav& outBinaryNav) override
    {
        Data::AttitudeHeading res;
        buffer >> res.heading_deg >> res.roll_deg >> res.pitch_deg;
        outBinaryNav.attitudeHeading = res;
    }
};
} // namespace Parser
} // namespace StdBinDecoder
