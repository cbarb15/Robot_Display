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
//	BLEStatus.setVisible(true);
//	BLEStatus.invalidate();
	xQueueSend(messageQueue, &message, 0);
}

void MainDisplayView::updateBLEStatus(string newBLEStatus)
{
//	Unicode::snprintf(BLEStatusBuffer, BLESTATUS_SIZE, "%s", touchgfx::TypedText(T_CONNECTED_STATUS).getText());
//	BLEStatus.invalidate();
}

