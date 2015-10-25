#include "Signal.hpp"

namespace Medit
{
namespace Threading
{


Signal::Signal()
{
    processed = false;
}

Signal::Signal(size_t signalType, void *data)
{
    this->signalType = signalType;
    this->data = data;
    processed = false;
}

Signal::~Signal()
{
}

size_t Signal::getSignalType() const
{
    return signalType;
}

const void *Signal::getData() const
{
    return data;
}

void *Signal::getData()
{
    return data;
}

bool Signal::isProcessed() const
{
    return processed;
}

void Signal::markProcessed()
{
    processed = true;
}

} // namespace Threading
} // namespace Medit
