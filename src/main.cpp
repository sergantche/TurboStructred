#include <iostream>
#include <vector>
#include "kernel\kernel.h";

struct ShockTubeParameters {
	double gammaL;
	double roL;
	double PL; 
	double uL; 
	double roR;
	double PR;
	double uR;
	double gammaR;
};

std::vector<double> SODinitialDistribution(Vector r, double xI, ShockTubeParameters params) {
	std::vector<double> U(5);	
	double ro;
	double u;
	double gamma;
	double P;

	//Left
	if (r.x <= xI) {
		ro = params.roL;
		u = params.uL;
		P = params.PL;
		gamma = params.gammaL;
	} else {
		ro = params.roR;
		u = params.uR;
		P = params.PR;
		gamma = params.gammaR;
	};

	U[0] = ro;
	U[1] = u * ro;
	U[2] = 0;
	U[3] = 0;
	U[4] = P / (gamma - 1.0) + ro * u * u / 2.0;

	return U;
};

int main(int argc, char *argv[])
{
	//main function
	KernelConfiguration conf;
	conf.nDims = 1;
	conf.nX = 1000;
	conf.nY = 1;
	conf.LX = 2.0;
	conf.LY = 1.0;
	conf.isPeriodicX = true;
	conf.isPeriodicY = true;

	conf.gamma = 1.4;
	conf.nVariables = 5;

	conf.SolutionMethod = KernelConfiguration::Method::ExplicitRungeKuttaFVM;
	conf.methodConfiguration.CFL = 0.5;
	conf.methodConfiguration.RungeKuttaOrder = 1;

	conf.MaxTime = 0.2;
	conf.MaxIteration = 10000000;
	conf.SaveSolutionSnapshotTime = 0.1;
	conf.SaveSolutionSnapshotIterations = 0;

	//init kernel
	Kernel kernel;
	kernel.Init(conf);

	// initial conditions
	ShockTubeParameters params;
	params.gammaL = params.gammaR = 1.4;
	params.roL = 1.0;
	params.PL = 1.0;
	params.uL = 0.0;
	params.roR = 0.1;
	params.PR = 0.125;
	params.uR = 0.0;
	auto initD = std::bind(SODinitialDistribution, std::placeholders::_1, 1.0, params);	
	kernel.SetInitialConditions(initD);

	//save solution
	kernel.SaveSolution("init.dat");
	
	//run computation
	kernel.Run();		

	//finalize kernel
	kernel.Finilaze();

	return 0;
};