/** 
 * \brief GWN FSM run test.
 *
 * @file fsm_test.cpp
 * @author Victor Gonzalez-Barbone.
 * @date 13th Nov 2018. 
 *
GWN Finite State Machine test.
 */

#include "fsm_init.h"

enum Options
{
    QUIT,
    FSM_STATE,
    INTERACTIVE,
    SYMBOL_CHAIN,
    FULL_GRAPH
};


int main () {

  FSM myfsm = make_fsm();

    // input variables
    std::string symbols;          // chars as symbols
    std::string smb = "";         // a single char symbol
    int length;                   // length of symbols
    std::string full_graph = "gxyrwrgrwrcrgrxys";

    // test options
    int option = 4;
    while (option >= 0 || option < 4)
    {

      std::cout << "\n=== GWN FSM test menu.\n";
      std::cout << "  1. FSM state and transitions.\n";
      std::cout << "  2. Interactive testing, one character.\n";
      std::cout << "  3. Chain testing, a string of characters.\n";
      std::cout << "  4. Full graph, travel all transitions.\n";
      std::cout << "  0. Quit.\n";
      std::cout << "   Choose option: "; 
      std::cin >> option;

      switch (option)
      {
        case FSM_STATE:
            std::cout << "\n=== FSM state and transitions\n";
            myfsm.print_transitions();
            myfsm.print_state();
            show_add_attrs(myfsm);
            break;
        case INTERACTIVE:
          //char smb = symbols[0];
          while ( smb != "q" )
          {
            std::cout << "\n  Type symbol, q to finish: ";
            std::cin >> smb;

            //process_symbol(myfsm, smb);
            try {
            myfsm.process(smb, "", "");
            }
            catch (ExceptionFSM e) {
              std::cout << "Exception catched: " << e.get_value() 
                << std::endl;
            }
            show_add_attrs(myfsm);
          }
          //break;
          return 0;
        case SYMBOL_CHAIN:
          std::cout << "\n  Type a string of chars (max 254): ";
          std::cin >> symbols;
        case FULL_GRAPH:
          if (symbols == "") {
            symbols = full_graph;
            std::cout << "\n  Full graph testing: " << full_graph <<
              std::endl << std::endl;
          }
          length = sizeof(symbols) / sizeof(symbols[0]);
          for (int index = 0; index < length; ++index)
          {
            std::cout << "Input symbol " << symbols[index] << ":\n";

            if (symbols[index] == 0)
              break;
            smb = symbols[index];
            try {
              myfsm.process(smb, "", "");
            }
            catch (ExceptionFSM e) {
            std::cout << "Exception catched: " << e.get_value() 
              << std::endl;
            }
            show_add_attrs(myfsm);

          }
          //break;
          return 0;
        case QUIT:
            std::cout << "Quit";
            return 0;
            //break;
        default:
            std::cout << "  Unknown option, please enter a valid option.";
            break;
      }  // end switch
      std::cout << std::endl; 
    }  // end while

  return 0;
}  // end main

