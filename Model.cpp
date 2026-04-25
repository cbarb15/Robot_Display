#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "cmsis_os.h"
#include <iostream>

extern "C"
{
    osMessageQueueId_t uartQueueHandle;
//    uint8_t uartData[16] = { 0 };
    uint8_t uartData = 0;
}

Model::Model() : modelListener(0)
{

}

osStatus_t messageStatus;
void Model::tick()
{
	uint8_t newStatus;

	messageStatus = osMessageQueueGet(uartQueueHandle, &newStatus, 0U, 0);
	if(messageStatus == osOK)
	{
		printf("Got status");

		modelListener->notifyBLEStatusChange();
	}
}
