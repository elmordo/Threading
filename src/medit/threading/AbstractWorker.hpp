#ifndef MEDIT_THREADING_ABSTRACTWORKER_HPP
#define MEDIT_THREADING_ABSTRACTWORKER_HPP

#include <queue>

#include "IWorker.hpp"

using namespace std;


namespace Medit
{
namespace Threading
{


class AbstractWorker : public IWorker
{

    typedef queue<ISignal *> SignalQueue;
    
    SignalQueue signals;

public:

    AbstractWorker();

    virtual ~AbstractWorker();

    virtual void sendSignal()
}


}
}


#endif
