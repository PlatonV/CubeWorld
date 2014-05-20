#include "Precompiled.h"

int main()
{
	int exitCode;

	// Create the application
	CW::Application* app = new (std::nothrow) CW::Application;

	// Run the application
	exitCode = app->Run();

    return exitCode;
}