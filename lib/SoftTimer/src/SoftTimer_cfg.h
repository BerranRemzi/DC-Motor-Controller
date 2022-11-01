/** @file SoftTimer_cfg.h
 *  @brief This module contains interface definition for the Dio configuration.
 *
 *  This is the header file for the definition of the interface for retrieving
 *  the digital input/output configuration table.
 */
#ifndef SOFT_TIMER_CFG_H
#define SOFT_TIMER_CFG_H

/*
 * Includes
 */
#include "SoftTimer.h"
/*
 * Preprocessor Constants
 */

/*
 * Configuration Constants
 */
#define TASK_COUNT 6
/*
 * Macros
 */

/*
 * Typedefs
 */

extern SoftTimer_Task_t SoftTimer_task[TASK_COUNT];

#endif /* SOFT_TIMER_CFG_H */