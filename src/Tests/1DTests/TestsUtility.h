#ifndef TurboStructured_Tests_1DTests_1DTestUtility
#define TurboStructured_Tests_1DTests_1DTestUtility

#include <iostream>
#include <vector>
#include "kernel\kernel.h"
#include "Methods\ExplicitRungeKuttaFVM.h"
#include "Utility\Integration.h"

// all common functions for 1D tests
namespace TestsUtility{
	// constants
	const int nVar = 5;
	const double gamma1 = 0.4;				// specific heat ratio - 1
	std::valarray<double> exact_solution;
	
	// Error norm functions
	std::vector<double> ComputeL2Error(std::valarray<double>& comp_val, Grid& g, ParallelManager& par, double normVal = 1.0) {
		// initialise collector of errors
		std::vector< std::valarray<double> > delta_solution(nVar);
		for (int i = 0; i < nVar; i++) delta_solution[i] = std::valarray<double>(g.nlocalX);
		std::vector<double> res(nVar, 0);

		// compute function equals delta between two functions
		for (int i = 0; i < comp_val.size(); i++) {
			double err = comp_val[i] - exact_solution[i];
			delta_solution[i % nVar][i / nVar] = err * err;
		};

		std::valarray<double> hx = { &(g.hx[g.iMin]), (size_t)g.nlocalX };
		for (int i = 0; i < nVar; i++) {
			res[i] = ComputeIntegrall(delta_solution[i], hx);
		};

		par.Barrier();
		for (int i = 0; i < nVar; i++) res[i] = par.Sum(res[i]);
		for (int i = 0; i < nVar; i++) res[i] = sqrt(res[i]);
		for (int i = 0; i < nVar; i++) res[i] /= normVal;
		return res;
	};

	std::vector<double> ComputeL1Error(std::valarray<double>& comp_val, Grid& g, ParallelManager& par, double normVal = 1.0) {
		// initialise collector of errors
		std::vector< std::valarray<double> > delta_solution(nVar);
		for (int i = 0; i < nVar; i++) delta_solution[i] = std::valarray<double>(g.nlocalX);
		std::vector<double> res(nVar, 0);

		// compute function equals delta between two functions
		for (int i = 0; i < comp_val.size(); i++) {
			double err = comp_val[i] - exact_solution[i];
			delta_solution[i % nVar][i / nVar] = abs(err);
		};

		std::valarray<double> hx = { &(g.hx[g.iMin]), (size_t)g.nlocalX };
		for (int i = 0; i < nVar; i++) {
			res[i] = ComputeIntegrall(delta_solution[i], hx);
		};

		par.Barrier();
		for (int i = 0; i < nVar; i++) res[i] = par.Sum(res[i]);
		for (int i = 0; i < nVar; i++) res[i] /= normVal;
		return res;
	};

	std::vector<double> ComputeLinfError(std::valarray<double>& comp_val, Grid& g, ParallelManager& par) {
		std::vector<double> res_temp(nVar, 0);
		std::vector<double> res(nVar, 0);
		for (int i = 0; i < comp_val.size(); i++) {
			double err = comp_val[i] - exact_solution[i];
			if (res_temp[i % nVar] < abs(err)) res_temp[i % nVar] = abs(err);
		};
		par.Barrier();
		for (int i = 0; i < nVar; i++) res[i] = par.Max(res_temp[i]);

		return res;
	};

	// Save exact solution to tec plot
	void SaveExactSolution(std::string fname, Grid& g, ParallelManager& pManager) {
		//Tecplot version    
		int rank = pManager.getRank();

		// Open the file
		if (!pManager.IsFirstNode()) pManager.Wait(rank - 1);

		//Reopen file for writing
		std::ofstream ofs(fname, std::ios_base::app);

		// begin new zone for exact solution
		if (pManager.IsMaster()) {
			ofs << R"(ZONE T="Exact solution")";
			ofs << std::endl;
		};
		ofs << std::scientific;

		// Exact solution
		for (int i = 0; i < g.nlocalX; i++) {
			//Obtain cell data
			double rho = exact_solution[i * nVar];
			double u = exact_solution[i * nVar + 1] / rho;
			double v = 0;
			double w = 0;
			double e = exact_solution[i * nVar + 4] / rho - 0.5 * u * u;
			double P = gamma1 * rho * e;

			//Write to file
			ofs << g.CoordinateX[g.iMin + i] << " ";
			ofs << rho << " ";
			ofs << u << " ";
			ofs << v << " ";
			ofs << w << " ";
			ofs << P << " ";
			ofs << e << " ";
			ofs << std::endl;
		};	//	end cycle

			//Signal to next process to begin writing
		if (!pManager.IsLastNode()) {
			pManager.Signal(rank + 1);
		};

		//Syncronize
		pManager.Barrier();
		return;
	};

	// write errors in file
	void WriteErrors(std::string fname, std::vector<double>& err, Grid& g, ParallelManager& pManager) { 		// write result in file
		if (pManager.IsMaster()) {
			std::ofstream ofs(fname, std::ios_base::app);
			ofs << log(g.hx[0]) << ' ';
			ofs << g.nX << ' ';				// X size of first element of the grid
			ofs << (err[0]) << ' ';
			ofs << (err[1]) << ' ';
			ofs << (err[4]) << ' ';
			ofs << (err[TestsUtility::nVar]) << ' ';
			ofs << (err[TestsUtility::nVar + 1]) << ' ';
			ofs << (err[TestsUtility::nVar + 4]);
			ofs << std::endl;
			ofs.close();
		};

		pManager.Barrier();
	};
};

#endif
