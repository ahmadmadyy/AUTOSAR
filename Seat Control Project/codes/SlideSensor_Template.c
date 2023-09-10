/**
 *
 * \file SlideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/30/2023 10:05 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideSensor.h"


/**
 *
 * Runnable RE_SlideSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideSensor_Opr_GetPosition
 *
 */

void RE_SlideSensor_GetPosition (SensorPositionType* position)
{
	Std_ReturnType status;
	Adc_ReadGroup(Adc_GroupType group,Adc_ValueGroupType* DataBufferPtr);
	IOSensorPositionReadingType position;

	/* Server Call Points */
	status = Rte_Call_rpIOGetSlide_Opr_IOGet(&position);
	if(position==0)
	{
		position=SENSOR_POSITION_STEP_0;
	}
	else if(position>0&&position<=64)
	{
		position=SENSOR_POSITION_STEP_1;
	}
	else if(position>64&&position<=192)
	{
		position=SENSOR_POSITION_STEP_2;
	}
	else if(position>192&&position<=255)
	{
		position=SENSOR_POSITION_STEP_3;
	}
	
}

