/*******************************************************************************
* File Name: Hibernate_LED.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Hibernate_LED_ALIASES_H) /* Pins Hibernate_LED_ALIASES_H */
#define CY_PINS_Hibernate_LED_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Hibernate_LED_0			(Hibernate_LED__0__PC)
#define Hibernate_LED_0_PS		(Hibernate_LED__0__PS)
#define Hibernate_LED_0_PC		(Hibernate_LED__0__PC)
#define Hibernate_LED_0_DR		(Hibernate_LED__0__DR)
#define Hibernate_LED_0_SHIFT	(Hibernate_LED__0__SHIFT)
#define Hibernate_LED_0_INTR	((uint16)((uint16)0x0003u << (Hibernate_LED__0__SHIFT*2u)))

#define Hibernate_LED_INTR_ALL	 ((uint16)(Hibernate_LED_0_INTR))


#endif /* End Pins Hibernate_LED_ALIASES_H */


/* [] END OF FILE */
