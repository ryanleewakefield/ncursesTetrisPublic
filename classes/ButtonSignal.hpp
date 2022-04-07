#ifndef __BUTTONSIGNAL_HPP__
#define __BUTTONSIGNAL_HPP__

enum ButtonSignal{
    UpButton,
    DownButton,
    LeftButton,
    RightButton,
    AButton,
    BButton,
    StartButton,
    SelectButton,
    QuitButton,
    StartThread,
    StopThread,
    // Used as a normal DownButton but with a conditional
    // that can be handled under the same mutex holding epoch.
    DownButton_Conditional, 
    PauseButton,
};


#endif