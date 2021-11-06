#include <ktrl/KtrlInputController.h>
#include <ktrl/KtrlInput.h>


void KtrlInputController::onInput(){

    int pressed = 0;
    int i = 50;
    while (i--) {
    to->reflect(0x00, 5);
    to->reflect(0x01, 5);
    }
}

void KtrlInputController::setup(KtrlInput* from, KtrlInput* to){
    this->from = from;
    this->to = to;
    if(this->from){
        this->from->setupAsSender();
    }
    if(this->to){
        this->to->setupAsReceiver();
    }
    //// @todo remove later
    onInput();
}