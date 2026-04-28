#include <gui/maindisplay_screen/MainDisplayView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "FreeRTOS.h"
#include "queue.h"

extern "C"
{
	QueueHandle_t messageQueue;
	char message[7] = "Search";
}

MainDisplayView::MainDisplayView()
{
	messageQueue = xQueueCreate(10, sizeof(unsigned char));
	bleStatus = Model::DISCONNECTED;
}

void MainDisplayView::setupScreen()
{
    MainDisplayViewBase::setupScreen();
}

void MainDisplayView::tearDownScreen()
{
    MainDisplayViewBase::tearDownScreen();
}

void MainDisplayView::searchAndConnectBLE()
{
	if(bleStatus == Model::DISCONNECTED)
	{
		BLEStatus.setVisible(true);
		BLEStatus.setColor(touchgfx::Color::getColorFromRGB(181, 215, 253));
		Unicode::snprintf(BLEStatusBuffer, BLESTATUS_SIZE, "%s", touchgfx::TypedText(T_SEARCHING).getText());
		BLEStatus.invalidate();
		xQueueSend(messageQueue, &message, 0);
	}
}

void MainDisplayView::updateBLEStatus(Model::BLEStatus newBLEStatus)
{
	bleStatus = newBLEStatus;
	if(newBLEStatus == Model::CONNECTED)
	{
		BLEStatus.setVisible(true);
		BLEStatus.setColor(touchgfx::Color::getColorFromRGB(0, 255, 120));
		Unicode::snprintf(BLEStatusBuffer, BLESTATUS_SIZE, "%s", touchgfx::TypedText(T_CONNECTED_STATUS).getText());
		BLEStatus.invalidate();
	}
	else if(newBLEStatus == Model::DISCONNECTED)
	{
		BLEStatus.setVisible(false);
		BLEStatus.invalidate();
	}


}

