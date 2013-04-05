
   /*--------------------------------------------------------------------+
    |                              Clay                                  |
    |--------------------------------------------------------------------|
    |                             functions.c                            |
    |--------------------------------------------------------------------|
    |                    First version: 03/04/2012                       |
    +--------------------------------------------------------------------+

 +--------------------------------------------------------------------------+
 |  / __)(  )    /__\ ( \/ )                                                |
 | ( (__  )(__  /(__)\ \  /         Chunky Loop Alteration wizardrY         |
 |  \___)(____)(__)(__)(__)                                                 |
 +--------------------------------------------------------------------------+
 | Copyright (C) 2012 University of Paris-Sud                               |
 |                                                                          |
 | This library is free software; you can redistribute it and/or modify it  |
 | under the terms of the GNU Lesser General Public License as published by |
 | the Free Software Foundation; either version 2.1 of the License, or      |
 | (at your option) any later version.                                      |
 |                                                                          |
 | This library is distributed in the hope that it will be useful but       |
 | WITHOUT ANY WARRANTY; without even the implied warranty of               |
 | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser  |
 | General Public License for more details.                                 |
 |                                                                          |
 | You should have received a copy of the GNU Lesser General Public License |
 | along with this software; if not, write to the Free Software Foundation, |
 | Inc., 51 Franklin Street, Fifth Floor,                                   |
 | Boston, MA  02110-1301  USA                                              |
 |                                                                          |
 | Clay, the Chunky Loop Alteration wizardrY                                |
 | Written by Joel Poudroux, joel.poudroux@u-psud.fr                        |
 +--------------------------------------------------------------------------*/


#include <stdlib.h>
#include <clay/functions.h>
#include <clay/data.h>


// Authorized functions in Clay


int clay_function_split_type[]        = {ARRAY_T, INTEGER_T};
int clay_function_reorder_type[]      = {ARRAY_T, ARRAY_T};
int clay_function_interchange_type[]  = {ARRAY_T, INTEGER_T, INTEGER_T, INTEGER_T};
int clay_function_reverse_type[]      = {ARRAY_T, INTEGER_T};
int clay_function_fuse_type[]         = {ARRAY_T};
int clay_function_skew_type[]         = {ARRAY_T, INTEGER_T, INTEGER_T};
int clay_function_iss_type[]          = {ARRAY_T, LIST_T};
int clay_function_stripmine_type[]    = {ARRAY_T, INTEGER_T, INTEGER_T, INTEGER_T};
int clay_function_unroll_type[]       = {ARRAY_T, INTEGER_T};
int clay_function_tile_type[]         = {ARRAY_T, INTEGER_T, INTEGER_T, INTEGER_T, INTEGER_T};
int clay_function_shift_type[]        = {ARRAY_T, INTEGER_T, LIST_T};
int clay_function_peel_type[]         = {ARRAY_T, LIST_T};
int clay_function_context_type[]      = {ARRAY_T};
int clay_function_dimreorder_type[]   = {ARRAY_T, INTEGER_T, ARRAY_T};
int clay_function_dimprivatize_type[] = {ARRAY_T, INTEGER_T, INTEGER_T};
int clay_function_dimcontract_type[]  = {ARRAY_T, INTEGER_T, INTEGER_T};
int clay_function_addarray_type[]     = {STRING_T};
int clay_function_getbetaloop_type[]  = {INTEGER_T};
int clay_function_getbetastmt_type[]  = {INTEGER_T};
int clay_function_getbetaloopbyname_type[]  = {STRING_T};
int clay_function_getarrayid_type[]   = {STRING_T};
int clay_function_print_type[]        = {MULTI_T};
int clay_function_replacearray_type[] = {INTEGER_T, INTEGER_T};


// That is just the prototype of each functions, so there are no data for args
const clay_prototype_t functions[CLAY_FUNCTIONS_TOTAL] = 
{
  {
    "split",      
    "void split(array beta, uint depth)",
    VOID_T, clay_function_split_type, 2
  },
  {
    "reorder",
    "void reorder(array beta_loop, array neworder)",
    VOID_T, clay_function_reorder_type, 2
  },
  {
    "interchange", 
    "void interchange(array beta_inner, uint depth_1, uint depth_2, bool pretty)",
    VOID_T, clay_function_interchange_type, 4
  },
  {
    "reverse",
    "void reverse(ident, uint depth)",
    VOID_T, clay_function_reverse_type, 2
  },
  {
    "fuse",
    "void fuse(array beta_loop)",
    VOID_T, clay_function_fuse_type, 1
  },
  {
    "skew",      
    "void skew(array beta, uint depth, int coeff)",
    VOID_T, clay_function_skew_type, 3
  },
  {
    "iss",    
    "void iss(array beta_loop, list inequation { ((output,) params,)) const }",
    VOID_T, clay_function_iss_type, 2
  },
  {
    "stripmine",
    "void stripmine(array beta, uint depth, uint size, bool pretty)",
    VOID_T, clay_function_stripmine_type, 4
  },
  {
    "unroll",  
    "void unroll(array beta_loop, uint factor)",
    VOID_T, clay_function_unroll_type, 2
  },
  {
    "unroll_noepilog",
    "void unroll_noepilog(array beta_loop, uint factor)",
    VOID_T, clay_function_unroll_type, 2
  },
  {
    "tile",    
    "void tile(array beta, uint depth, uint depth_outer, uint size, bool pretty)",
    VOID_T, clay_function_tile_type, 5
  },
  {
    "shift",   
    "void shift(array beta, uint depth, list vector { ((output,) (params,)) const })",
    VOID_T, clay_function_shift_type, 3
  },
  {
    "peel",   
    "void peel(array beta_loop,  list inequation { (params,) const })",
    VOID_T, clay_function_peel_type, 2
  },
  {
    "context", 
    "void context(array vector)",
    VOID_T, clay_function_context_type, 1
  },
  {
    "dimreorder",
    "void dimreorder(array beta, uint #access, array neworder)",
    VOID_T, clay_function_dimreorder_type, 3
  },
  {
    "dimprivatize",
    "void dimprivatize(array beta, uint #access, uint depth)",
    VOID_T, clay_function_dimprivatize_type, 3
  },
  {
    "dimcontract",
    "void dimcontract(array beta, uint #access, uint depth)",
    VOID_T, clay_function_dimcontract_type, 3
  },
  {
    "add_array",
    "int add_array(string name)",
    INTEGER_T, clay_function_addarray_type, 1
  },
  {
    "get_beta_loop",
    "array get_beta_loop(uint n >= 0)",
    ARRAY_T, clay_function_getbetaloop_type, 1
  },
  {
    "get_beta_stmt",
    "array get_beta_stmt(uint n >= 0)",
    ARRAY_T, clay_function_getbetastmt_type, 1
  },
  {
    "get_beta_loop_by_name",
    "array get_beta_loop_by_name(string iterator)",
    ARRAY_T, clay_function_getbetaloopbyname_type, 1
  },
  {
    "get_array_id",
    "int get_array_id(string name)",
    INTEGER_T, clay_function_getarrayid_type, 1
  },
  {
    "print",
    "void print(multi)",
    VOID_T, clay_function_print_type, 1
  },
  {
    "replace_array",
    "void replace_array(uint last_id, uint new_id)",
    VOID_T, clay_function_replacearray_type, 2
  }
};
