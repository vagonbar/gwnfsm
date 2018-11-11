# GWN FSM : an Extended Finite Sate Machine (FSM)

This project implements an Extended Finite State Machine which can be easily adapted to different purposes. Besides usual states and transitiones, the extended FSM accepts:

    actions: a function executed before changing state.
    conditions: only if the condition is true, the action and the change of state occur.
    memory: a LIFO stack of strings; may be easily changed to another data type by changin the typedef of the elements of the stack.

The GWN FSM is part of the GNU Wireless Network (GWN) project, which intends to provide support for data communications using [GNU Radio](https://www.gnuradio.org/) .


## Contents

The essential files of the project are:

   `fsm.h, fsm.cpp` : the FSM core.

   `fsm_init.h, fsm_init.cpp` : definitions for a particular FSM.

   `fsm_test.cpp` : to test the FSM defined.

The FSM core files need only be touched to add attributes specific to the FSM desired; sections to add attributes and setter, getter functions are indicated as comments in the code.

The FSM initialization files define the FSM desired: its transitions, action functions, and condition functions. A new FSM may be defined by adapting the code of the example initialization files.

The new FSM may be tested by adapting the test file provided. 

After installation, Doxygen documentation can be found by opening `html/index.html` in a browser.


## Installation and building

The following steps show how to build the project and run a test on the [example FSM](https://github.com/vagonbar/gwnfsm/blob/master/gwnfsm_test.png) provided:

1. Clone the project:
```
  git clone http://github.com/vagonbar/gwnfsm
```
This clones the project in directory `gwnfsm`.

2. Build using CMake:
```
  cd gwnfsm
  cmake .
  make
```

3. Run the test:
```
  ./fsm_test
```

## Test example

The test provided implements the FSM shown in the diagram.

![Example FSM](gwnfsm_test.png)

The FSM machine describes states as text, symbols as characters, actions and conditions as functions.

When running the test, the following menu should appear:

>=== GWN FSM test menu.
>  1. FSM state and transitions.
>  2. Interactive testing, one character.
>  3. Chain testing, a string of characters.
>  4. Full graph, travel all transitions.
>  0. Quit.
>   Choose option: 

Option 4 inserts a series of symbols which travel all transitions in the example FSM defined. For the given example, an output similar to the following is expected:

```
   Choose option: 4

  Full graph testing: gxyrwrgrwrcrgrxys

Input symbol g:
  --- FSM fn_goAA
  Executed transition:   (g, INIT) = (action, STATE_A, condition, where==A)
  FSM state: input symbol: g, initial state INIT,  current state STATE_A
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=A, fsm.to_c=0
Input symbol x:
  --- FSM none, nothing done
  Executed transition:   (, STATE_A) = (action, STATE_A, condition, any symbol)
  FSM state: input symbol: x, initial state INIT,  current state STATE_A
  Executed (any symbol, state) transition
  --- FSM show_add_attrs; fsm.where=A, fsm.to_c=0
Input symbol y:
  --- FSM none, nothing done
  Executed transition:   (, STATE_A) = (action, STATE_A, condition, any symbol)
  FSM state: input symbol: y, initial state INIT,  current state STATE_A
  Executed (any symbol, state) transition
  --- FSM show_add_attrs; fsm.where=A, fsm.to_c=0
Input symbol r:
  --- FSM fn_init
  Executed transition:   (r, STATE_A) = (action, INIT, condition, )
  FSM state: input symbol: r, initial state INIT,  current state INIT
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=A, fsm.to_c=0
Input symbol w:
  --- FSM fn_init, fsm.where set to B
  Executed transition:   (w, INIT) = (action, CHG_WHERE, condition, )
  FSM state: input symbol: w, initial state INIT,  current state CHG_WHERE
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=B, fsm.to_c=0
Input symbol r:
  --- FSM fn_init
  Executed transition:   (r, CHG_WHERE) = (action, INIT, condition, )
  FSM state: input symbol: r, initial state INIT,  current state INIT
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=B, fsm.to_c=0
Input symbol g:
  --- FSM fn_goB
  Executed transition:   (g, INIT) = (action, STATE_B, condition, where==B)
  FSM state: input symbol: g, initial state INIT,  current state STATE_B
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=B, fsm.to_c=0
Input symbol r:
  --- FSM fn_init
  Executed transition:   (r, STATE_B) = (action, INIT, condition, )
  FSM state: input symbol: r, initial state INIT,  current state INIT
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=B, fsm.to_c=0
Input symbol w:
  --- FSM fn_init, fsm.where set to C
  Executed transition:   (w, INIT) = (action, CHG_WHERE, condition, )
  FSM state: input symbol: w, initial state INIT,  current state CHG_WHERE
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=C, fsm.to_c=0
Input symbol r:
  --- FSM fn_init
  Executed transition:   (r, CHG_WHERE) = (action, INIT, condition, )
  FSM state: input symbol: r, initial state INIT,  current state INIT
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=C, fsm.to_c=0
Input symbol c:
  --- FSM fn_toC, to_c set to 1
  Executed transition:   (c, INIT) = (action, CHG_TOC, condition, )
  FSM state: input symbol: c, initial state INIT,  current state CHG_TOC
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=C, fsm.to_c=1
Input symbol r:
  --- FSM fn_init
  Executed transition:   (r, CHG_TOC) = (action, INIT, condition, )
  FSM state: input symbol: r, initial state INIT,  current state INIT
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=C, fsm.to_c=1
Input symbol g:
  --- FSM fn_goAC
  --- FSM fn_goB
  Executed transition:   (g, INIT) = (action, STATE_C, condition, where==C && to_c)
  FSM state: input symbol: g, initial state INIT,  current state STATE_C
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=C, fsm.to_c=1
Input symbol r:
  --- FSM fn_init
  Executed transition:   (r, STATE_C) = (action, INIT, condition, )
  FSM state: input symbol: r, initial state INIT,  current state INIT
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=C, fsm.to_c=1
Input symbol x:
  --- FSM none, nothing done
  Executed transition:   (, INIT) = (action, INIT, condition, any symbol)
  FSM state: input symbol: x, initial state INIT,  current state INIT
  Executed (any symbol, state) transition
  --- FSM show_add_attrs; fsm.where=C, fsm.to_c=1
Input symbol y:
  --- FSM none, nothing done
  Executed transition:   (, INIT) = (action, INIT, condition, any symbol)
  FSM state: input symbol: y, initial state INIT,  current state INIT
  Executed (any symbol, state) transition
  --- FSM show_add_attrs; fsm.where=C, fsm.to_c=1
Input symbol s:
  --- FSM memory show and erase, INIT state
      Memory size: 5, contents:
 : C visited! : B visited! : A visited! : B visited! : A visited!
  Executed transition:   (s, INIT) = (action, INIT, condition, )
  FSM state: input symbol: s, initial state INIT,  current state INIT
  Executed (symbol, state) transition
  --- FSM show_add_attrs; fsm.where=C, fsm.to_c=1
Input symbol :
```



