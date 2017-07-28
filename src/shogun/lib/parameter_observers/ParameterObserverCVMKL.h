/*
* BSD 3-Clause License
*
* Copyright (c) 2017, Shogun-Toolbox e.V. <shogun-team@shogun-toolbox.org>
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* * Redistributions of source code must retain the above copyright notice, this
*   list of conditions and the following disclaimer.
*
* * Redistributions in binary form must reproduce the above copyright notice,
*   this list of conditions and the following disclaimer in the documentation
*   and/or other materials provided with the distribution.
*
* * Neither the name of the copyright holder nor the names of its
*   contributors may be used to endorse or promote products derived from
*   this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* Written (W) 2017 Giovanni De Toni
*
*/

#ifndef SHOGUN_PARAMETEROBSERVERCVMKL_H
#define SHOGUN_PARAMETEROBSERVERCVMKL_H

#include <shogun/lib/SGMatrix.h>
#include <shogun/lib/parameter_observers/ParameterObserverCV.h>

namespace shogun
{
	class ParameterObserverCVMKL : public ParameterObserverCV
	{

	public:
		/**
		 * Constructor
		 */
		ParameterObserverCVMKL(bool verbose = false);
		/**
		 * Destructor
		 */
		virtual ~ParameterObserverCVMKL();

		/** @return mkl weights matrix, one set of weights per column,
		 *	num_folds*num_runs columns, one fold after another
		 * */
		virtual SGMatrix<float64_t> get_mkl_weights();

		/**
		 * Clear the MKL weights and the observations.
		 */
		virtual void clear();

		virtual const char* get_name() const
		{
			return "ParameterObserverCVMKL";
		}

	protected:
		/**
		 * Generate mkl weights based on observation caught.
		 * It is called by get_mkl_weights() and it is run only
		 * when m_mkl_weights is empty.
		 */
		void generate_mkl_weights();

		/** storage for MKL weights, one set per column
		 * num_kernel times num_folds*num_runs matrix where all folds of a runs
		 * are added one after another */
		SGMatrix<float64_t> m_mkl_weights;
	};
}

#endif // SHOGUN_PARAMETEROBSERVERCVMKL_H