#ifndef MAINDISPLAYPRESENTER_HPP
#define MAINDISPLAYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MainDisplayView;

class MainDisplayPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MainDisplayPresenter(MainDisplayView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~MainDisplayPresenter() {}
    virtual void notifyBLEStatusChange();

private:
    MainDisplayPresenter();

    MainDisplayView& view;
};

#endif // MAINDISPLAYPRESENTER_HPP
