//
// Created by ubuntu on 4/28/21.
//

#ifndef STATUSMACHINE_MYSTSTUSMACHINE_H
#define STATUSMACHINE_MYSTSTUSMACHINE_H

enum Status
{
    STATUS_0 = 0,
    STATUS_1 = 1,
    STATUS_2,
    STATUS_3,
    STATUS_4,
    STATUS_5,
    STATUS_6,
};

enum Event
{
    EVENT_INIT = 0,
    EVENT_1 = 1,
    EVENT_1to1,
    EVENT_1to2,
    EVENT_2to1,
    EVENT_2to2,
    EVENT_6,
};

typedef struct StatusTableItem
{
    Status now_status;
    Event trans_event;
    void (*eventAction)();
    Status next_status;
} StatusTableItem_t;

void func_init();
void func_1to1();
void func_1to2();
void func_2to1();
void func_2to2();

extern StatusTableItem tTable[5];

typedef struct StatusMachine
{
    int current_status;         //  当前状态
    StatusTableItem *status_table;  //  状态表
    int size;                   //  表的条目数
};

//  注册状态机
void fsm_Register(StatusMachine *pFsm, StatusTableItem *pTable);

//  状态迁移
void fsm_EventTransfer(StatusMachine *pFsm, int status);

//  事件处理
void fsm_StatusHandle(StatusMachine *pFsm, int event);




#endif //STATUSMACHINE_MYSTSTUSMACHINE_H
