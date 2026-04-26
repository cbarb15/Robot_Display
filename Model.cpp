#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "cmsis_os.h"
#include <iostream>

extern "C"
{
	extern osMessageQueueId_t uartQueueHandle;
}

Model::Model() : modelListener(0)
{

}

osStatus_t messageStatus;
void Model::tick()
{
//	static uint8_t newStatus;
	static uint8_t newStatus[16];

	messageStatus = osMessageQueueGet(uartQueueHandle, &newStatus, 0U, 0);
	if(messageStatus == osOK)
	{
		printf("Got status");

		modelListener->notifyBLEStatusChange();
	}
}
