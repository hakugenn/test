#include "GameLib/Framework.h"

using namespace GameLib;

namespace GameLib{
	void Framework::update(){
		unsigned* vram = videoMemory();
		static unsigned i;
		vram[ 200*width() + 100] = 0xff0000;
		//vram[ i ] += i * 100;
		//i += 9973; //1万以下最大の素数
		//i %= ( width() * height() );
	}
}