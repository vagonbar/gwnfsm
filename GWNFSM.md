\mainpage GWN FSM : an Extended Finite State Machine

This project implements an Extended Finite State Machine which can be easily adapted to different purposes. Besides usual states and transitiones, the extended FSM accepts:

* actions: a function executed before changing state.

* conditions: only if the condition is true, the action and the change of state occur.

* memory: a LIFO stack of strings; may be easily changed to another data type by changing the typedef of the elements of the stack.

For a full description, please see the [README](md_README.html) file.

The GWN FSM is part of the GNU Wireless Network (GWN) project, which intends to provide support for data communications using [GNU Radio](https://www.gnuradio.org/) .

