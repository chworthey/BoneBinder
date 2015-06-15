#include "BoneBinderEngine.h"
#include "EngineInitialSettings.h" 



int main(int argc, char** argv)
{
	EngineInitialSettings settings;

	settings.SetWindowTitle("Bone Binder");

	BoneBinderEngine engine(settings);
	engine.Run();

	return 0;
}