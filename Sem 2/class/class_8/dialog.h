#include "list.h"
#include "Event.h"

class Dialog :public List {
protected:
    int EndState;
public:
    Dialog();
    ~Dialog() {};
    virtual void GetEvent(TEvent& event);
    virtual void HandleEvent(TEvent& event);
    virtual void ClearEvent(TEvent& event);
    virtual int Execute();
    int Valid();
    void EndExec();
};