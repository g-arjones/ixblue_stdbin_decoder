#pragma once

#include "iXblue_stdbin_decoder/data_models/external_data/sound_velocity.h"
#include "iXblue_stdbin_decoder/memory_block_parser.h"

namespace StdBinDecoder
{
namespace Parser
{
class SoundVelocity : public MemoryBlockParser
{
public:
    SoundVelocity() : MemoryBlockParser(12, 8) {}
    void parse(boost::asio::mutable_buffer& buffer,
               Data::BinaryNav& outBinaryNav) override
    {
        Data::SoundVelocity res;
        buffer >> res.validityTime_100us >> res.ext_speedofsound_ms;
        outBinaryNav.soundVelocity = res;
    }
};
} // namespace Parser
} // namespace StdBinDecoder