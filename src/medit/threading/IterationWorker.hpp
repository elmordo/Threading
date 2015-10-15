#ifndef MEDIT_THREADING_ITERATIONWORKER_HPP
#define MEDIT_THREADING_ITERATIONWORKER_HPP

#include "AbstractWorker.hpp"


namespace Medit
{
namespace Threading
{

class IterationWorker : public AbstractWorker
{
public:

    /**
     * @brief create empty instance
     */
    IterationWorker();

    /**
     * @brief copytor
     * @param original instance with original data
     */
    IterationWorker(const IterationWorker &original);

    /**
     * @brief ~IterationWorker
     */
    virtual ~IterationWorker();

    /**
     * @brief do one iteration of calculation
     */
    virtual void iterate() = 0;


    // IWorker interface
public:
    virtual void doAction();
};

} // namespace Threading
} // namespace Medit

#endif // MEDIT_THREADING_ITERATIONWORKER_HPP
