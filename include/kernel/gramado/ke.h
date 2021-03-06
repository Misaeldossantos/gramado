/*
 * File: ke.h
 *     Kernel External functions support.
 *     O objetivo � chamar rotinas que est�o fora do kernel base.
 * As rotinas chamadas podem estar em servidores em user mode ou
 * em m�dulos em kernel mode.
 *
 * Hist�rico:
 *     Oct 2016 - Created.
 */

/*
 * Servers and Drivers:
 * ====================
 *
 * Chamadas aos m�dulos externos que est�o em user mode.
 * S�o servers e drivers.
 * O Kernel pode cham�-los para uso pr�prio ou 
 * pode cham�-los para atender alguma solicita��o
 * de cliente, que tamb�m est� em user mode.
 * O Cliente chama solicida algum servi�o de um Server
 * atrav�z do kernel.
 *
 * @todo: Definir melhor o que deve ir para user modr e organizar.
 * por servidor por exemplo.
 */
 
 
//Informa��es sobre o kernel. m�dulo externo.
void KeInformation();   

//Faults support.
void KeCpuFaults(unsigned long fault_number);

//Window support.
void KeSetFocus(int pid);
int KeGetFocus();

//File support.
//carrega um arquivo. 
int 
KeLoadFile ( struct channel_d *channel, 
             unsigned char *file_name, 
			 unsigned long file_address );

//Scheduler support.
void KeNewProcessScheduler();
void KeSaveCurrentContext();
void KeRestoreCurrentContext();	

//dispatch support.
void KeDispatchProcess();

void KeDoProcessReady(int pid);
void KeDoProcessRunning(int pid);
void KeDoProcessSleeping(int pid);
void KeDoProcessZombie(int pid);
void KeDoProcessDead(int pid);
void KeStartProcess(unsigned long pid, unsigned long *task_address);	
void KeWakeupProcess(int pid);
void KeProcessExit();
void KeKillProcess(int pid);



int KeExecProcess(int pid, unsigned long *process_address);

void KeSetQuantum(unsigned long q);
unsigned long KeGetQuantum();
void KeSetCurrentQuantum(unsigned long q);
unsigned long KeGetCurrentQuantum();
void KeSetNextQuantum(unsigned long q);
unsigned long KeGetNextQuantum();
int KeSetPriority();
int KeIncreasePriority(int pid);


//
// passando o comando para os processos.
//

void KeStartShell();
void KeStartTaskManager();



// Tasks ??
// #bugbug: Nao usar esse termo.


//spawn thread.
void KeSpawnTask(int id);
int KeSelectNextThread(int current);									
void KeSaveContextOfNewTask(int id, unsigned long *task_address);
void KeReloadCurrentTask();
void KeShowTasksParameters();
void KeMostraSlots();
void KeMostraSlot(int id);
void KeMostraReg(int id);
void KeShowPreemptedTask();	
int KeCheckTaskContext( int task_id);


//debug support.
void KeDebugBreakpoint();

//Finalization support.
void KeAbort();         // Global, qualquer m�dulo pode abortar. 
void KeReboot();


//
// End.
//

