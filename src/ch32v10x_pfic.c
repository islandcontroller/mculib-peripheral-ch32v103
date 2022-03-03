/********************************** (C) COPYRIGHT *******************************
 * File Name          : ch32v10x_pfic.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2020/04/30
 * Description        : This file provides PFIC access functions
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * SPDX-License-Identifier: Apache-2.0
 *********************************************************************************/
#include "ch32v10x_pfic.h"

__IO uint32_t PFIC_Priority_Group = 0;

/*********************************************************************
 * @fn      PFIC_PriorityGroupConfig
 *
 * @brief   Configures the priority grouping - pre-emption priority and subpriority.
 *
 * @param   PFIC_PriorityGroup - specifies the priority grouping bits length.
 *            PFIC_PriorityGroup_0 - 0 bits for pre-emption priority
 *                                   4 bits for subpriority
 *            PFIC_PriorityGroup_1 - 1 bits for pre-emption priority
 *                                   3 bits for subpriority
 *            PFIC_PriorityGroup_2 - 2 bits for pre-emption priority
 *                                   2 bits for subpriority
 *            PFIC_PriorityGroup_3 - 3 bits for pre-emption priority
 *                                   1 bits for subpriority
 *            PFIC_PriorityGroup_4 - 4 bits for pre-emption priority
 *                                   0 bits for subpriority
 *
 * @return  none
 */
void PFIC_PriorityGroupConfig(uint32_t PFIC_PriorityGroup)
{
    PFIC_Priority_Group = PFIC_PriorityGroup;
}

/*********************************************************************
 * @fn      PFIC_Init
 *
 * @brief   Initializes the PFIC peripheral according to the specified parameters in
 *        the PFIC_InitStruct.
 *
 * @param   PFIC_InitStruct - pointer to a PFIC_InitTypeDef structure that contains the
 *        configuration information for the specified PFIC peripheral.
 *
 * @return  none
 */
void PFIC_Init(PFIC_InitTypeDef *PFIC_InitStruct)
{
    uint8_t tmppre = 0;

    if(PFIC_Priority_Group == PFIC_PriorityGroup_0)
    {
        PFIC_SetPriority(PFIC_InitStruct->PFIC_IRQChannel, PFIC_InitStruct->PFIC_IRQChannelSubPriority << 4);
    }
    else if(PFIC_Priority_Group == PFIC_PriorityGroup_1)
    {
        if(PFIC_InitStruct->PFIC_IRQChannelPreemptionPriority == 1)
        {
            PFIC_SetPriority(PFIC_InitStruct->PFIC_IRQChannel, (1 << 7) | (PFIC_InitStruct->PFIC_IRQChannelSubPriority << 4));
        }
        else
        {
            PFIC_SetPriority(PFIC_InitStruct->PFIC_IRQChannel, (0 << 7) | (PFIC_InitStruct->PFIC_IRQChannelSubPriority << 4));
        }
    }
    else if(PFIC_Priority_Group == PFIC_PriorityGroup_2)
    {
        if(PFIC_InitStruct->PFIC_IRQChannelPreemptionPriority <= 1)
        {
            tmppre = PFIC_InitStruct->PFIC_IRQChannelSubPriority + (4 * PFIC_InitStruct->PFIC_IRQChannelPreemptionPriority);
            PFIC_SetPriority(PFIC_InitStruct->PFIC_IRQChannel, (0 << 7) | (tmppre << 4));
        }
        else
        {
            tmppre = PFIC_InitStruct->PFIC_IRQChannelSubPriority + (4 * (PFIC_InitStruct->PFIC_IRQChannelPreemptionPriority - 2));
            PFIC_SetPriority(PFIC_InitStruct->PFIC_IRQChannel, (1 << 7) | (tmppre << 4));
        }
    }
    else if(PFIC_Priority_Group == PFIC_PriorityGroup_3)
    {
        if(PFIC_InitStruct->PFIC_IRQChannelPreemptionPriority <= 3)
        {
            tmppre = PFIC_InitStruct->PFIC_IRQChannelSubPriority + (2 * PFIC_InitStruct->PFIC_IRQChannelPreemptionPriority);
            PFIC_SetPriority(PFIC_InitStruct->PFIC_IRQChannel, (0 << 7) | (tmppre << 4));
        }
        else
        {
            tmppre = PFIC_InitStruct->PFIC_IRQChannelSubPriority + (2 * (PFIC_InitStruct->PFIC_IRQChannelPreemptionPriority - 4));
            PFIC_SetPriority(PFIC_InitStruct->PFIC_IRQChannel, (1 << 7) | (tmppre << 4));
        }
    }
    else if(PFIC_Priority_Group == PFIC_PriorityGroup_4)
    {
        PFIC_SetPriority(PFIC_InitStruct->PFIC_IRQChannel, PFIC_InitStruct->PFIC_IRQChannelPreemptionPriority << 4);
    }

    if(PFIC_InitStruct->PFIC_IRQChannelCmd != DISABLE)
    {
        PFIC_EnableIRQ(PFIC_InitStruct->PFIC_IRQChannel);
    }
    else
    {
        PFIC_DisableIRQ(PFIC_InitStruct->PFIC_IRQChannel);
    }
}
