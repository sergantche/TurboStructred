#include "Tests/tests.h"
#include <conio.h>



// Run the test
int main(int argc, char *argv[])
{
	//RunPoiseuille2D(argc, argv);
	//RunKonuhovMixing(argc, argv);
	Price2008KHI::RunExperiment(argc, argv);
	//RunKHI2D(argc, argv);
	//RunTurbulentMixing(argc, argv);
	//DrivenCavityTest::RunExperiment(argc, argv);
	//RunPoiseuille3D(argc, argv);
	//RunPoiseuille3D(argc, argv);
	//RunShearFlow2D(argc, argv);
	//RunPoiseuille2D(argc, argv);
	//RunShearFlow3D(argc, argv);
	//ToroTests::RunExperiment(argc, argv);
	
	_getch();
	return 0;
};