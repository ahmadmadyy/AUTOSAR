/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/31/2023 02:02 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"


/**
 *
 * Runnable RE_HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_HMI_MainFunction_100ms
 *
 */

void RE_HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	MultiStateBtnType SlideBtnState;
	MultiStateBtnType InclineBtnState;
	uint8 Height;
	uint8 Slide;
	uint8 Incline;
	
	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlData_Height(&Height);
	
	/* Software Logic */
	if(Height == Timeout || Height== Not Updated || Height == 0) 
	{
		HeightBtnState = MULTI_STATE_BTN INIT;
	}
	else if(Height == 1)
	{
		HeightBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if(Height == 2)
	{
		HeightBtnState = MULTI_STATE_BTN_PLUS;
	}
	
	status = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	if(Slide == Timeout || Slide == Not Updated || Slide == 0) 
	{
		SlideBtnState = MULTI_STATE_BTN INIT;
	}
	else if(Slide == 1)
	{
		SlideBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if(Slide == 2)
	{
		SlideBtnState = MULTI_STATE_BTN_PLUS;
	}
	
	status = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	if(Incline == Timeout || Incline == Not Updated || Incline == 0) 
	{
		InclineBtnState = MULTI_STATE_BTN INIT;
	}
	else if(Slide == 1)
	{
		InclineBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if(Slide == 2)
	{
		InclineBtnState = MULTI_STATE_BTN_PLUS;
	}
	
	/* Data Send Points */
	status = Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	status = Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	status = Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	
}


/**
 *
 * Runnable RE_HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_DE_SeatModeBtn
 *
 */

void RE_HMI_SeatModeChanged (void)
{
	Std_ReturnType status;
	SeatModeBtnType SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	/* Data Receive Points */
	status = Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);

	if(SeatModeBtn==SEAT_MODE_BTN_MANUAL) 
	{
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
	}
	else if(SeatModeBtn==SEAT_MODE_BTN_AUTO) 
	{
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
	}
	
	/* Mode Switch Points */
	status = Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
	
}

