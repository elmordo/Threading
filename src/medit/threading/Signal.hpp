#ifndef MEDIT_THREADING_ISIGNAL_HPP
#define MEDIT_THREADING_ISIGNAL_HPP

#include <cstddef>
#include <memory>

using namespace std;


namespace Medit
{
namespace Threading
{

class Signal
{

    /**
     * @brief pointer to data
     */
    void *data;

    /**
     * @brief if true, signal was processed
     */
    bool processed;

    /**
     * @brief unique identifier of signal
     */
    size_t signalType;

public:

    /**
     * @brief create empty instance with signalType set to 0
     */
    Signal();

    /**
     * @brief create initialized instance. Memory management of data is not
     *        sender of signal
     *
     * @param signalType type of signal
     * @param data pointer to memory where data is stored
     */
    Signal(size_t signalType, void *data)

    /**
     * @brief destroy instance
     */
    virtual ~Signal();

    /**
     * @brief return identifier of signal type
     * @return signal type
     */
    size_t getSignalType() const;

    /**
     * @brief return data
     * @return constant pointer to data
     */
    const void *getData() const;

    /**
     * return editable data
     * @return pointer to data
     */
    void *getData();

    /**
     * @brief test if signal was processed by receiver
     * @return true if signal was processed. Otherwise false
     */
    bool isProcessed() const;

    /**
     * mark signal as processed
     */
    void markProcessed();

};

} // namespace Threading
} // namespace Medit

#endif // MEDIT_THREADING_ISIGNAL_HPP
