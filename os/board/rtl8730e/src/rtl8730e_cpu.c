/****************************************************************************
 *
 * Copyright 2025 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ****************************************************************************/

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <tinyara/config.h>
#include <tinyara/cpu_state.h>
#include <debug.h>
#include <errno.h>
#include <sys/types.h>

#include "board_cpu.h"
#include "amebasmart_cpu.h"


int board_cpu_initialize(void)
{
#ifdef CONFIG_SMP
    const struct cpu_arch_ops_s *ops = up_cpuinitialize();
    if (!ops) {
        lldbg("Arch ops not available\n");
        return -ENODEV;
    }

    /* Initialize the global pointer to architecture-specific CPU operations */
    g_cpu_arch_ops = ops;

#endif  /* CONFIG_SMP */

    return OK;
}
