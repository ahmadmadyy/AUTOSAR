/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/30/2023 07:31 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManager.h"


/**
 *
 * Runnable RE_SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_SeatManager_AutoHeight_200ms
 *
 */

void RE_SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	StepMotorStepType Step;
	SensorPositionType position;
	SensorWeightType weight;

	/* Server Call Points */
	
	status = Rte_Call_rpHeightSensor_Opr_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&weight);
	
	switch(position)
	{
		case SENSOR_POSITION_STEP_0:
		     if(weight>60)
			 {
				Step=MOTOR_STEP_PLUS;
			 }
			 break;
	    case SENSOR_POSITION_STEP_1:
		     if(weight>80)
			 {
				Step=MOTOR_STEP_PLUS;
			 }
			 else if(weight>=60&&weight<=80)
			 {
				/*Position OK*/
			 }
			 else
			 {
			    Step=MOTOR_STEP_MINUS;	
			 }
			 break;
		case SENSOR_POSITION_STEP_2:
		     if(weight>100)
			 {
				Step=MOTOR_STEP_PLUS;
			 }
			 else if(weight>=80&&weight<=100)
			 {
				/*Position OK*/
			 }
			 else
			 {
			    Step=MOTOR_STEP_MINUS;	
			 }
			 break;
		case SENSOR_POSITION_STEP_3:
		     if(weight<100)
			 {
				Step=MOTOR_STEP_MINUS;
			 }
			 break;
		}
	status = Rte_Call_rpHeightMotor_Opr_HeightMotorMove(Step);
}


/**
 *
 * Runnable RE_SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_SeatManager_AutoIncline_200ms
 *
 */

void RE_SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	StepMotorStepType Step;
	SensorPositionType position;
	SensorWeightType weight;

	/* Server Call Points */
	
	status = Rte_Call_rpInclineSensor_Opr_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&weight);
	switch(position)
	{
		case SENSOR_POSITION_STEP_0:
		     if(weight>60)
			 {
				Step=MOTOR_STEP_PLUS;
			 }
			 break;
	    case SENSOR_POSITION_STEP_1:
		     if(weight>80)
			 {
				Step=MOTOR_STEP_PLUS;
			 }
			 else if(weight>=60&&weight<=80)
			 {
				/*Position OK*/
			 }
			 else
			 {
			    Step=MOTOR_STEP_MINUS;	
			 }
			 break;
		case SENSOR_POSITION_STEP_2:
		     if(weight>100)
			 {
				Step=MOTOR_STEP_PLUS;
			 }
			 else if(weight>=80&&weight<=100)
			 {
				/*Position OK*/
			 }
			 else
			 {
			    Step=MOTOR_STEP_MINUS;	
			 }
			 break;
		case SENSOR_POSITION_STEP_3:
		     if(weight<100)
			 {
				Step=MOTOR_STEP_MINUS;
			 }
			 break;
		}
	status = Rte_Call_rpInclineMotor_Opr_InclineMotorMove(Step);
}


/**
 *
 * Runnable RE_SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_SeatManager_AutoSlide_200ms
 *
 */

void RE_SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	StepMotorStepType Step;
	SensorPositionType position;
	SensorWeightType weight;

	/* Server Call Points */
	
	status = Rte_Call_rpSlideSensor_Opr_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&weight);
	switch(position)
	{
		case SENSOR_POSITION_STEP_0:
		     if(weight>60)
			 {
				Step=MOTOR_STEP_PLUS;
			 }
			 break;
	    case SENSOR_POSITION_STEP_1:
		     if(weight>80)
			 {
				Step=MOTOR_STEP_PLUS;
			 }
			 else if(weight>=60&&weight<=80)
			 {
				/*Position OK*/
			 }
			 else
			 {
			    Step=MOTOR_STEP_MINUS;	
			 }
			 break;
		case SENSOR_POSITION_STEP_2:
		     if(weight>100)
			 {
				Step=MOTOR_STEP_PLUS;
			 }
			 else if(weight>=80&&weight<=100)
			 {
				/*Position OK*/
			 }
			 else
			 {
			    Step=MOTOR_STEP_MINUS;	
			 }
			 break;
		case SENSOR_POSITION_STEP_3:
		     if(weight<100)
			 {
				Step=MOTOR_STEP_MINUS;
			 }
			 break;
		}

		status = Rte_Call_rpSlideMotor_Opr_SlideMotorMove(Step);
}


/**
 *
 * Runnable RE_SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void RE_SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	/* Software Logic */
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
		Step=MOTOR_STEP_MINUS;
	else if(InclineBtnState == MULTI_STATE_BTN_PLUS)
		Step=MOTOR_STEP_PLUS;
	
	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Opr_InclineMotorMove(Step);
	
}


/**
 *
 * Runnable RE_SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void RE_SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType SlideBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	/* Software Logic */
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
		Step=MOTOR_STEP_MINUS;
	else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
		Step=MOTOR_STEP_PLUS;
	
	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Opr_SlideMotorMove(Step);
	
}


/**
 *
 * Runnable RE_SeatManger_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void RE_SeatManger_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	StepMotorStepType Step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	/* Software Logic */
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
		Step=MOTOR_STEP_MINUS;
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
		Step=MOTOR_STEP_PLUS;
	
	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Opr_HeightMotorMove(Step);
	
}

