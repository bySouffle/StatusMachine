#include <iostream>
#include "MyststusMachine.h"

int main() {

    StatusMachine m_fsm;
    fsm_Register(&m_fsm, tTable);
    m_fsm.current_status = STATUS_0;
    m_fsm.size = sizeof (tTable)/sizeof (StatusTableItem);

    printf("current status[%d]\n", m_fsm.current_status);
    printf("start!\n");
    fsm_StatusHandle(&m_fsm, EVENT_INIT);
    printf("status[%d]\n",m_fsm.current_status);
    fsm_StatusHandle(&m_fsm, EVENT_1to1);
    printf("status[%d]\n",m_fsm.current_status);
    fsm_StatusHandle(&m_fsm, EVENT_1to2);
    printf("status[%d]\n",m_fsm.current_status);
    fsm_StatusHandle(&m_fsm, EVENT_2to1);
    printf("status[%d]\n",m_fsm.current_status);
    fsm_StatusHandle(&m_fsm, EVENT_2to2);
    printf("status[%d]\n",m_fsm.current_status);

    return 0;
}
