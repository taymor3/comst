/* 046266 Compilation Methods, EE Faculty, Technion                 */
/* part3_helpers.h - Helper functions for project - API definitions */

#ifndef _PART3_HELPERS_H_
#define _PART3_HELPERS_H_
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <fstream>

using namespace std;

void operational_err(string err);
bool replace_str(string& str, const string& src, const string& dst);    //TODO change func name

#define YYSTYPE Node* // changed yylval type to Node*

//Defining our primitive types
typedef enum {
	void_t = 0,
	int_ = 1,
	float_ = 2
	} Type;

// Defining arguments format
struct Arg_dcl {
    string id;
    Type type;
} ;

#define INT_REG_START 5
#define FLOAT_REG_START 4

// Registers macro  TODO comments on saved registers

//return address pointer
#define RA "I0"
//stack pointer (next write pointer in stack)
#define SP "I1"
//frame start pointer
#define FP "I2"
//declarations pointer (points on the first variable in the frame)
#define DP "I3"
//return int type
#define RT_I "I4"
/**
 * SAVED FLOAT REGS
 */
//stack pointer (next write pointer in stack)
#define SP_F "F0"
//frame address pointer
#define FP_F "F1"
//declarations pointer (points on the first variable in the frame)
#define DP_F "F2"
//return float type
#define RT_F "F3"


/**************************************************************************/
/*                       ALL PARSE TREE NODES                             */
/**************************************************************************/

// An abstract node which all other parser nodes inherits from
class Node{
public:
    string type;    
    Node() {};
    virtual ~Node(){};
};

// A class for a terminal node in parse tree
class Terminal : public Node{
public:
    string terminal_type;
    string terminal_value;
    Terminal(string type);      //implemented in cpp file
    Terminal(string type, string terminal_val);     //implemented in cpp file
};

// A class for a expression symbol in parse tree
class ExpSymbol : public Node{
public:
    Type exp_type;
    string place;
};

// A class for a type symbol in parse tree
class TypeSymbol : public Node{
public:
    Type type_value;
};

// A class for a statement symbol in parse tree
class StmtSymbol : public Node{
public:
    list<int> nextlist;
};

// A class for a boolean expression symbol in parse tree
class BexpSymbol : public Node{
public:
    list<int> truelist;
    list<int> falselist;
};

// A class for a declaration expression symbol in parse tree
class DclSymbol : public Node{
public:
    list<string> dcl_list;
    Type id_type;
};

// A class for a function API expression symbol in parse tree
class FuncApiSymbol : public Node{
public:
    Type ret_type;
    string func_id;
    list<Arg_dcl> func_args;
};

// A class for a call function expression symbol in parse tree
class CallArgsSymbol : public Node{
public:
    list<ExpSymbol> exp_args;
};

// A class for a function's arguments expression symbol in parse tree
class FuncArgsSymbol : public Node{
public:
    list<Arg_dcl> args;
};

// A class for M marker symbol
class Marker_M_Symbol : public Node{
public:
    int quad;
};

// A class for N marker symbol
class Marker_N_Symbol : public Node{
public:
    list<int> nextlist;
};


/**************************************************************************/
/*                       Variables Symbol Table                           */
/**************************************************************************/

struct Var_Table_Entry{
    Type type;
    int offset;     
};

class Table_per_type_block_scope {   //lower level table
public:
    int next_temp_reg;
    int temp_start_idx;
    Type block_table_type;
    string type_rep;
    map<string, int> vars_in_block;

    Table_per_type_block_scope(Type block_table_type);  //constructor, gets type of table (int/float)
    string get_next_temp();
    void insert_var_to_map(string id, int offset);
    bool find_in_type_block_scope(Var_Table_Entry& var, string id);
    void reset_temp_reg();
    void store_reg_update_stack();
    void load_reg_update_stack();
};

class Table_block_scope {   //middle level table
public:
    int stack_offset;
    int stack_start_idx;
    Table_per_type_block_scope int_table;
    Table_per_type_block_scope float_table;

    Table_block_scope(int start_offset);    //constructor gets start offset in stack
    string next_temp_reg(Type type);        //uses get_next_temp of lower class "table per type" to get the next available reg
    int insert_variable(string id, Type type);  //uses insert_var_to_map of lower class "table per type" with the given type
    bool find_in_block_scope(Var_Table_Entry& var, string id);   //uses find_in_type_block_scope of lower class "table per type"
    void reset_reg();   //uses reset_temp_reg of lower class "table per type" for both types
    void store_reg();   //uses store_reg_update_stack of lower class "table per type" for both types
    void load_reg();   //uses store_reg_update_stack of lower class "table per type" for both types
    void empty_stack();
};

class variable_table {  //upper level table
public:
    list<Table_block_scope> block_tables;
    list<Arg_dcl> func_args;

    void add_block_table();     //add block at beginning of list block_tables
    void remove_block_table();      //remove inner-most block (first block)
    bool is_var_exist(Var_Table_Entry& var, string id); //search for var in the tables
    void store();   //uses store_reg of middle class Table_block_scope
    void load();    //uses load_reg of middle class Table_block_scope
    bool find_var_in_block(string id);  //searches variable 'id' in the first block
};

/**************************************************************************/
/*                       Functions Symbol Table                           */
/**************************************************************************/


class Function_Table_Entry {
public:
    int def_line;   //where the function is defined, at beginning initialized to -1
    Type ret_type;
    string func_id;
    list<Arg_dcl> func_args;
    list<int> callers_list; 

    Function_Table_Entry(Type& ret_type, string& func_id, list<Arg_dcl>& func_args);    // constructor
    string get_func_def_place(int caller_line);
    void define_and_backpatch(int func_def_line);   //update func def_line and backpatch it to caller list 
    bool is_matching(Type& other_ret_type, string& other_func_id, list<Arg_dcl>& other_func_args);  //is func matches one of the given funcs

};

class Function_Table {
public:
    map<string, Function_Table_Entry> func_table_mp;
    Function_Table_Entry* curr_func_entry;

    Function_Table_Entry* find_func_entry(string id);
    Function_Table_Entry* insert_func_entry(Type& ret_type, string& func_id, list<Arg_dcl>& func_args);
    string unimplemented_funcs();
    string implemented_funcs();

};



/**************************************************************************/
/*              Class for the buffer we emit the commands to              */
/**************************************************************************/



class Vec_buf {
public:
    vector<string> buffer;
    Vec_buf(){};
    int nextquad();
    void backpatch(list<int> commitment_list, int line_number);
    void print_code(ofstream& output_file);
    void emit(string& command);
};


#endif //_PART3_HELPERS_H_
