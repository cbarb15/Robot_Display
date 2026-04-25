#ifndef MAINDISPLAYVIEW_HPP
#define MAINDISPLAYVIEW_HPP

#include <gui_generated/maindisplay_screen/MainDisplayViewBase.hpp>
#include <gui/maindisplay_screen/MainDisplayPresenter.hpp>
#include <string>

using namespace std;

class MainDisplayView : public MainDisplayViewBase
{
public:
    MainDisplayView();
    virtual ~MainDisplayView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void searchAndConnectBLE();
    void updateBLEStatus(string newStatus);
protected:
};

#endif // MAINDISPLAYVIEW_HPP
