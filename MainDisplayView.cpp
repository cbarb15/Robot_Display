#include <gui/maindisplay_screen/MainDisplayView.hpp>
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
	xQueueSend(messageQueue, &message, 0);
}
