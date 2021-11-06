#include <ktrl/KtrlUInput.h>

#include <linux/input.h>
#include <iostream>
#include <cstring>
#include <sys/unistd.h>

#include <fcntl.h>

void debug(std::string msg){
	std::cout << msg << std::endl;
}

inline void emit(int filehandle, int type, int code, int value) {
    struct input_event ev;
    memset(&ev, 0, sizeof(struct input_event));
    gettimeofday(&ev.time, nullptr);
    ev.type = type;
    ev.code = code;
    ev.value = value;

    write(filehandle, &ev, sizeof(struct input_event));
}

void KtrlUInput::setupAsSender() {
  //
}

void KtrlUInput::setupAsReceiver() {
 /* enable mouse button left and relative events */
   ioctl(fd, UI_SET_EVBIT, EV_KEY);
   ioctl(fd, UI_SET_KEYBIT, BTN_LEFT);

   ioctl(fd, UI_SET_EVBIT, EV_REL);
   ioctl(fd, UI_SET_RELBIT, REL_X);
   ioctl(fd, UI_SET_RELBIT, REL_Y);

   memset(&usetup, 0, sizeof(usetup));
   /// @todo rename device
   usetup.id.bustype = BUS_USB;
   usetup.id.vendor = 0x1234; /* sample vendor */
   usetup.id.product = 0x5678; /* sample product */
   strcpy(usetup.name, "Example device");

   ioctl(fd, UI_DEV_SETUP, &usetup);
   ioctl(fd, UI_DEV_CREATE);

   /*
    * On UI_DEV_CREATE the kernel will create the device node for this
    * device. We are inserting a pause here so that userspace has time
    * to detect, initialize the new device, and can start listening to
    * the event, otherwise it will not notice the event we are about
    * to send. This pause is only needed in our example code!
    */
   sleep(1);
}

KtrlUInput::KtrlUInput(KtrlInputController* inputController) : KtrlInput(inputController) {
    fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
    if(fd == -1){
	debug("Cannot open /dev/uinput for writing");
	return;
    }
}

void write_uinput_event(int filehandle, int type, int code, int value, bool syn)
{
    ::emit(filehandle, type, code, value);
    if (syn)
    {
        ::emit(filehandle, EV_SYN, SYN_REPORT, 0);
    }
}


void KtrlUInput::reflect(int code, int value){
    if ( fd == -1){
	debug("FATAL ERROR: Can't write to file");
	return;
    }
    write_uinput_event(fd, EV_REL, code, value, true);
    usleep(15000);
}

KtrlUInput::~KtrlUInput(){
    /*
    * Give userspace some time to read the events before we destroy the
    * device with UI_DEV_DESTOY.
    */
   sleep(1);

   ioctl(fd, UI_DEV_DESTROY);
   close(fd);
}
