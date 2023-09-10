/**
 *
 * \file HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/30/2023 10:05 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HeightMotor.h"


/**
 *
 * Runnable HeightMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_Opr_HeightMotorMove
 *
 */

void HeightMotor_Move (StepMotorStepType Step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if(Step==MOTOR_STEP_PLUS)
	status = Rte_Call_rpIoSetHeight_IOSetForward();
	else if(Step==MOTOR_STEP_MINUS)
	status = Rte_Call_rpIoSetHeight_IOSetReverse();
	
}

