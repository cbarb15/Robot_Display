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
	BLEStatus newStatus;

	messageStatus = osMessageQueueGet(uartQueueHandle, &newStatus, 0U, 0);
	if(messageStatus == osOK && newStatus != 0)
	{
		bleStatus = newStatus;
		modelListener->notifyBLEStatusChange();
	}
}
