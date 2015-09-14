#ifndef MEDIT_THREADING_ISIGNAL_HPP
#define MEDIT_THREADING_ISIGNAL_HPP

#include <cstddef>

namespace Medit
{
namespace Threading
{

class ISignal
{
public:

    ISignal();

    /**
     * @brief return identifier of signal type
     * @return signal type
     */
    size_t getSignalType() const;

    /**
     * @brief return data
     * @return pointer to data
     */
    void *getData() const;

};

} // namespace Threading
} // namespace Medit

#endif // MEDIT_THREADING_ISIGNAL_HPP
