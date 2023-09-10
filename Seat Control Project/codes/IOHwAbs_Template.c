/**
 *
 * \file IOHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: IOHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 7/30/2023 10:06 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_IOHwAbs.h"

#include "Adc.h"

#include "Spi.h"

#include "Dio.h";

static Adc_ValueGroupType IoHwAb_PositionSensorsReadings[ADC_GR0_NUM_CHANNELS] =
{
   /* Height */
   0,
   /* Incline */
   0,
   /* Slide */
   0
};
/**
 *
 * Runnable RE_IOHwAbs_ECUGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetHeight_Opr_IOGet
 *
 */

void RE_IOHwAbs_ECUGet_Height (IOSensorPositionReadingType* position)
{
	Std_ReturnType status;

	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp, IoHwAb_PositionSensorsReadings);
	
	if(status == E_OK)
	{
		/* IoPositionSensorReadingType has to be adjusted in arxml file */
		/* as per Adc resolution "Adc_ValueGroupType can be uint8 or uint16" */
		*position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[0];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}

}


/**
 *
 * Runnable RE_IOHwAbs_ECUGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetIncline_Opr_IOGet
 *
 */

void RE_IOHwAbs_ECUGet_Incline (IOSensorPositionReadingType* position)
{
	Std_ReturnType status;

	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp, IoHwAb_PositionSensorsReadings);
	
	if(status == E_OK)
	{
		/* IoPositionSensorReadingType has to be adjusted in arxml file */
		/* as per Adc resolution "Adc_ValueGroupType can be uint8 or uint16" */
		*position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[1];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}

}


/**
 *
 * Runnable RE_IOHwAbs_ECUGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetSlide_Opr_IOGet
 *
 */

void RE_IOHwAbs_ECUGet_Slide (IOSensorPositionReadingType* position)
{
	Std_ReturnType status;

	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp, IoHwAb_PositionSensorsReadings);
	
	if(status == E_OK)
	{
		/* IoPositionSensorReadingType has to be adjusted in arxml file */
		/* as per Adc resolution "Adc_ValueGroupType can be uint8 or uint16" */
		*position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[2];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}

}


/**
 *
 * Runnable RE_IOHwAbs_ECUGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetWeight_Opr_IOGet
 *
 */

void RE_IOHwAbs_ECUGet_Weight (IOWeightSensorReadingType* weight)
{
	Std_ReturnType status;
	Spi_DataType spiData;

	status = Spi_ReadIB(SpiConf_SpiChannel_WeightSensor, &spiData);
	
	if(status == E_OK)
	{
		/* IoWeightSensorReadingType has to be adjusted in arxml file */
		/* as per Spi_DataType "can be uint8 or uint16" */
		*weight = (IoWeightSensorReadingType)spiData;
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}

}


/**
 *
 * Runnable RE_IOHwAbs_ECUSetBackward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_Opr_IOSetBackward
 *
 */

void RE_IOHwAbs_ECUSetBackward_Height (void)
{
	Std_ReturnType status;
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_LOW); 

}


/**
 *
 * Runnable RE_IOHwAbs_ECUSetBackward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_Opr_IOSetBackward
 *
 */

void RE_IOHwAbs_ECUSetBackward_Incline (void)
{
	Std_ReturnType status;
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_LOW); 

}


/**
 *
 * Runnable RE_IOHwAbs_ECUSetBackward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_Opr_IOSetBackward
 *
 */

void RE_IOHwAbs_ECUSetBackward_Slide (void)
{
	Std_ReturnType status;
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_LOW); 

}


/**
 *
 * Runnable RE_IOHwAbs_ECUSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_Opr_IOSetForward
 *
 */

void RE_IOHwAbs_ECUSetForward_Height (void)
{
	Std_ReturnType status;
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_HIGH); 

}


/**
 *
 * Runnable RE_IOHwAbs_ECUSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_Opr_IOSetForward
 *
 */

void RE_IOHwAbs_ECUSetForward_Incline (void)
{
	Std_ReturnType status;
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_HIGH); 

}


/**
 *
 * Runnable RE_IOHwAbs_ECUSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_Opr_IOSetForward
 *
 */

void RE_IOHwAbs_ECUSetForward_Slide (void)
{
	Std_ReturnType status;
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_HIGH); 

}

