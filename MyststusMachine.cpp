//
// Created by ubuntu on 4/28/21.
//

#include <cstdio>
#include "MyststusMachine.h"

StatusTableItem tTable[5] =
        {
                { STATUS_0, EVENT_INIT, func_init,  STATUS_1},
                { STATUS_1, EVENT_1to1, func_1to1,  STATUS_1},
                { STATUS_1, EVENT_1to2, func_1to2,  STATUS_2},
                { STATUS_2, EVENT_2to1, func_2to1,  STATUS_1},
                { STATUS_2, EVENT_2to2, func_2to2,  STATUS_2},

        };

void fsm_Register(StatusMachine *pFsm, StatusTableItem *pTable) {
    pFsm->status_table = pTable;
}

void fsm_EventTransfer(StatusMachine *pFsm, int status) {
    pFsm->current_status = status;
}

void fsm_StatusHandle(StatusMachine *pFsm, int event) {
    StatusTableItem * pActTable = pFsm->status_table;
    void (*eventAction)() = nullptr;    //  函数指针初始化
    int NextStatus;
    int CurrentStatus = pFsm->current_status;
    int maxNum = pFsm->size;
    int flag = 0;

    //  获取当前事件的函数
    for (int i = 0; i< sizeof (tTable)/sizeof (StatusTableItem);++i)
    {
        if( event == pActTable[i].trans_event && CurrentStatus == pActTable[i].now_status )
        {
            flag = 1;
            eventAction = pActTable[i].eventAction;
            NextStatus = pActTable[i].next_status;
            break;
        }

    }
    if ( flag == 1 )
    {
        if( eventAction != nullptr)
        {
            eventAction();
        }
        //  跳转到下一个状态
        fsm_EventTransfer(pFsm, NextStatus);
    } else
    {
        printf("no match");

    }

}

void func_init() {
    printf("exec func_init\n");
}

void func_1to1() {
    printf("exec func_1-1\n");
}

void func_1to2() {
    printf("exec func_1-2\n");
}

void func_2to1() {
    printf("exec func_2-1\n");

}

void func_2to2() {
    printf("exec func_2-2\n");
}

