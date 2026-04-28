#ifndef MAINDISPLAYVIEW_HPP
#define MAINDISPLAYVIEW_HPP

#include <gui_generated/maindisplay_screen/MainDisplayViewBase.hpp>
#include <gui/maindisplay_screen/MainDisplayPresenter.hpp>
#include <gui/model/Model.hpp>
#include <touchgfx/Color.hpp>

using namespace std;
using namespace touchgfx;

class MainDisplayView : public MainDisplayViewBase
{
public:
    MainDisplayView();
    virtual ~MainDisplayView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void searchAndConnectBLE();
    void updateBLEStatus(Model::BLEStatus newStatus);
protected:
    Model::BLEStatus stat;
};

#endif // MAINDISPLAYVIEW_HPP
