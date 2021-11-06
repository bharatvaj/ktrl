#include <ktrl/KtrlInput.h>

KtrlInput::KtrlInput(KtrlInputController* inputController) : inputController(inputController) {}

void KtrlInput::setup() {
    // for(std::pair<int, int> binding : bindings){

    // }
}


void KtrlInput::setupAsSender() {}
void KtrlInput::setupAsReceiver() {}

/**
 *          Controller1, Controller2, Controller3
 *      /               \
 * KtrlInput1(ctrl1)   KtrlInput2(ctrl1)
 */

KtrlInput::~KtrlInput() {

}