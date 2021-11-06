#pragma once

class KtrlInput;

/**
 * This class is responsible for receiving and forwarding input
 * from/to the Input classes
 * 'Controller' not to be confused with 'Joystick'
 */
class KtrlInputController {
    public:
    KtrlInput* from = nullptr;
    KtrlInput* to = nullptr;
    KtrlInputController() {}

    void onInput();

    void setup(KtrlInput* from, KtrlInput* to);
};