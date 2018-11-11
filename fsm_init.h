/**
 * \brief  GWN Finite State Machine initialization for testing.
 *
 * @file fsm_init.h
 * @author Victor Gonzalez-Barbone.
 * @date 13th Nov 2018.
 *
This file defines transitions, functions and other elements to implement a particular FSM machine. This file is provided as an example definition of an FSM; a user may follow this example as a guide to implement her own FSM.
 */


#include "fsm.h"


/** Create FSM, add transitions, return an FSM instance

    Creates an instance of an FSM for testing, adds transitions including action functions, action conditions, an memory.
    @return an FSM instance for testing.
 */
FSM make_fsm(); 

/** Show additional attributes.

  This functions shows additional attributes of the FSM; these attributes are added as necessary according to the purpose of the FSM being defined.
 */
void show_add_attrs(FSM &fsm);   // show additional atributes

