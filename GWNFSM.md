/** \mainpage GWN FSM, an Extended Finite State Machine.

\brief This project implements an FSM usable for any purpose.
\author Victor Gonzalez-Barbone.
\date 13th Nov 2018
 
This module implements a Finite State Machine (FSM) engine. In addition to the usual states and transitions, the GWN FSM includes actions, conditions, and memory. 

The FSM is defined by transitions. For an input symbol, according to the current state in which the machine is, if there is a transition for the pair (symbol, current state), the condition is evaluated, and if found true, the action is executed and the next state is made the current state (the machine is moved to the next state).

An action is a user written function executed on a transition, before moving the machine to the next state. The action function, as well as the transition, are only executed if the condition function for the transition is true.

A condition is a user written function which returns true or false when executed or evaluated. The action function and the transition are only executed if the condition evaluates to true. If the condition evaluates to false, the transition is not performed, and its related action is not executed. The use of action functions is optional, since actions can be coded in condition functions. In this case, care must be taken in returning false before the actions are executed, to ensure the actions will only be executed if the condition evaluates to true.

Memory is implemented as a stack and is accessed as a LIFO (Last In First Out) container. A type definition describes the type of data stored in the FSM memory. By changing the data type definition, different types of data may be stored. Memory functions in the FSM machine allow to insert an element (push), get the top element (top), delete top element (pop), determine size of the stack, and if it is empty.

The FSM is implemented as a table of transitions. For a given input symbol and according to the current state the machine is in, the process() method searches the table for a transition corresponding to the pair (input symbol, current state). If one or more transitions are found, the condition functions are evaluated. The first transition where the condition is true is executed, which means the action is executed and the next state is made the current state (the machine is moved to the next state). If no transitions are found or no conditions are true on the found transitions, nothing happens; the action is not excecuted, and the current state is not changed.

The table of transitions defines the following associations:

        (input_symbol, current_state) --> (action, next_state, condition)

where action is a function, symbols and states are strings, and condition is a function which returns a boolean. This table is created through the FSM methods add_transition().

A transition with the null string as an input_symbol ('') stands for a transition valid for any input symbol. For the current state, if the condition is true, the transition will be executed on receiving any symbol.

The FSM accepts one default transition not associated with any specific input symbol or state, i.e. valid for any input symbol and any current state. The default transition may be used as a catch-all transition. The default transition is set by insertin a transition with null strings as input symbol and current state, i.e. a pair ("", ""). There should be only one default transition; if there are several, the first one found will be executed.

The FSM machine operates in the following way. On receiving a symbol, 
  1. The FSM searches the transition table for a key (input symbol, current state). If one or more transitions are found, the condition is evaluated for each transition in order. The first transition on which condition is true is executed.
  2. If no conditions in any of the found transitions are true, or no transitions were found, the FSM searches the transition table for a key ("", current state), which stands for a transition valid for any input symbol. If one or more are found, their conditions are evaluated, and the first condition which returns true is executed.
  3. If no transitions with true conditions were found so far, the FSM searches for a default transition and executes it if one is found.
  4. If no valid transition was found, i.e. no default transition exists, the FSM will raise an exception.

The action functions and the condition functions receive a reference to the FSM object as a parameter, hence the action function has access to all attributes in the FSM, such as current state, input symbol or memory.

The GWN Finite State Machine implementation is an extension of Noah Spurrier's FSM 20020822, C{http://www.noah.org/python/FSM/}.




