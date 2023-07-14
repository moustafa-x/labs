#include "tp_ups.h"
#include "tpl_os.h"

#define APP_Task_a_task_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard(BUTTON_NOIT);
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

DeclareTask(task_0);
DeclareTask(task_1);

TASK(a_task)
{
  ledOn(BLUE);
  ActivateTask(task_0);
  ActivateTask(task_1);
  delay(1000);
  ledOff(BLUE);
  delay(1000);
	TerminateTask();
}
#define APP_Task_a_task_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_0_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_0)
{
  delay(1000);
  TerminateTask();
}
#define APP_Task_task_0_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_1)
{
  delay(1000);
  TerminateTask();
}
#define APP_Task_task_1_STOP_SEC_CODE
#include "tpl_memmap.h"

/*
 * This is necessary for ST libraries
 */
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

FUNC(void, OS_CODE) PreTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == a_task) {
    ledOn(ORANGE);
  }
  else if (task_id == task_0) {
    ledOn(GREEN);
  }
  else if (task_id == task_1) {
    ledOn(RED);
  }
}

FUNC(void, OS_CODE) PostTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == a_task) {
    ledOff(ORANGE);
  }
  else if (task_id == task_0) {
    ledOff(GREEN);
  }
  else if (task_id == task_1) {
    ledOff(RED);
  }
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

