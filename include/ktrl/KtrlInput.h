#pragma once
#include <map>

#include <ktrl/KtrlInputController.h>

class KtrlInput {
    private:
    KtrlInputController* inputController = nullptr;
    public:
    KtrlInput(KtrlInputController* inputController);
    // so we can call this later when we are free
    /// @todo change names
    virtual void setup();
    virtual void setupAsSender();
    virtual void setupAsReceiver();
    virtual void reflect(int type, int code) = 0;
    //////////////////////
    virtual ~KtrlInput();
};
