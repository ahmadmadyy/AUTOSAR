/**
 *
 * \file WeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: WeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/30/2023 10:05 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_WeightSensor.h"


/**
 *
 * Runnable RE_WeigtSensor_GetWeight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppWeightSensor_Opr_GetWeight
 *
 */

void RE_WeigtSensor_GetWeight (SensorWeightType* weight)
{
	Std_ReturnType status;
	IOWeightSensorReadingType weight;

	/* Server Call Points */
	status = Rte_Call_rpIOGetWeight_Opr_IOGet(&weight);
	
	weight=weight/1000;
	
}

