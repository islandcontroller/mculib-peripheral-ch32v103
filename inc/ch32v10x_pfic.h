/********************************** (C) COPYRIGHT  *******************************
 * File Name          : ch32v10x_pfic.h
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2020/04/30
 * Description        : This file contains all the functions prototypes for the 
 *                      PFIC access functions.
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/   
#ifndef __CH32V10X_PFIC_H
#define __CH32V10X_PFIC_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "ch32v10x.h"

/* PFIC Init Structure definition */
typedef struct
{
  uint8_t PFIC_IRQChannel;
  uint8_t PFIC_IRQChannelPreemptionPriority;
  uint8_t PFIC_IRQChannelSubPriority;
  FunctionalState PFIC_IRQChannelCmd;
} PFIC_InitTypeDef;
 

/* Preemption_Priority_Group */
#define PFIC_PriorityGroup_0           ((uint32_t)0x00)
#define PFIC_PriorityGroup_1           ((uint32_t)0x01)
#define PFIC_PriorityGroup_2           ((uint32_t)0x02)
#define PFIC_PriorityGroup_3           ((uint32_t)0x03)
#define PFIC_PriorityGroup_4           ((uint32_t)0x04)


void PFIC_PriorityGroupConfig(uint32_t PFIC_PriorityGroup);
void PFIC_Init(PFIC_InitTypeDef* PFIC_InitStruct);

#ifdef __cplusplus
}
#endif

#endif /* __CH32V10x_PFIC_H */

