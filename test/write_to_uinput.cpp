#include <ktrl/KtrlUInput.h>

int main(int argc, char* argv[]){
    KtrlInputController* inputController = new KtrlInputController();
    KtrlInput* ktrlInput1 = new KtrlUInput(inputController);
    KtrlInput* ktrlInput2 = new KtrlUInput(inputController);
    // ktrlInput1->setupAsSender(); // from - setups up callbacks
    // ktrlInput2->setupAsReceiver(); // to - inits outs
    inputController->setup(ktrlInput1, ktrlInput2);
    // while(1){
    //     // no-op
    // }
    return 0;
}