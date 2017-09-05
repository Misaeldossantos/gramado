/*
 * File: include\object.h
 *
 * Descri��o:
 *    Header do gerenciador de objetos.
 *    Observe que esse header deve ficar em /include.
 *
 * Obs: Se cada objeto tem um Handle � porque todos objetos
 *      est�o em gavetas. O desktop � uma mesa com muitas gavetas
 *      e cada gaveta tem um puxador e dentro de cada gaveta tem um objeto.
 *
 * Obs: Teremos um vetor que � uma lista de tipos de objetos.
 *      Aplica��es em user mode solicitam um objeto atrav�s de um �ndice, 
 * que seleciona um ponteiro armazenado em algum �ndice do vetor. Cada �ndice
 * representa um tipo de objeto. Esse �ndice � chamado de descritor de objeto.
 * A estrutura tamb�m � considerada descritor. 
 *
 * Hist�rico:
 *     Vers�o 1.0, 2016 - Criado por Fred Nora.
 *     //... 
 */

 
//
// �ndices para o vetor de objetos. (provis�rio).
//
//@todo: Essa lista ser� revisada e modificada.
//       Selecioar e organizar... 
// Obs: Uma forma boa de organizar � colocar em ordem alfab�tica
//      Incluir um objeto na lista ser� f�cil.         
// @todo: Uma liste enumerada, com descri��o.
//


//
// ****   CADA �NDICE DESCREVE UM TIPO DE OBJETO   ****
//

//
// Obs: Essa lista deve estar sincronizada com a da 'enum' em gdef.h.
//

//Null.
#define OBJECT_NULL      0

#define OBJECT_ASPACE 1
#define OBJECT_DSPACE 2
#define OBJECT_BANK   3

#define OBJECT_CHANNEL       4
#define OBJECT_DIRECTORY     5       //DIRET�RIO DE ARQUIVOS.
#define OBJECT_MEMORY_HEAP   6
#define OBJECT_IOBUFFER  7
#define OBJECT_IPADDRESS 8
#define OBJECT_PROCESS_MEMORY_INFO 9
#define OBJECT_PHYSICAL_MEMORY_INFO 10
#define OBJECT_MEMORY_INFO         11
#define OBJECT_MEMORY_BLOCK   12
#define OBJECT_PAGEDIRECTORY 13
#define OBJECT_PAGETABLE 14
#define OBJECT_PAGEFRAME 15
#define OBJECT_SOCKET 16
#define OBJECT_USERINFO 17

#define OBJECT_DESKTOP    18    //Desktop. STRUCT
#define OBJECT_MENUITEM   19    //Menu ITEM
#define OBJECT_MENU 20
#define OBJECT_USESSION   21    //User Session.
#define OBJECT_WIN_PROCEDURE  22
#define OBJECT_RECTANGLE 23
#define OBJECT_RGBA 24
#define OBJECT_WINDOW     25    //Window.
#define OBJECT_WSTATION   26    //Window Station.(DESKTOP POOL)
#define OBJECT_CONSOLE 27
#define OBJECT_LINE 28
#define OBJECT_TERMINAL 29

// \microkernel
#define OBJECT_PROCESS   30
#define OBJECT_SEMAPHORE   31
#define OBJECT_THREAD    32
// \microkernel.cpu
#define OBJECT_CPU 33
// \microkernel.dma
#define OBJECT_DMA 34

// \hal
#define OBJECT_PROCESSOR 35
#define OBJECT_DEVICE    36 
#define OBJECT_DISK_INFO 37
#define OBJECT_PROCESSOR_BLOCK 38
#define OBJECT_HOST_INFO 39
#define OBJECT_KEYBOARD 40
#define OBJECT_MAC_ADDRESS 41
#define OBJECT_MEMORY      42  //HARDWARE, CARD.
#define OBJECT_PCIDEVICE 43
#define OBJECT_PCIDEVICEDRIVER 44
#define OBJECT_PIC
#define OBJECT_RTC 45
#define OBJECT_SCREEN 46
#define OBJECT_TIMER 47
#define OBJECT_VIDEO 48
#define OBJECT_VOLUME  49

//THINGS
//...

//OUTROS...
#define OBJECT_CURSOR    50
#define OBJECT_REQUEST   51 //KERNEL REQUEST.
#define OBJECT_SIGNAL    52
#define OBJECT_FILE      53
#define OBJECT_METAFILE  54
#define OBJECT_MUTEX 55
#define OBJECT_TOKEN 56
#define OBJECT_FONT 57
#define OBJECT_ICON 58
#define OBJECT_PIPE 59


#define OBJECT_GROUP     60 //Grupo de usu�rios.
#define OBJECT_USER      61 //usu�rio

#define OBJECT_COMPUTER      62  //computador (host em rede)
#define OBJECT_CPU_REGISTER  63  //REGISTRADORES DA CPU. cr0, cr1 ...
#define OBJECT_DISK          64 

#define OBJECT_DISK_PARTITION  65
#define OBJECT_GDT      66       //LIKE GDT, IDT ...
#define OBJECT_LDT 67
#define OBJECT_IDT 68
#define OBJECT_TSS 69 

#define OBJECT_PORT       70      //Porta de controlador de dispositivo
#define OBJECT_CONTROLLER  71     //Controlador de dispositivo.
#define OBJECTS_KM         73 //Kernel mode??
#define OBJECTS_UM       74  //Use mode ??


/*

#define OBJECT_JOB     35  //Job de processos.
//#define OBJECT_PROFILE 36  
//...(30~39)

//ipc - inter process comunication.

#define OBJECT_MSG            42
#define OBJECT_EVENT          43


#define OBJECT_TOKEN  46
//...(40~49)

//Memory 

#define OBJECT_MEMORY_STACK   52

#define OBJECT_MEMORY_FRAME   54
#define OBJECT_MEMORY_PAGE    55
#define OBJECT_MEMORY_VIEW    56
#define OBJECT_MEMORY_BUFFER  57
#define OBJECT_MEMORY_CACH    58
//... (50~59)

//GUI.
#define OBJECTS_GUI            60
#define OBJECT_IMAGE           61
#define OBJECT_MENU_PROCEDURE  62
//... (60~69)

//grupo 7x
#define OBJECT_7x 70
//...(70~79)

//grupo 8x
#define OBJECT_8x 80
//...(80~89)

//Outros
#define OBJECT_LIST       90
#define OBJECT_REQUEST    91
//...(90~99)

//  *** (100~Max) ***
//Extendida (Novos objetos s�o inclu�dos).
//...
#define OBJECT_AMBIENTE  100 //boot, kernel mode, user mode.
//...(100~Max)

*/


/*
 * struct object_d:
 *     Estrutura para objetos.
 */
//typedef struct object_d object_t;
typedef struct object_d object_descriptor_t;
struct object_d 
{
	//@todo: 
    //?? N�o sei se isso � necess�rio para essa estrutura em particular. ?? 
	object_type_t objectType;
	object_class_t objectClass;	
    
	//@todo: fazer isso para todas as estrututras.
	//medir quantos bytes tem cada estrutura.
	//int object_size;  	
	
   //identificadores
   int id;            // Id do objeto.
   unsigned long name_address;
   char name[16];	  // Nome do objeto com 16 chars. @todo: usar ponteiro para nome.
   int used;          // Se o slot esta sendo usado.
   int magic;         // N�mero m�gico pra ver se o slot n�o esta corrompido.
   
	
   //endere�os
   unsigned long obj_address;
   unsigned long obj_procedure;
   
    /*
	 * Status do objeto.
	 */   
	 
	int token; //algum processo 'pegou' o objeto e esta usando.
    
	int task_id; //id da tarefa que pegou o processo.
	
    
	//int signaled;
	//struct process_d *waitListHead;
	
	//channel	
    //process
	//thread
	//window
	
	//continua...
};
object_descriptor_t *object;  //object
//...


//
// @todo: Essas listas ocupam muito espa�o, precisa ser alocado dinamicamente.
//        Por�m � certo que manipularemos muitos objetos.  
//

//@todo: Usar array din�mico.
object_descriptor_t objects_km[256+1];  //objetos em kernel mode.
object_descriptor_t objects_um[256+1];  //objetos em user mode. 
object_descriptor_t objects_gui[256+1]; //objetos gr�ficos. 





/*
 * Se o gerenciador de recursos foi inicializado.
 */
int g_object_manager_status;

//id do objeto atual
int g_current_object;

//id da lista ao qual o objeto atual pertence.
// object_km, object_um, object_gui. 
int g_current_list;

					   
int init_object_manager();



//
//fim.
//

