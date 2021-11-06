#pragma once

#include <ktrl/KtrlInput.h>
#include <linux/uinput.h>


class KtrlUInput : public KtrlInput{
    private:
    struct uinput_setup usetup;
    int fd = -1;

    public:
    KtrlUInput(KtrlInputController* inputController);
    void setupAsSender() override;
    void setupAsReceiver() override;
    void reflect(int type, int code) override;
    ~KtrlUInput();
    void write();
};