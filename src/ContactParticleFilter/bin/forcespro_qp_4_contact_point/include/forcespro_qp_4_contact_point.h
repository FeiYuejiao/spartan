/*
forcespro_qp_4_contact_point : A fast customized optimization solver.

Copyright (C) 2013-2017 EMBOTECH AG [info@embotech.com]. All rights reserved.


This software is intended for simulation and testing purposes only. 
Use of this software for any commercial purpose is prohibited.

This program is distributed in the hope that it will be useful.
EMBOTECH makes NO WARRANTIES with respect to the use of the software 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
PARTICULAR PURPOSE. 

EMBOTECH shall not have any liability for any damage arising from the use
of the software.

This Agreement shall exclusively be governed by and interpreted in 
accordance with the laws of Switzerland, excluding its principles
of conflict of laws. The Courts of Zurich-City shall have exclusive 
jurisdiction in case of any dispute.

*/

/* Generated by FORCES PRO v1.6.115 on Tuesday, January 2, 2018 at 11:53:46 PM */

#include <stdio.h>

#ifndef __forcespro_qp_4_contact_point_H__
#define __forcespro_qp_4_contact_point_H__

/* DATA TYPE ------------------------------------------------------------*/
typedef double forcespro_qp_4_contact_point_float;

typedef double forcespro_qp_4_contact_pointinterface_float;

#ifndef __SOLVER_STANDARD_TYPES__
#define __SOLVER_STANDARD_TYPES__

typedef signed char solver_int8_signed;
typedef unsigned char solver_int8_unsigned;
typedef char solver_int8_default;
typedef signed short int solver_int16_signed;
typedef unsigned short int solver_int16_unsigned;
typedef short int solver_int16_default;
typedef signed int solver_int32_signed;
typedef unsigned int solver_int32_unsigned;
typedef int solver_int32_default;
typedef signed long long int solver_int64_signed;
typedef unsigned long long int solver_int64_unsigned;
typedef long long int solver_int64_default;

#endif

#ifndef __SOLVER_STANDARD_TYPES__
#define __SOLVER_STANDARD_TYPES__

typedef signed char solver_int8_signed;
typedef unsigned char solver_int8_unsigned;
typedef char solver_int8_default;
typedef signed short int solver_int16_signed;
typedef unsigned short int solver_int16_unsigned;
typedef short int solver_int16_default;
typedef signed int solver_int32_signed;
typedef unsigned int solver_int32_unsigned;
typedef int solver_int32_default;
typedef signed long long int solver_int64_signed;
typedef unsigned long long int solver_int64_unsigned;
typedef long long int solver_int64_default;

#endif

/* SOLVER SETTINGS ------------------------------------------------------*/
/* print level */
#ifndef forcespro_qp_4_contact_point_SET_PRINTLEVEL
#define forcespro_qp_4_contact_point_SET_PRINTLEVEL    (0)
#endif

/* timing */
#ifndef forcespro_qp_4_contact_point_SET_TIMING
#define forcespro_qp_4_contact_point_SET_TIMING    (1)
#endif

/* Numeric Warnings */
/* #define PRINTNUMERICALWARNINGS */

/* maximum number of iterations  */
#define forcespro_qp_4_contact_point_SET_MAXIT         (200)	

/* scaling factor of line search (affine direction) */
#define forcespro_qp_4_contact_point_SET_LS_SCALE_AFF  (forcespro_qp_4_contact_point_float)(0.9)      

/* scaling factor of line search (combined direction) */
#define forcespro_qp_4_contact_point_SET_LS_SCALE      (forcespro_qp_4_contact_point_float)(0.95)  

/* minimum required step size in each iteration */
#define forcespro_qp_4_contact_point_SET_LS_MINSTEP    (forcespro_qp_4_contact_point_float)(1E-08)

/* maximum step size (combined direction) */
#define forcespro_qp_4_contact_point_SET_LS_MAXSTEP    (forcespro_qp_4_contact_point_float)(0.995)

/* desired relative duality gap */
#define forcespro_qp_4_contact_point_SET_ACC_RDGAP     (forcespro_qp_4_contact_point_float)(0.0001)

/* desired maximum residual on equality constraints */
#define forcespro_qp_4_contact_point_SET_ACC_RESEQ     (forcespro_qp_4_contact_point_float)(1E-06)

/* desired maximum residual on inequality constraints */
#define forcespro_qp_4_contact_point_SET_ACC_RESINEQ   (forcespro_qp_4_contact_point_float)(1E-06)

/* desired maximum violation of complementarity */
#define forcespro_qp_4_contact_point_SET_ACC_KKTCOMPL  (forcespro_qp_4_contact_point_float)(1E-06)


/* RETURN CODES----------------------------------------------------------*/
/* solver has converged within desired accuracy */
#define forcespro_qp_4_contact_point_OPTIMAL      (1)

/* maximum number of iterations has been reached */
#define forcespro_qp_4_contact_point_MAXITREACHED (0)

/* no progress in line search possible */
#define forcespro_qp_4_contact_point_NOPROGRESS   (-7)

/* fatal internal error - nans occurring */
#define forcespro_qp_4_contact_point_NAN  (-10)

/* licensing error - solver not valid on this machine */
#define forcespro_qp_4_contact_point_LICENSE_ERROR  (-100)


/* PARAMETERS -----------------------------------------------------------*/
/* fill this with data before calling the solver! */
typedef struct forcespro_qp_4_contact_point_params
{
    /* matrix of size [16 x 16] (column major format) */
    forcespro_qp_4_contact_point_float QuadraticCost[256];

    /* vector of size 16 */
    forcespro_qp_4_contact_point_float LinearCost[16];

} forcespro_qp_4_contact_point_params;


/* OUTPUTS --------------------------------------------------------------*/
/* the desired variables are put here by the solver */
typedef struct forcespro_qp_4_contact_point_output
{
    /* vector of size 16 */
    forcespro_qp_4_contact_point_float alpha[16];

} forcespro_qp_4_contact_point_output;


/* SOLVER INFO ----------------------------------------------------------*/
/* diagnostic data from last interior point step */
typedef struct forcespro_qp_4_contact_point_info
{
    /* iteration number */
    solver_int32_default it;

	/* number of iterations needed to optimality (branch-and-bound) */
	solver_int32_default it2opt;
	
    /* inf-norm of equality constraint residuals */
    forcespro_qp_4_contact_point_float res_eq;
	
    /* inf-norm of inequality constraint residuals */
    forcespro_qp_4_contact_point_float res_ineq;

    /* primal objective */
    forcespro_qp_4_contact_point_float pobj;	
	
    /* dual objective */
    forcespro_qp_4_contact_point_float dobj;	

    /* duality gap := pobj - dobj */
    forcespro_qp_4_contact_point_float dgap;		
	
    /* relative duality gap := |dgap / pobj | */
    forcespro_qp_4_contact_point_float rdgap;		

    /* duality measure */
    forcespro_qp_4_contact_point_float mu;

	/* duality measure (after affine step) */
    forcespro_qp_4_contact_point_float mu_aff;
	
    /* centering parameter */
    forcespro_qp_4_contact_point_float sigma;
	
    /* number of backtracking line search steps (affine direction) */
    solver_int32_default lsit_aff;
    
    /* number of backtracking line search steps (combined direction) */
    solver_int32_default lsit_cc;
    
    /* step size (affine direction) */
    forcespro_qp_4_contact_point_float step_aff;
    
    /* step size (combined direction) */
    forcespro_qp_4_contact_point_float step_cc;    

	/* solvertime */
	forcespro_qp_4_contact_point_float solvetime;   

} forcespro_qp_4_contact_point_info;









/* SOLVER FUNCTION DEFINITION -------------------------------------------*/
/* examine exitflag before using the result! */
#ifdef __cplusplus
extern "C" {
#endif
extern solver_int32_default forcespro_qp_4_contact_point_solve(forcespro_qp_4_contact_point_params *params, forcespro_qp_4_contact_point_output *output, forcespro_qp_4_contact_point_info *info, FILE *fs);

#ifdef __cplusplus
}
#endif

#endif