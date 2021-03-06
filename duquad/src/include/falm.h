/*
 * falm.h
 *
 *  Created on: Nov 3, 2014
 *      Author: sverre
 */

/** \file
 *  ### Fast Augmented Lagrangian Method ###
 */

#ifndef FALM_H_
#define FALM_H_

#include "head.h"
#include "math_functions.h"
#include "fgm.h"
#include "print.h"

struct Struct_FALM{

	struct Problem * prob;
	struct Options * opt;
	struct Info * info;
	struct Result * res;

	// Vectors used for calculations
	real_t * z;
	real_t * lambda;
	//real_t * lambda2;
	real_t * temp1_dim_N;
	real_t * temp2_dim_M;
	real_t * temp3_dim_M;
	real_t * z_avg;
	real_t * summ;
	real_t * pf_vec;
	real_t * A_z;

	// Different from DGM
	real_t * lambda_old;
	real_t * y1;
	real_t * z_ds;
	real_t * A_z_ds;

	real_t time_inner_y;
	uint32_t iterations_inner_y;

	// New for alm
	real_t * H_hat;
	real_t * A2;
	real_t * rho_At_b;

}; /**< Struct containing all necessary vectors and parameters for running FALM */

// Public functions
int32_t FALM(struct Struct_FALM *s);

#endif /* FALM_H_ */
