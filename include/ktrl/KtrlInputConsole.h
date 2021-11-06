#pragma once

#include <ktrl/KtrlInput.h>

class KtrlInputConsole: public KtrlInput {
    public:
    KtrlInputConsole(KtrlInputContrller* inputController) : KtrlInput(inputController){}
}
